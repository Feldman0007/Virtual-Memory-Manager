/*
====================================================================================================================================
TLB Replacement Algorithm  
====================================================================================================================================

We understand that a polymorphic approach would have been ideal for the replacement algorithms, since the Page Replacement Algorithm and TLB Replacement Algorithm classes are almost identical in design, however we were rusty
with polymorphism. We would have had no problem brushing up on it, but since we are short on time, we more concerned with  implementing and testing our program
for timely delivery. We implemented them as seperate classes and haven't had the time to refactor for a polymorphic approach... so it looks ugly but works lol

Purpose:
	Ensures that entries with current information remain in the TLB when it becomes full.
Role:
	When TLB is full and we have page request that results in a TLB miss, TLB Replacement will decide the victim entry to be replaced by the new page-frame pair.
Responsibilities:
	Select a victim entry using either an LRU or FIFO strategy.
	Based on user selection, a victim frame will be selected according to the procedure of that algorithm.
 
	Least Recent Used (LRU) Algorithm
		This algorithm selects the victim entry that has not been accessed for the longest time using the clock styled method. 
		This algorithm will search through the TLB array to check the usedTime of each TLB entry. 

	First in First Out (FIFO) Algorithm
		This algorithm selects the victim entry associated with the order in which they were cached into the TLB.
		The TLB entry that was cached first will be selected first, and so on. 
===================================================================================================================================
*/
#pragma once
#ifndef TLBREPLACEMENTALGORITHM_H
#define TLBREPLACEMENTALGORITHM_H
#include "Configuration.hpp"

#include <queue>

using namespace std;


struct TLBEntry; //forward declaration of tlb entry. We were having circular dependecies so we fixed it with forward declaration lol

class TLBReplacementAlgorithm {
private:
//FIFO TLB replacement queue
	queue<int> replacementQueue;
public:
//FIFO management
	void enqueue(uint32_t value);
	uint32_t dequeue();
	
//TLB replacement algorithms
	uint32_t LRUreplace(TLBEntry * tlb);
	uint32_t FIFOreplace();
};
#endif