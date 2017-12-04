#ifndef T_BLOCK_H_
#define T_BLOCK_H_


class T_Block : public FallingBlock{

    /*

     | 0 1 0 |
     | 1 1 1 |
     | 0 0 0 |

     */

public:
    T_Block() : FallingBlock(3) { // Configure original position of block and create grid
        // Default position
        grid[0][1] = -6;
        grid[1][0] = -6;
        grid[1][1] = -6;
        grid[1][2] = -6;
    }
    short getType() {
        	return 6;
	}
    ~T_Block() {};
};



#endif /* T_BLOCK_H_ */
