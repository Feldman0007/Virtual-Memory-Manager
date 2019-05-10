#pragma once
#include <cstdint>     // We need to include this so that uint32_t can be recognized when compiled on Linux
/*
==============================================================================================================================================
Hardware Configuration Constants
==============================================================================================================================================
Here, we define all of our hardware specs as constants. They determine how our virtual memory management system will operate.

We tried to make some of the Hardware constants derivable like you had suggested in the email, but we struggled trying to understand your technique :/
We understand this would have been ideal, since it would demonstrate how different hardware specifications are related.

==============================================================================================================================================
*/

#define ADDRESS_MASK 0xFFFF
#define OFFSET_MASK 0xFF


#define TLB_REPLACE 1 //1 for for tlb replacement using lru, 0 for FIFO
#define PAGE_REPLACE 0 //1 for page replacement using lru, 0 for FIFO

#define FRAME_SIZE 256U
#define RAM_SIZE 128U
#define TLB_SIZE 16U
#define PAGE_TABLE_SIZE 256U
