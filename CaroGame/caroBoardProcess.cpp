#include <iostream>

#include "table.h"
#include "console.h"

using namespace std;

static int caroBoard[30][30];

void initCaroBoard() {
	memset(caroBoard, 0, sizeof(caroBoard));
}

bool checkWin(int row, int col, int value) {
	bool isWin = false;
	//Check Column
	int d = 0;
	for (int i = 0; i < 14; i++)
		if (caroBoard[i][col] == value) d++;
		else {
			if (d >= 5) {
				for (int j = i - 1; caroBoard[j][col] == value; j--)
					if (value == 1) checkInTableByIndex(j, col, 'x' , 1); 
						else checkInTableByIndex(j, col, 'o', 1);
		
				isWin = true;
			}
			d = 0;
		}

	//Check Row
	d = 0;
	for (int i = 0; i < 22; i++)
		if (caroBoard[row][i] == value) d++;
		else {
			if (d >= 5) {

				for (int j = i - 1; caroBoard[row][j] == value; j--)
					if (value == 1) checkInTableByIndex(row, j, 'x', 1);
					else checkInTableByIndex(row, j, 'o', 1);

				isWin = true;
			} 
			d = 0;
		}

	//Check Diagonal
	d = 0; int d1 = 0;
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 22; j++) {
			if ((i - j) == (row - col)) {
				if (caroBoard[i][j] == value) d++;
				else {
					if (d >= 5) { 
						for (int k = j - 1; caroBoard[(row - col) + k][k] == value; k--)
							if (value == 1) checkInTableByIndex((row - col) + k, k, 'x', 1);
							else checkInTableByIndex((row - col) + k, k, 'o', 1);
						isWin = true; 
					}
					d = 0;
				}
			}

			if ((i + j) == (row + col)) {
				if (caroBoard[i][j] == value)  d1++; 
				else {
					if (d1 >= 5) { 
						for (int k = i - 1; caroBoard[k][(row + col) - k] == value; k--) {
							if (value == 1) checkInTableByIndex(k, (row + col) - k, 'x', 1);
							else checkInTableByIndex(k, (row + col) - k, 'o', 1);
						}
						isWin = true;
					} 
					d1 = 0;
				}
			}
		}

	}
	if (d == 5 || d1 == 5) isWin = true;
	return isWin;
}

bool checkValueInBoard(int row, int column, int value) {
	caroBoard[row][column] = value;
	bool ok = checkWin(row, column, value);

	return ok;
}

