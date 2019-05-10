
/*
=================================================================================================================================================================================================
Backing Store
=================================================================================================================================================================================================

The BackingStore class provides methods for reading in data from the binary file BACKING_STORE.bin using a page number to select where in secondary storage to read from.
BackingStore will be utilized when a page fault occurs, where a page of data is read into BackingStore's buffer and sent to main memory.

Purpose:
	The Backing Store is an alternative, nonvolatile form of data storage, as opposed to volatile main memory. It allows the user to store data that persists until it is overwritten or deleted.
	When used in conjunction with a virtual memory management system, it enables paging and swapping techniques, which extend the capacity of memory that may be accessed by a running program.
Role:
	The backing store enables virtual memory via paging.
	The backing store stores data that can be retrieved and loaded into physical memory during a page fault.

Responsibilities:
	Backing store will use default constructor to open the BackingStore.bin and make sure that it is being opened properly
	In the scope of this project, we are only reading from the BackingStore, so accesses to the BackingStore are only when we need to page data into main memory.
	Backing store will be closed at destruction

==================================================================================================================================================================================================
*/



#pragma once
#ifndef BACKINGSTORE_H
#define BACKINGSTORE_H
#include "RAM.h"

#include <iostream>
#include <fstream>

using namespace std;

class BackingStore {
private: 
	ifstream binaryFileReader;
	char dataBuffer[FRAME_SIZE] = { 0 };
public:
	BackingStore();
	~BackingStore();
	char * read(uint32_t pageNum);
};
#endif