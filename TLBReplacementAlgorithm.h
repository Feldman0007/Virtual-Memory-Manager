#pragma once
#ifndef TLBREPLACEMENTALGORITHM_H
#define TLBREPLACEMENTALGORITHM_H

#define TLB_REPLACE 0 //1 for for tlb replacement using lru, 0 for FIFO
#include <queue>

using namespace std;


/*-------------------------------- TLB Replacement Algorithm  ---------------------------------------
Role:



Responsiblity


-----------------------------------------------------------------------------------------------------
*/

struct TLBEntry; //forward declaration of tlb entry. We were having circular dependecies so we needed to do some forward declarations

class TLBReplacementAlgorithm {
private:
	queue<int> tlbQueue;																//queue of index numbers
public:
	void enqueue(int);
	int dequeue();																		//return index to remove from tlb
	int LRUreplace(TLBEntry *);
	int FIFOreplace();
};
#endif