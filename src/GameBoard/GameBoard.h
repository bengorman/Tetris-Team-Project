#ifndef GAMEBOARD_GAMEBOARD_H_
#define GAMEBOARD_GAMEBOARD_H_

#include <iostream>
#include "FallingBlock.h"
using namespace std;

class GameBoard {
public:
	GameBoard();
	void draw(); //draws the board
	void createNext(); //randomly creates the next nextBlock
	void descend(); //moves currentFallingBlock down if possible. calls land() if it hits the bottom
	bool translateLeftCollision(); //checks to see if a left translation is possible
	bool translateRightCollision(); //checks to see if a right translation is possible
	bool rotateCollision(); //checks to see if a (clockwise) rotation is possible
	bool bottomCollision(); //checks to see if a downward translation is possible
	void newFallingBlock(int rand); //creates a new currentFallingBlock from nextBlock
	void land(); //includes currentFallingBlock into the bottom geometry, checks for full rows, deletes rows, and calls updateScore() with info
	bool rowFull(int row); //checks to see if the row is full
	void updateScore(int height, short numFullRows); //increments score when a piece lands
	void swap(); //swaps the storedBlock with the currentFallingBlock
private:
	int** matrix; //stores all already fallen blocks
	FallingBlock* currentFallingBlock; //block being controlled
	short nextBlock; //identifies the shape of the next block
	short storedBlock; //identifies the shape of the stored block
	bool swapped; //bool if a swap has occurred (1 is allowed)
};



#endif /* GAMEBOARD_GAMEBOARD_H_ */
