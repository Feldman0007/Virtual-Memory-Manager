#pragma once
#ifndef TLB_H
#define TLB_H
#define TLB_SIZE 16

#include "ReplacementAlgorithm.h"

/*
class TLBReplacementAlgorithm : public ReplacementAlgorithm {
};
*/
struct TLBEntry{
	int frameNum;
	int pageNum;
	bool isAvailable;
	//int time;

	void updateTLBEntry(int frame, int page) {
		frameNum = frame;
		pageNum = page;
	}
	int getFrame() {
		return frameNum;
	}
	int getPage() {
		return pageNum;
	}
};


class TLB {
	private:
		TLBEntry translationLookAsideBuffer[TLB_SIZE];
		int minTime;												//for quicker algorithm
		bool isFull;
																	//ReplacementAlgorithm replacementAlgorithm;

		//int translationLookasideBuffer[TLB_SIZE];
	public:
		bool hit(int);
		int findAvailableSpot();
		void update(int, int, int);
		int tlbGetFrame(int);
};

#endif
