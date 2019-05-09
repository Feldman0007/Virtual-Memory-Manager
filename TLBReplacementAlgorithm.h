#pragma once
#ifndef TLBREPLACEMENTALGORITHM_H
#define TLBREPLACEMENTALGORITHM_H
#include "Configuration.hpp"

#include <queue>

using namespace std;


/*-------------------------------- TLB Replacement Algorithm  ---------------------------------------
Purpose:
	Keep recent use value in touch even though TLB is full
Role:
	When TLB is full and we have new coming value. TLB Replacement will decide who will be left to take place for new one.

Responsibilities:
	Depending on algorithm is FIFO or LRU, leaving element will be picked differently.
	In both FIFO and LRU, TLB replacement manages processes from picking a victim, take it out, put the new in, and return the victim which can be use later by other process.
	In FIFO, queue system is involved while time management is used in LRU to control who will be in and who will be out when needed.

-----------------------------------------------------------------------------------------------------
*/

struct TLBEntry; //forward declaration of tlb entry. We were having circular dependecies so we needed to do some forward declarations

class TLBReplacementAlgorithm {
private:
	queue<int> tlbQueue;																//queue of index numbers
public:
	void enqueue(uint32_t value);
	uint32_t dequeue();																		//return index to remove from tlb
	uint32_t LRUreplace(TLBEntry * tlb);
	uint32_t FIFOreplace();
};
#endif