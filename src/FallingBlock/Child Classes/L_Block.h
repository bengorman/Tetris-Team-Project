#ifndef L_BLOCK_H_
#define L_BLOCK_H_

#include "FallingBlock.h"

class L_Block : public FallingBlock{

    /*

     | 1 0 0 |
     | 1 0 0 |
     | 1 1 0 |

     */

public:
    L_Block(){ // Configure original position of block and create grid

        size = 3; // 3 x 3
        createGrid(size);

        // Default position
        grid[0][0] = 1;
        grid[1][0] = 1;
        grid[2][0] = 1;
        grid[2][1] = 1;
    }
};



#endif /* L_BLOCK_H_ */
