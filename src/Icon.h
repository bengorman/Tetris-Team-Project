#ifndef ICON_H_
#define ICON_H_

#include <iostream>
#include <cstdlib>
#include <exception>
#include <windows.h>

using namespace std;

struct Icon
{
private:
	string icon[4];
	short color;

public:
	string dispLine(short line)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);
		cout << icon[line];
		SetConsoleTextAttribute(h, 15);
		return "";
	}

	void setType(short type)
	{
		color = 8 + (type - 1) % 7 + 1;
		switch(type) //makes the icon the correct one
		{
		case 1:
			icon[0] = "   ▓▓   ";
			icon[1] = "   ▓▓   ";
			icon[2] = "   ▓▓   ";
			icon[3] = "   ▓▓   ";
			break;
		case 2:
			icon[0] = "        ";
			icon[1] = "    ▓▓  ";
			icon[2] = "    ▓▓  ";
			icon[3] = "  ▓▓▓▓  ";
			break;
		case 3:
			icon[0] = "        ";
			icon[1] = "  ▓▓    ";
			icon[2] = "  ▓▓    ";
			icon[3] = "  ▓▓▓▓  ";
			break;
		case 4:
			icon[0] = "        ";
			icon[1] = "  ▓▓▓▓  ";
			icon[2] = "  ▓▓▓▓  ";
			icon[3] = "        ";
			break;
		case 5:
			icon[0] = "        ";
			icon[1] = "   ▓▓▓▓ ";
			icon[2] = " ▓▓▓▓   ";
			icon[3] = "        ";
			break;
		case 6:
			icon[0] = "        ";
			icon[1] = "   ▓▓   ";
			icon[2] = " ▓▓▓▓▓▓ ";
			icon[3] = "        ";
			break;
		case 7:
			icon[0] = "        ";
			icon[1] = " ▓▓▓▓   ";
			icon[2] = "   ▓▓▓▓ ";
			icon[3] = "        ";
			break;
		case 8:
			icon[0] = "        ";
			icon[1] = " ▓▓  ▓▓ ";
			icon[2] = " ▓▓▓▓▓▓ ";
			icon[3] = "        ";
			break;
		case 9:
			icon[0] = "        ";
			icon[1] = " ▓▓  ▓▓ ";
			icon[2] = "   ▓▓   ";
			icon[3] = "   ▓▓   ";
			break;
		case 10:
			icon[0] = "        ";
			icon[1] = "   ▓▓   ";
			icon[2] = " ▓▓▓▓▓▓ ";
			icon[3] = "   ▓▓   ";
			break;
		default:
			icon[0] = "        ";
			icon[1] = "        ";
			icon[2] = "        ";
			icon[3] = "        ";
		}
	}
};



#endif /* ICON_H_ */
