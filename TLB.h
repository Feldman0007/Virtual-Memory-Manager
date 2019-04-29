#pragma once
#ifndef TLB_H
#define TLB_H
#define TLB_SIZE 16

#include "ReplacementAlgorithm.h"

using namespace std;
/*
class TLBReplacementAlgorithm : public ReplacementAlgorithm {
};
*/
struct TLBEntry{
	int frameNum;
	int pageNum;
	int useTime;
	bool isAvailable;


	TLBEntry() {
		frameNum = -999;
		pageNum = -999;
		useTime = 0;
		isAvailable = true;
	}
	void updateTLBEntry(int f, int p) {
		frameNum = f;
		pageNum = p;
		isAvailable = false;
		useTime = 0;
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
		TLBReplacementAlgorithm algorithm;
		int numTLBEntries;
																	//ReplacementAlgorithm replacementAlgorithm;

		//int translationLookasideBuffer[TLB_SIZE];
	public:
		TLB();
		bool hit(int);
		int findAvailableSpot();
		void update(int, int);
		int getFrameTLBEntry(int);
};

#endif
