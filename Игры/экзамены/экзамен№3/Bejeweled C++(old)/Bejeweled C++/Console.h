#pragma once
#include <Windows.h>
#include "JustJewels.h"
class Console//Работа с Консолью
{
public:
	static HANDLE hConsole;
	static void SetCur(int x, int y);
	static void SetCur(COORD pos);
	static void SetColor(color text, color font = Black);
	static void SetColorV2(int text);
	static void ConsoleSize();
};