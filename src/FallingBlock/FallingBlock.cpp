#include "FallingBlock.h"
using namespace std;


FallingBlock::FallingBlock(int size) {
	this->size = size;
	xCoordinate = 0;
	yCoordinate = 0;
	// Creates space in grid
	grid = new int*[size];
	for(int i = 0; i < size; i++){
		grid[i] = new int[size];
	}

	// Sets everything to 0
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			grid[i][j] = 0;
		}
	}
}


void FallingBlock::rotate(){
	int** newArr = new int*[size];
	for(int i = 0; i < size; i++)
		newArr[i] = new int[size];

	int x = 0;
	for(int i = 0; i < getSize(); i++){
		for(int j = getSize()-1; j >= 0; j--) {
			newArr[i][x++] = getGrid()[j][i]; // Rotates each section 90 degress clockwise
		x = 0;
		}
	}

	grid = newArr;
}


int** FallingBlock::getGrid(){
	return grid;
}


int FallingBlock::getSize(){
	return size;
}


int FallingBlock::getXCoordinate() {
	return xCoordinate;
}


int FallingBlock::getYCoordinate() {
	return yCoordinate;
}
