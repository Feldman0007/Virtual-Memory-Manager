#pragma once
/**********************************************************************************************************************************
** Hardware Configuration Constants
*********************************************************************************************************************************/

#include <cstdlib>                  // size_t
#include "Utilities/Common.hpp"     // exp2()


namespace Hardware
{
  using namespace Utilities::Literals;

  // Addressing constants
  constexpr auto DISPACEMENT_EXTENT  = 8U;                                     // in bits - number of bits in address used to index into a page or frame
  constexpr auto ADDRESS_EXTENT      = 16U;                                    // in bits - number of bits used for addressing
  constexpr auto PAGE_EXTENT         = ADDRESS_EXTENT - DISPACEMENT_EXTENT;    // in bits - number of bits used to identify the logical address's page
  constexpr auto FRAME_EXTENT        = PAGE_EXTENT;                            // in bits - number of bits used to identify the physical address's frame

  // Computer endowment constants
  constexpr auto TLB_SIZE            = 16U;                                    // in Page Table Entries (PTEs) - number of slots in Translation Lookaside Buffer
  constexpr auto RAM_SIZE            = 32_KBytes;                              // in bytes - amount of Physical Memory
                                            
  // Derived hardware constants             
  constexpr auto FRAME_SIZE          = Utilities::exp2( DISPACEMENT_EXTENT );  // in bytes - size of a frame
  constexpr auto FRAMES              = RAM_SIZE / FRAME_SIZE;                  // in frames - number of FRAME_SIZE frames physical memory holds
  constexpr auto PAGES               = Utilities::exp2( PAGE_EXTENT );         // in Page Table Entries (PTEs) - number of slots in Page Table, one for each page

  static_assert(FRAME_SIZE <= RAM_SIZE, "The size of a physical frame must be a multiple of the RAM size");
}