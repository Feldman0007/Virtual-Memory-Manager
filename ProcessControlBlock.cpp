#include "ProcessControlBlock.h"

bool ProcessControlBlock::pageTableLookup(uint32_t pageNum)
{
	if (!pageTable[pageNum].getValidBit()) { 
		return false;												//valid bit is set to invalid, page must be brought into memory
	}
	else {									
		return true;												//valid bit set, and the page has already been loaded into memory
	}
}
void ProcessControlBlock::updatePageTable(uint32_t pageNum, uint32_t frameNum) {
	pageTable[pageNum].updatePageEntry(frameNum);					//Update the frame number stored in the given page and set the valid bit to valid
}
PageTableEntry ProcessControlBlock::getEntry(uint32_t index){
	return pageTable[index];
}

uint32_t ProcessControlBlock::getFrame(uint32_t pageNum) {
	return pageTable[pageNum].getFrameNumber();
}

void ProcessControlBlock::invalidate_PT_Entries(uint32_t invalidframeNum) {		//Since we replaced a frame during page replacement...
	for (uint32_t i = 0; i < PAGE_TABLE_SIZE; i++) {
		if (pageTable[i].frameNumber == invalidframeNum) {		//pages that still reference this frame... 
			pageTable[i].valid_invalid_bit = false;				//should be marked invalid  
		}
	}
};