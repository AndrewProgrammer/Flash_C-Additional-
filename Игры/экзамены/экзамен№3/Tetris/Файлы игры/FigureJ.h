#pragma once
#include "Figura.h"
class FigureJ : public Figure
{
public:
	FigureJ(int Jcolor = COLOR_OF_J, int Jposition = 2) : Figure(Jcolor, Jposition) 
	{
		//Отрисовка лежачего Г вверх справа
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][0] = true;
		vecFigure[2][1] = true;
	}
	void ChangeFigure();// 2 - ПУНКТ ПЛАНА ДЛЯ J
};