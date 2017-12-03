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
}


void GameBoard::updateBoard(FallingBlock myBlock) {
	//TODO
}


bool GameBoard::translateCollision(FallingBlock myBlock) {
	int** grid = myBlock.getGrid();
	int temp = myBlock.getXCoordinate() + myBlock.getSize();
	if(myBlock.getXCoordinate() == 0 || myBlock.getXCoordinate() == -1) {
		for(int i = 0; i < myBlock.getSize(); i++) {
			if(grid[i][0] != 0) {
				return false;
			}
		}
	}
	else if(temp == 10 || temp == 11 || temp == 13) {
		for(int i = 0; i < myBlock.getSize(); i++) {
			if(grid[i][myBlock.getSize() - 1] != 0) {
				return false;
			}
		}
	}
	return true;
}


bool GameBoard::rotateCollision(FallingBlock myBlock) {
	if(myBlock.getXCoordinate() == -1) {
		myBlock.rotate();
		for(int i = 0; i < myBlock.getSize(); i++) {
			if(myBlock.getGrid()[i][0] != 0) {
				return false;
			}
		}
	}
	else if(myBlock.getXCoordinate + myBlock.getSize() > 10) {
		myBlock.rotate();
		for(int i = 0; i < myBlock.getSize(); i++) {
			if(myBlock.getGrid[i][myBlock.getSize() - 1]) {
				return false;
			}
		}
	}
	return true;
}

