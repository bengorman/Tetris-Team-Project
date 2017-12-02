/*
 * S_Block.h
 *
 *  Created on: Dec 2, 2017
 *      Author: Mom and Dad
 */

#ifndef S_BLOCK_H_
#define S_BLOCK_H_

#include "FallingBlock.h"

class S_Block : public FallingBlock{

    /*

     | 0 0 0 |
     | 0 1 1 |
     | 1 1 0 |

     */

public:
    S_Block(){ // Configure original position of block and create grid

        size = 3; // 3 x 3
        createGrid(size);

        // Default position
        grid[1][1] = 1;
        grid[1][2] = 1;
        grid[2][0] = 1;
        grid[2][1] = 1;
    }
};



#endif /* S_BLOCK_H_ */
