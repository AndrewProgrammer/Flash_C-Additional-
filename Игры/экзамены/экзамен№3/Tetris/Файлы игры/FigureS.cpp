#include "FigureS.h"
void FigureS::ChangeFigure()
{
	ClearFigure();
	if (changecount % 2 == 0)
	{
		//Отрисовка горизонтального квадрата вверх
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][2] = true;
	}
	else
	{
		//Отрисовка сдвинутого влево
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][0] = true;
		vecFigure[2][1] = true;
	}
	changecount++;//Увеличиваем позицию(при дальнейшем перемещении)
}