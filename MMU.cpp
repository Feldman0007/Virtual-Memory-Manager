#include "MMU.h"
#define ADDRESS_MASK 0xFFFF
#define OFFSET_MASK 0xFF


//void getPhysicalA(string file) { ; }
Address MMU::processAddress(string strAddr) {
	// convert input string to int and get its address
	stringstream convertToInt;
	convertToInt << strAddr;
	int intAddress;
	convertToInt >> intAddress;

	int intOffset = intAddress; //need to store original address twice so we can mask and seperate offset and page number
	int intPageNum = intAddress;

	//mask to get the offset  
	//mask to get pagenumber 
	intPageNum = ((intPageNum & ADDRESS_MASK) >> 8);
	intOffset = intOffset & OFFSET_MASK;

	// int page number = mask bits
	tempAddress.setOffset(intOffset);
	tempAddress.setPageNum(intPageNum);

	return tempAddress;
}
	
