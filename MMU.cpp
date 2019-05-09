#include "MMU.h"

void MMU::processAddress(uint32_t intAddr) {
	currentAddress.setLogicalAddress(intAddr);
	currentAddress.setPage((intAddr & ADDRESS_MASK) >> 8);															//Extract the page number p and use it as an index into the page table
	currentAddress.setDisplacement(intAddr & OFFSET_MASK); 															//Extract the displacement d that will be used to construct physical address	
}

void MMU::read_and_print(RAM &r, uint32_t frameNumber, uint32_t frameOffset) {
	unsigned int byteOfData = r.accessRAM(frameNumber, frameOffset);
	cout << " (" << setw(2) << frameNumber << setw(2) << frameOffset << "): " << setw(2) << (byteOfData) << endl;	//output physical address																																			//output byte of data stored in memory at the given physical address
}

void MMU::trap(bool validBit, uint32_t pgNum) {																		//will the MMU execute a trap? w
	if (!validBit) {																								//if the valid bit of the page table entry is set to invalid (false)
		throw pgNum;																								//generate a page fault
	}
}

void MMU::clearTLB() {
	tlb.clear();
}

/*
void MMU::validateAddressSpace(){
	
}
*/
void MMU::storeInRam(RAM &r, uint32_t freeFrame, char * frameOfData) {
	r.store(freeFrame, frameOfData);
}

Address MMU::getAddress(){
	return currentAddress;
}

hitStatus MMU::checkTLB(uint32_t pageNum) {
	return tlb.hit(pageNum);
}

void MMU::updateTLB(uint32_t frameNum, uint32_t pageNum, hitStatus status) {
	if (status.isHit) {
		tlb.update(status.indexOfHit, frameNum, pageNum);
	}
	else{
		tlb.update(tlb.findAvailableSpot(), frameNum, pageNum);
	}
}

uint32_t MMU::tlb_get_frame(uint32_t pageNum){
	return tlb.retrieveFrame(pageNum);
}

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

void MMU::calculateTLBRate(){
	cout << "TLB Faults: " << dec << tlb_faults << endl;
	cout << "TLB_Access_count: " << tlb_access_count << endl;

	float hitRate = (1 - (tlb_faults / (float)tlb_access_count)) * 100;
	cout << "TLB Hit Rate: " <<  hitRate << "%" << endl;
}

void MMU::calculatePageFaultRate(){
	cout << "Page-Fault: " << page_in_faults << endl;					
	cout << "Page-Access_Count: " << page_access_count << endl;			

	float faultRate = (page_in_faults / ((float)page_access_count + (float)page_in_faults)) * 100;
	cout << "Page-Fault Rate: " << faultRate << "%" << endl;
}