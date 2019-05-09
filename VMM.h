#pragma once
#ifndef VMM_H
#define VMM_H

#include <iomanip>
#include "Address.h"
#include "MMU.h"
#include "ProcessControlBlock.h"
#include "RAM.h"
#include "BackingStore.h"
#include "PageReplacementAlgorithm.h"


/*
------------------------------------------------------------------------------ Virtual Memory Manager ----------------------------------------------------------------------------------------
	Virtual Memory Manager is our over arching class that includes many of the working pieces of a virtual memory management system including the MMU, backing store, RAM,
	free frames list, and PCBs (containing Page Tables associated with the processes that are requesting pages of data).
	The primary function of VMM, pageRequest, simulates the process of satisfying a request for a page of data. (See implementation and additional comments in VMM.cpp)

Purpose:
	Virtual Memory Management systems enable virtual memory, which provide running programs with access to large amounts of data from secondary storage while 
	minimizing the amount of memory that is actually loaded and maintained in physical memory. 
	Memory that appears to exist as main storage although most of it is supported by data held in secondary storage.

Role:
	Occupy physical memory with things that are likely to be used
	Load things in as we need them (demand paging)
	Satisfy page requests

Responsibilities:
	Automatically transfer and maintain data between main memory and secondary storage. 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

	char* pageIn(uint32_t faultingPage);
	void pageFaultRoutine(uint32_t faultingPage);
	void servicePageRequest(uint32_t intAddr);
	uint32_t findFreeFrame();
	void printResults();
	void mmu_clearTLB();
	//void mmu_validateAddressSpace();
}; 

#endif

