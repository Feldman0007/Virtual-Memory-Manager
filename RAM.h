#pragma once
#ifndef RAM_H
#define RAM_H
#define FRAME_SIZE 256
#define RAM_SIZE 128

#include <iostream>
#include <iomanip>

using namespace std;

/*
--------------------------------------------------- RAM  ----------------------------------------------------
Purpose:
	RAM (Random Access Memory) is the hardware in a computing device where the operating system processes, 
	and data in current use are kept so that they can be quickly reached by the device's processor

Role:
	Store byte of data which can use to get the physical address.

Responsiblity
	Receive and store Physical address from backing store and MMU
	Even in those cases where the entire program is needed, it may not all be needed at the same time.
	Ram allows overwrite so when it is full, the value will be overwrite at the right frame.
-----------------------------------------------------------------------------------------------
*/

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
	int accessRAM(int, int);																		 //access RAM using physical address and return byte of data
	int getUseTime(int);
};

#endif