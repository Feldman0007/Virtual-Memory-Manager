#include "Address.h"

void Address::setDisplacement(int d) //store offset
{ 
	pageOffset = d;
}

void Address::setPage(int p) //store pageNUm
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

void Address::setLogicalAddress(int intAddr){
	logicalAddress = intAddr;
}