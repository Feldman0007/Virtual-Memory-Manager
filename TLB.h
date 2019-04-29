#pragma once
#ifndef TLB_H
#define TLB_H
#define TLB_SIZE 16

#include "ReplacementAlgorithm.h"

/*
class TLBReplacementAlgorithm : public ReplacementAlgorithm {
};
*/
struct TLBEntry {
	int frameNum;
	int pageNum;
	bool isAvailable;

	int useTime;

	void updateTLBEntry(int frame, int page) {
		frameNum = frame;
		pageNum = page;
		useTime = 0;
		isAvailable = false;
	}
	int getFrame() {
		return frameNum;
	}
	int getPage() {
		return pageNum;
	}
};


class TLB{
	private:
		TLBEntry translationLookAsideBuffer[TLB_SIZE];								//ReplacementAlgorithm replacementAlgorithm;
		int numTLBEntries;
		ReplacementAlgorithm algorithm;

	public:
		TLB();
		bool hit(int);
		int findAvailableSpot();
		void update(int, int, int);
		int tlbGetFrame(int);
};

#endif
