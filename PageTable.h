#pragma once
#define PAGE_TABLE_SIZE 256
#define PAGE_SIZE 256
#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <iostream>

using namespace std;

#include "Address.h"
#include "ReplacementAlgorithm.h"

struct PageTableEntry {
	int frameNumber;
	bool valid_invalid_bit;
	
	PageTableEntry() {
		valid_invalid_bit = false; // false = page not yet loaded into physical memory
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

class PageTable {
private:
	PageTableEntry pageTable[PAGE_TABLE_SIZE]; 
	ReplacementAlgorithm replacementAlgorithm;

public:
	bool pageTableLookup(int);
	int getFrame(int);
	PageTableEntry getEntry(int);
	void updatePageTable(int, int);
};
#endif
