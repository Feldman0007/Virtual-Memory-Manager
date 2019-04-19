#pragma once
#include <iostream>
#include <string>
#include "PageTable.h"
#include "Address.h"
#include <sstream>
using namespace std;

#ifndef MMU_H
#define MMU_H

class MMU { 
private:
	Address currentAddress;
	int offset;
public: 
	//void getPhysicalA(string file) { ; }
	void process(string addr) { 
        // convert input string to int and get its address
		stringstream convertToInt;
		convertToInt << addr;
		int intAddress;
		convertToInt << intAddress;
		//get the offset  
		//pagenumber 
		currentAddress.setOffset(intAddress);
	}
	currentAddress.getOFfset();
	currentAddress.getPage();

	//call function in page table to convert 
	

    void setoOffset(int newOffset) {
		//last 4 digit
		newOffset = newOffset & 0x11110000;
	}
	void getOffset (newOffset) {
		return offset;
	}
};

#endif