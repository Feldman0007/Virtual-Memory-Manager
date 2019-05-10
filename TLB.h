/*
======================================================================================================================================================
Translation look-aside buffer
======================================================================================================================================================

	The TLB is a member of (part of) the MMU, and it is referenced every time we receive a page request in an attempt to forgo the pagetable and speed up the translation process. We implemented the TLB as an array 
	of TLB entry structures. Each TLB entry contains a page-frame pair, a flag variable indicating whether it is occupied, and a clock variable for the LRU algorithm.  

Purpose:
	Caches frequently used pages in an effort to speed up the address translation process.
	Potentially improves process performance (when the cache is warm).
Role:
	Keeps address translation information readily available.

Responsibilities:
	Quickly provides a frame number for page requests that have the same page number of other recent request.
	On a TLB miss, TLB will be updated that page/frame pair for pontential access in the future.
	If TLB is full, it will use a replacement algorithm to select a victim TLB entry.

=====================================================================================================================================================
*/
#pragma once
#ifndef TLB_H
#define TLB_H
#include "Configuration.hpp"
#include "TLBReplacementAlgorithm.h"

struct TLBEntry {
	uint32_t frameNum;																		//frame number stored in each tlb entry
	uint32_t pageNum;																		//page number stored in each tlb entry
	bool isAvailable;																		//used to determine if this tlb entry is occupied
	uint32_t useTime;																		//used in the LRU replacement algorithm
	
	void updateTLBEntry(uint32_t frame, uint32_t pg) {
		frameNum = frame;																	//update frame number
		pageNum = pg;																		//update page number
		useTime = 0;																		//when updating a tlb entry, it is now the most recently used. Reset clock
	}	
	uint32_t getFrame() {
		return frameNum;
	}
	uint32_t getPage() {
		return pageNum;
	}
};

struct hitStatus {																			//stores the status when we check the TLB for a hit
	bool isHit = false;
	uint32_t indexOfHit = 999;
};

class TLB{
private:
	TLBEntry entries[TLB_SIZE];															//entries is an array of TLB entries. 
	uint32_t numTLBEntries;																//counter to keep track of the number of entries in the TLB
	TLBReplacementAlgorithm algorithm;													//fifo or lru tlb entry replacement

public:	
//TLB Maintenance
	void clear();
	void update(uint32_t index, uint32_t frameNum, uint32_t pageNum);					//adds a page + frame entry to an available spot in the TLB, if TLB is full, we execute a replacement algorithm
//Helpers
	hitStatus hit(uint32_t pageNum);													//if there is a TLB hit, returns true
	uint32_t findAvailableSpot();														//returns the first available spot in the tlb. returns sentinel value 999 if tlb is full. 
	uint32_t retrieveFrame(uint32_t pageNum);											//get the frame stored at an entry, given the page number
	TLB();
};	

#endif
