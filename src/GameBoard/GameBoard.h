#ifndef GAMEBOARD_GAMEBOARD_H_
#define GAMEBOARD_GAMEBOARD_H_

#include <iostream>
#include "FallingBlock.h"
using namespace std;

class GameBoard {
public:
	GameBoard();
	void draw();
	void createNext();
	void descend();
	bool translateLeftCollision();
	bool translateRightCollision();
	bool rotateCollision();
	bool bottomCollision();
	void newFallingBlock(int rand);
private:
	int** matrix;
	FallingBlock* currentFallingBlock;
	int nextFallingBlock;
};



#endif /* GAMEBOARD_GAMEBOARD_H_ */
