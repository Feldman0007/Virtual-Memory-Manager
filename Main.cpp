#include <iostream>
#include <fstream>
#include <string>
#include "VMM.h"

using namespace std;
/*
-----------------------------------------------------------------------Main thread of execution--------------------------------------------------------------------------------------------------------|
Main.cpp is our program's main thread of execution. Inside main we create an instance of VMM (see vmm.h for description), and pass it all the logical addresses from the input file to be processed.   |
After VMM has processed all page requests, we print the TLB hit rate and Page Fault rate.																											   |																																																   | 				
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
*/
											//cout << "Logical Address: " << logicalAddress << endl; 
											//Process is the primary function of VMM input is will:

int main() {
	
	ifstream fileReader;//remove later
	fileReader.open("addresses.txt");//remove later

	VMM virtualMemoryManager;
	unsigned int logicalAddress;

	while (fileReader >> logicalAddress) {
		virtualMemoryManager.processInput(logicalAddress);
	}	
	
	virtualMemoryManager.printResults();
	fileReader.close();
	
	system("PAUSE"); // remove
	return 0;

	/*
	
	for (int i = 0; i < 32; i++) {
	printf("%x", hashedChars[i];
*/
}

