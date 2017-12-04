#ifndef S_BLOCK_H_
#define S_BLOCK_H_


class S_Block : public FallingBlock{

    /*

     | 0 0 0 |
     | 0 1 1 |
     | 1 1 0 |

     */

public:
    S_Block() : FallingBlock(3) { // Configure original position of block and create grid
        // Default position
        grid[1][1] = -5;
        grid[1][2] = -5;
        grid[2][0] = -5;
        grid[2][1] = -5;
    }
    short getType() {
        	return 5;
	}
    ~S_Block() {};
};



#endif /* S_BLOCK_H_ */
