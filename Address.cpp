#include "Address.h"


//save offset
void Address::setOffset(int d)
{ 
	pageOffset = d;
}

//save pageNUm
void Address::setPageNum(int p)
{
	pageNumber = p;
}

//return pageNumber
int Address::getPageNum()
{ 
	return pageNumber; 
} 

//return offset
int Address::getOffset()
{ 
	return pageOffset; 
}


/*
void setFrameNum(int a)
{
	frameNumber = a;
}
int getFrameNum()
{
	return frameNumber;
}


void storeToTables(int){

}

*/
