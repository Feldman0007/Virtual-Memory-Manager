#pragma once
#ifndef VMM_H
#define VMM_H
#include "Address.h"
#include "MMU.h"
#include "PageTable.h"
#include "RAM.h"
#include "TLB.h"
#include "Address.h"

//#include "ReplacmentAlgorithm.h"
//Virtual memory manager is our over arching class that includes all working peices of a virtual memory manager

class VMM {
private:
	MMU mmu;
	PageTable pgTable;
	RAM ram;
	TLB tlb;
	Word data; // The byte of memory retreived from physical memory
	bool freeFramesList[256] = {true};
	
	//ReplacementAlgorithm replacementAlgorithm;
	//BackingStore backingStore;

	

public:
	void pageFaultRoutine();
	void processInput(string);
	void print();
	int checkAvailable(); // maybe return a struct with status
	void updateAvailability(int);

	//int getFrameNumber(int);
}; 

#endif

