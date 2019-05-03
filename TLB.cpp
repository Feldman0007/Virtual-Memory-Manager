#include "TLB.h"

TLB::TLB() {
	
	numTLBEntries = 0;
}

bool TLB::hit(int pageNum) {
	for (int i = 0; i < TLB_SIZE; i++) {
		if (entries[i].getPage() == pageNum) {		
			entries[i].useTime = 0;
			return true; 
		}
	}
	return false; 
}

void TLB::update(int index, int frameNum, int pageNum) {
	#if (TLB_REPLACE)
		for (int i = 0; i < TLB_SIZE; i++) {												 //We are accessing the tlb, so update the use time of all entries
			entries[i].useTime++;
		}
	#endif
	if (index == -1){																		 //If tlb if full, execute a tlb replacement algorithm
		#if (TLB_REPLACE)																	 //If LRU selected
			int victim = algorithm.LRUreplace(entries);					                     //execute LRU replacement algorithm
			entries[victim].updateTLBEntry(frameNum, pageNum);								 //boot victim entry off and replace it with new entry
		#else																				 //else FIFO selected
			int victim = algorithm.FIFOreplace();					 //execute FIFO replacement algorithm
			entries[victim].updateTLBEntry(frameNum, pageNum);								 //boot victim entry off and replace it with new entry
		#endif
	}
	else{																					 //else, we found an available spot
		entries[index].updateTLBEntry(frameNum, pageNum);									 //simply add that entry to the tlb
		#if (!TLB_REPLACE)																	 //if we are using FIFO replacement algorithm
				algorithm.enqueue(index);													 //add to fifo queue 
		#endif
	}
}

int TLB::findAvailableSpot(){
	if (numTLBEntries == TLB_SIZE) {
		return -1;
	}
	else {
		for (int i = 0; i < TLB_SIZE; i++){
			if (entries[i].isAvailable == true) {
				entries[i].isAvailable = false;	
				numTLBEntries++;
				return i;
			}
		}
		return -1;
	}
}
int TLB::retrieveFrame(int pageNum){
	for (int i = 0; i < TLB_SIZE; i++) {
		if (entries[i].getPage() == pageNum) {
			return entries[i].getFrame();
		}
	}
}