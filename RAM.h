#pragma once
#ifndef RAM_H
#define RAM_H
#define FRAME_SIZE 256
#define RAM_SIZE 256

#include <iostream>
#include <iomanip>

using namespace std;

class RAM {
private:
	char physicalMemory[RAM_SIZE][FRAME_SIZE];

public:
	void store(int, char *);
	void print(int, int);
};

#endif