#include "FigureZ.h"
void  FigureZ::ChangeFigure()
{
	ClearFigure();
	if (changecount % 2 == 0)
	{
		// ��������� ���������� ����� ��������������� ���������
		vecFigure[0][1] = true;
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[2][0] = true;
	}
	else
	{
		//��������� ���������� �������� �����
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
		vecFigure[2][2] = true;
	}
	changecount++;//����������� �������(��� ���������� �����������)
}