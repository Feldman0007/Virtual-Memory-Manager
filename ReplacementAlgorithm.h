#pragma once
#ifndef REPLACEMENTALGORITHM_H
#define REPLACEMENTALGORITHM_H

#include "TLB.h"
#include <queue>
using namespace std;

class ReplacementAlgorithm {
private:
	queue<int> fifoTLB; //queue of index numbers
public:
	void enqueue(int);
	int dequeue(); //return index to remove from tlb
	void LRUreplace(int, int, TLBEntry* tlb) ;
	void FIFOreplace(int, int, TLBEntry tlb);
};


#endif

