#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "BackingStore.h"
#include "Address.h"
#include "RAM.h"
#include "PageTable.h"
#include "Word.h"

using namespace std;

#ifndef MMU_H
#define MMU_H

class MMU { 
private:
	Address currentAddress; // The address we are currently working with
	
	BackingStore backingStore;

	uint32_t page_access_count_;
	uint32_t page_in_faults_;
	uint32_t tlb_access_count_;
	uint32_t tlb_faults_;
	
public: 
	//void getPhysicalA(string file) { ; }
	void processAddress(string);
	void pageIn();
	Address getAddress();
	uint32_t word;
	//call function in page table to convert 
};


#endif
