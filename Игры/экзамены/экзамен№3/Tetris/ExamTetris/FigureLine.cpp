#pragma once 
#include "FigureLine.h"
void FigureLine::ChangeFigure()
{
	ClearFigure();
	if (changecount % 2 == 0)
	{
		//��������� �������
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
		vecFigure[3][1] = true;
	}
	else
	{
		//����� �����
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[1][3] = true;
	}
	changecount++;
}