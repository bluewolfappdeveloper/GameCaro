#include <iostream>
#include <conio.h>
#include <iomanip>

#include "console.h"

using namespace std;

void aboutGame() {
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
		cout << "============ ABOUT ============" << endl;
		gotoXY(46, 8);
		cout << "\tGV huong dan: Truong Toan Thinh" << endl;
		gotoXY(46, 11);
		cout << "\t1. Vo Nhat Tan "<<setw(20)<<"- 20127323" << endl;
		gotoXY(46, 14);
		cout << "\t2. Nguyen Phat Thinh " << setw(14) << "- 20127334" << endl;
		gotoXY(46, 17);
		cout << "\t3. Nguyen Sanh Tai " << setw(16) << "- 20127069" << endl;
		gotoXY(46, 20);
		cout << "\t4. Ngo Duc Bao " << setw(20) << "- 20127447" << endl;
		gotoXY(46, 23);
		cout << "\t5. Dinh Anh Quoc " << setw(18) << "- 20127302" << endl;
		gotoXY(46, 26);
	}

}