#include "BackingStore.h"



BackingStore::BackingStore() {
	binaryFileReader.open("BACKING_STORE.bin", ios::in | ios::binary | ios::trunc);
	if (binaryFileReader.fail()) {
			cout << "Error Opening File " << endl;
			system("PAUSE");
	}
}

uint32_t BackingStore::read(int pageNum, int offSet) {
	uint32_t data;
	binaryFileReader.seekg(pageNum * FRAME_SIZE + offSet);
	binaryFileReader.read((char*)& data, sizeof(FRAME_SIZE));
	return data; 
}


BackingStore::~BackingStore() {
	binaryFileReader.close();
}

