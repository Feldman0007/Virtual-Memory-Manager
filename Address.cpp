#include "Address.h"

void Address::setDisplacement(unsigned int d) //store offset
{ 
	pageOffset = d;
}

void Address::setPage(unsigned int p) //store pageNUm
{
	pageNumber = p;
}

int Address::getPage()//return pageNumber
{ 
	return pageNumber; 
} 

int Address::getDispacement()//return offset
{ 
	return pageOffset; 
}

int Address::getAddress() {
	return logicalAddress;
}

void Address::setLogicalAddress(unsigned int intAddr){
	logicalAddress = intAddr;
}