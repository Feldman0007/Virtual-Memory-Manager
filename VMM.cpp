#include "VMM.h"

VMM::VMM() {
	for (int i = 0; i < 256; i++) {
		freeFramesList[i] = true;
	}
}
char * VMM::pageIn() {								
	return backingStore.read(currentAddress.getPage());													    //fetch data from backingStore 
}

void VMM::processInput(int intAddr) {
	cout << "Logical Address: " << setw(5) << hex <<  intAddr  << " | " ;
	mmu.processAddress(intAddr, currentAddress);
	
	mmu.update_tlb_access_count();
	if (mmu.checkTLB(currentAddress.getPage())) {														     //if we have a TLB hit
		int frame = mmu.getFrameTLB(currentAddress.getPage());												 //grab the frame number so we can index into RAM
		ram.print(frame, currentAddress.getDispacement());													 //access RAM  using frame number provided by the TLB and output													 //we need to update the time of this TLB entry. For replacement algorithms
	}	
	else {																									 //else we have a tlb miss, look in the page table			
		mmu.update_tlb_faults();																			 //if that page is valid
		mmu.update_page_access_count();
		if (page_table.pageTableLookup(currentAddress.getPage())) {											 //If valid bit is marked as valid
			int frame = page_table.getFrame(currentAddress.getPage());										 //grab the frame number so we can update the TLB and index into RAM
			ram.print(frame, currentAddress.getDispacement());												 //access RAM using frame number provided by page table and output
			mmu.updateTLB(frame, currentAddress.getPage());
		}
		else {
			mmu.update_page_in_faults();								                  			    	//update number of faults
			pageFaultRoutine();							
		}
		// call update here
	}
}

void VMM::print() {
	mmu.calculateTLBRate();
	mmu.calculatePageFaultRate();
}

void VMM::pageFaultRoutine() {																				//trap
	char * frameOfData = pageIn();																			//grab page from backing store
	int freeFrameNumber = findAvailableFrame();																//select free frame from RAM
	
	if (freeFrameNumber == -1){
		cout << "RAM is full";
		system("PAUSE");
		//call page replacement algorithm and/or boot stuff off ram????
	}
	ram.store(freeFrameNumber, frameOfData);												//Push data into the free frame in RAM
	page_table.updatePageTable(currentAddress.getPage(), freeFrameNumber);					// Update the page table
	ram.print(freeFrameNumber, currentAddress.getDispacement());							//send data to output
	mmu.updateTLB(freeFrameNumber, currentAddress.getPage());
}

int VMM::findAvailableFrame() {
	//replacementAlgo
	for (int i = 0; i < 256; i++) {
		if (freeFramesList[i] == true) { //If available
			freeFramesList[i] = false;   // occupy it
			return i;					
		}
	}
	return -1; //RAM is full, return a sentinel value
}


