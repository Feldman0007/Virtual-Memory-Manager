#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "BackingStore.h"
#include "Address.h"
#include "RAM.h"
#include "ProcessControlBlock.h"
#include "TLB.h"

using namespace std;

#ifndef MMU_H
#define MMU_H

/*
-------------------------------------------------- Memory Management Unit -------------------------------------------------------------
Role:
	We will be using Memory Managememt Unit to oversees and regulates the process's use of Ram
	It also translate 
	validation and trap 

Responbility 
	It will receive logical addresses (page requests) from a process, and it will also be incharge of reading and access through Ram

---------------------------------------------------------------------------------------------------------------------------------------
*/

class MMU { 
private:
	Address currentAddress; // Instance of the address we are currently working with
	TLB tlb;                // Instance of the tlb. The tlb is an object of the MMU

	int page_access_count;
	int page_in_faults;
	int tlb_access_count;
	int tlb_faults;
	
public: 
	MMU();
	void processAddress(int);
	Address getAddress();
	
	bool checkTLB(int);
	int tlb_get_frame(int);
	void updateTLB(int, int);
	void read_and_print(RAM &, int, int);
	void storeInRam(RAM &, int, char *);
	
	void update_page_access_count();
	void update_page_in_faults();
	void update_tlb_access_count();
	void update_tlb_faults();
	void calculateTLBRate();
	void calculatePageFaultRate();
};


#endif
