#ifndef FALLINGBLOCK_H_
#define FALLINGBLOCK_H_

#include <iostream>

using namespace std;

class FallingBlock{
    
protected:
	FallingBlock(int size);
    int **grid; // 2D grid
    int size; // Grid size
    int xCoordinate; //anchor coordinate for piece in top left space
    int yCoordinate; //anchor coordinate for piece in top left space
public:
    virtual ~FallingBlock();
    void rotate(); //rotates currentFallingBlock
    int** getGrid();
    int getSize();
    int getXCoordinate();
    int getYCoordinate();
    void setYCoordinate(int y);
    void setXCoordinate(int x);
    virtual short getType() = 0;
};

#endif /* FALLINGBLOCK_H_ */
