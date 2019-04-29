#include "VMM.h"

VMM::VMM() {
	for (int i = 0; i < 256; i++) {
		freeFramesList[i] = true;
	}
}
char * VMM::pageIn() {
										
	int pageNum = mmu.getAddress().getPage();
	return backingStore.read(pageNum);													//fetch data from backingStore 
}

void VMM::processInput(int intAddr) {
	cout << "Logical Address: " << setw(5) << hex <<  intAddr  << " | " ;
	mmu.processAddress(intAddr);
	int pageNum = mmu.getAddress().getPage();											//get page number of the address we're working with
	
	mmu.update_tlb_access_count();
	if (mmu.checkTLB(pageNum)) {														//if we have a TLB hit
		ram.print(mmu.retrieveFrame(pageNum), mmu.getAddress().getDispacement());		//access RAM and output using frame number provided by the TLB
		mmu.updateTLB(mmu.retrieveFrame(pageNum), mmu.getAddress().getDispacement());
	}	
	else {																				//else we have a tlb miss, look in the page table			
																						//store the page in TLB as we are about to
		mmu.update_tlb_faults();
		bool valid = pgTable.pageTableLookup(pageNum);									//determine if that page's valid bit is marked valid or invalid
		if (valid) {																	//If valid bit is marked as valid
			mmu.update_page_access_count();
			ram.print(pgTable.getFrame(pageNum), mmu.getAddress().getDispacement());    //access RAM and output using frame number provided by page table				  
		}
		else {
			mmu.update_page_in_faults();												//update number of faults
			pageFaultRoutine();							
		}
		// call update here
	}
}

void VMM::print() {
	mmu.calculateTLBRate();
	mmu.calculatePageFaultRate();
}

void VMM::pageFaultRoutine() {														//trap 
	char * frame = pageIn();														//grab page from backing store
	int freeFrameNumber = findAvailableFrame();										//select free frame from RAM
	
	if (freeFrameNumber == -1){
		cout << "RAM is full";
		system("PAUSE");
		//call page replacement algorithm and/or boot stuff off ram
	}

	ram.store(freeFrameNumber, frame);												//Push data into the free frame in RAM
	
																					
//mmu.updateTLB(freeFrameNumber, pageNum);
	pgTable.updatePageTable(mmu.getAddress().getPage(), freeFrameNumber);			// Update the page table
	ram.print(freeFrameNumber, mmu.getAddress().getDispacement());					//send data to output
}

int VMM::findAvailableFrame() {
	for (int i = 0; i < 256; i++) {
		if (freeFramesList[i] == true) { //If available
			freeFramesList[i] = false;   // occupy it
			return i;					
		}
	}
	return -1; //RAM is full, return a sentinel value
}


