#include "GameBoard.h"
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#define BOARDWIDTH 10
#define BOARDHEIGHT 22


GameBoard::GameBoard(short dif) {
	srand(time(0));
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	//creates an empty board
	matrix = new int*[BOARDHEIGHT];
	for(int i = 0; i < BOARDHEIGHT; i++) {
		matrix[i] = new int[BOARDWIDTH];
		for(int j = 0; j < BOARDWIDTH; j++) {
			matrix[i][j] = 0;
		}
	}
	currentFallingBlock = nullptr;
	createNext(); //creates the first nextBlock
	swapped = false;
	storedBlock = 0;
	storedIcon.setType(0);
	score = 0;
	lines = 0;
	level = dif;
	newFallingBlock(rand() % 10 + 1); //creates the first block
	oldXCoordinate = currentFallingBlock->getXCoordinate();
	oldYCoordinate = currentFallingBlock->getYCoordinate();
	drawToMatrix();
}


void GameBoard::descend() {

	if(!bottomCollision()) {
		updateOldCoordinates();
		currentFallingBlock->setYCoordinate(currentFallingBlock->getYCoordinate() + 1); //increments location of fallingBlock downwards
		drawToMatrix();
	}
	else {
		land();
	}
	//draw();
}


void GameBoard::updateOldCoordinates() {
	oldXCoordinate = currentFallingBlock->getXCoordinate();
	oldYCoordinate = currentFallingBlock->getYCoordinate();
}


bool GameBoard::translateLeftCollision() {
	int** grid = currentFallingBlock->getGrid();
	cout << currentFallingBlock->getXCoordinate();
	if(currentFallingBlock->getXCoordinate() == 0) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][0] < 0) {
				cout << "returns true1";
				return true;
			}
		}
	}
	else if(currentFallingBlock->getXCoordinate() == -1) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][1] < 0) {
				return true;
			}
		}
	}
	else if(currentFallingBlock->getXCoordinate() == -2) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][2] < 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(currentFallingBlock->getXCoordinate() + j - 1 < 0) {
				continue;
			}
			else if(grid[i][j] != 0 && matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + j - 1] > 0) {
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
			if(currentFallingBlock->getXCoordinate() + j + 1 > 9) {
				continue;
			}
			else if(grid[i][j] != 0 && matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + j + 1] > 0) {
				return true;
			}
		}

	}
	return false;
}


bool GameBoard::bottomCollision() {
	int** grid = currentFallingBlock->getGrid();
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid[i][j] != 0 && currentFallingBlock->getYCoordinate() + i >= BOARDHEIGHT - 1) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid[i][j] != 0 && matrix[currentFallingBlock->getYCoordinate() + i + 1][currentFallingBlock->getXCoordinate() + j] > 0) {
				return true;
			}
		}
	}
	return false;
}


bool GameBoard::rotateCollision() {
	int** grid = currentFallingBlock->getGrid();
	int** newArr = new int*[currentFallingBlock->getSize()];
	for(int i = 0; i < currentFallingBlock->getSize(); i++)
		newArr[i] = new int[currentFallingBlock->getSize()];

	for(int i = 0; i < currentFallingBlock->getSize(); i++){
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			newArr[i][j] = grid[currentFallingBlock->getSize() - j - 1][i]; // Rotates each section 90 degress clockwise
			cout << newArr[i][j] << " ";
		}
		cout << endl;
	}

	grid = newArr;
	if(currentFallingBlock->getXCoordinate() == -1) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][0] != 0) {
				return true;
			}
		}
	}
	else if(currentFallingBlock->getXCoordinate() + currentFallingBlock->getSize() > 10) {
		for(int i = 0; i < currentFallingBlock->getSize(); i++) {
			if(grid[i][currentFallingBlock->getSize() - 1] != 0) {
				return true;
			}
		}
	}
	else if(currentFallingBlock->getYCoordinate() + currentFallingBlock->getSize() > 21) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid[currentFallingBlock->getSize()][j] != 0) {
				return true;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid[i][j] != 0) {
				if(matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + j] > 0) {
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
		case 8:
			currentFallingBlock = new U_Block();
			break;
		case 9:
			currentFallingBlock = new Y_Block();
			break;
		case 10:
			currentFallingBlock = new Plus_Block();
			break;
	}
	//draw();
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
	for(int i = 0; i < BOARDWIDTH; i++) {
		if(matrix[1][i] != 0) {
			throw "GAME OVER";
		}
	}
	updateScore(currentFallingBlock->getYCoordinate() + currentFallingBlock->getSize() - 1, numFullRows);
	newFallingBlock(nextBlock);
	createNext();
	swapped = false;	//resets swapped bool for new currentFallingBlock
	//draw();
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
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(oldXCoordinate + j > 9 || oldXCoordinate + j < 0) {
				continue;
			}
			else if(matrix[oldYCoordinate + i][oldXCoordinate + j] < 0) {
				matrix[oldYCoordinate + i][oldXCoordinate + j] = 0;
			}
		}
	}
	for(int i = 0; i < currentFallingBlock->getSize(); i++) {
		for(int j = 0; j < currentFallingBlock->getSize(); j++) {
			if(grid[i][j] < 0) {
				matrix[currentFallingBlock->getYCoordinate() + i][currentFallingBlock->getXCoordinate() + j] = grid[i][j];
			}
		}
	}
}


void GameBoard::translateLeft() {
	if(!translateLeftCollision()) {
		updateOldCoordinates();
		oldXCoordinate = currentFallingBlock->getXCoordinate();
		currentFallingBlock->setXCoordinate(currentFallingBlock->getXCoordinate() - 1);
		drawToMatrix();
	}
	//draw();
}


void GameBoard::translateRight() {
	if(!translateRightCollision()) {
		updateOldCoordinates();
		oldXCoordinate = currentFallingBlock->getXCoordinate();
		currentFallingBlock->setXCoordinate(currentFallingBlock->getXCoordinate() + 1);
		drawToMatrix();
	}
	//draw();
}


void GameBoard::rotateCW() {
	if(!rotateCollision()) {
		currentFallingBlock->rotate();
		drawToMatrix();
	}
}


void GameBoard::display(int line) //displays a line of the game board
{
	SetConsoleTextAttribute(h, 8);
	cout << "  ██";
	for(int i=0; i<10; i++)
	{
		if(matrix[line][i]==0)
		{
			cout << "  ";
		}
		else
		{
			SetConsoleTextAttribute(h, 8+abs(matrix[line][i]));
			printf("▓▓");

		}
	}
	SetConsoleTextAttribute(h, 8);
	printf("██");
	SetConsoleTextAttribute(h, 15);
}


void GameBoard::draw() //displays GUI
{
	system("cls"); //clears console
	cout << "                     ╔══════════╗\n";
	cout << "                     ║ Text-ris ║\n";
	cout << " ════════════════════╩══════════╩════════════════════\n";
	SetConsoleTextAttribute(h, 8);
	cout << "  ████████████████████████";
	SetConsoleTextAttribute(h, 15);
	cout << "   Score: " << score << "\n";
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
	cout << "  ║";
	cout << nextIcon.dispLine(0);
	printf("║ ║");
	cout << storedIcon.dispLine(0);
	printf("║\n");
	display(19);
	cout << "  ║";
	cout << nextIcon.dispLine(1);
	printf("║ ║");
	cout << storedIcon.dispLine(1);
	printf("║\n");
	display(20);
	cout << "  ║";
	cout << nextIcon.dispLine(2);
	printf("║ ║");
	cout<< storedIcon.dispLine(2);
	printf("║\n");
	display(21);
	cout << "  ║";
	cout << nextIcon.dispLine(3);
	printf("║ ║");
	cout << storedIcon.dispLine(3);
	printf("║\n");
	SetConsoleTextAttribute(h, 8);
	cout << "  ████████████████████████";
	SetConsoleTextAttribute(h, 15);
	cout << "  ╚════════╝ ╚════════╝\n";
	cout << " ══════════════════════════════════════════════════\n";
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
	nextBlock = rand() % 10 + 1; //picks a random piece
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
		throw "number must be between 0 and 4";
		break;
	}
}


void GameBoard::swap() { //swaps currentBlock with storedBlock
	if(swapped)
	{
		return;
	}
	updateOldCoordinates();
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
	drawToMatrix();
}



