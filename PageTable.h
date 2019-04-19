#pragma once
#define PAGE_TABLE_SIZE 256
#define PAGE_SIZE 256
#ifndef PAGETABLE_H
#define PAGETABLE_H

class PageTable {
private:
	int pageTable[PAGE_TABLE_SIZE];

public:
	bool isFull();
	



};

#endif