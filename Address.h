#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <sstream>
#include <iostream>
using namespace std;


/* 
-------------------------------------------------- Address Class ------------------------------------------

Role:
	The address class is responsible for housing address information 

Responsiblity 
	We use Address class to store information regarding to Page Number, Page Offset, and logicalAddress

-----------------------------------------------------------------------------------------------------------
*/

class Address {
private:
	int pageNumber;
	int pageOffset;	
	int logicalAddress;

public:
	void setLogicalAddress(int);
	int getAddress();
	void setPage(int);
	void setDisplacement(int);
	int getPage();
	int getDispacement();	

};

#endif
