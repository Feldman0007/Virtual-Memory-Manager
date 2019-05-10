/*
=============================================================================================================================================================================
Virtual Memory Manager
=============================================================================================================================================================================
	Virtual Memory Manager is our over arching class that includes the primary components of a virtual memory management system including, but not limited to, the MMU, backing store, RAM,
	free frames list, and PCBs (containing the Page Tables associated with the processes that are requesting pages of data).
	The primary function of VMM, servicePageRequest, simulates the process of servicing a process's request for a page of data. (See VMM.cpp for additional comments and implementation details)

Purpose:
	Virtual Memory Management systems enable virtual memory, which provides running programs with access to large amounts of data from secondary storage while
	minimizing the amount of memory consumed in physical memory.
	Memory appears to exist as main storage although most of it is supported by data held in secondary storage.

Role:
	Occupy physical memory with things that are likely to be used
	Load things in as we need them (demand paging)
	Satisfy page requests

Responsibilities:
	Automatically transfer and maintain data between main memory and secondary storage.
==============================================================================================================================================================================
*/
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


class VMM {
private:
//Key Components of a VMM system
	MMU mmu;
	ProcessControlBlock pcb;
	BackingStore backingStore; 
	RAM ram;
	bool freeFramesList[RAM_SIZE];
	PageReplacementAlgorithm algorithm;
public:
//Primary functions of the VMM
	void servicePageRequest(uint32_t intAddr);	
	void pageFaultRoutine(uint32_t faultingPage);	
	char* pageIn(uint32_t faultingPage);
	uint32_t findFreeFrame();

//Housekeeping functions (included in VMM because we need to execute these outside of the while loop in main
	//void mmu_validateAddressSpace();
	void mmu_clearTLB();

//Helpers
	void printResults();
	VMM();
}; 

#endif

