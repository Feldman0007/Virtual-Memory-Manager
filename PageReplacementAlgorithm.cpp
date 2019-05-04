#include "PageReplacementAlgorithm.h"
#include "RAM.h"

int PageReplacementAlgorithm::LRUreplace(RAM & r) {											//same approach as TLB replacement. returns number of the frame that was least recently used
	int lruValue = 0;
	int victim = 0;
	for (int i = 0; i < RAM_SIZE; i++) {
		if (r.getUseTime(i) > lruValue) {
			lruValue = r.getUseTime(i);
			victim = i;
		}
	}
	return victim;
}

int PageReplacementAlgorithm::FIFOreplace() { 											    //same approach as TLB replacement.
	int victim = dequeue();
	enqueue(victim);
	return victim;
}
void PageReplacementAlgorithm::enqueue(int value) {
	pageQueue.push(value);
}
int PageReplacementAlgorithm::dequeue() {
	int victim = pageQueue.front();
	pageQueue.pop();
	return victim;
}