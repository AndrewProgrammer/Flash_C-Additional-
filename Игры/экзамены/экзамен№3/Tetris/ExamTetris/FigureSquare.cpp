#include "FigureSquare.h"
void FigureSquare::ChangeFigure()
{
	//Квадрат не будет не как менятся, поэтому: //Отрисовка квадарата 
	vecFigure[1][1] = true;
	vecFigure[1][2] = true;
	vecFigure[2][1] = true;
	vecFigure[2][2] = true;
}