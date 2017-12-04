#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

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
