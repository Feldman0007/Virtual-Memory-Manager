#pragma once
#include <iostream>
#include <string>
//#include "PageTable.h"
#include "Address.h"

#include <sstream>
using namespace std;

#ifndef MMU_H
#define MMU_H

class MMU { 
private:
public: 
	//void getPhysicalA(string file) { ; }
	Address processAddress(string);
	//call function in page table to convert 
};

#endif
