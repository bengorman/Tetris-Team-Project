#ifndef I_BLOCK_H_
#define I_BLOCK_H_



class I_Block : public FallingBlock{

    /*

     | 0 1 0 0 |
     | 0 1 0 0 |
     | 0 1 0 0 |
     | 0 1 0 0 |

     */

public:
    I_Block() : FallingBlock(4) { // Configure original position of block and create grid
        // Default position
        grid[0][1] = -1;
        grid[1][1] = -1;
        grid[2][1] = -1;
        grid[3][1] = -1;
    }
    short getType() {
    	return 1;
    }
    ~I_Block() {};
};



#endif /* I_BLOCK_H_ */
