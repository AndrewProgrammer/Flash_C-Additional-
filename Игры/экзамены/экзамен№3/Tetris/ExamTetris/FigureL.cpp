#include "FigureL.h"
void FigureL::ChangeFigure()
{
	ClearFigure();
	if ((changecount > 4) && (changecount = 1)); // Проверка на вход по нашим позициям

	if (changecount == 4)
	{
		//Отрисовка Г
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][0] = true;
	}
	else if (changecount == 3)
	{
		//Отрисовка Лежачего Г влево на вверх
		vecFigure[0][0] = true;
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
	}
	else if (changecount == 2)
	{
		//Отрисовка Г вниз влево
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[0][2] = true;
	}
	else
	{
		//Отрисовка зеркального Г
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
		vecFigure[2][2] = true;
	}
	changecount++;//Увеличиваем позицию(при дальнейшем перемещении)
}