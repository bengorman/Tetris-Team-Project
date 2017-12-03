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
	bool translateLeftWallCollision();
	bool translateRightWallCollision();
	bool rotateWallCollision();
	bool bottomWallCollision();
	bool translateRightGeometryCollision();
	bool translateLeftGeometryCollision();
	bool rotateGeometryCollision();
	bool bottomGeometryCollision();
private:
	int** matrix;
	FallingBlock* currentFallingBlock;
};



#endif /* GAMEBOARD_GAMEBOARD_H_ */
