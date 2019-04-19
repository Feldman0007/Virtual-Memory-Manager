#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#define ADDRESS_MASK 0xFFFF
#define OFFSET_MASK 0xFFFF

class Address {
private:
	int pageNumber;
	int pageOffset;
	int frameNumber;

public:
	int store();
	int getFrame(int);
	int getPageNum(); //return pageNumber
	int getoffset();
    int setOffset(int newOffset);
    
};

#endif