#pragma once
#ifndef TLB_H
#define TLB_H
#define TLB_SIZE 16
#include "TLBReplacementAlgorithm.h"
/*
----------------------------------------------------------- Translation look-aside buffer -------------------------------------------------------
Purpose:
	Improve process' performance. With TLB, process runs faster than without it.
Role:
	TLB store address space identifiers in each TLB entry -uniquely identifies each process to provide address-soace protection for that process.
	TLB has the size of 16 which will store 16 entries 

Responsibilities:
	TLB will help access to frame number faster. 
	On a TLB miss, value is loaded into the TLB for faster access next time. 
	TLB will store a frame number, a page number and a useTime
	useTime is will be used to track the number of time a pageNumber in TLB is being use. If its being use, the value will restart to 0. 
		-> the one with the most value will be send to Least Recent Use Replacement Algorithm if th3e TLB is full when we are update the TLB. 
-------------------------------------------------------------------------------------------------------------------------------------------------
*/
struct TLBEntry {
	int frameNum;									//frame number stored in each tlb entry
	int pageNum;									//page number stored in each tlb entry
	bool isAvailable;								//used to determine if this tlb entry is occupied
	int useTime;									//used in the LRU replacement algorithm
	
	TLBEntry() {
		frameNum = -999;							//dummy values
		pageNum = -999;								
		isAvailable = true;							//initially available
		useTime = 0;								
	}
	void updateTLBEntry(int frame, int pg) {
		frameNum = frame;							//update frame number
		pageNum = pg;								//update page number
		useTime = 0;								//when updating a tlb entry, it is now the most recently used. Reset timer
		isAvailable = false;						//now occupied, isAvailable marked false.
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
		bool hit(int);								//if there is a TLB hit, returns true
		int findAvailableSpot();					//returns the first available spot in the tlb. returns sentinel value -1 if tlb is full. 
		void update(int, int, int);					//adds a page + frame entry to an available spot in the TLB, if TLB is full, we execute a replacement algorithm
		int retrieveFrame(int);						//get the frame stored at an entry, given the page number
};	

#endif
