#ifndef Z_BLOCK_H_
#define Z_BLOCK_H_

#include "FallingBlock.h"

class Z_Block : public FallingBlock{

    /*

     | 0 0 0 |
     | 1 1 0 |
     | 0 1 1 |

     */

public:
    Z_Block() : FallingBlock(3){ // Configure original position of block and create grid
        // Default position
        grid[1][1] = 1;
        grid[1][0] = 1;
        grid[2][1] = 1;
        grid[2][2] = 1;
    }
};



#endif /* Z_BLOCK_H_ */
