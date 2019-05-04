#pragma once
#ifndef WORD_H
#define WORD_H
#include <iostream>

class Word {
private:
	uint32_t value; 	//peice of data retreived when we access an address
public:
	uint32_t getValue(uint32_t val) {
		return value;
	};
};
#endif