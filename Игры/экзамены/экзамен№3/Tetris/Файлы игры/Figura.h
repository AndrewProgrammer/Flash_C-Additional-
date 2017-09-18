#pragma once
#include <iostream>
#include <vector> // подключение массива вектор
#include <conio.h> //для управление через _kbhit()
#include <Windows.h>
#include "Console.h"

using namespace std;

const int FIGURE_SIZE = 4;
const char SymbolCell = 219;

class Figure // Абстарктный класс фигура, который нужен нам для создание себе подобных //1 - ПУНКТ ПЛАНА
{
private:

protected://Спецификатор доступа, который означает, что будет принимать остальные наследуемые классы
	int color;
	int changecount; // смещение индексирование последующей фигуры
	vector <vector < bool>> vecFigure;//Вектор векторов, нашей фигуры
public:
	Figure(int Color, int Position) : color(Color), changecount(Position), vecFigure(FIGURE_SIZE, vector <bool>(FIGURE_SIZE, false)){};//Конструктор параметризированный наших наследуемых фигур (принимает также вектор чистого поля)
	virtual void ChangeFigure() = 0; //Управление фигуры распределенная в каждом класе, зависит от четности счетчика позиции относительно верхней границы поля
	bool GetCells(int x, int y);// Получение наших кубиков
	int GetColor();
	int getPosition();
	void ClearFigure();
	void ShowFigure(int ColorFigure);
};