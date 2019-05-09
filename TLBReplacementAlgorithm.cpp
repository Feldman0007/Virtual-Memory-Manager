#include "TLB.h"
#include <iostream>

using namespace std;

uint32_t TLBReplacementAlgorithm::LRUreplace(TLBEntry *tlb) {								    //LRU replacement algorithm for TLB
	uint32_t lruValue = 0;																		// least recently used time, used in comparisons to find LRU time
	uint32_t victim = 0;																		// used to save the index of that with the LRU time
	for (uint32_t i = 0; i < TLB_SIZE; i++) {													//find victim
		if (tlb[i].useTime > lruValue) {
			lruValue = tlb[i].useTime;
			victim = i;
		}
	}
	return victim;																				//return victim
}

uint32_t TLBReplacementAlgorithm::FIFOreplace() {
	uint32_t victim = dequeue();																//find victim and remove from front of queue
	enqueue(victim);																			//add that entry back to the end of the queue since it is now the last entry added
	return victim;																				//return victim
}

void TLBReplacementAlgorithm::enqueue(uint32_t value) {
	tlbQueue.push(value);
}

uint32_t TLBReplacementAlgorithm::dequeue() {
	if (tlbQueue.empty()) {
		cout << "Error, we are trying to pop an empty queue!";
		exit(0);
	}
	uint32_t victim = tlbQueue.front();															//save tlb index at the front of the queue, this will be our victim
	tlbQueue.pop();																			//pop the fifo queue
	return victim;																			//return that index
}
