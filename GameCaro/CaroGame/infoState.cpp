#include <iostream>

#include "console.h"

using namespace std;

void drawx() {
	TextColor(ColorCode_DarkBlue);
	for (int i = 98;i <= 106; i++) {
		if (i >= 98 && i <= 100 || i >= 104 && i <= 106) {
			gotoXY(i, 8);
			cout << char(177);
			gotoXY(i, 12);
			cout << char(177);
		}
	}
	for (int i = 99;i <= 105; i++) {
		if (i >= 99 && i <= 101 || i >= 103 && i <= 105) {
			gotoXY(i, 9);
			cout << char(177);
			gotoXY(i, 11);
			cout << char(177);
		}
	}
	for (int i = 101;i <= 103; i++) {
		gotoXY(i, 10);
		cout << char(177);
	}
}

void drawo() {
	TextColor(ColorCode_DarkRed);
	for (int i = 123;i <= 125; i++) {
		gotoXY(i, 8);
		cout << char(177);
		gotoXY(i, 12);
		cout << char(177);
	}
	for (int i = 121;i <= 127; i++) {
		if (i >= 121 && i <= 123 || i >= 125 && i <= 127) {
			gotoXY(i, 9);
			cout << char(177);
			gotoXY(i, 11);
			cout << char(177);
		}
	}
	for (int i = 120;i <= 128; i++) {
		if (i >= 120 && i <= 122 || i >= 126 && i <= 128) {
			gotoXY(i, 10);
			cout << char(177);
		}
	}
}

void deletexo() {
	for (int i = 8; i <= 12; i++) {
		for (int j = 90; j <= 136; j++) {
			gotoXY(j, i);
			cout << char(255);
		}
	}
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
	gotoXY(90, 3);
	if (isPlayer1) cout << "Nguoi 1 danh chien thang";
	else cout << "Nguoi 2 danh chien thang";
}

void mainInfoState(bool isPlayer1, bool isWinning) {
	if (isWinning)  infoStateWin(isPlayer1);
	else infoStateNotWin(isPlayer1);

}


