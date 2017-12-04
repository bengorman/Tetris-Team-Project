#include <iostream>
#include <thread>
#include <conio.h>
#include <chrono>

//#include <Windows.h>
//#include "Controller.h"
#include "GameBoard/GameBoard.h"

#define LEFTKEY 'a'
#define RIGHTKEY 'd'
#define DOWNKEY 's'
#define ROTATEKEY 'w'
#define PAUSEKEY 'p'
#define SWAPKEY 'c'

using namespace std;

bool stillRunning = true;

void scanInput(GameBoard *board)
{
    //cout << "\nScan Input runs\n";
    char key_code = ' ';

    //this_thread::sleep_for(chrono::seconds(2));

    inputLoop:
    while(stillRunning)
    {
        if(_kbhit())
        {
            key_code = _getch();
            /*
            if(key_code == PAUSEKEY)
            {
                switch(pauseMenu()) {
					case 'p':
						break;
					case 'q':
						exit(0);
						break;
                }
            }
            */
            /*else */if(key_code == SWAPKEY)
            {
                board->swap();
            }
            else if(key_code == ROTATEKEY)
            {
                board->rotateCW();
            }
            else if(key_code == LEFTKEY)
            {
                board->translateLeft();
            }
            else if(key_code == RIGHTKEY)
            {
                board->translateRight();
            }
            else if(key_code == DOWNKEY)
            {
            	try {
            		board->descend();
            	}
                catch(...) {
                	cout << "GAME OVER";
                	stillRunning = false;

                }
            }

        }
        else
        {
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        board->draw();
    }
    //gameOver();
}

void descend(GameBoard *board)
{
	descendLoop:
    while(stillRunning)
    {
    	try {
			board->descend();
		}
		catch(...) {
			cout << "GAME OVER";
			stillRunning = false;
		}
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    while(!stillRunning) {}
    goto descendLoop;
}

int main()
{
	GameBoard *board = new GameBoard();

	thread fallThread(descend, board);
    thread keyThread(scanInput, board);

    fallThread.join();
    keyThread.join();

	return 0;
}
