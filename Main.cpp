#include <iostream>
#include <fstream>
#include <string>
#include "VMM.h"

using namespace std;

struct headers {
	unsigned int totalFrames;
};

int main() {

	//filename
	string filename = "addresses.txt";//remove later

	ifstream fileReader;//remove later
	fileReader.open(filename);//remove later

	//Each time we read we call mmu to convert logical to physical 
	
	VMM virtualMemoryManager;
	string input; //remove later

	ifstream binaryFileReader;
	binaryFileReader.open("BACKING_STORE.bin", ios::in | ios::binary);

	if (!binaryFileReader) {
		cout << "Error Opening File " << endl;
		return -1;
	}

	headers test;
	binaryFileReader.seekg(60 * 256 + 20, ios::beg);
	binaryFileReader.read((char*)& test, sizeof(test));
	cout << test.totalFrames << endl;

	//while (fileReader >> input) {
	//	virtualMemoryManager.processInput(input);	
	//	//Process is the primary function of VMM input is will:
	//	// 1) Extract page number p so we may use it to index into the page table
	//	// 2) Use the page number p to index into the page table to retreive frame number f 
	//	// 3) Replace the page number p in the logical address with the frame number f.
	//	// 4) Use that physical address to locate the and output the value of the byte stored in RAM
	//	// 5) Convert to hex to print 
	//	virtualMemoryManager.print();

	//}	


	fileReader.close();
	system("PAUSE");
	return 0;

	/*
		std::ifstream infile("address.txt");
		int a;
		while (infile >> a)
		{
		// process a
		}

		backing_store = fopen("BACKING_STORE.bin");
		if (backing_store = NULL) {
			cout << "Error opening backing_store.bin" << endl;
			return -1;
		}

		int numOfphysicalAddress = 0;
		hexConvertion(physicalAddress);


		double pfRate = pageFaults / (double)numOfphysicalAddress;
		double TLBRate = TLBHits / (double)numOfphysicalAddress;
	*/
}

/*

void hexConvertion(int address)
{
	char hexNum[100];
	int i = 0;
	while (n != 0)
	{
		int temp = 0;
		temp = n % 16;
		if (temp < 10)
		{
			hexNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexNum[i] = temp + 55;
			i++;
		}
		n = n / 16;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << hexNum[j];
}


*/



