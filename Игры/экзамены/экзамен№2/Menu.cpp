#include "Header.h"


void PrintLogo()
{
	system("cls");
	cout << R"XXX(
		*		   
		*			
		*
		*
		******)XXX";
	PrintMenuButtons();
}

void PrintMenuButtons()
{
	SetCur(35,10);
	cout << "New Game";
	SetCur(35, 13);
	cout << " Scores ";
	SetCur(35, 16);
	cout << "Settings";
	SetCur(35, 19);
	cout << "  Exit  ";
}

void PlayGame()
{
	system("cls");
	cout << "Game" ;
	int code = 1;
	while (code != 27)
	{
		code = _getch();
	}
}
void Scores()
{
	system("cls");
	cout << "Scores";
	system("pause");
}
void Settings()
{
	system("cls");
	cout << "Settings";
	system("pause");
}

int MenuPrc()
{
	int choose = 1;
	int step = 3;
	int X = 32, Y = 10;
	int PosX = X, PosY = Y;
	SetCur(X, Y);
	cout << char(16);
	int code = 1;
	while (code!=13)
	{
		code = _getch();
		switch (code)
		{
		case 72:
			if (PosY > Y)
			{
				SetCur(PosX, PosY);
				cout << " ";
				PosY -= step;
				SetCur(PosX, PosY);
				cout << char(16);
				choose--;
			}
			break;
		case 80:
			if (PosY < Y + step * 3)
			{
				SetCur(PosX, PosY);
				cout << " ";
				PosY += step;
				SetCur(PosX, PosY);
				cout << char(16);
				choose++;
			}
			break;			
		}
	}
	return choose;
}



void SetCur(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, pos); 
}