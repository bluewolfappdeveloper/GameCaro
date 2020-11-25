#include <iostream>
#include <string>
#include <fstream>
#include <direct.h> // _getcwd

#include "console.h"
#include "form.h"
#include "mainGame.h"
#include <conio.h>

//Max length Name 15

using namespace std;

struct UserGame {
	string Name;
	int Win;
	int Lose;
	int Draw;
	int Pos;
};

UserGame users[10000]; int index = 0;
UserGame player1, player2;

void setMenuUserSelect(int a) {
	if (a > 3 || a < 0) return;

	int col = getMaxScreenX / 2, row = 15;

	for (int i = 16; i <= 25; i += 2)
	{
		gotoXY(col, i);
		TextColor(default_ColorCode);
		for (int j = 0; j <= 30; j++) cout << " ";
	}


	if (a == 0) {
		return;
	}


	gotoXY(col, ++row);
	if (a == 1) {
		TextColor(31);
		cout << ">> " << "PLAY AS GUEST" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "PLAY AS GUEST";

	row++;

	gotoXY(col, ++row);

	
	if (a == 2) {
		if (index == 0) TextColor(248); else  TextColor(31);
		cout << ">> " << "SIGN IN YOUR ACCOUNT" << " <<";
		TextColor(default_ColorCode);
	}
	else {
		if (index == 0) TextColor(248);
		cout << "SIGN IN YOUR ACCOUNT"; 
	}
	TextColor(default_ColorCode);

	row++;

	gotoXY(col, ++row);
	if (a == 3) {
		TextColor(31);
		cout << ">> " << "CREATE YOUR ACCOUNT" << " <<";
		TextColor(default_ColorCode);
	}
	else cout << "CREATE YOUR ACCOUNT";

}

int getMenuUserSelect() {
	int selected = 1;
	setMenuUserSelect(selected); ShowConsoleCursor(false);
	while (true) {
		// menu lua chon khi thang
		if (_kbhit()) {
			int key = _getch();

			if (key == '1' || key == '2' || key == '3') {
				
				if (key - 48 == 2 && index == 0) {}
				else {
					selected = key - 48;
					setMenuUserSelect(selected);
				} 
			}
			else {
				//Enter:13 and  Space:32
				if (key == 13 || key == 32) {
					clrscr(); setMenuUserSelect(0);
					// Do something
					return 	selected;
				}
				else {
					if (key == 0 || key == 0xE0) key = _getch();

					if (key == 80) {
						//DOWN
						if (selected + 1 > 3) cout << (char)7;
						else {
							if (selected + 1 == 2 && index == 0) selected+=2;
							else selected++;
							
							setMenuUserSelect(selected);
						}
					}
					else if (key == 72) {
						//UP
						if (selected - 1 < 1) cout << (char)7;
						else {
								if (selected - 1 == 2 && index == 0) selected -= 2;
								else selected--;
								setMenuUserSelect(selected);
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

string stringToASCII(string a) {
	string result = "";
	for (int i = 0; i < a.length(); i++) {
		result += to_string((int)a[i]);
	}
	return result;
}

string formatString(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ') a[i] = '.';
	}
	
	return a;
}

string formatStringSpace(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '.') a[i] = ' ';
	}

	return a;
}

void loadUserFromFile() {
	string add = _getcwd(NULL, 0);
	
	ifstream userFileInput;
	

	userFileInput.open(add+"\\userGame.txt");
	
	index = 0;

	if (userFileInput.fail()) {
		ofstream userFileOutput;
		userFileOutput.open(add + "\\userGame.txt");
		userFileOutput.close();
	}
	else {
		while (!userFileInput.eof()) {
			string id; string name; int win; int lose; int draw;

			userFileInput >> name >> win >> lose >> draw;
			if (name == "") continue;
			index++;
			users[index].Name = formatStringSpace(name);
			users[index].Win = win;
			users[index].Lose = lose;
			users[index].Draw = draw;
			users[index].Pos = index;
		}
	}

	userFileInput.close();

}

void SaveUserToFile() {
	string add = _getcwd(NULL, 0);
	ofstream userFile;
	userFile.open(add + "\\userGame.txt");

	for (int i=1; i<=index; i++){
		if (i == index) {
			userFile << formatString(users[i].Name) << " " << users[i].Win << " " << users[i].Lose << " " << users[i].Draw;
		}
		else
			userFile << formatString(users[i].Name) << " " << users[i].Win << " " << users[i].Lose << " " << users[i].Draw<<"\n";
	}
	userFile.close();


}

void inputUser(UserGame &userGame, string namePlayer1) {
	clrscr();
	

	bool isSelect = false;
	while (!isSelect) {
		if (namePlayer1.empty()) setTitle(ColorCode_DarkBlue);
		else setTitle(ColorCode_DarkRed);

		int selected = getMenuUserSelect();
		if (selected == 1) {
			// Playing with Guest
			return;
		}
		else
		{
			bool ok = false;
			int x = 50, y = 15;
			string user;

			clrscr();
			if (namePlayer1.empty()) setTitle(ColorCode_DarkBlue);
			else setTitle(ColorCode_DarkRed);

			while (!ok) {
				ShowConsoleCursor(true);
				gotoXY(x, y);

				cout << "Nhap tai khoan cua ban: ";
				getline(cin, user);
				
				string temp = user;
				for (int i = 0; i < user.length(); i++) {
					temp[i] = toupper(user[i]);
				}

				if (temp == "BACK") {
					clrscr();
					break;
				}

				int d = user.find('.');
				bool ok = (namePlayer1.empty() == false && user == namePlayer1);

				if (user.length() > 15 || user.length() == 0 || d > 0 || ok) {
					gotoXY(x, y + 1);
					cout << "Sai dinh dang. Vui long nhap lai tai khoan cua ban." << endl;
					Sleep(300);
					clrscr();
					if (namePlayer1.empty()) setTitle(ColorCode_DarkBlue);
					else setTitle(ColorCode_DarkRed);
					gotoXY(x, y);
				}
				else {
					bool isUser = false; int i;
					for (i = 1; i <= index; i++) {
						if (user == users[i].Name) {
							isUser = true;
							break;
						}
					}

					if (selected == 2) {
						if (isUser) { userGame = users[i];  return; }
						else {
							gotoXY(x, y + 1);
							cout << "Khong tim thay tai khoan cua ban. Vui long nhap lai tai khoan cua ban. " << endl;
							Sleep(600);
							clrscr();
							if (namePlayer1.empty()) setTitle(ColorCode_DarkBlue);
							else setTitle(ColorCode_DarkRed);
							gotoXY(x, y);
						}
					}
					else {
						if (!isUser) {
							userGame.Name = user;
							userGame.Pos = -1;
							return;
						}
						else {
							gotoXY(x, y + 1);
							cout << "Khong tim thay tai khoan cua ban. Vui long nhap lai tai khoan cua ban. " << endl;
							Sleep(600);
							clrscr();
							if (namePlayer1.empty()) setTitle(ColorCode_DarkBlue);
							else setTitle(ColorCode_DarkRed);
							gotoXY(x, y);
						}
					}
				}
			}
		}
	}

	

	

}

void mainLoginGame() {
	loadUserFromFile();

	player1.Name = "Player 1";
	player1.Win = 0;
	player1.Draw = 0;
	player1.Lose = 0;
	player1.Pos = -2;

	player2.Name = "Player 2";
	player2.Win = 0;
	player2.Draw = 0;
	player2.Lose = 0;
	player2.Pos = -2;

	inputUser(player1, "");
	inputUser(player2, player1.Name);

	if (player1.Pos == -1) {
		index++;
		users[index].Name = player1.Name;
		users[index].Win = player1.Win;
		users[index].Lose = player1.Lose;
		users[index].Draw = player1.Draw;
		users[index].Pos = index;
		player1.Pos = index;
		
	}
	if (player2.Pos == -1) {
		index++;
		users[index].Name = player2.Name;
		users[index].Win = player2.Win;
		users[index].Lose = player2.Lose;
		users[index].Draw = player2.Draw;
		users[index].Pos = index;
		player2.Pos = index;
	}

	SaveUserToFile();

	clrscr();
	mainGame(player1.Name, player2.Name);
}

string getNamePlayer1() {
	return player1.Name;
}

string getNamePlayer2() {
	return player2.Name;
}

int getWinPlayer1() {
	return player1.Win;
}

int getWinPlayer2() {
	return player2.Win;
}

int getDrawPlayer1() {
	return player1.Draw;
}

int getDrawPlayer2() {
	return player2.Draw;
}

int getLosePlayer1() {
	return player1.Lose;
}

int getLosePlayer2() {
	return player2.Lose;
}

void setWinPlayer1() {
	player1.Win++;
	if (player1.Pos > -1) users[player1.Pos].Win++;
}

void setWinPlayer2() {
	player2.Win++;
	if (player2.Pos > -1) users[player2.Pos].Win++;
}

void setDrawPlayer1() {
	player1.Draw++;
	if (player1.Pos > -1) users[player1.Pos].Draw++;
}

void setDrawPlayer2() {
	player2.Draw++;
	if (player2.Pos > -1) users[player2.Pos].Draw++;
}

void setLosePlayer1() {
	player1.Lose++;
	if (player1.Pos > -1) users[player1.Pos].Lose++;
}

void setLosePlayer2() {
	player2.Lose++;
	if (player2.Pos > -1) users[player2.Pos].Lose++;
}
