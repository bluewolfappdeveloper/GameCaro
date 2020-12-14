#include <iostream>
#include <conio.h>
#include <iomanip>

#include "console.h"

using namespace std;

void helpGame() {
	clrscr();
	for (int i = 4; i <= 25; i++) {
		gotoXY(40, i);
		cout << (char)179;
		Sleep(10);
	}
	gotoXY(40, 3);
	cout << (char)218;
	Sleep(100);
	for (int i = 41; i <= 89; i++) {
		gotoXY(i, 3);
		cout << (char)196;
		Sleep(10);
	}
	gotoXY(40, 25);
	cout << (char)192;
	gotoXY(40, 6);
	cout << (char)195;
	for (int i = 41; i <= 88; i++) {
		gotoXY(i, 6);
		cout << (char)196;
		Sleep(10);
	}
	for (int i = 41; i <= 88; i++) {
		gotoXY(i, 25);
		cout << (char)196;
		Sleep(10);
	}
	gotoXY(89, 3);
	cout << (char)191;
	gotoXY(89, 25);
	cout << (char)217;
	Sleep(25);
	gotoXY(89, 6);
	cout << (char)180;

	for (int i = 4; i <= 24; i++) {
		if (i == 6) continue;
		gotoXY(89, i);
		cout << (char)179;
		Sleep(10);
	}

	
	while (true) {
		if (_kbhit()) {
			int key = _getch();

			if (key == 27) {
				clrscr();
				system("color F0");
				return;
			}
		}
		ShowConsoleCursor(false);
		gotoXY(50, 4);
		cout << "\t========HELP========" << endl;
		gotoXY(46, 8);
		cout << "\t1. W/Top Key          : Move Top" << endl;
		gotoXY(46, 11);
		cout << "\t2. S/Bottom Key       : Move Bottom" << endl;
		gotoXY(46, 14);
		cout << "\t3. A/Left Key         : Move Left." << endl;
		gotoXY(46, 17);
		cout << "\t4. D/ Right Key       : Move Right" << endl;
		gotoXY(46, 20);
		cout << "\t5. Space/Enter        : Chose" << endl;
		gotoXY(46, 23);
		cout << "\t6. Esc                : Exit" << endl;
		cout << "\n";
		gotoXY(46, 28);
	}
	
}