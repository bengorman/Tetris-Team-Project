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
	storedIcon = new Icon;
	nextIcon = new Icon;
	createNext(); //creates the first nextBlock
	swapped = false;
	oldXCoordinate = currentFallingBlock->getXCoordinate();
	oldYCoordinate = currentFallingBlock->getYCoordinate();
	drawToMatrix();
	storedBlock = 0;
	storedIcon.setType(0);
	score = 0;
	lines = 0;
	level = 0;
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
	else if(currentFallingBlock->getXCoordinate() == -2) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][0] != 0 || grid[i][2] != 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + j - 1] != 0) {
				return true;
			}
		}

	}
	return false;
}


bool GameBoard::translateRightCollision() {
	int** grid = currentFallingBlock->getGrid();
	int temp = currentFallingBlock->getXCoordinate() + currentFallingBlock->getSize();
	if(temp  == 10) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][currentFallingBlock->getSize() - 1] != 0) {
				return true;
			}
		}
	}
	else if(temp == 11) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][currentFallingBlock->getSize() - 2] != 0) {
				return true;
			}
		}
	}
	else if(temp == 12) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][currentFallingBlock->getSize() - 3] != 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + j + 1] > 0) {
				return true;
			}
		}
	}
	return false;
}


bool GameBoard::bottomCollision() {
	int** grid = currentFallingBlock->getGrid();
	if(currentFallingBlock->getYCoordinate() + currentFallingBlock->getSize() > 21) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid[currentFallingBlock->getSize()][j] != 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(matrix[currentFallingBlock->getYCoordinate() + i + 1][currentFallingBlock->getXCoordinate() + j] > 0) {
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
				if(matrix[myBlock->getYCoordinate() + i][myBlock->getXCoordinate() + j] > 0) {
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
			if(grid[i][j] < 0) {
				matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + j] = grid[i][j] * -1;
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


void GameBoard::rotateCW() {
	if(!rotateCollision()) {
		currentFallingBlock->rotate();
		drawToMatrix();
	}
	draw();
}


void GameBoard::display(int line) //displays a line of the game board
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 8);
	cout << " ██";
	short color;
	for(int i=0; i<10; i++)
	{
		if(matrix[line][i]==0)
		{
			cout << "  ";
		}
		else
		{
			SetConsoleTextAttribute(h, 8+abs(matrix[line][i]));
			cout << "▓▓";
		}
	}
	SetConsoleTextAttribute(h, 8);
	cout <<  "██";
	SetConsoleTextAttribute(h, 15);
}


void GameBoard::draw() //displays GUI
{
	system("cls"); //clears console
	cout << "                    ╔══════╗\n";
	cout << "                    ║Tetris║\n";
	cout << "════════════════════╩══════╩════════════════════";
	cout << " ████████████████████████   Score: " << score << "\n";
	display(2);
	cout << "\n";
	display(3);
	cout << "   Lines: " << lines << "\n";
	display(4);
	cout << "\n";
	display(5);
	cout << "   Level: " << level << "\n";
	display(6);
	cout << "\n";
	display(7);
	cout << "  ┌ Controls\n";
	display(8);
	cout << "  ├ A Move block left\n";
	display(9);
	cout << "  ├ D Move block right\n";
	display(10);
	cout << "  ├ S Drop block\n";
	display(11);
	cout << "  ├ W Rotate block\n";
	display(12);
	cout << "  ├ P Pause\n";
	display(13);
	cout << "  └ C Swap block\n";
	display(14);
	cout << "\n";
	display(15);
	cout << "  ╔════════╗ ╔════════╗\n";
	display(16);
	cout << "  ║  Next  ║ ║ Stored ║\n";
	display(17);
	cout << "  ╠════════╣ ╠════════╣\n";
	display(18);
	cout << "  ║" << nextIcon.dispLine(0) << "║ ║" << storedIcon.dispLine(0) << "║\n";
	display(19);
	cout << "  ║" << nextIcon.dispLine(1) << "║ ║" << storedIcon.dispLine(1) << "║\n";
	display(20);
	cout << "  ║" << nextIcon.dispLine(2) << "║ ║" << storedIcon.dispLine(2) << "║\n";
	display(21);
	cout << "  ║" << nextIcon.dispLine(3) << "║ ║" << storedIcon.dispLine(3) << "║\n";
	cout << " ████████████████████████  ╚════════╝ ╚════════╝\n";
	cout << "════════════════════════════════════════════════\n";
}


/* Block IDs
 1-I
 2-J
 3-L
 4-O
 5-S
 6-T
 7-Z
 */
void GameBoard::createNext() //generates next block to be used
{
	nextBlock = rand() % 7 + 1; //picks a random piece
	nextIcon.setType(nextBlock);
}


void GameBoard::updateScore(int fell, short rows) { //updates the score
	score += fell - 3; //increments score based on height fallen
	switch(rows) //increments score based on rows removed
	{
	case 0:
		break;
	case 1:
		score += 40 * (level+1);
		break;
	case 2:
		score += 100 * (level+1);
		break;
	case 3:
		score += 300 * (level+1);
		break;
	case 4:
		score += 1200 * (level+1);
		break;
	default:
		throw invalid_argument;
	}
}


void GameBoard::swap() { //swaps currentBlock with storedBlock
	if(swapped)
	{
		return;
	}
	short tempBlock = currentFallingBlock->getType();
	if(storedBlock != 0) {
		newFallingBlock(storedBlock);
	}
	else {
		newFallingBlock(nextBlock);
		createNext();
	}
	storedBlock = tempBlock;
	storedIcon.setType(storedBlock);
	swapped = true;
}



