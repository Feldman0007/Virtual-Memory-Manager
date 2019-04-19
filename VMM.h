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
//#include "BackingStore.h"

class VMM {
private:
	Address currentAddress;
	MMU mmu;
	PageTable pageTable;
	RAM ram;
	TLB tlb;
	//ReplacementAlgorithm replacementAlgorithm;
	//BackingStore backingStore;


public:
	void processInput(string);
	int getFrameNumber(int);
	void setAddress(Address);
	void print(); 
	//create overarching function later?
}; 

#endif