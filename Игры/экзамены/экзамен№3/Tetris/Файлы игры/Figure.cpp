#include "Figura.h"
int Figure::GetColor()
{
	return color;
}
int Figure::getPosition()
{
	return changecount;
}
bool Figure::GetCells(int x, int y)
{
	return vecFigure[x][y];
}
void Figure::ClearFigure()
{
	for (int i = 0; i < FIGURE_SIZE; i++)
	{
		for (int j = 0; j < FIGURE_SIZE; j++)
		{
			vecFigure[i][j] = false;
		}
	}
}
void Figure::ShowFigure(int ColorFigure)
{
	for (int i = 0; i < FIGURE_SIZE; i++)
	{
		for (int j = 0; j < FIGURE_SIZE; j++)
		{
			if (vecFigure[i][j] == true)
			{
				HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hStdOut, ColorFigure);
				cout << SymbolCell;
			}
		}
	}
}