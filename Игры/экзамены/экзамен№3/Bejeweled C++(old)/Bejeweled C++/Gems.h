#pragma once
#include <vector>
#include "ScoreField.h"
#include "Console.h"
#include "DisplayCombo.h"
#include "JustJewels.h"
#include <ctime>
#include <iostream>
using namespace std;
class Gems
{
public:
	color m_color;//���� ������ ����
	Gems();
	~Gems() = default;
	Gems(color color);
	int GetLenght(int size);//������ ��������
	void PrintGem(int x, int y,int size)const;//������� �� ����� ��� ����� � ��������� ������
	void ActionWithScore(Score & score);//��������� ����� �� ����� �����
	bool operator == (Gems & right);//���������� ��������� �����
};