#pragma once
#include "Figura.h"
class FigureS : public Figure 
{
public:
	FigureS(int Scolor = COLOR_OF_S, int Sposition = 2) : Figure(Scolor, Sposition) 
	{
		//Отрисовка сдвинутого вверх квадрата
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][0] = true;
		vecFigure[2][1] = true;
	}
	void ChangeFigure(); // 2 - ПУНКТ ПЛАНА ДЛЯ S
};