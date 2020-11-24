#include <iostream>
#include <conio.h>

#include "console.h"
#include "table.h"
#include "caroBoardProcess.h"
#include "infoStage.h"

using namespace std;

void mainPlayGame(string path) {
	bool isExit = false;
	bool isPlayer1 = true;
	bool isWinning = false;

	if (!path.empty()) loadTable(path);
		else initTable();

	drawTable();

	mainInfoState(isPlayer1, false);
	gotoXY(0, 0);
	

	while (!isExit) {
		if (isWinning) {
			mainInfoState(isPlayer1, true);
		}
		else {
			moveCursorPosition(getCursorY(), getCursorX());
			if (_kbhit()) {
				int key = _getch();

				if (toupper(key) == 'W' || toupper(key) == 'S' || toupper(key) == 'A' || toupper(key) == 'D' || key == 13 || key == 32) {
					if (toupper(key) == 'W') //UP
						moveCursorPosition(getCursorY(), getCursorX(), UP);
					else if (toupper(key) == 'S') //DOWN
						moveCursorPosition(getCursorY(), getCursorX(), DOWN);
					else if (toupper(key) == 'A') //LEFT
						moveCursorPosition(getCursorY(), getCursorX(), LEFT);
					else if (toupper(key) == 'D') //RIGHT
						moveCursorPosition(getCursorY(), getCursorX(), RIGHT);
					if (key == 13 || key == 32) //Space
					{
						bool isChecked = true;
						if (isPlayer1) {
							// Player 1 check position 
							char k = 'x';
							isChecked = checkInTableByPos(getCursorY(), getCursorX(), toupper(k));
							isWinning = insertDataFromMatrix(getCursorY(), getCursorX(), isPlayer1);
						}
						else {
							// Player 2 check position 
							char k = 'o';
							isChecked = checkInTableByPos(getCursorY(), getCursorX(), toupper(k));
							isWinning = insertDataFromMatrix(getCursorY(), getCursorX(), isPlayer1 + 2);
						}

						if (!isWinning && isChecked) {
							isPlayer1 = !isPlayer1;

							int x = getCursorX();
							int y = getCursorY();

							mainInfoState(isPlayer1, false);
							
							gotoXY(x,y);
						}
					}

				}
				else
				{
					if (key == 0 || key == 0xE0) key = _getch();

					if (key == 72) //UP
						moveCursorPosition(getCursorY(), getCursorX(), UP);
					else if (key == 80) //DOWN
						moveCursorPosition(getCursorY(), getCursorX(), DOWN);
					else if (key == 75) //LEFT
						moveCursorPosition(getCursorY(), getCursorX(), LEFT);
					else if (key == 77) //RIGHT
						moveCursorPosition(getCursorY(), getCursorX(), RIGHT);
				}


			}
		}
	}
}

	