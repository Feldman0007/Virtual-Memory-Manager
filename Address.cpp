#include "Address.h"
#define ADDRESS_MASK 0xFFFF
#define OFFSET_MASK 0xFFFF

int Address::getPageNum()
{
	return ((pageOffset & ADDRESS_MASK) >> 8);
}

int Address::getoffset()
{
	return (pageOffset & OFFSET_MASK);
}