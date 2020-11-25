#include <iostream>
#include <fstream>
#include <direct.h> // _getcwd

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

void drawTable() {
	for (int i = 0; i < rowBoard; i++) {
		for (int j = 0; j < columnBoard; j++)
			cout << boardMatrix[i][j];
		cout << endl;
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
	int x = getCursorX();
	int y = getCursorY();

	gotoXY(column * 4 + 2, row * 2 + 1);

	TextColor(colorCode);
	cout << (char)k;
	TextColor(default_ColorCode);
	gotoXY(x, y);
}

int insertDataFromMatrix(int row, int column, int value) {
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