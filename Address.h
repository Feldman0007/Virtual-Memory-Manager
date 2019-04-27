#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <sstream>
#include <iostream>
using namespace std;

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
