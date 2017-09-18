#include "FigureT.h"
void FigureT::ChangeFigure()
{
	ClearFigure();
	if ((changecount > 4) && (changecount = 1)); // Проверка на вход по нашим позициям
	if (changecount == 4)
	{
		//Отрисовка T 
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][1] = true;
	}
	else if (changecount == 3)
	{
		//Отрисовка Т влево
		vecFigure[0][1] = true;
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
	}
	else if (changecount == 2)
	{
		//Отрисовка Т вверх
		vecFigure[0][1] = true;
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
	}
	else
	{
		// Отрисовка T вправо
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][1] = true;
	}
	changecount++;//Увеличиваем позицию(при дальнейшем перемещении)
}