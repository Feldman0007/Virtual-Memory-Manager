#include <iostream>
#include <fstream>
#include <string>
#include "VMM.h"

using namespace std;

int main() {

	//filename
	string filename = "Addresses.txt";

	ifstream fileReader;
	fileReader.open(filename);

	//Each time we read we call mmu to convert logical to physical 
	
	
	VMM virtualMemoryManager; // Virtually memory manager is our over arching class that encompasses all domain objects of a virtual memory manager
	string input; //remove later

	//logicalAddress.setAddress(address);

	while (fileReader >> input) {
		virtualMemoryManager.processInput(input);	
		//Process is the primary function of VMM input is will:
		// 1) Extract page number p so we may use it to index into the page table
		// 2) Use the page number p to index into the page table to retreive frame number f 
		// 3) Replace the page number p in the logical address with the frame number f.
		// 4) Use that physical address to locate the and output the value of the byte stored in RAM
		// 5) Convert to hex to print 
		virtualMemoryManager.print();

	}	
	virtualMemoryManager.print2();

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

/*
Use at TLB
	1. FIFO
		2nd chance/enhanced 2nd chance
	2. LRU
	3. MFU
	4. LFU


*/


