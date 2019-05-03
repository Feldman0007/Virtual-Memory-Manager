#pragma once
#ifndef TLB_H
#define TLB_H
#define TLB_SIZE 16
#include "TLBReplacementAlgorithm.h"

struct TLBEntry {
	int frameNum;
	int pageNum;
	bool isAvailable;
	int useTime;
	
	TLBEntry() {
		frameNum = -999;
		pageNum = -999;
		isAvailable = true;
		useTime = 0;
	}
	void updateTLBEntry(int frame, int pg) {
		frameNum = frame;
		pageNum = pg;
		useTime = 0;
		isAvailable = false;
	}
	int getFrame() {
		return frameNum;
	}
	int getPage() {
		return pageNum;
	}
};

class TLB{
	private:
		TLBEntry entries[TLB_SIZE];					//entries is an array of TLB entries. 
		int numTLBEntries;							//counter to keep track of the number of entries in the TLB
		TLBReplacementAlgorithm algorithm;			//fifo or lru tlb entry replacement

	public:
		TLB();
		bool hit(int);
		int findAvailableSpot();					//returns the first available spot in the tlb. returns sentinel value -1 if tlb is full. 
		void update(int, int, int);					
		int retrieveFrame(int);		
};	

#endif
