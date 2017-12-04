#include "Controller.h"

#define LEFTKEY 'a'
#define RIGHTKEY 'd'
#define DOWNKEY 's'
#define ROTATEKEY 'w'
#define PAUSEKEY 'p'
#define SWAPKEY 'c'


Controller::Controller()
{
	//construct GameBoard
	//start Thread
	

}

char Controller::scanInput()
{
	if(GetKeyState(LEFTKEY) & 0x8000)
	{
   		cout << "\nMove Left"; 
	}
	else if(GetKeyState(RIGHTKEY) & 0x8000)
	{
      		cout << "\nMove Right";
	}
	else if(GetKeyState(DOWNKEY) & 0x8000)
	{
      		cout << "\nMove Down";
	}
	else if(GetKeyState(ROTATEKEY) & 0x8000)
	{
   		cout << "\nRotate";
	}
	else if(GetKeyState(PAUSEKEY) & 0x8000)
	{
	      	cout << "\nPaused";
	}
	else if(GetKeyState(PAUSEKEY) & 0x8000)
	{
      		cout << "\nMove Down";		
	}
}
