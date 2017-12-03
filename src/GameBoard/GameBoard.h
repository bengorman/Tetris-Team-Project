#ifndef GAMEBOARD_GAMEBOARD_H_
#define GAMEBOARD_GAMEBOARD_H_

#include <iostream>
#include "FallingBlock.h"
using namespace std;

class GameBoard {
public:
	GameBoard();
	void draw();
	void updateBoard();
	bool translateLeftCollision();
	bool translateRightCollision();
	bool rotateCollision();
	bool bottomCollision();
private:
	int** matrix;
	FallingBlock* currentFallingBlock;
};



#endif /* GAMEBOARD_GAMEBOARD_H_ */
