#include <iostream>
#include <conio.h>

#include "console.h"
#include "loginMain.h"
#include "form.h"
#include "table.h"
#include "caroBoardProcess.h"
#include "infoState.h"

using namespace std;

void setMenuSelectWhenWinning(int a, bool isUser1=false) {
	if (a > 2 || a < 0) return;

	int col = 107, row = 22;

	for (int i = row + 1; i <= row + 3; i += 2)
	{
		gotoXY(col, i);
		TextColor(default_ColorCode);
		for (int j = 0; j <= 20; j++) cout << " ";
	}


	if (a == 0) {
		return;
	}

	int colorSelect = -1;
	if (isUser1) colorSelect = 31; else colorSelect = 79;

	gotoXY(col, ++row);
	if (a == 1) {
		TextColor(colorSelect);
		cout << ">> " << "PLAY AGAIN" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "PLAY AGAIN";

	row++;

	gotoXY(col, ++row);
	if (a == 2) {
		TextColor(colorSelect);
		cout << ">> " << "MENU" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "MENU";
}

void setMenuSelectWhenExit(int a, bool isUser1 = false) {
	if (a > 2 || a < 0) return;

	int col = 95, row = 21;

	for (int i = row + 1; i <= row + 5; i += 2)
	{
		gotoXY(col, i);
		TextColor(default_ColorCode);
		for (int j = 0; j <= 35; j++) cout << " ";
	}


	if (a == 0) {
		return;
	}

	int colorSelect = -1;
	if (isUser1) colorSelect = 31; else colorSelect = 79;

	gotoXY(95, ++row);

	cout << "Do you want to save your changes ?";

	row++;

	gotoXY(col + 10, ++row);
	if (a == 1) {
		TextColor(colorSelect);
		cout << ">> " << "YES" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "YES";

	row++;

	gotoXY(col + 10, ++row);
	if (a == 2) {
		TextColor(colorSelect);
		cout << ">> " << "NO" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "NO";
}

void mainPlayGame(string fileName) {
	bool isExit = false;
	bool isPlayer1 = true;
	int isWinning = -1;

	initTable();
	drawTable();

	if (!fileName.empty()) {
		loadCaroBoard(fileName, isPlayer1);
	}

	mainInfoState(isPlayer1, -1);
	drawInfoTable(default_ColorCode, false);
	gotoXY(0, 0);


	while (!isExit) {
		if (isWinning >= 0) {

			if (isWinning == 0) {
				if (isPlayer1) setDrawPlayer1(); else setDrawPlayer2();
			}
			else {
				if (isPlayer1) setWinPlayer1(); else setWinPlayer2();
				if (isPlayer1) setLosePlayer2(); else setLosePlayer1();
				
			}

			if (!fileName.empty()) {
				deleteFile(fileName);
			}

			SaveUserToFile();
			ShowConsoleCursor(false);
			
			mainInfoState(isPlayer1, isWinning);
			int selected = 1;
			setMenuSelectWhenWinning(selected, isPlayer1);
			while (true) {
				// menu lua chon khi thang
				if (_kbhit()) {
					int key = _getch();

					if (key == '1' || key == '2') {
						selected = key - 48;
						setMenuSelectWhenWinning(selected, isPlayer1);
					}
					else {
						//Enter:13 and  Space:32
						if (key == 13 || key == 32) {
							// Do something

							switch (selected) {
							case 1:
								//Play Again
								ShowConsoleCursor(true);
								clrscr(); system("color F0");
								mainPlayGame("");
								break;
							case 2:
								//Menu
								clrscr(); system("color F0");
								mainGame(getNamePlayer1(), getNamePlayer2());
								return;
								break;
							}
						}
						else {
							if (key == 0 || key == 0xE0) key = _getch();

							if (key == 80) {
								//UP
								if (selected + 1 > 2) {
									selected = 1;
									setMenuSelectWhenWinning(selected, isPlayer1);
								}
								else {
									selected++;
									setMenuSelectWhenWinning(selected, isPlayer1);
								}
							}
							else if (key == 72) {
								//DOWN
								if (selected - 1 < 1) {
									selected = 2;
									setMenuSelectWhenWinning(selected, isPlayer1);
								}
								else {
									selected--;
									setMenuSelectWhenWinning(selected, isPlayer1);
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
		else {
			moveCursorPosition(getCursorY(), getCursorX());
			if (_kbhit()) {
				int key = _getch();

				if (toupper(key) == 'W' || toupper(key) == 'S' || toupper(key) == 'A' || toupper(key) == 'D' || key == 13 || key == 32 || key == 27) {
					if (toupper(key) == 'W') //UP
						moveCursorPosition(getCursorY(), getCursorX(), UP);
					else if (toupper(key) == 'S') //DOWN
						moveCursorPosition(getCursorY(), getCursorX(), DOWN);
					else if (toupper(key) == 'A') //LEFT
						moveCursorPosition(getCursorY(), getCursorX(), LEFT);
					else if (toupper(key) == 'D') //RIGHT
						moveCursorPosition(getCursorY(), getCursorX(), RIGHT);
					if (key == 13 || key == 32) //Space
					{
						bool isChecked = true;
						if (isPlayer1) {
							// Player 1 check position 
							char k = 'x';
							isChecked = checkInTableByPos(getCursorY(), getCursorX(), toupper(k));
							isWinning = insertDataFromMatrix(getCursorY(), getCursorX(), isPlayer1);
						}
						else {
							// Player 2 check position 
							char k = 'o';
							isChecked = checkInTableByPos(getCursorY(), getCursorX(), toupper(k));
							isWinning = insertDataFromMatrix(getCursorY(), getCursorX(), isPlayer1 + 2);
						}

						if (isWinning == -1 && isChecked) {
							isPlayer1 = !isPlayer1;

							int x = getCursorX();
							int y = getCursorY();

							mainInfoState(isPlayer1, isWinning);

							gotoXY(x, y);
						}
					}

					if (key == 27) {
						int selected = 1; int coorX = getCursorX(), coorY = getCursorY();
						setMenuSelectWhenExit(selected, isPlayer1); ShowConsoleCursor(false);
						while (true) {
							// menu lua chon khi muoon thoat
							if (_kbhit()) {
								int key = _getch();

								if (key == '1' || key == '2') {
									selected = key - 48;
									setMenuSelectWhenExit(selected, isPlayer1);
								}
								else {
									//Enter:13 and  Space:32
									if (key == 13 || key == 32) {
										// Do something
										string nameFile = formatString(getNamePlayer1()) + "_" + formatString(getNamePlayer2())+".txt";
										switch (selected) {
										case 1:
											//Save Table
											saveCaroBoard(nameFile,isPlayer1);
											clrscr(); system("color F0");
											mainGame(getNamePlayer1(), getNamePlayer2());
											break;
										case 2:
											//Menu
											clrscr(); system("color F0");
											mainGame(getNamePlayer1(), getNamePlayer2());
											return;
											break;
										}
									}
									else if (key==27) {
										setMenuSelectWhenExit(0);
										gotoXY(coorX, coorY);
										ShowConsoleCursor(true);
										break;
									}
									else {
										if (key == 0 || key == 0xE0) key = _getch();

										if (key == 80) {
											//UP
											if (selected + 1 > 2) {
												selected = 1;
												setMenuSelectWhenExit(selected,isPlayer1);
											}
											else {
												selected++;
												setMenuSelectWhenExit(selected,isPlayer1);
											}
										}
										else if (key == 72) {
											//DOWN
											if (selected - 1 < 1) {
												selected = 2;
												setMenuSelectWhenExit(selected, isPlayer1);
											}
											else {
												selected--;
												setMenuSelectWhenExit(selected, isPlayer1);
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
				}
				else
				{
					if (key == 0 || key == 0xE0) key = _getch();

					if (key == 72) //UP
						moveCursorPosition(getCursorY(), getCursorX(), UP);
					else if (key == 80) //DOWN
						moveCursorPosition(getCursorY(), getCursorX(), DOWN);
					else if (key == 75) //LEFT
						moveCursorPosition(getCursorY(), getCursorX(), LEFT);
					else if (key == 77) //RIGHT
						moveCursorPosition(getCursorY(), getCursorX(), RIGHT);
				}
			}
		}
	}
}



/*
* if (isPlayer1) {
					if (toupper(key) == 'W' || toupper(key) == 'S' || toupper(key) == 'A' || toupper(key) == 'D' || key == 32) {
						if (toupper(key) == 'W') //UP
							moveCursorPosition(getCursorY(), getCursorX(), UP);
						else if (toupper(key) == 'S') //DOWN
							moveCursorPosition(getCursorY(), getCursorX(), DOWN);
						else if (toupper(key) == 'A') //LEFT
							moveCursorPosition(getCursorY(), getCursorX(), LEFT);
						else if (toupper(key) == 'D') //RIGHT
							moveCursorPosition(getCursorY(), getCursorX(), RIGHT);
						if (key == 32) //Space
						{
							bool isChecked = checkInTableByPos(getCursorY(), getCursorX(), toupper('x'));
							isWinning = insertDataFromMatrix(getCursorY(), getCursorX(), isPlayer1);

							if (!isWinning && isChecked) {
								isPlayer1 = !isPlayer1;

								int x = getCursorX();
								int y = getCursorY();

								mainInfoState(isPlayer1, false);

								gotoXY(x, y);
							}
						}

					}

				}
				else {
					if (key == 13) {

						bool isChecked = checkInTableByPos(getCursorY(), getCursorX(), toupper('o'));
						isWinning = insertDataFromMatrix(getCursorY(), getCursorX(), isPlayer1 + 2);


						if (!isWinning && isChecked) {
							isPlayer1 = !isPlayer1;

							int x = getCursorX();
							int y = getCursorY();

							mainInfoState(isPlayer1, false);

							gotoXY(x, y);
						}

					}
					else
					{
						if (key == 0 || key == 0xE0) key = _getch();

						if (key == 72) //UP
							moveCursorPosition(getCursorY(), getCursorX(), UP);
						else if (key == 80) //DOWN
							moveCursorPosition(getCursorY(), getCursorX(), DOWN);
						else if (key == 75) //LEFT
							moveCursorPosition(getCursorY(), getCursorX(), LEFT);
						else if (key == 77) //RIGHT
							moveCursorPosition(getCursorY(), getCursorX(), RIGHT);
					}
				}
*/