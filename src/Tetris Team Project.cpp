#include <iostream>
#include <thread>
#include <conio.h>
#include <chrono>
#include <cmath>

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


char pauseMenu() //draws pause menu
{
	system("cls"); //clears console
	cout << "                ╔══════════════╗\n";
	cout << "                ║    Paused    ║\n";
	cout << "                ╠══════════════╣\n";
	cout << "                ║  P - Resume  ║\n";
	//cout << "                ║ N - New Game ║\n";
	cout << "                ║   Q - Quit   ║\n";
	cout << "                ╚══════════════╝\n";

	while(true)
	{
		switch(tolower(getch()))
		{
		case 'p':
			return 'p';
		/*case 'n':
			return 'n';*/
		case 'q':
			return 'q';
		}
	}
}

short startMenu()
{
	short diff = 0;

	wait:
	system("cls"); //clears console
	cout << "        ╔══════════════════════════════╗\n";
	cout << "        ║           Text-ris           ║\n";
	cout << "        ╠══════════════════════════════╣\n";
	printf("        ║    Current Difficulty:  %u    ║\n", diff);
	cout << "        ║ Press D to Change Difficulty ║\n";
	cout << "        ║       Press B to Begin       ║\n";
	cout << "        ╚══════════════════════════════╝\n";

	switch(tolower(getch()))
	{
	case 'd':
		goto choose;
	case 'b':
		return diff;
	default:
		goto wait;
	}

	choose:
	system("cls"); //clears console
	cout << "        ╔══════════════════════════════╗\n";
	cout << "        ║           Text-ris           ║\n";
	cout << "        ╠══════════════════════════════╣\n";
	printf("        ║    Current Difficulty:  %u    ║\n", diff);
	cout << "        ║  Enter New Difficulty (0-9)  ║\n";
	cout << "        ║    ~~~~~~~~~~~~~~~~~~~~~~    ║\n";
	cout << "        ╚══════════════════════════════╝\n";

	check:
	switch(getch())
	{
	case 48:
		diff = 0;
		goto wait;
	case 49:
		diff = 1;
		goto wait;
	case 50:
		diff = 2;
		goto wait;
	case 51:
		diff = 3;
		goto wait;
	case 52:
		diff = 4;
		goto wait;
	case 53:
		diff = 5;
		goto wait;
	case 54:
		diff = 6;
		goto wait;
	case 55:
		diff = 7;
		goto wait;
	case 56:
		diff = 8;
		goto wait;
	case 57:
		diff = 9;
		goto wait;
	default:
		goto dumb;
	}

	dumb:
	system("cls"); //clears console
	cout << "        ╔══════════════════════════════╗\n";
	cout << "        ║           Text-ris           ║\n";
	cout << "        ╠══════════════════════════════╣\n";
	printf("        ║    Current Difficulty:  %u    ║\n", diff);
	cout << "        ║  Enter New Difficulty (0-9)  ║\n";
	cout << "        ║    -- BETWEEN 0 AND 9! --    ║\n";
	cout << "        ╚══════════════════════════════╝\n";

	goto check;
	return -1;
}

void gameOver()
{
	system("cls");
	cout << "          ╔═══════════════╗\n";
	cout << "          ║   GAME OVER   ║\n";
	cout << "          ╠═══════════════╣\n";
	cout << "          ║ Press Any Key ║\n";
	cout << "          ║    To Quit    ║\n";
	cout << "          ╚═══════════════╝\n";

	getch();
}


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
    gameOver();
    exit(0);
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
        this_thread::sleep_for(chrono::milliseconds((int)(750 / pow(1.1, board->level) + 250)));
    }
    while(!stillRunning) {}
    goto descendLoop;
}

int main()
{
	GameBoard *board = new GameBoard(startMenu());

	thread fallThread(descend, board);
    thread keyThread(scanInput, board);

    fallThread.join();
    keyThread.join();

	return 0;
}
