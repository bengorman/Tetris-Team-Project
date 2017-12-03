#ifndef J_BLOCK_H_
#define J_BLOCK_H_

#include "FallingBlock.h"

class J_Block : public FallingBlock{

    /*

     | 0 1 0 |
     | 0 1 0 |
     | 1 1 0 |

     */

public:
    J_Block(){ // Configure original position of block and create grid

        size = 3; // 3 x 3

        // Default position
        grid[0][1] = 1;
        grid[1][1] = 1;
        grid[2][1] = 1;
        grid[2][0] = 1;
    }
};



#endif /* J_BLOCK_H_ */
