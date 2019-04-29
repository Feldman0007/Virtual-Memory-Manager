#include "RAM.h"

void RAM::store(int frameNum, char * frameOfData){
	for (int i = 0; i < FRAME_SIZE; i++){
		physicalMemory[frameNum][i] = frameOfData[i];
	}
}

void RAM::print(int frameNumber, int frameOffset) {
	int byteOfData = physicalMemory[frameNumber][frameOffset]; //grab byte of data from RAM using physical address (f + d)

	cout << "Physical Address: " << frameNumber << frameOffset << right << setw(3) << " | ";
	cout << "Byte of Data: " << setw(8) << std::hex << byteOfData << endl;
}