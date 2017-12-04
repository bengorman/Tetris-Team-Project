#ifndef Y_BLOCK_H_
#define Y_BLOCK_H_


class Y_Block : public FallingBlock{

    /*

     | 1 0 1 |
     | 0 1 0 |
     | 0 1 0 |

     */

public:
    Y_Block() : FallingBlock(3){ // Configure original position of block and create grid
        // Default position
        grid[0][0] = -2;
        grid[0][2] = -2;
        grid[1][1] = -2;
        grid[2][1] = -2;
    }
    short getType() {
        	return 9;
	}
    ~Y_Block() {};
};



#endif /* Y_BLOCK_H_ */
