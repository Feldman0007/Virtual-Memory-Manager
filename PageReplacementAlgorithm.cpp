#include "PageReplacementAlgorithm.h"
#include "RAM.h"

uint32_t PageReplacementAlgorithm::LRUreplace(RAM & r) {											//same approach as TLB replacement, but recieves different parameters and selects the frame that was least recently used
	uint32_t lruValue = 0;
	uint32_t victim = 0;
	for (uint32_t i = 0; i < RAM_SIZE; i++) {
		if (r.getUseTime(i) > lruValue) {
			lruValue = r.getUseTime(i);
			victim = i;
		}
	}
	return victim;
}

uint32_t PageReplacementAlgorithm::FIFOreplace() { 												   //same approach as TLB replacement, but selects frame that was brought into main memory first.
	uint32_t victim = dequeue();
	enqueue(victim);
	return victim;
}
void PageReplacementAlgorithm::enqueue(uint32_t value) {
	replacementQueue.push(value);
}
uint32_t PageReplacementAlgorithm::dequeue() {
	if (replacementQueue.empty()) {
		cout << "Error, we are trying to pop an empty queue!";
		exit(0);
	}
	uint32_t victim = replacementQueue.front();
	replacementQueue.pop();
	return victim;
}