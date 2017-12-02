<<<<<<< HEAD
/*
 * Z_Block.h
 *
 *  Created on: Dec 2, 2017
 *      Author: Mom and Dad
 */

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
    Z_Block(){ // Configure original position of block and create grid

        size = 3; // 3 x 3
        createGrid(size);

        // Default position
        grid[1][1] = 1;
        grid[1][0] = 1;
        grid[2][1] = 1;
        grid[2][2] = 1;
    }
};



#endif /* Z_BLOCK_H_ */
=======
/*
 * Z_Block.h
 *
 *  Created on: Dec 2, 2017
 *      Author: Mom and Dad
 */

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
    Z_Block(){ // Configure original position of block and create grid

        size = 3; // 3 x 3
        createGrid(size);

        // Default position
        grid[1][1] = 1;
        grid[1][0] = 1;
        grid[2][1] = 1;
        grid[2][2] = 1;
    }
};



#endif /* Z_BLOCK_H_ */
>>>>>>> c4b337b46c1c96da747cbb812da91caee21b9625
