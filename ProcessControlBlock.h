#pragma once
#define PAGE_TABLE_SIZE 256
#define PAGE_SIZE 256
#ifndef PROCESSCONTROLBLOCK_H
#define PROCESSCONTROLBLOCK_H

#include <iostream>
#include "Address.h"

using namespace std;

/*
------------------------------------- Process Control Block -----------------------------------
Role:



Responsiblity


-----------------------------------------------------------------------------------------------
*/

struct PageTableEntry {
	int frameNumber;
	bool valid_invalid_bit;
	
	PageTableEntry() {
		valid_invalid_bit = false; // initially false (invalid) = we have not yet loaded any pages into physical memory
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

class ProcessControlBlock {
private:
	PageTableEntry pageTable[PAGE_TABLE_SIZE];
	/*Many other members that aren't in the scope of the project such as:
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
	bool pageTableLookup(int);
	int getFrame(int);
	PageTableEntry getEntry(int);
	void updatePageTable(int, int);
	void invalidate_PT_Entries(int);
};
#endif
