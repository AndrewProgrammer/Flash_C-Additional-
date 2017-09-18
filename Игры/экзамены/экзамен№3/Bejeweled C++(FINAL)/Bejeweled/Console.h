#pragma once
enum directions{ UP = 72, RIGHT = 77, DOWN = 80, LEFT = 75, ENTER = 13, PROBEL = 32, ESCAPE = 27 };// Перечисление направлений (без функции(_getch))
#include <Windows.h>
enum color//Перечисление цветов
{
	Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9,
	LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15, Black = 16
};
class Console
{
public:
	static HANDLE hConsole;
	static void SetCur(int x, int y);
	static void SetCur(COORD pos);
	static void SetColor(color text, color font = Black);
	static void SetColorV2(int text);
	static void ResizeConsole();
};