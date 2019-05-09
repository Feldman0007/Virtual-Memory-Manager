#include "RAM.h"

void RAM::store(uint32_t frameNum, char * frameOfData) {
	for (uint32_t i = 0; i < FRAME_SIZE; i++) {
		physicalMemory[frameNum][i] = frameOfData[i];
	}
	frameStatuses[frameNum].useTime = 0; //the frame we just stored data in is now most recently used 
	frameStatuses[frameNum].dirty = false;
	frameStatuses[frameNum].accessed = true;
}
uint32_t RAM::getUseTime(uint32_t frameNumber) {
	return frameStatuses[frameNumber].useTime;
}

char RAM::accessRAM(uint32_t frameNumber, uint32_t frameOffset) {
	for (uint32_t i = 0; i < RAM_SIZE; i++) { //increment the use time of all other frame use times
		frameStatuses[i].useTime++;
	}
	frameStatuses[frameNumber].useTime = 0; //the frame we just accessed is now most recently used
	frameStatuses[frameNumber].accessed = true;

	return physicalMemory[frameNumber][frameOffset]; //grab byte of data from RAM using physical address (f + d)
}