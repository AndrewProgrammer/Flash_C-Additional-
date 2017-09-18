#pragma once
#include <Windows.h>
#include <iostream>
#pragma once
enum COLOR
{
	COLOR_OF_LINE = 14,
	COLOR_OF_SQUARE = 13,
	COLOR_OF_S = 12,
	COLOR_OF_Z = 11,
	COLOR_OF_L = 10,
	COLOR_OF_J = 9,
	COLOR_OF_T = 8,
	Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9,
	LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15, Black = 16
};
class Console
{
public:
	static HANDLE hConsole;
	static void SetCur(int x, int y);
	static void SetCur(COORD pos);
	static void SetColor(COLOR text, COLOR font = Black);
	static void SetColor(HANDLE Newho, COLOR color);
	static void SetColorV2(int text);
	static void ResizeConsole();
};
