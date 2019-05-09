#pragma once
#ifndef PAGEREPLACEMENTALGORITHM_H
#define PAGEREPLACEMENTALGORITHM_H
#include "Configuration.hpp"

#include <queue>

using namespace std;

/*
---------------------------------------- Page Replacment Algorithm -----------------------------------
Purpose:
	Page replacement allows a VMM recent using data in touch eventhough the RAM is full by replacing.
Role:
	We will be handling Page replacement in this class
	We will have Least Recent Used and First in First Out alorigthm 


Responsibilities:
	Least Recent Used (LRU) Algorithm
		It will use the time of each frame to determine which frame to be kick out.
	First in First out
		We will be using a queue to store the order of the value going in the the Ram.
		We will pop the queue according order First in First out
		
------------------------------------------------------------------------------------------------------
*/

class RAM;																						//forward declaration

class PageReplacementAlgorithm {
private:
	queue<int> pageQueue;																		//queue of index numbers
public:
	void enqueue(uint32_t value);
	uint32_t dequeue();																			//return index to remove from page table
	uint32_t LRUreplace(RAM &r);
	uint32_t FIFOreplace();
};
#endif