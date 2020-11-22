#include <iostream>
#include <windows.h>

#include "console.h"
#include "form.h"

#include <conio.h>

using namespace std;

int main()
{
	//change ASCII format
	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	FixConsoleWindow();

	mainGame("","");
	//mainLoginGame();
	Sleep(10);
	system("pause");

	return 0;
}

