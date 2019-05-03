#pragma once
#ifndef REPLACEMENTALGORITHM_H
#define REPLACEMENTALGORITHM_H

#define TLB_REPLACE 1 //1 for for tlb replacement using lru, 0 for FIFO
#define PAGE_REPLACE 1 //1 for page replacement using lru, 0 for FIFO

#include "TLB.h"
#include "PageTable.h"
#include "RAM.h"
#include <queue>

using namespace std;

class TLBReplacementAlgorithm {
private:
	queue<int> tlbQueue;																//queue of index numbers
public:
	void enqueue(int);
	int dequeue();																		//return index to remove from tlb
	int LRUreplace(TLBEntry*) ;
	int FIFOreplace();
};


class PageReplacementAlgorithm {
private:
	queue<int> pageQueue;																//queue of index numbers
public:
	void enqueue(int);
	int dequeue();																		//return index to remove from page table
	int LRUreplace (RAM &);
	int FIFOreplace();
};


#endif

