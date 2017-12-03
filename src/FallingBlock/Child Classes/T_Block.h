#ifndef T_BLOCK_H_
#define T_BLOCK_H_

#include "FallingBlock.h"

class T_Block : public FallingBlock{

    /*

     | 0 1 0 |
     | 1 1 1 |
     | 0 0 0 |

     */

public:
    T_Block() : FallingBlock(3) { // Configure original position of block and create grid
        // Default position
        grid[0][1] = 1;
        grid[1][0] = 1;
        grid[1][1] = 1;
        grid[1][2] = 1;
    }
    short getType() {
        	return 6;
	}
};



#endif /* T_BLOCK_H_ */
