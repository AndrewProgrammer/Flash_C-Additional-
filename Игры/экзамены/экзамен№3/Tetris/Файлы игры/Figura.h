#pragma once
#include <iostream>
#include <vector> // ����������� ������� ������
#include <conio.h> //��� ���������� ����� _kbhit()
#include <Windows.h>
#include "Console.h"

using namespace std;

const int FIGURE_SIZE = 4;
const char SymbolCell = 219;

class Figure // ����������� ����� ������, ������� ����� ��� ��� �������� ���� �������� //1 - ����� �����
{
private:

protected://������������ �������, ������� ��������, ��� ����� ��������� ��������� ����������� ������
	int color;
	int changecount; // �������� �������������� ����������� ������
	vector <vector < bool>> vecFigure;//������ ��������, ����� ������
public:
	Figure(int Color, int Position) : color(Color), changecount(Position), vecFigure(FIGURE_SIZE, vector <bool>(FIGURE_SIZE, false)){};//����������� ������������������� ����� ����������� ����� (��������� ����� ������ ������� ����)
	virtual void ChangeFigure() = 0; //���������� ������ �������������� � ������ �����, ������� �� �������� �������� ������� ������������ ������� ������� ����
	bool GetCells(int x, int y);// ��������� ����� �������
	int GetColor();
	int getPosition();
	void ClearFigure();
	void ShowFigure(int ColorFigure);
};