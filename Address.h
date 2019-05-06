#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <sstream>
#include <iostream>
using namespace std;


/* 
---------------------------------------------------------------------------------- Address Class -----------------------------------------------------------------------------------------------
Purpose:
	The address class is responsible for housing address information 
Role:
	In the program, we create an instance of addresses to store the current address involved in the page request. 
	It will be passed to components of the VMM system that need access to address information
Responsibilities:
	The Address class in this case stores logical address information, such as Page Number (p) and Page Offset (d) that will be used in the construction of a physical address in the program.
	The Address can be used to store and retrieve address information.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

struct Word {
	uint32_t value;
};


class Address {
private:
	int pageNumber;
	int pageOffset;	
	int logicalAddress;

public:
	void setLogicalAddress(unsigned int);
	void setPage(unsigned int);
	void setDisplacement(unsigned int);	
	
	int getAddress();
	int getPage();
	int getDispacement();	
};

#endif
/*
Word Address::page() const

{
	constexpr Word bitMask = { Hardware::PAGES - 1 };											// some middle M bits of the word is the page index.

	return { (value_ >> Hardware::DISPACEMENT_EXTENT) & bitMask.value_ };						// move into position and mask off the top bits
}

void Address::page(const Word & pageNumber)

{
	constexpr Word bitMask = { (Hardware::PAGES - 1) << Hardware::DISPACEMENT_EXTENT };


	value_ &= ~bitMask.value_;																	// zero out the target page bits in value

	value_ |= bitMask.value_ & (pageNumber.value_ << Hardware::DISPACEMENT_EXTENT);				// move the target bits from offset into value_

}
*/