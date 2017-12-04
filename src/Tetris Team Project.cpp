#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include "GameBoard/GameBoard.h"
using namespace std;

int main() {
	//_setmode(_fileno(stdout), _O_U16TEXT);



	cout <<"0" << endl;
	GameBoard myBoard;
	cout << "1" << endl;
	myBoard.draw();
	cout << "2" << endl;
	for(int i = 0; i < 19; i++) {
		myBoard.descend();
	}
	cout << "3" << endl;







	return 0;
}
