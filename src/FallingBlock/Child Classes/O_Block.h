#ifndef O_BLOCK_H_
#define O_BLOCK_H_

#include "FallingBlock.h"

class O_Block : public FallingBlock{

    /*

     | 0 0 0 |
     | 1 1 0 |
     | 1 1 0 |

     */

public:
    O_Block(){ // Configure original position of block and create grid

        size = 3; // 3 x 3
        createGrid(size);

        // Default position
        grid[1][0] = 1;
        grid[1][1] = 1;
        grid[2][0] = 1;
        grid[2][1] = 1;
    }
};



#endif /* O_BLOCK_H_ */
