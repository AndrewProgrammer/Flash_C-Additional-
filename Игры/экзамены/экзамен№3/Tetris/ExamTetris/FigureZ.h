#pragma once
#include "Figura.h"
class FigureZ : public Figure
{
public:
	FigureZ(int Zcolor = COLOR_OF_Z, int Zposition = 2) : Figure(Zcolor, Zposition) 
	{
		//Отрисовка сдвинутого квадрата вверх
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
		vecFigure[2][2] = true;
	}
	void ChangeFigure(); // 2 -  ПУНКТ ПЛАНА ДЛЯ Z
};