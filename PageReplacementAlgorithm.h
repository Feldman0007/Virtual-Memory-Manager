#pragma once
#ifndef PAGEREPLACEMENTALGORITHM_H
#define PAGEREPLACEMENTALGORITHM_H
#define PAGE_REPLACE 1 //1 for page replacement using lru, 0 for FIFO
#include <queue>

using namespace std;

class RAM; //forward declaration

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

