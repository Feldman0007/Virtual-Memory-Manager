#include "PageTable.h"

/*
int pageTableLookup(int){
	return 0;
}

*/


void PageTable::pageTableLookup(int a)
{
	if (pageTable[a].getValidBit()) { // if there is no mapped frame to our logical address
		PageTableEntry nextEntry; //create new Page Table entry  
		// trap and go to backing store
		// get frame number
		//nextEntry.populatePageEntry(frameNum, false);
		
		// nextEntry.setValidBit();
		// pageTable[a] = nextEntry
	}
	else { //valid address
		  //get frame number right away
	}
	;
	
}
