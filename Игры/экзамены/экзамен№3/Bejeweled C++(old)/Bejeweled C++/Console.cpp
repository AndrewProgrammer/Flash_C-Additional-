#include "Console.h"
#include "JustJewels.h"
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
	int ConsoleColor = text;
	SetConsoleTextAttribute(hConsole, ConsoleColor);
}
void Console::SetColor(color text, color font)
{
	SetConsoleTextAttribute(hConsole, (WORD)((font << 4) | text));
}
void Console::ConsoleSize()
{
	system("mode con cols=223 lines=35");// Изменение размера окна
}