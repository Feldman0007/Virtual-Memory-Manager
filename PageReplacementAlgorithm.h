/*
===========================================================================================================================================================================
Page Replacment Algorithm
===========================================================================================================================================================================

We understand that a polymorphic approach would have been ideal for the replacement algorithms, since the Page Replacement Algorithm and TLB Replacement Algorithm classes are almost identical in design, however we were rusty
with polymorphism. We would have had no problem brushing up on it, but since we are short on time, we more concerned with  implementing and testing our program 
for timely delivery. We implemented them as seperate classes and haven't had the time to refactor for a polymorphic approach... so it looks ugly but works lol

Purpose:
	Page replacement algorithms allow the system to select a victim frame for replacement when RAM becomes full.
	
Roles:
	Page replacement allows a VMM to maintain data that is recent and likely to be used again.
	This class implements the replacement process.
	It supports the Least Recently Used and First-in-First-Out page replacement alorigthms.

Responsibilities:
	Select a victim frame using either an LRU or FIFO strategy
	Based on user selection, a victim frame will be selected according to the procedure of that algorithm. 

	Least Recent Used (LRU) Algorithm
		This algorithm selects the victim frame that has not been accessed for the longest time using the clock styled method. 
		This algorithm will search through the RAM status array to check the usedTime of each frame. 

	First in First Out (FIFO) Algorithm
		This algorithm selects the victim frame associated with the order in which they were brought into main memory.
		The frame associated with the page brought into memory first will be selected first, and so on. 

=============================================================================================================================================================================
*/


#pragma once
#ifndef PAGEREPLACEMENTALGORITHM_H
#define PAGEREPLACEMENTALGORITHM_H
#include "Configuration.hpp"

#include <queue>

using namespace std;


class RAM;																								//forward declaration to fix circular dependencies with RAM, lol


class PageReplacementAlgorithm {
private:
//FIFO page replacement queue
	queue<int> replacementQueue;																		
public:
//FIFO management
	void enqueue(uint32_t value);
	uint32_t dequeue();																			

//Page replacement algorithms
	uint32_t LRUreplace(RAM &r);
	uint32_t FIFOreplace();
};
#endif