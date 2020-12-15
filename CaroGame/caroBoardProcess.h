
#ifndef caroBoardProcess
#define caroBoardProcess

#include <string>
using namespace std;


void initCaroBoard();
int checkValueInBoard(int row, int column, int value);
void saveCaroBoard(string filename, bool isPlayer1);
void loadCaroBoard(string fileName, bool& isPlayer1);
void deleteFile(string fileName);

#endif // !caroBoardProcess

