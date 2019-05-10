/*
=================================================================================================================================================================
Process Control Block 
=================================================================================================================================================================
In our program, the proccess control block is associated with the process that is currently making page requests. Each PCB contains a page table, which we include as a private member. We access the page table of this PCB 
in order to perform address translation and service page requests. We implemented the page table as an array of Page Table Entry structures. Each Page Table Entry contains a frame number and a valid bit. 

Purpose
	Process Control Block (PCB) is a data structure associated with every process that provides complete information about that process.
	In this project, PCB will contain PageTable.
	PageTable is a data structure used by the virtual memory system to store the mapping between logical addresses and physical addresses

Role:
	The role of Page Table is to maps the page number to its actual location in Memory. 
	Page Table played a major part where Memory Management unit convert the page number of the logical address to the frame number of the physcical address.
	Memory Management Unit needs a special kind of mapping which is done by page table. 
	Page Table stores all the Frame numbers corresponding to the page numbers of the page table. 


Responsiblity
	Page Table will contain a PageTable Entries.
	Page Table Entries will store the frame number and the status of the bit. 
	Page Table will be responsible for the following:
		Checking the Page Table Entries Validation
		Updating the Page Table Entries
		Retrieve the frame number based on the page number


=================================================================================================================================================================
*/
#pragma once
#ifndef PROCESSCONTROLBLOCK_H
#define PROCESSCONTROLBLOCK_H

#include <iostream>
#include "Configuration.hpp"
#include "Address.h"

using namespace std;


struct PageTableEntry {
	uint32_t frameNumber = 0;
	bool valid_invalid_bit = false;
	
	void updatePageEntry(uint32_t frame) {
		frameNumber = frame;
		valid_invalid_bit = true;
	}
	uint32_t getFrameNumber() {
		return frameNumber;
	}
	bool getValidBit() {
		return valid_invalid_bit;
	}
};

class ProcessControlBlock {
private:
	PageTableEntry pageTable[PAGE_TABLE_SIZE];
/* 
Many other members that PCBs contain, but aren't in the scope of the project such as..
	ProcessState state;
	ProgramCounter prgmCounter;
	CPUSchedulingInfo scheduleInfo;
	IPCInfo ipc;
	Register associatedRegisters;
	int process_privelage;
	int processNumber;
	memory limits, list of open files, ect....
*/
public:
//Page Table Maintenance
	void updatePageTable(uint32_t pageNum, uint32_t frameNum);
	void invalidate_PT_Entries(uint32_t invalidframeNum);

//Helper Functions
	bool pageTableLookup(uint32_t pageNum);  // checks valid bit
	uint32_t getFrame(uint32_t pageNum);
	PageTableEntry getEntry(uint32_t);

};
#endif