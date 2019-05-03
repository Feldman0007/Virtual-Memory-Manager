#pragma once
#ifndef VMM_H
#define VMM_H
#include "Address.h"
#include "MMU.h"
#include "PageTable.h"
#include "RAM.h"
#include "BackingStore.h"
#include "PageReplacementAlgorithm.h"
#include <iomanip>



//Virtual memory manager is our over arching class that includes all working peices of a virtual memory manager

class VMM {
private:
	MMU mmu;
	PageTable pgTable;
	BackingStore backingStore; 
	RAM ram;
	bool freeFramesList[256];
	PageReplacementAlgorithm algorithm;
public:
	VMM();
	char* pageIn();
	void pageFaultRoutine(int);
	void processInput(int);
	int findFreeFrame();
	void print();
}; 

#endif

