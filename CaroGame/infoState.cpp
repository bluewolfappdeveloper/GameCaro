#include <iostream>
#include <iomanip>


#include "console.h"
#include "loginMain.h"

using namespace std;

void playNameInfo() {
	// viet chu win draw lose: Player 1
	TextColor(ColorCode_DarkBlue);
	gotoXY(95, 15);
	cout << getNamePlayer1();

	gotoXY(95, 17);
	cout << setw(4) << "Win" << setw(2) << ": " << getWinPlayer1();
	gotoXY(95, 18);
	cout << setw(4) << "Draw" << setw(2) << ": " << getDrawPlayer1();
	gotoXY(95, 19);
	cout << setw(4) << "Lose" << setw(2) << ": " << getLosePlayer1();

	// viet chu win draw lose: Player 2

	TextColor(ColorCode_DarkRed);
	gotoXY(118, 15);
	cout << getNamePlayer2();

	gotoXY(118, 17);
	cout << setw(4) << "Win" << setw(2) << ": " << getWinPlayer2();
	gotoXY(118, 18);
	cout << setw(4) << "Draw" << setw(2) << ": " << getDrawPlayer2();
	gotoXY(118, 19);
	cout << setw(4) << "Lose" << setw(2) << ": " << getLosePlayer2();

}

void drawx() {
	TextColor(ColorCode_DarkBlue);
	for (int i = 98; i <= 106; i++) {
		if (i >= 98 && i <= 100 || i >= 104 && i <= 106) {
			gotoXY(i, 9);
			cout << char(177);
			gotoXY(i, 13);
			cout << char(177);
		}
	}
	for (int i = 99; i <= 105; i++) {
		if (i >= 99 && i <= 101 || i >= 103 && i <= 105) {
			gotoXY(i, 10);
			cout << char(177);
			gotoXY(i, 12);
			cout << char(177);
		}
	}
	for (int i = 101; i <= 103; i++) {
		gotoXY(i, 11);
		cout << char(177);
	}
}

void drawo() {
	TextColor(ColorCode_DarkRed);
	for (int i = 123; i <= 125; i++) {
		gotoXY(i, 9);
		cout << char(177);
		gotoXY(i, 13);
		cout << char(177);
	}
	for (int i = 121; i <= 127; i++) {
		if (i >= 121 && i <= 123 || i >= 125 && i <= 127) {
			gotoXY(i, 10);
			cout << char(177);
			gotoXY(i, 12);
			cout << char(177);
		}
	}
	for (int i = 120; i <= 128; i++) {
		if (i >= 120 && i <= 122 || i >= 126 && i <= 128) {
			gotoXY(i, 11);
			cout << char(177);
		}
	}
}

void deletexo() {
	for (int i = 9; i <= 13; i++) {
		for (int j = 90; j <= 136; j++) {
			gotoXY(j, i);
			cout << char(255);
		}
	}
}

void drawInfoTable(int colorCode, bool isWinning) {
	TextColor(colorCode);
	// ve bang tren
	for (int i = 90; i <= 136; i++) {
		gotoXY(i, 0);
		cout << char(205);
		gotoXY(i, 8);
		cout << char(205);
	}
	for (int i = 0; i <= 8; i++) {
		gotoXY(90, i);
		cout << char(186);
		gotoXY(136, i);
		cout << char(186);
	}
	gotoXY(90, 0);
	cout << char(201);
	gotoXY(136, 0);
	cout << char(187);
	gotoXY(90, 8);
	cout << char(200);
	gotoXY(136, 8);
	cout << char(188);
	// ve 2 cai bang duoi
	for (int i = 93; i <= 111; ++i) {
		gotoXY(i, 14);
		cout << char(205);
		gotoXY(i, 16);
		cout << char(205);
		gotoXY(i, 20);
		cout << char(205);
		gotoXY(i + 23, 14);
		cout << char(205);
		gotoXY(i + 23, 16);
		cout << char(205);
		gotoXY(i + 23, 20);
		cout << char(205);
	}
	for (int i = 14; i <= 20; ++i) {
		gotoXY(93, i);
		cout << char(186);
		gotoXY(111, i);
		cout << char(186);
		gotoXY(93 + 23, i);
		cout << char(186);
		gotoXY(111 + 23, i);
		cout << char(186);
	}
	gotoXY(93, 14);
	cout << char(201);
	gotoXY(111, 14);
	cout << char(187);
	gotoXY(93, 20);
	cout << char(200);
	gotoXY(111, 20);
	cout << char(188);
	gotoXY(93 + 23, 14);
	cout << char(201);
	gotoXY(111 + 23, 14);
	cout << char(187);
	gotoXY(93 + 23, 20);
	cout << char(200);
	gotoXY(111 + 23, 20);
	cout << char(188);
	// ve chu CARO
	TextColor(ColorCode_DarkGreen);
	if (isWinning) {
		for (int i = 2; i <= 6; i++)
			for (int j = 99; j <= 127; j++) {
				gotoXY(j, i);
				cout << " ";
			}


		for (int i = 101; i <= 124; i++) {
			if (i >= 101 && i <= 103 || i >= 107 && i <= 109 || i >= 113 && i <= 117 || i >= 122 && i <= 124) {
				gotoXY(i, 1);
				cout << char(177);
			}
		}
		for (int i = 100; i <= 126; i++) {
			if (i >= 100 && i <= 102 || i == 106 || i == 107 || i == 109 || i == 110 || i == 113 || i == 114 || i == 116 || i == 117 || i >= 120 && i <= 122 || i >= 124 && i <= 126) {
				gotoXY(i, 2);
				cout << char(177);
			}
		}
		for (int i = 99; i <= 127; i++) {
			if (i >= 99 && i <= 101 || i >= 106 && i <= 110 || i >= 113 && i <= 116 || i >= 119 && i <= 121 || i >= 125 && i <= 127) {
				gotoXY(i, 3);
				cout << char(177);
			}
		}
		for (int i = 100; i <= 126; i++) {
			if (i >= 100 && i <= 102 || i >= 105 && i <= 107 || i >= 109 && i <= 111 || i == 113 || i == 114 || i == 116 || i == 117 || i >= 120 && i <= 122 || i >= 124 && i <= 126) {
				gotoXY(i, 4);
				cout << char(177);
			}
		}
		for (int i = 101; i <= 124; i++) {
			if (i >= 101 && i <= 103 || i >= 105 && i <= 107 || i >= 109 && i <= 111 || i == 113 || i == 114 || i == 116 || i == 117 || i >= 122 && i <= 124) {
				gotoXY(i, 5);
				cout << char(177);
			}
		}

	}
	else {
		for (int i = 101; i <= 124; i++) {
			if (i >= 101 && i <= 103 || i >= 107 && i <= 109 || i >= 113 && i <= 117 || i >= 122 && i <= 124) {
				gotoXY(i, 2);
				cout << char(177);
			}
		}
		for (int i = 100; i <= 126; i++) {
			if (i >= 100 && i <= 102 || i == 106 || i == 107 || i == 109 || i == 110 || i == 113 || i == 114 || i == 116 || i == 117 || i >= 120 && i <= 122 || i >= 124 && i <= 126) {
				gotoXY(i, 3);
				cout << char(177);
			}
		}
		for (int i = 99; i <= 127; i++) {
			if (i >= 99 && i <= 101 || i >= 106 && i <= 110 || i >= 113 && i <= 116 || i >= 119 && i <= 121 || i >= 125 && i <= 127) {
				gotoXY(i, 4);
				cout << char(177);
			}
		}
		for (int i = 100; i <= 126; i++) {
			if (i >= 100 && i <= 102 || i >= 105 && i <= 107 || i >= 109 && i <= 111 || i == 113 || i == 114 || i == 116 || i == 117 || i >= 120 && i <= 122 || i >= 124 && i <= 126) {
				gotoXY(i, 5);
				cout << char(177);
			}
		}
		for (int i = 101; i <= 124; i++) {
			if (i >= 101 && i <= 103 || i >= 105 && i <= 107 || i >= 109 && i <= 111 || i == 113 || i == 114 || i == 116 || i == 117 || i >= 122 && i <= 124) {
				gotoXY(i, 6);
				cout << char(177);
			}
		}
	}

	playNameInfo();

	if (colorCode != default_ColorCode) TextColor(colorCode);
}

void infoStateNotWin(bool isPlayer1) {
	if (isPlayer1) {
		deletexo();
		drawx();
	}
	else {
		deletexo();
		drawo();
	}
}

void infoStateWin(bool isPlayer1) {
	if (!isPlayer1) drawInfoTable(ColorCode_DarkRed, true);
	else drawInfoTable(ColorCode_DarkBlue, true);

	gotoXY(100, 7);
	if (isPlayer1) cout << getNamePlayer1() << " WINS";
	else cout << getNamePlayer2() << " WINS";
}

void infoStateDraw(bool isPlayer1) {
	
	gotoXY(100, 7);
	cout << "DRAW";
}

void mainInfoState(bool isPlayer1, int isWinning) {
	if (isWinning == 0) {
		if (isPlayer1) drawo(); else drawx();
	}
	else {
		if (isWinning > 0) infoStateWin(isPlayer1);
		else infoStateNotWin(isPlayer1);
	}
}

