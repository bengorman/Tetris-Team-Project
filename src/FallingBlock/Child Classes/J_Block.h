#ifndef J_BLOCK_H_
#define J_BLOCK_H_

#include "../FallingBlock.h"

class J_Block : public FallingBlock{

    /*

     | 0 1 0 |
     | 0 1 0 |
     | 1 1 0 |

     */

public:
    J_Block() : FallingBlock(3) { // Configure original position of block and create grid
        // Default position
        grid[0][1] = -2;
        grid[1][1] = -2;
        grid[2][1] = -2;
        grid[2][0] = -2;
    }
    short getType() {
        	return 2;
	}
    ~J_Block() {};
};



#endif /* J_BLOCK_H_ */
