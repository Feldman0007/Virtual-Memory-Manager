#include "VMM.h"

void VMM::processInput(string strAddr)
{
	Address tempAddress = mmu.processAddress(strAddr);	
	setAddress(tempAddress);

}
/*
int VMM::getFrameNumber(int pageNum)
{
	//check tlb first
	//currentAddress.setFrameNum(pageTable.pageTableLookup(pageNum));
	return 0;
}
*/
void VMM::setAddress(Address address) {
	currentAddress = address;
}

void VMM::print() {
	cout << "CurrentAddress --> Offset " << currentAddress.getOffset() << endl;
	cout << "CurrentAddress --> PageNum " << currentAddress.getPageNum() << endl;
}