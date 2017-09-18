#pragma once
#include "Figura.h"
class FigureL : public Figure
{
public:
	FigureL(int Lcolor = COLOR_OF_L, int Lposition = 2) : Figure(Lcolor, Lposition) 
	{
		//Отрисовка Лежачего Г вниз
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
		vecFigure[2][2] = true;
	}
	void ChangeFigure(); // 2 - ПУНКТ ПЛАНА ДЛЯ L
};