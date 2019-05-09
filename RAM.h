#pragma once
#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <iomanip>
#include "Configuration.hpp"

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
	bool accessed = false;
	bool dirty = false;
	uint32_t useTime = 0; //used in LRU algorithm
};

class RAM {
private:
	char physicalMemory[RAM_SIZE][FRAME_SIZE];														 //volatile memory
	Status frameStatuses[RAM_SIZE];																	 //parallel array storing status information for each frame.
public:
	void store(uint32_t frameNum, char* frameOfData);												 //store a frame of data in ram; from the backing store
	char accessRAM(uint32_t frameNumber, uint32_t frameOffset);										 //access RAM using physical address and return byte of data
	uint32_t getUseTime(uint32_t frameNumber);
};

#endif