#pragma once
#ifndef VMM_H
#define VMM_H
#include "Address.h"
#include "MMU.h"
#include "ProcessControlBlock.h"
#include "RAM.h"
#include "BackingStore.h"
#include "PageReplacementAlgorithm.h"
#include <iomanip>

/*
------------------------------------------------------------------------------ Virtual Memory Manager --------------------------------------------------------------------------------
Virtual Memory Manager is our over arching class that includes most of the working pieces of a virtual memory management system.
VMM includes : 
				MMU (which contains the TLB)
				Process Control Block (which contains the Page Table)
				Backing Store
				RAM
				Free Frames List
Purpose:
	Virtual Memory allows a system to run programs in a way that minimizes the ammount of physical memory consumed. Memory that appears to exist as main storage although 
	most of it is supported by data held in secondary storage.

Role:
	Occupy physical memory with things that are likely to be used
	Load things in as we need them (demand paging)

Responsibilities:
	Automatically transfer data between main memory and secondary storage. This is accomplished through the translation of logical address to physical address.
	A logical address is processed by:
			1) Extracting page number p, so we may use it to index into the page table/TLB and retrieve a frame number f
			2) Extracting displacement d
			3) Retreive frame number f from the TLB, or the page table
				3.1) frame number associated with page Page Fault - page in data and potentially involving a pageFault and the use of a page replacement algorithm to find an available frame)
			4) Construct a physical address and use that address to locate the and output the value of the byte stored in RAM

	
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/




class VMM {
private:
	MMU mmu;
	ProcessControlBlock pcb;
	BackingStore backingStore; 
	RAM ram;
	bool freeFramesList[RAM_SIZE];
	PageReplacementAlgorithm algorithm;
public:
	VMM();
	char* pageIn();
	void pageFaultRoutine(int);
	void processInput(int);
	int findFreeFrame();
	void printResults();
}; 

#endif

