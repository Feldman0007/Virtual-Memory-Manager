#include "MMU.h"

#define ADDRESS_MASK 0xFFFF
#define OFFSET_MASK 0xFF

//void getPhysicalA(string file) { ; }

MMU::MMU() {
	int page_access_count_  = 0;
	int page_in_faults_		= 0;
	int tlb_access_count_	= 0;
	int tlb_faults_			= 0;
}

void MMU::processAddress(int intAddr) {
	int intOffset;
	int intPageNum;

	intPageNum = ((intAddr & ADDRESS_MASK) >> 8);						 //mask to get pagenumber 
	intOffset = intAddr & OFFSET_MASK; 									 //mask to get the offset  

	currentAddress.setDisplacement(intOffset);
	currentAddress.setPage(intPageNum);
	currentAddress.setLogicalAddress(intAddr);
}

Address MMU::getAddress(){
	return currentAddress;
}

bool MMU::checkTLB(int pageNum) {
	return tlb.hit(pageNum);

}

void MMU::updateTLB(int frameNum, int pageNum) {
	tlb.updateTLB(tlb.findAvailableSpot(), frameNum, pageNum);
}

int MMU::retrieveFrame(int pageNum){
	return tlb.tlbGetFrame(pageNum);
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
	cout << "Page-Fault: " << page_in_faults << endl;					//243
	cout << "Page-Access_Count: " << page_access_count << endl;			//756 access count

	
	float faultRate = (page_in_faults / (float)page_access_count) * 100;	// page_in
	cout << "Page-Fault Rate: " << faultRate << "%" << endl;
}