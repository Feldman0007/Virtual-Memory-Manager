/*
==============================================================================================================================================================================
RAM  
==============================================================================================================================================================================

In our program, the RAM class mimics Random Access Memory in a real memory management system which houses main memory in the system. RAM stores data that is read in from the backing store after a page fault, and it
is indexed into using a physical address (frame number + displacement in that frame) for efficient data retrieval. The access and dirty associated with each frame keep of which ones are being accessed which one's have been modified.

Purpose:
	Data is loaded into RAM so that it can be accessed by the system significantly faster than it could through secondary storage.
	RAM houses current data.

Role:
	RAM is volatile memory, so it doesn't store data permanently. Data in main memory must be written to secondary storage if the changes are to persist (using the dirty bit as an indicator).
	Data is stored byte by byte in sections known as frames (which are equivalent to the size of a page), which the system accesses using a physical address.

Responsiblity:
	Stores data from the backing store that can be read and accessed (and written to).
	RAM has limited space. When it is filled up, it must replace a frame of data based on its replacement policy, and overlay the chosen frame in RAM with new data from the hard disk.
	If dirty bit marked on a victim frame, the data must be writted to backing store before it is removed from RAM.

=============================================================================================================================================================================
*/
#pragma once
#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <iomanip>
#include "Configuration.hpp"

using namespace std;

struct Status {
	bool accessed = false;
	bool dirty = false;

//clock; used in LRU algorithm
	uint32_t useTime = 0;
};

class RAM {
private:
//volatile memory
	char physicalMemory[RAM_SIZE][FRAME_SIZE];

//parallel array storing status information for each frame. Used by LRU replacement algorithm
	Status frameStatuses[RAM_SIZE];																	 
public:
//access, store, read in RAM
	void store(uint32_t frameNum, char* frameOfData);			
	char accessRAM(uint32_t frameNumber, uint32_t frameOffset);										 
	
//getter function used by LRU algorithm
	uint32_t getUseTime(uint32_t frameNumber);
};

#endif