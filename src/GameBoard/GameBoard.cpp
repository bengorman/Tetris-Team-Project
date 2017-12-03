#include "GameBoard.h"
#include "FallingBlock.h"
using namespace std;

#define BOARDWIDTH 10
#define BOARDHEIGHT 22


GameBoard::GameBoard() {
	matrix = new int*[BOARDWIDTH];
	for(int i = 0; i < BOARDWIDTH; i++) {
		matrix[i] = new int[BOARDHEIGHT];
		for(int j = 0; j < BOARDHEIGHT; j++) {
			matrix[i][j] = 0;
		}
	}
	currentFallingBlock = NULL;
}


void GameBoard::draw() {
	//TODO
}


void GameBoard::updateBoard() {
	//TODO
}


bool GameBoard::translateLeftCollision() {
	int** grid = currentFallingBlock->getGrid();
	int temp = currentFallingBlock->getXCoordinate() + currentFallingBlock->getSize();
	if(currentFallingBlock->getXCoordinate() == 0 || currentFallingBlock->getXCoordinate() == -1) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][0] != 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		if(matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() - 1] != 0) {
			return true;
		}
	}
	return false;
}


bool GameBoard::translateRightCollision() {
	int** grid = currentFallingBlock->getGrid();
	int temp = currentFallingBlock->getXCoordinate() + currentFallingBlock->getSize();
	if(temp == 10 || temp == 11 || temp == 13) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][currentFallingBlock->getSize() - 1] != 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		if(matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + currentFallingBlock->getSize()] != 0) {
			return true;
		}
	}
	return false;
}


bool GameBoard::bottomCollision() {
	int** grid2 = currentFallingBlock->getGrid();
	if(currentFallingBlock->getYCoordinate() + currentFallingBlock->getSize() > 21) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid2[currentFallingBlock->getSize()][j] != 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(matrix[currentFallingBlock->getXCoordinate() + i + 1][currentFallingBlock->getYCoordinate() + j] != 0) {
				return true;
			}
		}
	}
	return false;
}


bool GameBoard::rotateCollision() {
	FallingBlock* myBlock = currentFallingBlock;
	int** grid = myBlock->getGrid();
	myBlock->rotate();
	if(myBlock->getXCoordinate() == -1) {
		for(int i = 0; i < myBlock->getSize(); i++) {
			if(grid[i][0] != 0) {
				return true;
			}
		}
	}
	else if(myBlock->getXCoordinate + myBlock->getSize() > 10) {
		for(int i = 0; i < myBlock->getSize(); i++) {
			if(grid[i][myBlock->getSize() - 1] != 0) {
				return true;
			}
		}
	}
	else if(myBlock->getYCoordinate() + myBlock->getSize() > 21) {
		for(int j = 0; j < myBlock->getSize(); j++) {
			if(grid[myBlock->getSize()][j] != 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < myBlock->size(); i++) {
		for(int j = 0; j < myBlock->size(); j++) {
			if(grid[i][j] != 0) {
				if(matrix[myBlock->getYCoordinate + i][myBlock->getXCoordinate + j] != 0) {
					return true;
				}
			}
		}
	}
	return false;
}





