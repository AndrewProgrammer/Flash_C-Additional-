#include "FigureL.h"
void FigureL::ChangeFigure()
{
	ClearFigure();
	if ((changecount > 4) && (changecount = 1)); // �������� �� ���� �� ����� ��������

	if (changecount == 4)
	{
		//��������� �
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][0] = true;
	}
	else if (changecount == 3)
	{
		//��������� �������� � ����� �� �����
		vecFigure[0][0] = true;
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
	}
	else if (changecount == 2)
	{
		//��������� � ���� �����
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[0][2] = true;
	}
	else
	{
		//��������� ����������� �
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
		vecFigure[2][2] = true;
	}
	changecount++;//����������� �������(��� ���������� �����������)
}