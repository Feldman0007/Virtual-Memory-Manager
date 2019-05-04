#pragma once
#define PAGE_TABLE_SIZE 256
#define PAGE_SIZE 256
#ifndef PROCESSCONTROLBLOCK_H
#define PROCESSCONTROLBLOCK_H

#include <iostream>
#include "Address.h"

using namespace std;


struct PageTableEntry {
	int frameNumber;
	bool valid_invalid_bit;
	
	PageTableEntry() {
		valid_invalid_bit = false; // false = page not yet loaded into physical memory
		frameNumber = 0;
	}
	void updatePageEntry(int frame) {
		frameNumber = frame;
		valid_invalid_bit = true;
	}
	int getFrameNumber() {
		return frameNumber;
	}
	bool getValidBit() {
		return valid_invalid_bit;
	}
};

class ProcessControlBlock {
private:
	PageTableEntry pageTable[PAGE_TABLE_SIZE]; 

public:
	bool pageTableLookup(int);
	int getFrame(int);
	PageTableEntry getEntry(int);
	void updatePageTable(int, int);
	void invalidateEntries(int);
};
#endif
