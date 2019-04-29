#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "Address.h"
#include "TLB.h"
using namespace std;

#ifndef MMU_H
#define MMU_H

class MMU { 
private:
	TLB tlb;

	int page_access_count;
	int page_in_faults;
	int tlb_access_count;
	int tlb_faults;
	
public: 
	MMU();
	void processAddress(int, Address&);
	
	bool checkTLB(int);
	int getFrameTLB(int);
	void updateTLB(int, int);

	void update_page_access_count();
	void update_page_in_faults();
	void update_tlb_access_count();
	void update_tlb_faults();

	void calculateTLBRate();
	void calculatePageFaultRate();
};


#endif
