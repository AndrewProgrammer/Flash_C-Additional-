#define _CRT_SECURE_NO_WARNINGS
#pragma once
using namespace std;
enum directions{ UP = 72, RIGHT = 77, DOWN = 80, LEFT = 75, ENTER = 13};// Перечисление направлений (без функции(_getch))
enum color//Перечисление цветов
{
	Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9,
	LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15, Black = 16
};
const int m_sizefield = 8;
class JustJewels
{
private:
public:
	JustJewels();
	~JustJewels();
};