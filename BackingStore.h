#pragma once
#ifndef BACKINGSTORE_H
#define BACKINGSTORE_H
#include "RAM.H"
#include <iostream>
#include <fstream>

using namespace std;


/*
------------------------------------------------------------------------------------------ Backing Store ------------------------------------------------------------------------------------------
Purpose:
	The Backing Store is an alternative, nonvolotile form of data storage, secondary to volatile main memory. It allows the user to store data that persists until it is overwritten or deleted.
	When used in conjunction with a memory management system, it enables paging and swapping, which expands the capacity of memory (in the form of virtual memory) that may be requested by a running program.
Role:
	Backing store enables the paging process in our memory management program. We use page numbers to index into and retrieve data from the backing store, which we then transfer to physical memory. The
	Backing store is used when a process requests a page of data that has not yet been loaded into physical memory (page fault). By paging that data we load it into RAM.

Responsibilities:
	Backing store will use default constructor to open the BackingStore.bin and make sure that it is being open properly
	In the scope of this project, we are only reading from the BackingStore, so we only access the BackingStore when we need to page data into main memory. 
	Backing store will be closed at destruction
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


class BackingStore {
private: 
	ifstream binaryFileReader;
	char dataBuffer[FRAME_SIZE];
public:
	BackingStore();
	~BackingStore();
	char * read(int);
};
#endif