#pragma once 
#include "FigureLine.h"
void FigureLine::ChangeFigure()
{
	ClearFigure();
	if (changecount % 2 == 0)
	{
		//Отрисовка лежащей
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
		vecFigure[3][1] = true;
	}
	else
	{
		//Линия вдоль
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[1][3] = true;
	}
	changecount++;
}