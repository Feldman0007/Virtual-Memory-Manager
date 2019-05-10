#include "MMU.h"

void MMU::processAddress(uint32_t intAddr) {
	currentAddress.setLogicalAddress(intAddr);																				//Store the full logical address in case we need to reference it in the program
	currentAddress.setPage((intAddr & ADDRESS_MASK) >> 8);																	//Extract the page number p and use it as an index into the page table
	currentAddress.setDisplacement(intAddr & OFFSET_MASK); 																	//Extract the displacement d that will be used to construct physical address	
}

void MMU::read_and_print(RAM &r, uint32_t frameNumber, uint32_t frameOffset) {
	unsigned char byteOfData = r.accessRAM(frameNumber, frameOffset);														//read data from RAM using physical address (frame number + offset)
	cout << " (" << setw(2) << frameNumber << setw(2) << frameOffset << "): " << setw(2) << (uint32_t)byteOfData << endl;	//output physical address followed by the byte of data located at that address																																		//output byte of data stored in memory at the given physical address
}

void MMU::trap(bool validBit, uint32_t pgNum) {																				//should the MMU issue a trap? 
	if (!validBit) {																										//if the valid bit of the page table entry is set to invalid (false)
		throw pgNum;																										//generate a page fault
	}
}

void MMU::clearTLB() {																										//At the start of the program, we will need to clearTLB before store pageNumber in.
	tlb.clear();
}

/*
void MMU::validateAddressSpace() {																							// validates address space. commented out because this isn't really in the scope of the project

}
*/

void MMU::storeInRam(RAM &r, uint32_t freeFrame, char * frameOfData) {														//We will storing byte of data in to a free frame that we located in ram
	r.store(freeFrame, frameOfData);
}

Address MMU::getAddress(){																									//get current logical address
	return currentAddress;
}

hitStatus MMU::checkTLB(uint32_t pageNum) {																					//check the TLB using the pageNum of the page request to see if there is a hit
	return tlb.hit(pageNum);
}

void MMU::updateTLB(uint32_t frameNum, uint32_t pageNum, hitStatus status) {											    //update the entries of the TLB    
	if (status.isHit) {
		tlb.update(status.indexOfHit, frameNum, pageNum);																	//when we have a TLB hit, we only need to update the clock of the associated entry
	}
	else{
		tlb.update(tlb.findAvailableSpot(), frameNum, pageNum);																//otherwise we need to find a new spot and update that entry.
	}
}

uint32_t MMU::tlb_get_frame(uint32_t pageNum){
	return tlb.retrieveFrame(pageNum);																						//get the frame stored in a certain TLB entry
}
																															//counter incrementors...
void MMU::update_page_access_count(){
	page_access_count++;
}

void MMU::update_page_in_faults(){
	page_in_faults++;
}

void MMU::update_tlb_access_count(){
	tlb_access_count++;
}

void MMU::update_tlb_faults(){
	tlb_faults++;
}

void MMU::calculateTLBRate(){																								// calculate and display TLB hit rate, and page fault rate
	
	cout << endl << "TLB Faults: " << dec << tlb_faults << endl;
	cout << "TLB_Access_count: " << tlb_access_count << endl;

	float hitRate = (1 - (tlb_faults / (float)tlb_access_count)) * 100;
	cout << "TLB Hit Rate: " <<  hitRate << "%" << endl;
}

void MMU::calculatePageFaultRate(){
	cout << endl << "Page-Fault: " << page_in_faults << endl;
	cout << "Page-Access_Count: " << page_access_count << endl;			

	float faultRate = (page_in_faults / ((float)page_access_count + (float)page_in_faults)) * 100;
	cout << "Page-Fault Rate: " << faultRate << "%" << endl;
}