#ifndef U_BLOCK_H_
#define U_BLOCK_H_


class U_Block : public FallingBlock{

    /*
     | 1 0 1 |
     | 1 1 1 |
     | 0 0 0 |
     */

public:
    U_Block() : FallingBlock(3) { // Configure original position of block and create grid
        // Default position
        grid[0][0] = -1;
        grid[0][2] = -1;
        grid[1][0] = -1;
        grid[1][1] = -1;
        grid[1][2] = -1;
    }
    short getType() {
        	return 8;
	}
    ~U_Block() {};
};



#endif /* U_BLOCK_H_ */
