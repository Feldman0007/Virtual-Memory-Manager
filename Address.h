#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include "PageTable.h"


class Address {
private:
	int pageNumber;
	int pageOffset;
	//int frameNumber;

public:

	//int store();
	
	void setOffset(int); 
	void setPageNum(int);
	//void setFrameNum(int);
	
	int getPageNum();
	int getOffset();
	//int getFrameNum();
	//void storeToTables(int );
};

#endif
