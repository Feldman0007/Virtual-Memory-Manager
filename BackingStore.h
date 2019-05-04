#pragma once
#ifndef BACKINGSTORE_H
#define BACKINGSTORE_H
#include "RAM.H"
#include <iostream>
#include <fstream>

using namespace std;


/*
------------------------------------------------------------------------- Backing Store ----------------------------------------------------------------------------

Role:
	Backing store is typically part of a hard disk that is used by a paging or swapping system to store information not currently on main memory

Responsibliy
	Backing store will use default constructor to read the BackingStore.bin and make sure that it is being open properly
	Backing store will be closed at destruction
	In this project, we are limited to only reading from BackingStore, so we can only access to BackingStore when the data need to be brought to the main memory. 


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
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