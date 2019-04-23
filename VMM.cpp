#include "VMM.h"

void VMM::processInput(string strAddr)
{
	currentAddress = mmu.processAddress(strAddr);	

	pageTable.pageTableLookup(currentAddress.getPageNum());
}
/*
int VMM::getFrameNumber(int pageNum)
{
	//check tlb first
	//currentAddress.setFrameNum(pageTable.pageTableLookup(pageNum));
	return 0;
}
*/

void VMM::print() {
	cout << "CurrentAddress --> Offset " << currentAddress.getOffset() << endl;
	cout << "CurrentAddress --> PageNum " << currentAddress.getPageNum() << endl;


}
