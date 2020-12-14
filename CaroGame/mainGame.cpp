#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <direct.h> // _getcwd

#include "console.h"
#include "loginMain.h"
#include "form.h"

using namespace std;

void C(int t)
{
	for (int i = 1; i <= t; i++) cout << (char)219;
}

void C1(int t)
{
	for (int i = 1; i <= t; i++) cout << " ";
}

void setTitle(int colorCode) {
	//TextColor(colorCode);
	//int mid = getMaxScreenX/2 - 32;
	//gotoXY(mid,0); cout << " _______  _______  _______  _______     _______  _______  _______  _______ " << endl;
	//gotoXY(mid, 1); cout << "(  ____ \\(  ___  )(  ____ )(  ___  )   (  ____ \\(  ___  )(       )(  ____ \\" << endl;
	//gotoXY(mid, 2); cout << "| (    \\/| (   ) || (    )|| (   ) |   | (    \\/| (   ) || () () || (    \\/" << endl;
	//gotoXY(mid, 3); cout << "| |      | (___) || (____)|| |   | |   | |      | (___) || || || || (__    " << endl;
	//gotoXY(mid, 4); cout << "| |      |  ___  ||     __)| |   | |   | | ____ |  ___  || |(_)| ||  __)   " << endl;
	//gotoXY(mid, 5); cout << "| |      | (   ) || (\\ (   | |   | |   | | \\_  )| (   ) || |   | || (      " << endl;
	//gotoXY(mid, 6); cout << "| (____/\\| )   ( || ) \\ \\__| (___) |   | (___) || )   ( || )   ( || (____/\\" << endl;
	//gotoXY(mid, 7); cout << "(_______/|/     \\||/   \\__/(_______)   (_______)|/     \\||/     \\|(_______/" << endl;
	//TextColor(default_ColorCode);
	
	TextColor(colorCode);
	int mid = getMaxScreenX / 2 - 30;
	gotoXY(mid, 1);
	C1(2), C(6), C1(2), C(5), C1(2), C(6), C1(3), C(6), C1(8), C(6), C1(3), C(5), C1(2), C(3), C1(4), C(3), C1(1), C(7);
	cout << endl;
	gotoXY(mid, 2);
	C(3), C1(6), C(2), C1(3), C(2), C1(1), C(2), C1(3), C(2), C1(1), C(2), C1(4), C(2), C1(6), C(2), C1(7), C(2), C1(3), C(2), C1(1), C(4), C1(2), C(4), C1(1), C(2);
	cout << endl;
	gotoXY(mid, 3);
	C(3), C1(6), C(7), C1(1), C(6), C1(2), C(2), C1(4), C(2), C1(6), C(2), C1(3), C(3), C1(1), C(7), C1(1), C(2), C1(1), C(4), C1(1), C(2), C1(1), C(5);
	cout << endl;
	gotoXY(mid, 4);
	C(3), C1(6), C(2), C1(3), C(2), C1(1), C(2), C1(3), C(2), C1(1), C(2), C1(4), C(2), C1(6), C(2), C1(4), C(2), C1(1), C(2), C1(3), C(2), C1(1), C(2), C1(2), C(2), C1(2), C(2), C1(1), C(2);
	cout << endl;
	gotoXY(mid, 5);
	C1(2), C(6), C1(1), C(2), C1(3), C(2), C1(1), C(2), C1(3), C(2), C1(2), C(6), C1(8), C(6), C1(2), C(2), C1(3), C(2), C1(1), C(2), C1(6), C(2), C1(1), C(7);
	TextColor(default_ColorCode);
}

void setTitle(int colorCode1, int colorCode2) {
	TextColor(colorCode1);
	int mid = getMaxScreenX / 2 - 30;
	gotoXY(mid, 1); TextColor(colorCode1);
	C1(2), C(6), C1(2), C(5), C1(2), C(6), C1(3), C(6), C1(8), TextColor(colorCode2), C(6), C1(3), C(5), C1(2), C(3), C1(4), C(3), C1(1), C(7);
	cout << endl;
	gotoXY(mid, 2); TextColor(colorCode1);
	C(3), C1(6), C(2), C1(3), C(2), C1(1), C(2), C1(3), C(2), C1(1), C(2), C1(4), C(2), C1(6), TextColor(colorCode2), C(2), C1(7), C(2), C1(3), C(2), C1(1), C(4), C1(2), C(4), C1(1), C(2);
	cout << endl;
	gotoXY(mid, 3); TextColor(colorCode1);
	C(3), C1(6), C(7), C1(1), C(6), C1(2), C(2), C1(4), C(2), C1(6), TextColor(colorCode2), C(2), C1(3), C(3), C1(1), C(7), C1(1), C(2), C1(1), C(4), C1(1), C(2), C1(1), C(5);
	cout << endl;
	gotoXY(mid, 4); TextColor(colorCode1);
	C(3), C1(6), C(2), C1(3), C(2), C1(1), C(2), C1(3), C(2), C1(1), C(2), C1(4), C(2), C1(6), TextColor(colorCode2), C(2), C1(4), C(2), C1(1), C(2), C1(3), C(2), C1(1), C(2), C1(2), C(2), C1(2), C(2), C1(1), C(2);
	cout << endl;
	gotoXY(mid, 5); TextColor(colorCode1);
	C1(2), C(6), C1(1), C(2), C1(3), C(2), C1(1), C(2), C1(3), C(2), C1(2), C(6), C1(8), TextColor(colorCode2), C(6), C1(2), C(2), C1(3), C(2), C1(1), C(2), C1(6), C(2), C1(1), C(7);
	TextColor(default_ColorCode);
}

inline bool existsFile(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

void setMenuSelect(int a, bool isFile = true) {
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
		if (isFile) TextColor(31); else TextColor(248);
		cout << ">> " << "LOAD GAME" << " <<";
		TextColor(default_ColorCode);
	}
	else {
		if (!isFile)  TextColor(248);
		cout << "LOAD GAME";
		TextColor(default_ColorCode);
	}

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

string upcaseString(string a) {
	for (int i = 0; i < a.length(); i++)
		a[i] = toupper(a[i]);
	return a;
}

void showMainNamePlayer(string player1, string player2) {
	if (!player1.empty() && !player2.empty()) {
		int col = (getMaxScreenX / 2) - player1.length() + 1;// -((player1.length() + player2.length() + 4)) / 2 + 5;

		gotoXY(col, 11); 
		TextColor(225); cout << "  " << upcaseString(player1) << " ";
		TextColor(237); cout << " vs "; 
		TextColor(228); cout <<" " << upcaseString(player2) << "  " << endl;
		TextColor(default_ColorCode);
	}
}

void mainGame(string player1, string player2) {
	int selected = 1;
	
	string nameFile = formatString(getNamePlayer1()) + "_" + formatString(getNamePlayer2()) + ".txt";
	string addressFile = _getcwd(NULL, 0) + (string)"\\" + nameFile;
	
	setMenuSelect(selected, existsFile(addressFile));

	showMainNamePlayer(player1, player2);


	while (true) {
		ShowConsoleCursor(false);

		setTitle(ColorCode_DarkBlue, ColorCode_DarkRed);
		
		if (_kbhit()) {
			int key = _getch();
			
			if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5') {
				selected = key - 48; 
				if (selected == 2 && !existsFile(addressFile)) {
					setMenuSelect(selected, false);
				}
				else setMenuSelect(selected);
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
							clrscr(); ShowConsoleCursor(true);
							mainPlayGame(nameFile);
							break;
						case 3:
							//Help
							system("color F0");
							setMenuSelect(0);  ShowConsoleCursor(true);
							helpGame();
							setMenuSelect(3 , existsFile(addressFile)); showMainNamePlayer(player1, player2);
							break;
						case 4:
							//About
							system("color F0");
							setMenuSelect(0);  ShowConsoleCursor(true);
							aboutGame();
							setMenuSelect(4, existsFile(addressFile)); showMainNamePlayer(player1, player2);
							break;
						case 5:
							//Exit
							system("color F0");
							setMenuSelect(0);  ShowConsoleCursor(true);
							clrscr();
							exit(0);
							break;
					}

				}
				else {
					if (key == 0 || key == 0xE0) key = _getch();

					if (key == 80) {
						//DOWN
						if (selected + 1 > 5) {
							selected = 1;
							setMenuSelect(selected, false);
						}
						else {
							if (!existsFile(addressFile)) {
								if (selected + 1 == 2)
								{
									selected += 2;
									setMenuSelect(selected, false);
								}
								else {
									selected++;
									setMenuSelect(selected, false);
								}
							}
							else {
								selected++;
								setMenuSelect(selected);
							}
						}
					}
					else if (key == 72) {
						//UP
						if (selected - 1 < 1) {
							selected = 5;
							setMenuSelect(selected, false);
						}
						else {
							if (!existsFile(addressFile)) {
								if (selected - 1 == 2)
								{
									selected -= 2;
									setMenuSelect(selected, false);
								}
								else {
									selected--;
									setMenuSelect(selected, false);
								}
							}
							else {
								selected--;
								setMenuSelect(selected);
							}
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
