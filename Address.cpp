#include "Address.h"



void Address::setDisplacement(int d) //store offset
{ 
	pageOffset = d;
}


void Address::setPage(int p) //store pageNUm
{
	pageNumber = p;
}

void Address::setFrame(int f) {
	frameNumber = f;
}

int Address::getPage()//return pageNumber
{ 
	return pageNumber; 
} 

int Address::getDispacement()//return offset
{ 
	return pageOffset; 
}

int Address::getFrame()
{
	return 0;
}

uint32_t Address::getAddress() {
	return logicalAddress;
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
