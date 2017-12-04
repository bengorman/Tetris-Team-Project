#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <iostream>
#include <cstdlib>
#include <exception>
#include <windows.h>
#include "../FallingBlock/FallingBlock.h"
#include "../Icon.h"
#include "../FallingBlock/Child Classes/I_Block.h"
#include "../FallingBlock/Child Classes/J_Block.h"
#include "../FallingBlock/Child Classes/L_Block.h"
#include "../FallingBlock/Child Classes/O_Block.h"
#include "../FallingBlock/Child Classes/S_Block.h"
#include "../FallingBlock/Child Classes/T_Block.h"
#include "../FallingBlock/Child Classes/Z_Block.h"
#include "../FallingBlock/Child Classes/U_Block.h"
#include "../FallingBlock/Child Classes/Y_Block.h"
#include "../FallingBlock/Child Classes/Plus_Block.h"
using namespace std;

class GameBoard {
public:
	GameBoard();
	void draw(); //draws the board
	void descend(); //moves currentFallingBlock down if possible. calls land() if it hits the bottom
	void updateScore(int height, short numFullRows); //increments score when a piece lands
	void swap(); //swaps the storedBlock with the currentFallingBlock
	void translateLeft();
	void translateRight();
	void rotateCW();
private:
	int** matrix; //stores all already fallen blocks
	FallingBlock* currentFallingBlock; //block being controlled
	short nextBlock; //identifies the shape of the next block
	short storedBlock; //identifies the shape of the stored block
	bool swapped; //bool if a swap has occurred (1 is allowed)
	short oldXCoordinate;
	short oldYCoordinate;
	Icon nextIcon;
	Icon storedIcon;
	unsigned int score;
	unsigned short lines;
	unsigned short level;
	void display(); //helper function to draw
	void drawToMatrix(); //draws the currentFallingBlock's coordinates on the matrix
	bool translateLeftCollision(); //checks to see if a left translation is possible
	bool translateRightCollision(); //checks to see if a right translation is possible
	bool rotateCollision(); //checks to see if a (clockwise) rotation is possible
	bool bottomCollision(); //checks to see if a downward translation is possible
	bool rowFull(int row); //checks to see if the row is full
	void land(); //includes currentFallingBlock into the bottom geometry, checks for full rows, deletes rows, and calls updateScore() with info
	void newFallingBlock(int rand); //creates a new currentFallingBlock from nextBlock
	void createNext(); //randomly creates the next nextBlock
	void display(int line);
	void updateOldCoordinates();
	HANDLE h;
};



#endif /* GAMEBOARD_GAMEBOARD_H_ */
