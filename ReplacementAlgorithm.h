#pragma once
#ifndef REPLACEMENTALGORITHM_H
#define REPLACEMENTALGORITHM_H

#include "TLB.h"
#include <queue>
using namespace std;

class TLBReplacementAlgorithm  {
private:
	queue<int> fifoTLB; //queue of index numbers
public:
	void enqueue(int);
	int dequeue(); //return index to remove from tlb
	void LRUreplace(int, int, TLBEntry *);
	void FIFOreplace(int, int, TLBEntry *);
};

//class PageReplacementAlgorithm  {
//	void LRUreplacement(LRU page entry, &PageTable)
//		
//	void FIFOreplacement(Highest order TLB entry, &PageTable)
//};

#endif


/*

In TLB
	- pageNumber
	- frameNumber
	- TLBItemTime
-----------------------------------
Global or anywhere we can access when update TLB

	- TLBCurrentTime (global) int and start = 0
	- TLBMinTime (global) int and start = 0

-------------------------------------------
access TLB
	1st element in TLB 
		TLBItemTime = TLB current time
	Done adding item in TLB, TLBCurrentTime++

	if the element in TLB exist, upndate TLBItemTime = TLBCurrentTime;

	========================
	Example:
		index 0 item 0
			Item0:
				pageNumber
				frameNumber
				TLBItemTime = TLBCurrentTime = 0;
				TLBMinTime = 0 
			after add item, TLBCurrentTime++, now TLBCurrentTime = 1
		index 1 item 1
			Item1:
				pageNumber
				frameNumber
				TLBItemTime = TLBCurrentTime = 1;
			after add item, TLBCurrentTime++, now TLBCurrentTime = 2

		index 0 item 0 (Found again)
			Item0:
				pageNumber
				frameNumber
				TLBItemTime = TLBCurrentTime = 2;
			after found item, TLBCurrentTime++, now TLBCurrentTime = 3

		index 2 item 2 
			Item2:
				pageNumber
				frameNumber
				TLBItemTime = TLBCurrentTime = 3;
			after add item, TLBCurrentTime++, now TLBCurrentTime = 4

			....
		index 15 item 15
			Item15:
				pageNumber
				frameNumber
				TLBItemTime = TLBCurrentTime = example 25 (cause we found TLB therefore TLBCurrentTime larger than number of items);
			after add item, TLBCurrentTime++, now TLBCurrentTime = 26

			...
	From now on TLB is full, we will update TLBMinTime everytime we add new item.
		index 16 item 16
			Set Item16:
				pageNumber
				frameNumber
				TLBItemTime = TLBCurrentTime = example 26 (cause we found TLB therefore TLBCurrentTime larger than number of items);
			after add item, TLBCurrentTime++, now TLBCurrentTime = 27

			Then Replace item 16 with item 0 cause item0 has own the TLBItemTime = TLBMinTime

			Now at TLB index 0 contain Item 16 with 
				pageNumber
				frameNumber
				TLBItemTime = 26

			The min 
*/
