#include "VMM.h"

VMM::VMM() {
	for (uint32_t i = 0; i < RAM_SIZE; i++) {
		freeFramesList[i] = true;																					//all frames are initially free (true) since we haven't loaded anything into memory
	}
}
char * VMM::pageIn(uint32_t faultingPage){
	return backingStore.read(faultingPage);																			//fetch data from backingStore 
}

void VMM::servicePageRequest(uint32_t intAddr) {
	cout << hex << uppercase << setw(4) << setfill('0') << intAddr;
	mmu.processAddress(intAddr);																					//After this line, address is updated pageNumber, pageOffset, and logicalAddress
	uint32_t pageNum = mmu.getAddress().getPage();																	//get page number of the address we're working with
	

	mmu.update_tlb_access_count();																				    //we are about to access tlb, increment total tlb access count
	hitStatus status = mmu.checkTLB(pageNum);
	if (status.isHit) {																								//if we have a TLB hit, that is the page number is found in the TLB..
		mmu.read_and_print(ram, mmu.tlb_get_frame(pageNum), mmu.getAddress().getDispacement());						//access RAM through the MMU, read in data, and print output using frame number provided by the TLB
		mmu.updateTLB(mmu.tlb_get_frame(pageNum), pageNum, status);															//since we accessed tlb, update usage time for the LRU algorithm 
	}	
	else {																											//else we have a tlb miss, look in the page table			
		mmu.update_tlb_faults();																					//increment tlb fault count
		
		try {
			bool valid = pcb.pageTableLookup(pageNum);																//determine if that page's valid bit is marked valid or invalid - page table at index pageNum, return false=available, true=used
			mmu.trap(valid, pageNum);																				//Have we encountered a page fault? Let the MMU try and determine whether a trap will be generated.
		}																																																			
		catch (uint32_t faultingPage) {																				//we have a page fault
			mmu.update_page_in_faults();																			//increment page fault count
			pageFaultRoutine(faultingPage);																			//handle page fault
			return;																									//page fault routine complete, we are done processing this page request
		}																											//otherwise the frame associated with the page is valid and we can proceed normally
		mmu.update_page_access_count();																				//increment page access count, we have obtained a valid frame number to access main memory from the page table
		mmu.read_and_print(ram, pcb.getFrame(pageNum), mmu.getAddress().getDispacement());							//access RAM through the MMU, read in data, and print output using frame number provided by the page table			  
		mmu.updateTLB(pcb.getFrame(pageNum), pageNum, status);														//update the tlb with the page table entry we just accessed
	}		
}

uint32_t VMM::findFreeFrame() {
	for (uint32_t i = 0; i < RAM_SIZE; i++) {
		if (freeFramesList[i] == true) {																			//If available
			freeFramesList[i] = false;																				//occupy it
			return i;
		}																											//otherwise RAM is full, and we need to perform a page replacement.
	}
	return 999U;																									//return 999, a sentinal value indicating that RAM is full
}

void VMM::pageFaultRoutine(uint32_t faultingPage) {																	//executinng page fault routine...
	char * frame = pageIn(faultingPage);																			//grab data from backing store using page number that generated the fault
	uint32_t freeFrameNumber = findFreeFrame();																		//select free frame from RAM if available, otherwise return the sentinel value 99
	
	hitStatus status;
	status.indexOfHit = 999; //at this point we already checked the TLB and determined that it was a miss. We create another instance here because it's a require parameter to update tlb
	status.isHit = false;  

	if (freeFrameNumber == 999U){																					//if RAM is full execute a page replacement algorithm 																		
		#if (PAGE_REPLACE)																							//if LRU selected
				uint32_t victim = algorithm.LRUreplace(ram);														//use LRU algorithm to find victim frame	
			  /*if (victim.get_dirtyBit())																		//we need to write it to the backing store before we boot it out of ram
						if dirty bit marked, we need to write it to the backing store before we boot it out of ram
						but we do nothing since we aren't writing data in the scope of this project*/
				pcb.invalidate_PT_Entries(victim);																	//Invalidate the page table entries that still reference the victim frame 
				pcb.updatePageTable(faultingPage, victim);										                    //Update the frame referenced by the faulting page in the page table
				mmu.updateTLB(victim, faultingPage, status);																//update the tlb with the page and frame we just accessed
				mmu.storeInRam(ram, victim, frame);																	//place data in victim frame in RAM
				mmu.read_and_print(ram, victim, mmu.getAddress().getDispacement());									//page fault complete, restart original instuction of reading a byte and print to user
																
		#else																										//else FIFO selected
				uint32_t victim = algorithm.FIFOreplace();															//use FIFO algorithm to find victim frame	
			  /*if (victim frame is dirty)																	
						if dirty bit marked, we need to write it to the backing store before we boot it out of ram
						but we do nothing since we aren't writing data in the scope of this project*/
				pcb.invalidate_PT_Entries(victim);
				pcb.updatePageTable(faultingPage, victim);															//Same routine as above
				mmu.storeInRam(ram, victim, frame);
				mmu.updateTLB(victim, faultingPage, status);
				
				mmu.read_and_print(ram, victim, mmu.getAddress().getDispacement());									//page fault complete, restart original instuction of reading a byte and print to user
		#endif																											
	}
	else {																											//else we found an available frame, store data there
		mmu.storeInRam(ram, freeFrameNumber, frame);																//Push data into the free frame in RAM
		pcb.updatePageTable(faultingPage, freeFrameNumber);															//Update the page table
		mmu.updateTLB(freeFrameNumber, faultingPage, status);																//update the tlb with the page and frame we just accessed
		
		mmu.read_and_print(ram, freeFrameNumber, mmu.getAddress().getDispacement());								//page fault complete, restart original instuction of reading a byte and print to user
		
		#if (!PAGE_REPLACE)																							//if we are using FIFO page replacement
			algorithm.enqueue(freeFrameNumber);																		//add the number of the frame we just loaded into memory to the fifo queue
		#endif
	}																		
}

void VMM::printResults() {																							//calculate and print tlb hit rate and page fault rate
	mmu.calculateTLBRate();
	mmu.calculatePageFaultRate();
}

void VMM::mmu_clearTLB() {																							//clear the TLB when we enter a new address space
	mmu.clearTLB();
}

/*
void VMM::validateAddressSpace(){ 																					//validate the address space when we enter a new one
	mmu.validateAddressSpace();
}
*/
