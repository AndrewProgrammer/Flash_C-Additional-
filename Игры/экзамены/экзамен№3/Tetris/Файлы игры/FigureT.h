#pragma once
#include "Figura.h"
class FigureT : public Figure
{
public:
	FigureT(int Tcolor = COLOR_OF_T, int Tposition = 2) : Figure(Tcolor, Tposition) 
	{
		// Отрисовка T вправо
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][1] = true;
	}
	void ChangeFigure(); // 2 - ПУНКТ ПЛАНА ДЛЯ T
};