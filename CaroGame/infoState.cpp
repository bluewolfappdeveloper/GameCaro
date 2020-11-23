#include <iostream>

#include "console.h"

using namespace std;

void infoStateNotWin(bool isPlayer1) {
	gotoXY(90, 3);
	if (isPlayer1) cout << "Den luot nguoi 1";
	else cout << "Den luot nguoi 2";
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
