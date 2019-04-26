#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <sstream>
#include <iostream>
using namespace std;

class Address {
private:
	uint32_t logicalAddress;
	int pageNumber;
	int pageOffset;
	int frameNumber;

public:
	void setPage(int);
	void setDisplacement(int);
	void setFrame(int);
	
	uint32_t getAddress();
	int getPage();
	int getDispacement();
	int getFrame();
};

#endif
