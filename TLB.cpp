#include "TLB.h"


bool TLB::hit(int pageNum) {
	for (int i = 0; i < TLB_SIZE; i++) {
		if (translationLookAsideBuffer[i].getPage() == pageNum) {		//If an entry exists for the given page number
			return true; // we have a tlb hit, so return true
		}
	}
	return false; // tlb miss
}

void TLB::update(int index, int frameNum, int pageNum) {
	if (hit(pageNum)) {
		for (int i = 0; i < TLB_SIZE; i++) {
			if (pageNum = translationLookAsideBuffer[i].getPage()) {
				//translationLookAsideBuffer.updateTime
				return;
			}
		}
	}
	else {
		translationLookAsideBuffer[index].updateTLBEntry(frameNum, pageNum);
		//update priority/time for each entry with a for loop
		//update minTime
	}
}
int TLB::findAvailableSpot(){
	if (isFull) {
		//return (call replacement alogirthm to clear the oldest spot, then return that index)
	}
	else {
		for (int i = 0; i < TLB_SIZE; i++){
			if (translationLookAsideBuffer[i].isAvailable == true) {
				translationLookAsideBuffer[i].isAvailable = false;			// we will populate it, no longer available
				return i;
			}
		}
	}
}
int TLB::tlbGetFrame(int pageNum){
	return translationLookAsideBuffer[pageNum].getFrame();
}
