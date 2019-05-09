#pragma once
#ifndef PROCESSCONTROLBLOCK_H
#define PROCESSCONTROLBLOCK_H

#include <iostream>
#include "Configuration.hpp"
#include "Address.h"

using namespace std;

/*
----------------------------------------------------- Process Control Block -----------------------------------------------------------------
Purpose
	Manage page table activities.


Role:
	As a part of whole process, page table is a location where TLB looking for frame number.
	Process Control Block manage information in the page table to make sure that TLB can get the frame number in the fastest way.
	Page table Stores and manages frame number. 
	When a frame number is requested by TLB from the 2nd time, TLB can get it from the page table instead of getting it from backing store.
	This help increase process' performance 

	
Responsiblity
	Manage page table availability 
	Store recent using value for later access
	Lookup and pass the right value to TLB when needed
	
	

-----------------------------------------------------------------------------------------------------------------------------------------------
*/

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
	Many other members that aren't in the scope of the project such as:
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
	bool pageTableLookup(uint32_t pageNum);
	uint32_t getFrame(uint32_t pageNum);
	PageTableEntry getEntry(uint32_t);
	void updatePageTable(uint32_t pageNum, uint32_t frameNum);
	void invalidate_PT_Entries(uint32_t invalidframeNum);
};
#endif