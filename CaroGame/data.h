#ifndef DATA_H_
#define DATA_H_

#include <string>

#include "console.h"

using namespace std;

struct UserGame {
	string Name;
	int Win;
	int Lose;
	int Draw;
	int Pos;
};

enum Direction { UP, DOWN, LEFT, RIGHT };

void setTitle(int colorCode);


#endif // !DATA_H_
