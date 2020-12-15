#ifndef TABLE_H_
#define TABLE_H_

#include <string.h>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

void initTable();
void drawTable();

bool checkInTableByPos(int row, int column, char k);
void checkInTableByIndex(int row, int column, char k, int colorCode);
int insertDataFromMatrix(int row, int column, int value);

void moveCursorPosition(int row, int column);
void moveCursorPosition(int row, int column, Direction direct);

#endif // !TABLE_H_
