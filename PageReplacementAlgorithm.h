#pragma once
#ifndef PAGEREPLACEMENTALGORITHM_H
#define PAGEREPLACEMENTALGORITHM_H
#define PAGE_REPLACE 0 //1 for page replacement using lru, 0 for FIFO
#include <queue>

using namespace std;

/*
----------------------------- Page Replacment Algorithm -------------------------------

We will be handling Page replacement in this class
We will have Least Recent Used and First in First Out alorigthm 

Least Recent Used (LRU) Algorithm
	It will use the time of each frame to determine which frame to be kick out.
First in First out
	We will be using a queue to store the order of the value going in the the Ram.
	We will pop the queue according order First in First out

---------------------------------------------------------------------------------------
*/

class RAM;																				//forward declaration

class PageReplacementAlgorithm {
private:
	queue<int> pageQueue;																//queue of index numbers
public:
	void enqueue(int);
	int dequeue();																		//return index to remove from page table
	int LRUreplace(RAM &);
	int FIFOreplace();
};
#endif

