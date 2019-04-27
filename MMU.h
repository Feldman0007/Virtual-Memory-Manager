#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "BackingStore.h"
#include "Address.h"
#include "RAM.h"
#include "PageTable.h"
#include "Word.h"
#include "TLB.h"
using namespace std;

#ifndef MMU_H
#define MMU_H

class MMU { 
private:
	Address currentAddress; // The address we are currently working with
	TLB tlb;

	int page_access_count;
	int page_in_faults;
	int tlb_access_count;
	int tlb_faults;
	
public: 
	MMU();
	void processAddress(int);
	Address getAddress();
	
	bool checkTLB(int);
	int retrieveFrame(int);
	void updateTLB(int, int);

	void update_page_access_count();
	void update_page_in_faults();
	void update_tlb_access_count();
	void update_tlb_faults();

	void calculateTLBRate();
	void calculatePageFaultRate();
	//call function in page table to convert 
};


#endif
