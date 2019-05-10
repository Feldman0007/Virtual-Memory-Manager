#include "BackingStore.h"

BackingStore::BackingStore() {																			
	binaryFileReader.open("BACKING_STORE.bin", ios::binary | ios::in);										//open backing store in constructor
	if (binaryFileReader.fail()) {
		cout << "Error Opening backing_store " << endl;
		exit(1);
	}
}

char * BackingStore::read(uint32_t pageNum) {											
	binaryFileReader.seekg(pageNum * FRAME_SIZE);															//Seek to the position in secondary storage where we will begin reading a page of data. 
	binaryFileReader.read(dataBuffer, FRAME_SIZE);															//Read a page of data from secondary storage into a dataBuffer that will pass the data to RAM.
	return dataBuffer;
}

BackingStore::~BackingStore() {
	binaryFileReader.close();																				//close backing store in destructor
}
