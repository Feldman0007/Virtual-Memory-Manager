#pragma once
/**********************************************************************************************************************************
** Hardware Configuration Constants
*********************************************************************************************************************************/       
//We tried to make some of the Hardware constants derivable from others like you had suggested we do in the email, but we struggled trying to understand your implementation :/
//We understand this would have been ideal, since it would demonstrated how the hardware constants are related, but we struggle tor replicate your technique (we're unfamiliar with constexpression) 
#define ADDRESS_MASK 0xFFFF
#define OFFSET_MASK 0xFF


#define TLB_REPLACE 1 //1 for for tlb replacement using lru, 0 for FIFO
#define PAGE_REPLACE 0 //1 for page replacement using lru, 0 for FIFO

#define FRAME_SIZE 256U
#define RAM_SIZE 128U
#define TLB_SIZE 16U
#define PAGE_TABLE_SIZE 256U
