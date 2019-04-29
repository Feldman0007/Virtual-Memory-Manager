#pragma once
#ifndef VMM_H
#define VMM_H
#include "Address.h"
#include "MMU.h"
#include "PageTable.h"
#include "RAM.h"
#include "BackingStore.h"
#include <iomanip>



//Virtual memory manager is our over arching class that includes all working peices of a virtual memory manager

class VMM {
private:
	MMU mmu;
	PageTable pgTable;
	RAM ram;
	BackingStore backingStore; 
	bool freeFramesList[256];
	int numLogic = 0;

public:
	VMM();
	char* pageIn();
	void pageFaultRoutine();
	void processInput(int);
	int findAvailableFrame();
	void print();
}; 

#endif

