#pragma once
#ifndef RAM_H
#define RAM_H
#define FRAME_SIZE 256
#define RAM_SIZE 256

#include <iostream>

class RAM {
private:
	uint32_t physicalMemory[RAM_SIZE];

public:
	void store(int, uint32_t);
};

#endif