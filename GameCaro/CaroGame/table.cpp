#include <iostream>
#include "console.h"
#include "caroBoardProcess.h"

using namespace std;

int rowBoard, columnBoard;
static char boardMatrix[500][500];

static enum Direction { UP, DOWN, LEFT, RIGHT };

void drawRow(int line, char kyTuDau, char kiTu, char kyTuGiua, char kyTuCuoi,  int width, int distance) {

	boardMatrix[line][0] = char(kyTuDau);
	int d = 2; int k = 0;

	while (d < distance ) {
		for (int i = 1; i <= width; i++)
		{
			k++; d++;
			boardMatrix[line][k] = char(kiTu);
		}
		k++; d++;
		if (d >= distance) boardMatrix[line][k] = char(kyTuCuoi) ; else boardMatrix[line][k] = char(kyTuGiua);
	}

	
}

void initTable() {
	initCaroBoard();

	int w = 1, h;

	int rateTableX = (getMaxScreenX * 3) / 4;
	int rateTableY = (getMaxScreenY * 1) / 1;

	int distanceX = columnBoard = 89;
	int distanceY = rowBoard = 28;


	drawRow(0, char(201), char(205), char(209), char(187), 3, distanceX);

	for (int i = 1; i < distanceY; i++) {
		if (i % 2 == 0) {
			drawRow(i, char(199), char(196), char(197), char(182), 3, distanceX);
		}
		else {
			drawRow(i, char(186), ' ', char(179), char(186), 3, distanceX);
		}
	}

	drawRow(rowBoard++, char(200), char(205), char(207), char(188), 3, distanceX);

}

void loadTable(string path) {

}

void drawTable() {
	for (int i = 0; i < rowBoard; i++) {
		for (int j = 0; j < columnBoard; j++)
			cout << boardMatrix[i][j];
		cout << endl;
	}	
	// ve bang tren
	for (int i = 90; i <= 136; i++) {
		gotoXY(i, 0);
		cout << char(205);
		gotoXY(i, 7);
		cout << char(205);
	}
	for (int i = 0; i <= 7; i++) {
		gotoXY(90, i);
		cout << char(186);
		gotoXY(136, i);
		cout << char(186);
	}
	gotoXY(90, 0);
	cout << char(201);
	gotoXY(136, 0);
	cout << char(187);
	gotoXY(90, 7);
	cout << char(200);
	gotoXY(136, 7);
	cout << char(188);
	// ve 2 cai bang duoi
	for (int i = 93; i <= 111; ++i) {
		gotoXY(i, 13);
		cout << char(205);
		gotoXY(i, 20);
		cout << char(205);
		gotoXY(i + 23, 13);
		cout << char(205);
		gotoXY(i + 23, 20);
		cout << char(205);
	}
	for (int i = 13; i <= 20; ++i) {
		gotoXY(93, i);
		cout << char(186);
		gotoXY(111, i);
		cout << char(186);
		gotoXY(93 + 23, i);
		cout << char(186);
		gotoXY(111 + 23, i);
		cout << char(186);
	}
	gotoXY(93, 13);
	cout << char(201);
	gotoXY(111, 13);
	cout << char(187);
	gotoXY(93, 20);
	cout << char(200);
	gotoXY(111, 20);
	cout << char(188);
	gotoXY(93 + 23, 13);
	cout << char(201);
	gotoXY(111 + 23, 13);
	cout << char(187);
	gotoXY(93 + 23, 20);
	cout << char(200);
	gotoXY(111 + 23, 20);
	cout << char(188);
	// ve chu CARO
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

bool checkInTableByPos(int row, int column, char k) {
	// Colum 2 Row 1 is the first 
	if (!isblank(boardMatrix[row][column])) return false;
	boardMatrix[row][column] = k;

	gotoXY(column, row);
	
	
	if (toupper(k) == 'X') {
		TextColor(ColorCode_DarkBlue);
		cout << (char)k;
	}
	else {
		TextColor(ColorCode_DarkRed);
		cout << (char)k;
	}

	gotoXY(column, row);
	TextColor(default_ColorCode);

	return true;
}

void checkInTableByIndex(int row, int column, char k, int colorCode) {
	boardMatrix[row * 2 + 1][column * 4 + 2] = k;

	gotoXY(column * 4 + 2, row * 2 + 1);

	TextColor(colorCode);
	cout << (char)k;
	TextColor(default_ColorCode);
}

bool insertDataFromMatrix(int row, int column, int value) {
	return checkValueInBoard((row - 1) / 2, (column - 2) / 4, value);
}

void moveCursorPosition(int row, int column) {
	
	if ((column % 4 == 2) && (row % 2 == 1)) return;

	if (row % 2 == 0) row++;

	switch (column % 4) {
		case 0: column += 2;
			break;
		case 1:
			column += 1;
			break;
		case 3:
			column -= 1;
			break;
	}

	gotoXY(column, row);
	//cout << column << " "<< row;
}

void moveCursorPosition(int row, int column, Direction direct) {
	//direct = 1: UP 2: DOWN 3: LEFT 4: RIGHT

	switch (direct) {
		case UP:
			if (row - 2 < 0) cout << char(7);
				else row -= 2;
			break;
		case DOWN:
			if (row + 2 > 28) cout << char(7);
				else row += 2;
				break;
			break;
		case LEFT:
			if (column - 5 < 0) cout << char(7);
			else column -= 5;
			break;
		case RIGHT:
			if (column + 5 > 89) cout << char(7);
			else column += 5;
			break;
	}

	gotoXY(column, row);
	//cout << column << " "<< row;
}