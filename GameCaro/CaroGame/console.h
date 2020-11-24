// basic console functions, collected by Nguyen Trung Thanh
// abcxyz tcIT

#ifndef _console_header
#define _console_header


#define ColorCode_Black			240
#define ColorCode_DarkBlue		241
#define ColorCode_DarkGreen		242
#define ColorCode_DarkCyan		243
#define ColorCode_DarkRed		244
#define ColorCode_DarkPink		245
#define ColorCode_DarkYellow	246
#define ColorCode_DarkWhite		247
#define ColorCode_Grey			248
#define ColorCode_Blue			249
#define ColorCode_Green			250
#define ColorCode_Cyan			251
#define ColorCode_Red			252
#define ColorCode_Pink			253
#define ColorCode_Yellow		254
#define ColorCode_White			255

#define default_ColorCode		240


#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

#define getMaxScreenX 130
#define getMaxScreenY 29

//--------------------------------------------------------

#include <windows.h>

//--------------------------------------------------------

int inputKey();

//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY (int column, int line);

//screen: get [x]
int getCursorX();

//screen: get [y]
int getCursorY();

void TextColor (int color);

void FixConsoleWindow();

void ShowConsoleCursor(bool showFlag);
//end----------------------Screen----------------------end


#endif