#ifndef FALLINGBLOCK_H_
#define FALLINGBLOCK_H_

#include <iostream>

using namespace std;

class FallingBlock{
    
protected:
    int **grid; // 2D grid
    int size; // Grid size
public:
    void rotate();
    void createGrid(int size);
    int** getGrid();
    int getSize();
};

#endif /* FALLINGBLOCK_H_ */
