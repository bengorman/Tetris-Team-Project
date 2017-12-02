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
