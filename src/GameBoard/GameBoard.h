#ifndef GAMEBOARD_GAMEBOARD_H_
#define GAMEBOARD_GAMEBOARD_H_

#include <iostream>
#include "FallingBlock.h"
using namespace std;

class GameBoard {
public:
	GameBoard();
	void draw();
	void updateBoard(FallingBlock currentFallingBlock);
	bool translateCollision(FallingBlock currentFallingBlock);
	bool rotateCollision(FallingBlock currentFallingBlock);
	bool bottomCollision(FallingBlock currentFallingBlock);
private:
	int** matrix;
};



#endif /* GAMEBOARD_GAMEBOARD_H_ */
