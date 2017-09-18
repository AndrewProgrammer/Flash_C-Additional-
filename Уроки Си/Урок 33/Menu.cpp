#include "Header.h"

void GamePrc()
{
	int code = 1;
	while (code != 27)
	{
		code = _getch();
	}	
}



int MenuPrc()
{
	int step = 2;
	int X = 30, Y = 8;
	int PosX = X, PosY = Y;
	int choose = 1;
	SetCur(X, Y);
	cout << ">>>";

	int code = 0;
	while (code != 13)
	{
		code = _getch();
		switch (code)
		{
		case 72:
			if (PosY != Y)
			{
				SetCur(PosX, PosY);
				cout << "   ";
				PosY -= step;
				SetCur(PosX, PosY);
				cout << ">>>";
				choose--;
			}
			break;
		case 80:
			if (PosY != Y+3 * step)
			{
				SetCur(PosX, PosY);
				cout << "   ";
				PosY += step;
				SetCur(PosX, PosY);
				cout << ">>>";
				choose++;
			}
			break;
		}
	}

	return choose;
}


void PrintMenuList()
{
	SetCur(35, 8);
	cout << "New game";
	SetCur(35, 10);
	cout << " Scores ";
	SetCur(35, 12);
	cout << "Settings";
	SetCur(35,14);
	cout << "  Exit  ";
}


void PrintLogo()
{
	cout << R"XXX(
			*         **
			*        *  *
			*       *    *  
			*        *  * 
			******	  **	)XXX";
}

void SetCur(int X, int Y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = X;
	pos.Y = Y;
	SetConsoleCursorPosition(h, pos);
}