#include "BackingStore.h"

BackingStore::BackingStore() {
	binaryFileReader.open("BACKING_STORE.bin", ios::binary | ios::in);
	if (binaryFileReader.fail()) {
		cout << "Error Opening backing_store " << endl;
		exit(1);
	}
}

char * BackingStore::read(uint32_t pageNum) {
	binaryFileReader.seekg(pageNum * FRAME_SIZE);
	binaryFileReader.read(dataBuffer, FRAME_SIZE);
	return dataBuffer; 
}

BackingStore::~BackingStore() {
	binaryFileReader.close();
}
