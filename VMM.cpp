#include "VMM.h"

VMM::VMM() {
	for (int i = 0; i < RAM_SIZE; i++) {
		freeFramesList[i] = true;
	}
}
char* VMM::pageIn() {
	return backingStore.read(mmu.getAddress().getPage());																				//fetch data from backingStore 
}

void VMM::processInput(int intAddr) {
	cout <<setw(5) << hex << uppercase << intAddr;
	mmu.processAddress(intAddr);
	int pageNum = mmu.getAddress().getPage();																		//get page number of the address we're working with

	mmu.update_tlb_access_count();																				    //we are about to access tlb, increment total tlb access count
	if (mmu.checkTLB(pageNum)) {																					//if we have a TLB hit
		mmu.read_and_print(ram, mmu.tlb_get_frame(pageNum), mmu.getAddress().getDispacement());						//access RAM, read in data, and print output using frame number provided by the TLB
		mmu.updateTLB(mmu.tlb_get_frame(pageNum), pageNum);															//since we accessed tlb, update usage time for the LRU algorithm 
	}
	else {																											//else we have a tlb miss, look in the page table			
		mmu.update_tlb_faults();																					//increment tlb fault count

		mmu.update_page_access_count();																				//increment page access count, as we are about to check reference the page table

		bool valid = pcb.pageTableLookup(pageNum);
		try {
			if (!valid)																								//determine if that page's valid bit is marked valid or invalid, if valid bit is marked as valid...//if page table entry is marked invalid
			{
				throw valid;																						//generate an interrupt for the page fault routine
			}
			else {
				mmu.read_and_print(ram, pcb.getFrame(pageNum), mmu.getAddress().getDispacement());				//access RAM, read in data, and print output using frame number provided by the page table			  
				mmu.updateTLB(pcb.getFrame(pageNum), pageNum);													//update the tlb with the page table entry we just accessed
			}
		}
		catch (bool valid) {
			mmu.update_page_in_faults();
			pageFaultRoutine(pageNum);
		}
													

	}
}

void VMM::printResults() {
	mmu.calculateTLBRate();
	mmu.calculatePageFaultRate();
}

void VMM::pageFaultRoutine(int faultingPage) {																		//trap 
	char* frame = pageIn();																						//grab data from backing store
	int freeFrameNumber = findFreeFrame();																			//select free frame from RAM

	if (freeFrameNumber == -1) {																						//if RAM is full execute a page replacement algorithm 																		
#if (PAGE_REPLACE)																							//if LRU selected
		int victim = algorithm.LRUreplace(ram);																//use LRU algorithm to find victim frame	
		/*if (victim frame is dirty)																		//we need to write it to the backing store before we boot it out of ram
				but we do nothing since we aren't writing data in the scope of this project*/
		mmu.storeInRam(ram, victim, frame);																	//place data in victim frame in RAM
		pcb.invalidateEntries(victim);																	//Invalidate the page table entries that still reference the victim frame 
		pcb.updatePageTable(faultingPage, victim);										                //Update the frame referenced by the faulting page in the page table
		mmu.updateTLB(victim, faultingPage);																//update the tlb with the page and frame we just accessed
		mmu.read_and_print(ram, victim, mmu.getAddress().getDispacement());									//read byte from RAM and print to user

#else																										//else FIFO selected
		int victim = algorithm.FIFOreplace();																//use FIFO algorithm to find victim frame	
		/*if (victim frame is dirty)																		//we need to write it to the backing store before we boot it out of ram
				but we do nothing since we aren't writing data in the scope of this project*/
		mmu.storeInRam(ram, victim, frame);
		pcb.invalidateEntries(victim);
		pcb.updatePageTable(faultingPage, victim);														//Same routine as above
		mmu.updateTLB(victim, faultingPage);
		mmu.read_and_print(ram, victim, mmu.getAddress().getDispacement());
#endif																											
	}
	else {																											//else we found an available frame, store data there
		mmu.storeInRam(ram, freeFrameNumber, frame);																//Push data into the free frame in RAM
		pcb.updatePageTable(faultingPage, freeFrameNumber);														//Update the page table
		mmu.read_and_print(ram, freeFrameNumber, mmu.getAddress().getDispacement());								//send data to output
		mmu.updateTLB(freeFrameNumber, faultingPage);																//update the tlb with the page and frame we just accessed
#if (!PAGE_REPLACE)																							//if we are using FIFO page replacement
		algorithm.enqueue(freeFrameNumber);																		//add to fifo queu
#endif
	}
}

int VMM::findFreeFrame() {																							//faultingPage
	for (int i = 0; i < RAM_SIZE; i++) {
		if (freeFramesList[i] == true) {																			//If available
			freeFramesList[i] = false;																				//occupy it
			return i;
		}																											//otherwise RAM is full, and we need to perform a page replacement.
	}
	return -1;																										//return -1, a sentinal value indicating that  RAM is full
}

