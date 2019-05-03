#include "RAM.h"

void RAM::store(int frameNum, char * frameOfData) {
	for (int i = 0; i < FRAME_SIZE; i++) {
		physicalMemory[frameNum][i] = frameOfData[i];
	}
	//for (int i = 0; i < FRAME_SIZE; i++) {
	//	frameStatuses[i].useTime++;
	//}
	frameStatuses[frameNum].useTime = 0; //the frame we just stored data in is now most recently used 
	frameStatuses[frameNum].dirty = false;
	frameStatuses[frameNum].accessed = true;
}
int RAM::getUseTime(int frameNumber) {
	return frameStatuses[frameNumber].useTime;
}

int RAM::access(int frameNumber, int frameOffset) {
	for (int i = 0; i < FRAME_SIZE; i++) { //increment the use time of all other frame use times
		frameStatuses[i].useTime++;
	}
	frameStatuses[frameNumber].useTime = 0; //the frame we just accessed is now most recently used
	frameStatuses[frameNumber].accessed = true;

	int byteOfData = physicalMemory[frameNumber][frameOffset]; //grab byte of data from RAM using physical address (f + d)
	return byteOfData;
}