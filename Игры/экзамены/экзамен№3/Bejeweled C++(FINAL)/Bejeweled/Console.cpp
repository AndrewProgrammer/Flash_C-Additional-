#include "Console.h"
HANDLE Console::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Console::SetCur(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void Console::SetCur(COORD pos)
{
	SetConsoleCursorPosition(hConsole, pos);
}
void Console::SetColorV2(int text)
{
	text = rand() % 15 + 1;
	int color = text ;
	SetConsoleTextAttribute(hConsole, color);
}
void Console::SetColor(color text, color font)
{
	SetConsoleTextAttribute(hConsole, (WORD)((font << 4) | text));
}
void Console::ResizeConsole()
{
	system("mode con cols=32 lines=40");// Изменение размера окна
}