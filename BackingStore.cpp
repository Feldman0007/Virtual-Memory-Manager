#include "BackingStore.h"



BackingStore::BackingStore() {
	binaryFileReader.open("BACKING_STORE.bin", ios::binary | ios::in);
	if (binaryFileReader.fail()) {
			cout << "Error Opening backing_store " << endl;
			system("PAUSE");
	}
}

char * BackingStore::read(int pageNum) {
	binaryFileReader.seekg(pageNum * FRAME_SIZE);
	binaryFileReader.read(dataBuffer, FRAME_SIZE);
	return dataBuffer; 
}

BackingStore::~BackingStore() {
	binaryFileReader.close();
}
