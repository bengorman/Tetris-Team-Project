#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <thread>
#include <Windows.h>

using namespace std;

class Controller
{
	private:
		Thread fallThread(GameBoard.descend());
		Thread keyThread(scanInput());

	public:
		Controller();
		char scanInput();	


};


#endif
