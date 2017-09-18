#pragma once
#include "Figura.h"
#include "Figura.h"
#include "FigureT.h"
#include "FigureJ.h"
#include "FigureL.h"
#include "FigureLine.h"
#include "FigureS.h"
#include "FigureSquare.h"
#include "FigureZ.h"
#include "Console.h"
#include <memory> //���������� ����������� ��� ����������� ������ ���������

const int StartPositionX = 9;//9 - ��������� ���������� ������� �������
const int StartPositionY = 2;//2 - ��������� ��������� ������� ������� (���� �� ���� ����, ���� �����, ������� ����� ���������� ������,���������� � ������� ������)
const int AllSells = 1000;
const int WidthField = 21;
const int HightField = 21;

const char TopField = 220;
const char BottomField = 223;
const char LeftField = 221;
const char RightField = 222;

class Game
{
private:
	vector <vector <bool>> vecField; //���� ������� ���� (������ ��������, ��� ��� ��� ����� �������� ��� ������ bool � ���������� �������� �� ����� ��������� ����)
	vector <vector <int>> vecFieldColor;//���� ����� ������� �� ���� (���������� �� ����� �������� ��������)
	vector<shared_ptr<Figure>> vecFigures;//������ ������ ��������� ������ ������ - ���� ������
	vector <int> randomFigure;//������ ��������� �������� ������)��� ��� ��� ������ �������� �������  ����� �������� �� �������
	int indexRandom;//������ ��� ��������� ����������� �����
	int indexFigure;//������ ������ ���������� �� ������������ ����� 
	int score;
public:
	//����������� �������������������, ������� ��������� �� ���� ������, � ������(������� �������� ������� � ��� ����� ��� ������ bool � ����� �������� ��������)
	Game();
	shared_ptr <Figure> nextFigure(); //�������� ��������� ������ ����� ��������
	void ShowField();// ��������� ������ ����
	void ShowRules(); // ������� ����
	void SetFigureCoordinates(shared_ptr<Figure> Figure, int Position_YF, int Position_XF); //����������� ��������� ������ ���� 
	void ClearFigureCoordinates(shared_ptr<Figure> Figure, int Position_YF, int Position_XF); //������� ��������� ������ ���� // 4 - ����� �����
	bool ControlsAndStartGame(shared_ptr <Figure> figure, int  Position_XF, int Position_YF); // ���������� �������� � ��������� �������� ��� ������� ����
	bool CheckFigureCoordinatesLeftToRight(shared_ptr<Figure> Figure, int Position_XF, int Position_YF); // �������� ����� ������ ������ � ����� �� ���������� ����� ������������ ����� ����� ��������
	bool CheckFigureCoordinatesBottom(shared_ptr<Figure> figure, int Position_XF, int Position_YF); // �������� ����� ������ �� ���������� ��� ����.
	void ClearLines(); //������� ���������� ����� � ���������� ����� // 5 - ����� �����
	int GetScore(); // 3 - ����� �����
};