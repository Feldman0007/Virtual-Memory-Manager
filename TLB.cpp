#include "TLB.h"

TLB::TLB() {
	numTLBEntries = 0;
}

bool TLB::hit(int pageNum) {
	for (int i = 0; i < TLB_SIZE; i++) {
		if (translationLookAsideBuffer[i].getPage() == pageNum) {		
			translationLookAsideBuffer[i].useTime = 0;
			return true; 
		}
	}
	return false; 
}

void TLB::update(int index, int frameNum, int pageNum) {
	for (int i = 0; i < TLB_SIZE; i++) {
		translationLookAsideBuffer[i].useTime++;
	}
	int temp = findAvailableSpot();
	if (temp == -1) {
		algorithm.LRUreplace(frameNum, pageNum, translationLookAsideBuffer);
	}
	else{
		translationLookAsideBuffer[index].updateTLBEntry(frameNum, pageNum);
	}
}
int TLB::findAvailableSpot(){
	if (numTLBEntries == TLB_SIZE) {
		return -1;
	}
	else {
		for (int i = 0; i < TLB_SIZE; i++){
			if (translationLookAsideBuffer[i].isAvailable == true) {
				translationLookAsideBuffer[i].isAvailable = false;		
				return i;
			}
		}
	}
}
int TLB::tlbGetFrame(int pageNum){
	return translationLookAsideBuffer[pageNum].getFrame();
}
