#include "PageTableEntry.h"

PageTableEntry::PageTableEntry() {
	frameNumber = 0; // initially 0, null pointer, not yet mapped to physical address 
	valid_invalid_bit = false; // false = page not in memory
}
void PageTableEntry::populatePageEntry(int frameNum, bool validBit) {
	frameNumber = frameNum;
	valid_invalid_bit = validBit;
}
int PageTableEntry::getFrameNumber() {
	return frameNumber;
}
bool PageTableEntry::getValidBit() {
	return valid_invalid_bit;
}