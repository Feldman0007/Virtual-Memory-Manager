#pragma once
#define PAGE_TABLE_SIZE 256
#define PAGE_SIZE 256
#ifndef PAGETABLE_H
#define PAGETABLE_H
#include <iostream>

using namespace std;

#include "Address.h"
#include "PageTableEntry.h"
#include "ReplacementAlgorithm.h"
/*
class PageReplacementAlgorithm : public ReplacementAlgorithm {

};
*/

class PageTable {
private:
	PageTableEntry pageTable[PAGE_TABLE_SIZE]; 
	//PageReplacementAlgorithm 

public:
	void pageTableLookup(int);
};

#endif
