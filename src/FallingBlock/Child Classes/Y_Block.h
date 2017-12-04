#ifndef Z_BLOCK_H_
#define Z_BLOCK_H_


class Z_Block : public FallingBlock{

    /*

     | 1 0 1 |
     | 0 1 0 |
     | 0 1 0 |

     */

public:
    Z_Block() : FallingBlock(3){ // Configure original position of block and create grid
        // Default position
        grid[1][1] = -9;
        grid[1][0] = -9;
        grid[2][1] = -9;
        grid[2][2] = -9;
    }
    short getType() {
        	return 9;
	}
    ~Z_Block() {};
};



#endif /* Z_BLOCK_H_ */
