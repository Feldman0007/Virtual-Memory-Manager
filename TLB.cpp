#include "TLB.h"

TLB::TLB() {
	for (int i = 0; i < TLB_SIZE; i++) {
		entries[i].isAvailable = true;
	}
	numTLBEntries = 0;
}

hitStatus TLB::hit(uint32_t pageNum) {															//We will look through TLB to check if we can find the page number that is already existed in the TLB
	for (uint32_t i = 0; i < TLB_SIZE; i++) {
		if (entries[i].getPage() == pageNum) {															
			entries[i].useTime = 0;
			hitStatus hit;
			hit.indexOfHit = i;
			hit.isHit = true;
			return hit; 
		}
	}
	hitStatus miss;
	miss.indexOfHit = 999;
	miss.isHit = false;
	return miss; 
}

void TLB::update(uint32_t available_index, uint32_t frameNum, uint32_t pageNum) {
	#if (TLB_REPLACE)																			 //If we are using LRU replacement
		for (uint32_t i = 0; i < TLB_SIZE; i++) {												 //Update the use time of all entries since we are accessing the tlb
			entries[i].useTime++;
		}
	#endif

	if (available_index == 999U){																 //If tlb if full, execute a tlb replacement algorithm
		#if (TLB_REPLACE)																		 //If LRU selected
			uint32_t victim = algorithm.LRUreplace(entries);									 //execute LRU replacement algorithm
			entries[victim].updateTLBEntry(frameNum, pageNum);									 //boot victim entry off and replace it with new entry
		#else																					 //else FIFO selected
			uint32_t victim = algorithm.FIFOreplace();											 //execute FIFO replacement algorithm
			entries[victim].updateTLBEntry(frameNum, pageNum);									 //boot victim entry off and replace it with new entry
		#endif
	}
	else{																						 //else, we found an available spot
		entries[available_index].updateTLBEntry(frameNum, pageNum);								 //simply add that entry to the tlb
		#if (!TLB_REPLACE)																		 //if we are using FIFO replacement algorithm
				algorithm.enqueue(available_index);												 //add the newest entry into the FIFO queue 
		#endif
	}
}

void TLB::clear() {																				
	for(uint32_t i = 0; i < TLB_SIZE; i++){
		entries[i].frameNum = 999;
		entries[i].pageNum = 999;
		entries[i].isAvailable = true;
		entries[i].useTime = 0;
	}
}


uint32_t TLB::findAvailableSpot(){
	if (numTLBEntries == TLB_SIZE) {
		return 999U;																			//if TLB is full we return a sentinel value back to the TLB, where it will administer TLB replacement
	}
	else {																						//else look for the free spot
		for (uint32_t i = 0; i < TLB_SIZE; i++){
			if (entries[i].isAvailable == true) {												//found the free spot, occupy it and return that index
				entries[i].isAvailable = false;	
				numTLBEntries++;
				#if (!TLB_REPLACE)																//if we are using FIFO replacement algorithm
						algorithm.enqueue(i);													//add the newest entry into the FIFO queue 
				#endif
				return i;
			}
		}
		return 999U;
	}
}
uint32_t TLB::retrieveFrame(uint32_t pageNum){													//retrieve frame associated with a TLB entry
	for (uint32_t i = 0; i < TLB_SIZE; i++) {													//look for the tlb entry with the matching page number
		if (entries[i].getPage() == pageNum) {													//once found
			return entries[i].getFrame();														//return the associated frame number
		}
	}
	return 999U;																				// returns a value to appease the compiler :). Won't ever execute with the ordering of our program
}