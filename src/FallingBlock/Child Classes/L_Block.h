#ifndef L_BLOCK_H_
#define L_BLOCK_H_


class L_Block : public FallingBlock{

    /*

     | 0 1 0 |
     | 0 1 0 |
     | 0 1 1 |

     */

public:
    L_Block() : FallingBlock(3) { // Configure original position of block and create grid
        // Default position
        grid[0][1] = 1;
        grid[1][1] = 1;
        grid[2][1] = 1;
        grid[2][2] = 1;
    }
    short getType() {
        	return 3;
	}
    ~L_Block() {};
};



#endif /* L_BLOCK_H_ */
