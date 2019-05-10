/*
==============================================================================================================================================
Address Class 
==============================================================================================================================================

The address class houses address information and provides methods for address information retrieval and storage in the program.
In the program, we create an instance of Address in the MMU to store information on the address involved with the current page request. 
Addresses are stored as Words since we are only working with 16 bit addresses in the program.
It will be passed to components of the VMM system requiring address information.

Purpose:
	Addresses are used in a Memory Management systems to access/store data from main memory and secondary storage.
Role:
	Represents a location in memory.
	Provides an entry point for access and storage of information.

Responsibilities:
	Addresses store information such as, but not limited to, page number (p) and page offset (d).

==============================================================================================================================================
*/
#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <sstream>
#include <iostream>
using namespace std;

struct Word {
	uint32_t value; //Note that we are not using the entire 32 bit integer, we are masking the upper 16 bits and only using the word (2 byte) portion.
	void setValue(uint32_t address) {
		value = address;
	}
};

class Address {
private:
//Address information
	Word pageNumber;
	Word pageOffset;	
	Word logicalAddress;

public:
//Address storage and retrieval
	void setLogicalAddress(uint32_t intAddr);
	void setPage(uint32_t pageN);
	void setDisplacement(uint32_t displacement);
	
	uint32_t getAddress();
	uint32_t getPage();
	uint32_t getDispacement();
};

#endif