#include "VMM.h"

void VMM::processInput(string strAddr)
{
	mmu.processAddress(strAddr);
	PageTableEntry currentEntry = pgTable.getEntry(mmu.getAddress().getPage());
	if (currentEntry.getValidBit()) { //If valid bit marked, then the given page has already loaded into physical memory
		//ram.read(currentEntry.getFrameNumber()); //so we can fetch data from the associated frame in RAM						  
		// return page/byte of data 
	}
	else {
		pageFaultRoutine();
	}
}
/*
int VMM::getFrameNumber(int pageNum)
{
	//check tlb first
	//currentAddress.setFrameNum(pageTable.pageTableLookup(pageNum));
	return 0;
}
*/
void VMM::pageFaultRoutine() { //trap 
	mmu.pageIn();  //
	int freeFrame = checkAvailable();	//select free frame from RAM
	ram.store(freeFrame, mmu.word);//Push data into Ram
	pgTable.updatePageTable(mmu.getAddress());
}

void VMM::print() {
	cout << "CurrentAddress --> Offset " << mmu.getAddress().getDispacement() << endl;
	cout << "CurrentAddress --> PageNum " << mmu.getAddress().getPage() << endl;
	//cout << byteRetrieved.getValue();

}

void VMM::updateAvailability(int i) {
	freeFramesList[i] = false; // Not available
}
int VMM::checkAvailable() {
	for (int i = 0; i < 256; i++) {
		if (freeFramesList[i] == true) { //If available
			return i;
		}
	}
}
