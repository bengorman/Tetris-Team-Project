#ifndef Plus_BLOCK_H_
#define Plus_BLOCK_H_


class Plus_Block : public FallingBlock{

    /*
     | 0 1 0 |
     | 1 1 1 |
     | 0 1 0 |
     */

public:
    Plus_Block() : FallingBlock(3) { // Configure original position of block and create grid
        // Default position
        grid[0][1] = -3;
        grid[1][0] = -3;
        grid[1][1] = -3;
        grid[1][2] = -3;
        grid[2][1] = -3;
    }
    short getType() {
        	return 8;
	}
    ~Plus_Block() {};
};



#endif /* Plus_BLOCK_H_ */
