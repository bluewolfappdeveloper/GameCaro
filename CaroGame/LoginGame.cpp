#include <iostream>
#include <string>
#include <fstream>
#include <direct.h> // _getcwd

#include "console.h"
#include "form.h"
#include "mainGame.h"

using namespace std;

struct UserGame {
	string ID;
	string Name;
	int Win;
	int Lose;
	int Draw;
	
};

UserGame users[10000]; int index = 0;
string player1, player2; int index1, index2;

string stringToASCII(string a) {
	string result = "";
	for (int i = 0; i < a.length(); i++) {
		result += to_string((int)a[i]);
	}
	return result;
}

string formatString(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ') a[i] = '?';
	}
	
	return a;
}

string formatStringSpace(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '?') a[i] = ' ';
	}

	return a;
}

void loadUserFromFile() {
	string add = _getcwd(NULL, 0);
	ifstream userFile;
	userFile.open(add+"\\Debug\\userGame.txt");
	
	index = 0;

	while (!userFile.eof()) {
		string id; string name; int win; int lose; int draw;

		userFile >> id >>name>>win>>lose>>draw;
		if (id == "" || name == "") continue;
		index++;
		users[index].ID = id;
		users[index].Name = name;
		users[index].Win = win;
		users[index].Lose = lose;
		users[index].Draw = draw;
	}

	
	
	userFile.close();

}

void SaveUserToFile() {
	string add = _getcwd(NULL, 0);
	ofstream userFile;
	userFile.open(add + "\\Debug\\userGame.txt");

	for (int i=1; i<=index; i++){
		if (i == index) {
			userFile << users[i].ID << " " << users[i].Name
				<< " " << users[i].Win << " " << users[i].Lose << " " << users[i].Draw;
		}
		else
			userFile << users[i].ID << " " << users[i].Name
			<< " " << users[i].Win << " " << users[i].Lose << " " << users[i].Draw<<"\n";
	}


	userFile.close();


}

string setUser(int k, string name,  int &in) {
	string user;
	bool ok = false;
	int x = 50, y = 15;
	char c;
	
	clrscr(); 
	setTitle(ColorCode_DarkBlue);

	

	gotoXY(x, y);

	while (ok == false) {
		cout << "Nhap ten nguoi choi " << k <<  ": ";
		getline(cin, user);
		int d = user.find('?');
		if (d >= 0 || user == "" ||stringToASCII(formatString(user)) == stringToASCII(formatString(name))) {
			cout << "Vui Long Nhap Lai Ten Nguoi Choi " << endl;
			Sleep(300);
			clrscr(); 
			setTitle(ColorCode_DarkBlue); gotoXY(x, y);
		}
		else {
			ok = true;
			string name = stringToASCII(formatString(user));
			for (int i = 1; i <= index; i++) {
				if (name == users[i].ID) {
					
					gotoXY(x, y+1); cout << "****Tai khoan cua ban da ton tai****" << endl;
					gotoXY(x, y + 2); cout << "Ban muon choi voi tai khoan nay ???" << endl;
					gotoXY(x, y + 3);
					
					do {
						gotoXY(x, y + 3);
						cout << "";
						c = getchar();

					} while (tolower(c) != 'y' && tolower(c) != 'n');

					if (tolower(c) == 'y') {
						return user;
					}
					else {
						gotoXY(x+1, y + 1);  
						cout << "Vui Long Nhap Lai Ten Nguoi Choi" << endl;
						Sleep(300);
						clrscr();
						setTitle(ColorCode_DarkBlue); gotoXY(x, y);
						ok = false;
						break;
					}
				}
			}
			
			if (ok) {
				index++;
				users[index].ID = stringToASCII(formatString(user));
				users[index].Name = formatString(user);
				users[index].Win = 0;
				users[index].Lose = 0;
				users[index].Draw = 0;
				

				SaveUserToFile();
				return user;
			}
		}
	}
	return 0;
}

void mainLoginGame() {
	loadUserFromFile();

	player1 = setUser(1, "", index1);

	player2 = setUser(2, player1, index2);

	clrscr();
	mainGame(player1, player2);
}

string getNamePlayer1() {
	return player1;
}

string getNamePlayer2() {
	return player2;
}

