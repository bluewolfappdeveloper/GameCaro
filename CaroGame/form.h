#ifndef FORM_H_
#define FORM_H_

#include <string>

#include "console.h"
#include "loginGame.h"
#include "mainGame.h"

using namespace std;

void mainLoginGame();
void mainGame(string player1, string player2);
void mainPlayGame(string path);
void helpGame();
void aboutGame();
void SaveUserToFile();
#endif // !FORM_H_
