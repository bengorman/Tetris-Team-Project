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

void scanInput(GameBoard *board)
{
    //cout << "\nScan Input runs\n";
    char key_code = ' ';

    //this_thread::sleep_for(chrono::seconds(2));

    while(key_code != 'q')
    {
        if(_kbhit())
        {
            key_code = _getch();

            if(key_code == PAUSEKEY)
            {
                cout << "\nPaused\n";
            }
            else if(key_code == SWAPKEY)
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
                board->descend();
            }

        }
        else
        {
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        board->draw();
    }
}

void descend(GameBoard *board)
{
    while(true)
    {
    	board->descend();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
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
