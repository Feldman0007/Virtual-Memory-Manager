#include "PageTable.h"

bool PageTable::pageTableLookup(int pageNum)
{
	if (!pageTable[pageNum].getValidBit()) { 
		return false;												//valid bit is set to invalid, page must be brought into memory
	}
	else {									
		return true;												//valid bit set, and the page has already been loaded into memory
	}
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

void PageTable::invalidate_PT_Entries(int invalidframeNum) {		//Since we replaced a frame during page replacement...
	for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
		if (pageTable[i].frameNumber == invalidframeNum) {		//pages that still reference this frame... 
			pageTable[i].valid_invalid_bit = false;				//should be marked invalid  
		}
	}
};