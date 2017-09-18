#pragma once
#include "Figura.h"
class FigureSquare : public Figure
{
public:
	FigureSquare(int Squarecolor = COLOR_OF_SQUARE, int Squareposition = 0) : Figure(Squarecolor, Squareposition)
	{
		//Отрисовка квадарата
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][1] = true;
		vecFigure[2][2] = true;
	}
	void ChangeFigure(); // 2 - ПУНКТ ПЛАНА ДЛЯ SQUARE
};