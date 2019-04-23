#pragma once
#ifndef PAGETABLEENTRY_H
#define PAGETABLEENTRY_H

class PageTableEntry { // https://www.youtube.com/watch?v=OaTR3S3MPRw
private:
	int frameNumber;
	bool valid_invalid_bit;// false = page not yet loaded into physical memory

public:
	PageTableEntry();

	void populatePageEntry(int, bool);
	int getFrameNumber();
	bool getValidBit();
	// algorithm to store on tlb????
};



#endif