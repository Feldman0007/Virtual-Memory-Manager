#pragma once
#ifndef BACKINGSTORE_H
#define BACKINGSTORE_H
#include "RAM.H"
#include <iostream>
#include <fstream>

using namespace std;

class BackingStore {
private: 
	ifstream binaryFileReader;
public:
	BackingStore();
	~BackingStore();
	uint32_t read(int, int);
};
#endif


////int fetchPage(const &pageNumber)
//string filename = "BACKING_STORE.bin";//remove later
//ifstream binaryFileReader;//remove later

//char data[PAGE_SIZE];

//binaryFileReader.open(filename, ios::in | ios::binary);
//binaryFileReader.seekg(0, ios::end);
//binaryFileReader.read(data, PAGE_SIZE);
////index * PAGE_SIZE



//if (binaryFileReader.fail()) {
//	cout << "Error Opening File " << endl;
//	system("PAUSE");
//}
//for (int i = 0; i < PAGE_SIZE; i++) {
//	cout << "Page: " << i << " Data: " << data[i] << endl;
//}