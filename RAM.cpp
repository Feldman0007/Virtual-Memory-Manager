#include "RAM.h"

void RAM::store(int frame, uint32_t data){
	physicalMemory[frame] = data;
}

