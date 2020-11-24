#include <string.h>

using namespace std;

#ifndef table_H_

enum Direction { UP, DOWN, LEFT, RIGHT };

void initTable();
void loadTable(string path);
void drawTable();

bool checkInTableByPos(int row, int column, char k);
void checkInTableByIndex(int row, int column, char k, int colorCode);
bool insertDataFromMatrix(int row, int column, int value);

void moveCursorPosition(int row, int column);
void moveCursorPosition(int row, int column, Direction direct);

#endif // !table_H_
