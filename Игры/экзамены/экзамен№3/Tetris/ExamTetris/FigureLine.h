#pragma once
#include "Figura.h"
class FigureLine : public Figure 
{
public:
	FigureLine(int LineColor= COLOR_OF_LINE, int LinePoisition = 2) : Figure(LineColor, LinePoisition) 
	{
		//Ëèíèÿ âäîëü
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[1][3] = true;
	}
	void ChangeFigure(); // 2 - ÏÓÍÊÒ ÏËÀÍÀ ÄËß LINE
};