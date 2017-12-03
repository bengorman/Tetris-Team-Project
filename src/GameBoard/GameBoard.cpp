#include "GameBoard.h"
using namespace std;


GameBoard::GameBoard() {
	matrix = new int*[10];
	for(int i = 0; i < 10; i++) {
		matrix[i] = new int[22];
	}
}


void GameBoard::updateBoard(FallingBlock currentFallingBlock) {
	//TODO
}


void GameBoard::collision(FallingBlock currentFallingBlock) {
	//TODO
}


