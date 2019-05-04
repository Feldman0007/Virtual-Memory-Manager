#pragma once
#ifndef RAM_H
#define RAM_H
#define FRAME_SIZE 256
#define RAM_SIZE 128

#include <iostream>
#include <iomanip>

using namespace std;

struct Status {
	bool accessed;
	bool dirty;
	int useTime; //used in LRU algorithm

	Status() {
		accessed = false;
		dirty = false;
		useTime = 0;
	}
};

class RAM {
private:
	char physicalMemory[RAM_SIZE][FRAME_SIZE];														 //volatile memory
	Status frameStatuses[RAM_SIZE];																	 //parallel array storing status information for each frame.
public:
	void store(int, char *);																		 //store a frame of data in ram; from the backing store
	int access(int, int);																			 //access RAM using physical address and return byte of data
	int getUseTime(int);
};

#endif