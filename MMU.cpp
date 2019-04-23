#include "MMU.h"
#define ADDRESS_MASK 0xFFFF
#define OFFSET_MASK 0xFF


//void getPhysicalA(string file) { ; }
Address MMU::processAddress(string strAddr) {
	
	Address tempAddress;
	stringstream convertToInt;// convert string input to int so we can work with the logical address
	int intAddress;
	convertToInt << strAddr;
	convertToInt >> intAddress;

	int intOffset = intAddress; //need temporary copies for masking and seperating page number and offset 
	int intPageNum = intAddress;

	intPageNum = ((intPageNum & ADDRESS_MASK) >> 8);//mask bits to isolate pagenumber   
	intOffset = intOffset & OFFSET_MASK; //mask bits to isolate offset

	tempAddress.setOffset(intOffset);
	tempAddress.setPageNum(intPageNum);

	return tempAddress;
}
	
