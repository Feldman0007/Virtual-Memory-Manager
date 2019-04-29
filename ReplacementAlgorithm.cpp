#include "ReplacementAlgorithm.h"

void TLBReplacementAlgorithm::LRUreplace(int frameNum, int pageNum, TLBEntry *tlb){ //index of the least used 
	int lruIndex = 0;
	int lruValue = 0;
	for (int i = 0; i < TLB_SIZE; i++) {
		if (tlb[i].useTime > lruValue) {
			lruValue = tlb[i].useTime;
			lruIndex = i;
		}
	}
	tlb[lruIndex].updateTLBEntry(frameNum, pageNum);
}

void TLBReplacementAlgorithm::FIFOreplace(int frameNum, int pageNum, TLBEntry *tlb) {
	int index = dequeue();
	tlb[index].updateTLBEntry(frameNum, pageNum);
	enqueue(index);
}

void TLBReplacementAlgorithm::enqueue(int value) {
	fifoTLB.push(value);
}

int TLBReplacementAlgorithm::dequeue() {
	int index = fifoTLB.front();
	fifoTLB.pop();
	return index;
}