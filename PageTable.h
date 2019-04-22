#pragma once
#define PAGE_TABLE_SIZE 256
#define PAGE_SIZE 256
#ifndef PAGETABLE_H
#define PAGETABLE_H
#include <iostream>

using namespace std;

#include "Address.h"
#include "ReplacementAlgorithm.h"
/*
class PageReplacementAlgorithm : public ReplacementAlgorithm {

};
*/

class PageTable {
private:
	int pageTable[PAGE_TABLE_SIZE];


public:
	void storePageNum(int );
	void printPage();
};

#endif
