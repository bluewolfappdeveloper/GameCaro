#include <iostream>

#include "data.h"

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
	TextColor(colorCode);
	int mid = getMaxScreenX / 2 - 32;
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

	/*MauChu1
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
	*/
}