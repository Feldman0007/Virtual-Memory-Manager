#include "TLB.h"

int TLBReplacementAlgorithm::LRUreplace(TLBEntry *tlb) {								    //LRU replacement algorithm for TLB
	int lruValue = 0;																		// least recently used time, used in comparisons to find LRU time
	int victim = 0;																			// used to save the index of that with the LRU time
	for (int i = 0; i < TLB_SIZE; i++) {													//find victim
		if (tlb[i].useTime > lruValue) {
			lruValue = tlb[i].useTime;
			victim = i;
		}
	}
	return victim;																			//return victim
}

//int TLBReplacementAlgorithm::FIFOreplace() {
//	int victim = dequeue();																	//find victim and remove from front of queue
//	enqueue(victim);																		//add that entry back to the end of the queue since it is now the last entry in
//	return victim;																			//return victim
//}
//
//void TLBReplacementAlgorithm::enqueue(int value) {
//	tlbQueue.push(value);
//}
//
//int TLBReplacementAlgorithm::dequeue() {
//	int victim = tlbQueue.front();															//save tlb index at the front of the queue, this will be our victim
//	tlbQueue.pop();																			//pop the fifo queue
//	return victim;																			//return that index
//
//}
