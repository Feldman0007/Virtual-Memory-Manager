#include "MMU.h"

#define ADDRESS_MASK 0xFFFF
#define OFFSET_MASK 0xFF


//void getPhysicalA(string file) { ; }
void MMU::processAddress(string strAddr) {
	
	stringstream convertToInt;
	convertToInt << strAddr;
	uint32_t intAddress;
	convertToInt >> intAddress;

	int intOffset;
	int intPageNum;

	intPageNum = ((intAddress & ADDRESS_MASK) >> 8); //mask to get pagenumber 
	intOffset = intAddress & OFFSET_MASK; 	//mask to get the offset  

	// int page number = mask bits
	currentAddress.setDisplacement(intOffset);
	currentAddress.setPage(intPageNum);

}

void MMU::pageIn() {
	word = backingStore.read(currentAddress.getPage(), currentAddress.getDispacement()); //Pull data from backingStore 
}


Address MMU::getAddress(){
	return currentAddress;
}


