#ifndef LOGINGAME_H_
#define LOGINGAME_H_
#include <string>
using namespace std;

string formatString(string a);

string getNamePlayer1();
string getNamePlayer2();

int getWinPlayer1();
int getWinPlayer2();

int getDrawPlayer1();
int getDrawPlayer2();

int getLosePlayer1();
int getLosePlayer2();

void setWinPlayer1();
void setWinPlayer2();

void setDrawPlayer1();
void setDrawPlayer2();

void setLosePlayer1();
void setLosePlayer2();

#endif // !LOGINGAME_H_
