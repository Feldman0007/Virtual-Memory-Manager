#include <iostream>
#include <fstream>
#include <string>
#include "MMU.h"

using namespace std;

int main() {

    //filename
    string filename = "addresses.txt";

	ifstream fileReader;
	fileReader.open(filename);

	//Each time we read we call mmu to convert logical to physical 
	MMU mmu;	
	string tempAddress; //remove later

	//logicalAddress.setAddress(address);
	
	while (fileReader >> tempAddress) {
		mmu.process(tempAddress);
		//look in page table
		//physical address = (calculate physical address)
		//use that address to index into RAM
		//retreive value from rAM
		//store to physicalAddress to std out



/*
std::ifstream infile("address.txt");
int a;
while (infile >> a)
{
    // process a
}

*/

	}

    //pass filename to MMU
	MMU mmu;
    mmu.process();


	backing_store = fopen("BACKING_STORE.bin");
	if (backing_store = NULL) {
		cout << "Error opening backing_store.bin" << endl;
		return -1;
	}

	int numOfphysicalAddress = 0; 
	hexConvertion(physicalAddress);


	/*
	double pfRate = pageFaults / (double)numOfphysicalAddress;
	double TLBRate = TLBHits / (double)numOfphysicalAddress;
	*/

	return 0;
}


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




/*
Use at TLB
    1. FIFO
        2nd chance/enhanced 2nd chance
    2. LRU
    3. MFU
    4. LFU


*/


