#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>

#include "console.h"
#include "form.h"

using namespace std;

void setTitle(int colorCode) {

	TextColor(colorCode);

	int mid = getMaxScreenX/2 - 32;
	gotoXY(mid,0); cout << " _______  _______  _______  _______     _______  _______  _______  _______ " << endl;
	gotoXY(mid, 1); cout << "(  ____ \\(  ___  )(  ____ )(  ___  )   (  ____ \\(  ___  )(       )(  ____ \\" << endl;
	gotoXY(mid, 2); cout << "| (    \\/| (   ) || (    )|| (   ) |   | (    \\/| (   ) || () () || (    \\/" << endl;
	gotoXY(mid, 3); cout << "| |      | (___) || (____)|| |   | |   | |      | (___) || || || || (__    " << endl;
	gotoXY(mid, 4); cout << "| |      |  ___  ||     __)| |   | |   | | ____ |  ___  || |(_)| ||  __)   " << endl;
	gotoXY(mid, 5); cout << "| |      | (   ) || (\\ (   | |   | |   | | \\_  )| (   ) || |   | || (      " << endl;
	gotoXY(mid, 6); cout << "| (____/\\| )   ( || ) \\ \\__| (___) |   | (___) || )   ( || )   ( || (____/\\" << endl;
	gotoXY(mid, 7); cout << "(_______/|/     \\||/   \\__/(_______)   (_______)|/     \\||/     \\|(_______/" << endl;
	
	TextColor(default_ColorCode);

}

void setMenuSelect(int a) {
	if (a > 5 || a < 0) return;

	int col = getMaxScreenX / 2, row = 15;

	for (int i = 16; i <= 25; i +=2)
	{
		gotoXY(col, i); 
		TextColor(default_ColorCode);
		for (int j = 0; j <= 20;j++) cout << " ";
	}
	

	if (a == 0) {
		return;
	}


	gotoXY(col, ++row);
	if (a == 1) {
		TextColor(31);
		cout <<">> "<< "NEW GAME" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "NEW GAME";

	row++;

	gotoXY(col, ++row);
	if (a == 2) {
		TextColor(31);
		cout << ">> " << "LOAD GAME" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "LOAD GAME";

	row++;

	gotoXY(col, ++row);
	if (a == 3) {
		TextColor(31);
		cout << ">> " << "HELP" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "HELP";

	row++;

	gotoXY(col, ++row);
	if (a == 4) {
		TextColor(31);
		cout << ">> " << "ABOUT" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "ABOUT";

	row++;

	gotoXY(col, ++row);
	if (a == 5) {
		TextColor(31);
		cout << ">> " << "EXIT" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "EXIT";

}

void mainGame(string player1, string player2) {
	int selected = 1;
	
	
	setMenuSelect(selected);


	if (!player1.empty() && !player2.empty()) {
		int col = (getMaxScreenX / 2) - player1.length() + 4;// -((player1.length() + player2.length() + 4)) / 2 + 5;

		gotoXY(col, 11); TextColor(228);
		cout << player1 << " vs " << player2 << endl;
		TextColor(default_ColorCode);
	}
		//calculator center
		

	while (true) {
		ShowConsoleCursor(false);
		setTitle(ColorCode_DarkRed);

		
		if (_kbhit()) {
			int key = _getch();

			if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5') {
				selected = key - 48; 
				setMenuSelect(selected);
			}
			else {
				//Enter:13 and  Space:32
				if (key == 13 || key == 32) {
					// Do something

					switch (selected) {
						case 1:
							//New Game
							clrscr(); ShowConsoleCursor(true);
							mainPlayGame("");
							break;
						case 2:
							//Load Game

							break;
						case 3:
							//Help
							setMenuSelect(0);  ShowConsoleCursor(true);
							helpGame();
							setMenuSelect(3);
							break;
						case 4:
							//About

							break;
						case 5:
							//Exit

							break;
					}

				}
				else {
					if (key == 0 || key == 0xE0) key = _getch();

					if (key == 80) {
						//UP
						if (selected + 1 > 5) cout << (char)7;
						else {
							selected++;
							setMenuSelect(selected);
						}
					}
					else if (key == 72) {
						//DOWN
						if (selected - 1 < 1) cout << (char)7;
						else {
							selected--;
							setMenuSelect(selected);
						}
					} 
						
				}
			}
		}
		else {
			gotoXY(0, 0);
		}
	}

}