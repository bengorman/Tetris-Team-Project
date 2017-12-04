#include "GameBoard.h"
#include "../FallingBlock/FallingBlock.h"
#include "../FallingBlock/Child Classes/I_Block.h"
#include "../FallingBlock/Child Classes/J_Block.h"
#include "../FallingBlock/Child Classes/L_Block.h"
#include "../FallingBlock/Child Classes/O_Block.h"
#include "../FallingBlock/Child Classes/S_Block.h"
#include "../FallingBlock/Child Classes/T_Block.h"
#include "../FallingBlock/Child Classes/Z_Block.h"
#include <cstdlib>
using namespace std;

#define BOARDWIDTH 10
#define BOARDHEIGHT 22


GameBoard::GameBoard() {
	//creates an empty board
	matrix = new int*[BOARDWIDTH];
	for(int i = 0; i < BOARDWIDTH; i++) {
		matrix[i] = new int[BOARDHEIGHT];
		for(int j = 0; j < BOARDHEIGHT; j++) {
			matrix[i][j] = 0;
		}
	}

	newFallingBlock(rand() % 7 + 1); //creates the first block
	createNext(); //creates the first nextBlock
	oldXCoordinate = currentFallingBlock->getXCoordinate();
	oldYCoordinate = currentFallingBlock->getYCoordinate();
	drawToMatrix();
}


void GameBoard::draw() {
	//TODO John Luzier
}


void GameBoard::createNext() {
	//TODO John Luzier
}


void GameBoard::updateScore(int height, short numFullRows) {
	//TODO John Luzier
}


void GameBoard::descend() {
	if(!bottomCollision()) {
		currentFallingBlock->setYCoordinate(currentFallingBlock->getYCoordinate() + 1); //increments location of fallingBlock downwards
		drawToMatrix();
	}
	else {
		land();
	}
	draw();
}


bool GameBoard::translateLeftCollision() {
	int** grid = currentFallingBlock->getGrid();
	if(currentFallingBlock->getXCoordinate() == 0) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][0] != 0) {
				return true;
			}
		}
	}
	else if(currentFallingBlock->getXCoordinate() == -1) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][0] != 0 || grid[i][1] != 0) {
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
	else if(myBlock->getXCoordinate() + myBlock->getSize() > 10) {
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
	for(int i = 0; i < myBlock->getSize(); i++) {
		for(int j = 0; j < myBlock->getSize(); j++) {
			if(grid[i][j] != 0) {
				if(matrix[myBlock->getYCoordinate() + i][myBlock->getXCoordinate() + j] != 0) {
					return true;
				}
			}
		}
	}
	return false;
}


void GameBoard::newFallingBlock(int rand) {
	if(currentFallingBlock != nullptr) {
		delete currentFallingBlock;
	}
	switch(rand) {
		case 1:
			currentFallingBlock = new I_Block();
			break;
		case 2:
			currentFallingBlock = new J_Block();
			break;
		case 3:
			currentFallingBlock = new L_Block();
			break;
		case 4:
			currentFallingBlock = new O_Block();
			break;
		case 5:
			currentFallingBlock = new S_Block();
			break;
		case 6:
			currentFallingBlock = new T_Block();
			break;
		case 7:
			currentFallingBlock = new Z_Block();
			break;
	}
	draw();
}


void GameBoard::land() {
	//include currentFallingBlock into bottom geometry
	int** grid = currentFallingBlock->getGrid();
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid[i][j] != 0) {
				matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + j] = grid[i][j];
			}
		}
	}
	draw();
	//counts rows to be deleted and deletes rows
	short numFullRows = 0;
	for(int i = BOARDHEIGHT - 1; i > 1; i--) {
		if(rowFull(i)) {
			numFullRows++;	//counts number of deleted rows
			for(int j = i; j > 1; j--) {	//deletes row and moves everything down
				for(int k = 0; k < BOARDWIDTH; k++) {
					matrix[j][k] = matrix[j - 1][k];
				}
			}
		}
	}
	updateScore(currentFallingBlock->getYCoordinate() + currentFallingBlock->getSize() - 1, numFullRows);
	newFallingBlock(nextBlock);
	createNext();
	swapped = false;	//resets swapped bool for new currentFallingBlock
	draw();
}


bool GameBoard::rowFull(int row) {
	for(int j = 0; j < BOARDWIDTH; j++) {
		if(matrix[row][j] == 0) {
			return false;
		}
	}
	return true;
}


void GameBoard::drawToMatrix() {
	int** grid = currentFallingBlock->getGrid();
	for(int i = oldYCoordinate; i < currentFallingBlock->getSize() + oldYCoordinate; i++) {
		for(int j = oldXCoordinate; j < currentFallingBlock->getSize() + oldXCoordinate; j++) {
			matrix[i][j] = 0;
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid[i][j] < 0) {
				matrix[currentFallingBlock->getYCoordinate + i][currentFallingBlock->getXCoordinate + j] = grid[i][j];
			}
		}
	}
}


void GameBoard::translateLeft() {
	if(!translateLeftCollision()) {
		oldXCoordinate = currentFallingBlock->getXCoordinate();
		currentFallingBlock->setXCoordinate(currentFallingBlock->getXCoordinate() - 1);
		drawToMatrix();
	}
	draw();
}


void GameBoard::translateRight() {
	if(!translateRightCollision()) {
		oldXCoordinate = currentFallingBlock->getXCoordinate();
		currentFallingBlock->setXCoordinate(currentFallingBlock->getXCoordinate() + 1);
		drawToMatrix();
	}
	draw();
}


void GameBoard::rotateCaller() {
	if(!rotateCollision()) {
		currentFallingBlock->rotate();
		drawToMatrix();
	}
	draw();
}


