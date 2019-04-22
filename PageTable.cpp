#include "PageTable.h"

/*
int pageTableLookup(int){
	return 0;
}

*/


void PageTable::storePageNum(int a)
{
	pageTable[a] = a;
	
}

void PageTable::printPage()
{
	for (int i = 0; i < PAGE_SIZE; i++)
		cout << "Print at index " << i << " element " << pageTable[i] << endl;
}
