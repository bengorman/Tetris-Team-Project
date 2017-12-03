/*
 * GameBoard.h
 *
 *  Created on: Dec 2, 2017
 *      Author: Mom and Dad
 */

#ifndef GAMEBOARD_GAMEBOARD_H_
#define GAMEBOARD_GAMEBOARD_H_

#include <iostream>
#include "FallingBlock.h"
using namespace std;

class GameBoard {
public:
	GameBoard();
	void updateBoard(FallingBlock currentFallingBlock);
	void collision(FallingBlock currentFallingBlock);
private:
	int** matrix;
};



#endif /* GAMEBOARD_GAMEBOARD_H_ */
