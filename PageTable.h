#pragma once
#define PAGE_TABLE_SIZE 256
#define PAGE_SIZE 256
#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <iostream>

using namespace std;

#include "Address.h"
#include "ReplacementAlgorithm.h"
/*
class LRUPageReplacementAlgorithm : public ReplacementAlgorithm {

};
*/
struct PageTableEntry {
	int frameNumber;
	bool valid_invalid_bit ;// false = page not yet loaded into physical memory
	
	PageTableEntry() {
		frameNumber = -1; // initially -1, null pointer, not yet mapped to physical address 
		valid_invalid_bit = false; // false = invalid, page not loaded into memory
	}
	void updatePageEntry(int frameNum, bool validBit) {
		frameNumber = frameNum;
		valid_invalid_bit = validBit;
	}
	int getFrameNumber() {
		return frameNumber;
	}
	bool getValidBit() {
		return valid_invalid_bit;
	}
};

class PageTable {
private:
	PageTableEntry pageTable[PAGE_TABLE_SIZE]; 
	//PageReplacementAlgorithm 

public:
	bool pageTableLookup(int);
	PageTableEntry getEntry(int);
	void updatePageTable(Address);
};
#endif
