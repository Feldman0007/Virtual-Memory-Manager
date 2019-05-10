#include <iostream>
#include <string>
#include "VMM.h"

using namespace std;
/*
-----------------------------------------------------------------------Main thread of execution--------------------------------------------------------------------------------------------------------|
Main.cpp is our program's main thread of execution. Inside main we create an instance of VMM (see VMM.h for details) and feed it page requests from the current process								   |
After VMM has processed all page requests, we print the TLB hit rate and Page Fault rate.												        													   |
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
*/

int main() {

	VMM virtualMemoryManager;                                             

/*                                                                                  The next two functions are called through VMM because we need them to execute before we begin to service page requests
	virtualMemoryManager.mmu_validateAddressSpace();								Assuming we have just switched context to the current process's address space, we must validate address space and flush the TLB before processing requests. This method is commented our because it really isn't in the scope of the project.			*/																		
	virtualMemoryManager.mmu_clearTLB();
																				  
	uint32_t logicalAddress;
	while (cin >> logicalAddress) {
		virtualMemoryManager.servicePageRequest(logicalAddress);
	}	
	
	virtualMemoryManager.printResults();
	
	exit(0);
}

