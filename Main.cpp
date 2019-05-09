#include <iostream>
#include <fstream>
#include <string>
#include "VMM.h"

using namespace std;
/*
-----------------------------------------------------------------------Main thread of execution--------------------------------------------------------------------------------------------------------|
Main.cpp is our program's main thread of execution. Inside main we create an instance of VMM (see vmm.h for description), and pass it all the logical addresses from the input file to be processed.   |
After VMM has processed all page requests, we print the TLB hit rate and Page Fault rate.												        													   |
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
*/

int main() {

	ifstream fileReader;//remove later
	fileReader.open("addresses.txt");//remove later

	VMM virtualMemoryManager;
	uint32_t logicalAddress;
	//virtualMemoryManager.mmu_validateAddressSpace();								//Assuming we have just switched context to the current process's address space, so we must validate before process requests
	virtualMemoryManager.mmu_clearTLB();											/* Since we've likely performed a context stwitch to the address space of the process currently demanding pages
																						we should flush the TLB*/
	while (fileReader >> logicalAddress) {
		virtualMemoryManager.servicePageRequest(logicalAddress);
	}	
	
	virtualMemoryManager.printResults();
	fileReader.close();
	
	exit(0);
}

