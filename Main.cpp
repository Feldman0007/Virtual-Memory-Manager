#include <iostream>
#include <fstream>
#include <string>
#include "VMM.h"

using namespace std;



int main() {
	
	ifstream fileReader;//remove later
	fileReader.open("addresses.txt");//remove later

	VMM virtualMemoryManager;
	int logicalAddress;
	
	while (fileReader >> logicalAddress) {
		//cout << "Logical Address: " << logicalAddress << endl; 
		virtualMemoryManager.processInput(logicalAddress);
		//Process is the primary function of VMM input is will:
		// 1) Extract page number p so we may use it to index into the page table
		// 2) Use the page number p to index into the page table to retreive frame number f 
		// 3) Replace the page number p in the logical address with the frame number f.
		// 4) Use that physical address to locate the and output the value of the byte stored in RAM

	}	

	virtualMemoryManager.print();


	fileReader.close();
	system("PAUSE");
	return 0;

	/*

		double pfRate = pageFaults / (double)numOfphysicalAddress;
		double TLBRate = TLBHits / (double)numOfphysicalAddress;
	*/
}





