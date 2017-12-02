/*
 * I_Block.h
 *
 *  Created on: Dec 2, 2017
 *      Author: Mom and Dad
 */

#ifndef I_BLOCK_H_
#define I_BLOCK_H_

#include "FallingBlock.h"

class I_Block : public FallingBlock{

    /*

     | 1 0 0 0 |
     | 1 0 0 0 |
     | 1 0 0 0 |
     | 1 0 0 0 |

     */

public:
    I_Block(){ // Configure original position of block and create grid

        size = 4; // 3 x 3
        createGrid(size);

        // Default position
        grid[0][0] = 1;
        grid[1][0] = 1;
        grid[2][0] = 1;
        grid[3][0] = 1;
    }
};



#endif /* I_BLOCK_H_ */
