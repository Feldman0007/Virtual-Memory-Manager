#include "PageTable.h"



bool PageTable::pageTableLookup(int pageNum)
{
	if (!pageTable[pageNum].getValidBit()) { // if the invalid bit is there is no mapped frame to our logical address
		return false; // use backing store
	}
	else { //valid bit set, the page has already been loaded into memory
		return true; 
	}
}
void PageTable::updatePageTable(Address addr) {
	pageTable[addr.getPage()].updatePageEntry(/*values returned from pageIn*/);

}
PageTableEntry PageTable::getEntry(int index){
	return pageTable[index];
}
