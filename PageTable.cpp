#include "PageTable.h"

bool PageTable::pageTableLookup(int pageNum)
{
	return pageTable[pageNum].getValidBit();
}
void PageTable::updatePageTable(int pageNum, int frameNum) {
	pageTable[pageNum].updatePageEntry(frameNum);					//Update the frame number stored in the given page and set the valid bit to valid
}
PageTableEntry PageTable::getEntry(int index){
	return pageTable[index];
}
int PageTable::getFrame(int pageNum) {
	return pageTable[pageNum].getFrameNumber();
}
