#ifndef O_BLOCK_H_
#define O_BLOCK_H_


class O_Block : public FallingBlock{

    /*

     | 1 1 |
     | 1 1 |

     */

public:
    O_Block() : FallingBlock(2 ){ // Configure original position of block and create grid
        // Default position
        grid[0][0] = 1;
        grid[0][1] = 1;
        grid[1][0] = 1;
        grid[1][1] = 1;
    }
    short getType() {
        	return 4;
	}
    ~O_Block() {};
};



#endif /* O_BLOCK_H_ */
