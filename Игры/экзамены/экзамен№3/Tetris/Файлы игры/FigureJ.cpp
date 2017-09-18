#include "FigureJ.h"
void FigureJ::ChangeFigure()
{
	ClearFigure();
	if ((changecount > 4) && (changecount = 1)); // Проверка на вход по нашим позициям
	if (changecount == 4)
	{
		//Отрисовка |_
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][2] = true;
	}
	else if (changecount == 3)
	{
		//Отрисовка зеркально лежачего Г вниз
		vecFigure[0][1] = true;
		vecFigure[0][2] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
	}
	else if (changecount == 2)
	{
		//Зеркальное Г
		vecFigure[0][0] = true;
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
	}
	else
	{
		//Отрисовка лежачие Г вверх cправа
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][0] = true;
		vecFigure[2][1] = true;
	}
	changecount++;//Увеличиваем позицию(при дальнейшем перемещении)
}