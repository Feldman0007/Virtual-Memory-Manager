#include "TLB.h"

TLB::TLB() {
	numTLBEntries = 0;
}
bool TLB::hit(int pageNum) {
	for (int i = 0; i < TLB_SIZE; i++) {
		if (translationLookAsideBuffer[i].getPage() == pageNum) {		//If an entry exists for the given page number
			//if LRU
			translationLookAsideBuffer[i].useTime = 0;
			return true;												// we have a tlb hit, so return true
		}
	}
	return false; // tlb miss
}

void TLB::update(int frameNum, int pageNum) {											//Update pageNum, frameNum  in TLB at available slot. If there is already a TLB entry for the given page 
	for (int i = 0; i < TLB_SIZE; i++) {
		translationLookAsideBuffer[i].useTime++;
	}
	int index = findAvailableSpot();	//Find available index
	if (index == -1) {  //if the TLB is full, call a replacement algorithm
		//if (LRU)
		algorithm.LRUreplace(frameNum, pageNum, translationLookAsideBuffer); // call 
		//else (FIFO)
			//algorithm.FIFOreplace(frameNum, pageNum, translationLookAsideBuffer);
	}
	else{
		translationLookAsideBuffer[index].updateTLBEntry(frameNum, pageNum); 
		//if FIFO
			//algorithm.enqueue(i);
	}
}

int TLB::findAvailableSpot() {
	if (numTLBEntries == TLB_SIZE) {
		return -1; //flag variable, TLB is full
	}
	else
	{
		for (int i = 0; i < TLB_SIZE; i++) {
			if (translationLookAsideBuffer[i].isAvailable == true) {
				translationLookAsideBuffer[i].isAvailable = false;			// we will populate it, no longer available
				numTLBEntries++;
				return i;
			}

		}
	}
}

int TLB::getFrameTLBEntry(int pageNum){
	return translationLookAsideBuffer[pageNum].getFrame();
}