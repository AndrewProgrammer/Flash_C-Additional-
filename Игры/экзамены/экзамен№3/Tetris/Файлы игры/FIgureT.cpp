#include "FigureT.h"
void FigureT::ChangeFigure()
{
	ClearFigure();
	if ((changecount > 4) && (changecount = 1)); // �������� �� ���� �� ����� ��������
	if (changecount == 4)
	{
		//��������� T 
		vecFigure[0][1] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][1] = true;
	}
	else if (changecount == 3)
	{
		//��������� � �����
		vecFigure[0][1] = true;
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
	}
	else if (changecount == 2)
	{
		//��������� � �����
		vecFigure[0][1] = true;
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[2][1] = true;
	}
	else
	{
		// ��������� T ������
		vecFigure[1][0] = true;
		vecFigure[1][1] = true;
		vecFigure[1][2] = true;
		vecFigure[2][1] = true;
	}
	changecount++;//����������� �������(��� ���������� �����������)
}