#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <sstream>
#include <iostream>
using namespace std;


/* 
---------------------------------------------------------------------------------- Address Class -----------------------------------------------------------------------------------------------
The address class houses address information and provides methods for address information retrieval and storage in the program. 
In the program, we create an instance of Address in the MMU to store address information involved with the current page request. 
It will be passed to components of the VMM system require address information

Purpose:
	Addresses are used in a Memory Management systems to access/store data from main memory and secondary storage.  
Role:
	Represents a location in memory.
	Provides an entry point for access and storage of information.

Responsibilities:
	Addresses store address information, including page number (p) and page offset (d).
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

struct Word {
	uint32_t value;
	void setValue(uint32_t address) {
		value = address;
	}
};

class Address {
private:
	Word pageNumber;
	Word pageOffset;	
	Word logicalAddress;

public:
	void setLogicalAddress(uint32_t intAddr);
	void setPage(uint32_t pageN);
	void setDisplacement(uint32_t displacement);
	
	uint32_t getAddress();
	uint32_t getPage();
	uint32_t getDispacement();
};

#endif