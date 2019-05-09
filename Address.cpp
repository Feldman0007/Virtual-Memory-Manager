#include "Address.h"

void Address::setDisplacement(uint32_t displacement){										//store offset
	pageOffset.setValue(displacement);
}

void Address::setPage(uint32_t pageN){														//store pageNUm
	pageNumber.setValue(pageN);
}

void Address::setLogicalAddress(uint32_t intAddr){
	logicalAddress.setValue(intAddr);
}

uint32_t Address::getPage(){ 																			//return pageNumber
	return pageNumber.value; 
} 

uint32_t Address::getDispacement(){																	//return offset
	return pageOffset.value; 
}

uint32_t Address::getAddress() {
	return logicalAddress.value;
}



