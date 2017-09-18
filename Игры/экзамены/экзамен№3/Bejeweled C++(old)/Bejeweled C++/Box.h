#pragma once
#include "JustJewels.h"
#include "Console.h"
#include "Gems.h"
#include "ScoreField.h"
#include "DisplayCombo.h"
#include "CheckBox.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
typedef unsigned int uint;
const int m_height = 33;
const  int m_width = 65;
const int m_size = 2;
const int FieldSize= 64;
const int FieldSizem = 8;
using namespace std;
class Box  
{
private:
	Gems ** playField = new Gems*[64];//��� ������������ ������ ���� ��������� �� ��������
	int gridField[m_height][m_width];//��������� �����
public:
	Box();//����������� �� ���������
	~Box();//����������
	void PrintCheckBox();
	Box(int x, int y);//������������� ���� ���� �� ���������
	Box(int x, int y, int randColor);//������������� ���� ���� �� ��������� � ������
	Box(int x, int y, int cursorX, int cursorY);//������������ ��� �������
	//void DrawBox() const;//������� �� �� ����� ���� ����
	void DrawGrid() const;//������� ��� ������� (�����) �� �����
	//void InitBox(char symbol);//������ �������� ��� ������ ����
	Gems** PrintPlayField();//����� ������� ������ ��� ���� playField
	void Swap(Gems first, Gems second, Gems ** playField);//����� ������ ������ ���������
	void Swap(Gems first, Gems second, Gems *& playField);//����� ������ ������ ���������
	void Swap(Gems *& our, Gems *& dest);//��� ���� Swap
	void Swap(Gems first, Gems second, Gems playField);//��� ���� Swap
	Gems *& operator[](uint index);//������������� �������� [] ����� ��� ����������� ��������[]
	void Engine();//������� ��� ����(����� ����� ���������� � CheckBoxom ������� � ����� �����)
	bool FindBoxesForRemove(Gems **playField);//����� � ���������� ������ ������
	void FallAndGenerate();//����� ������ � ������� �����
	void DestroyJewels(Gems ** playField, bool **BoxesToRemove);//��������� ������
	bool isEmpty(bool **BoxesToRemove);//�������� �� ������ �� ��� ������ ��������� ������
	bool isEmpty(bool BoxesToRemove);
	//bool isEmpty(Gems ** playField);//�������� �� ������ �� ���� ����
	//bool isEmpty(Gems *& playField);//��� ���� ���������� isEmpty
	bool isFull(Gems **playField);//������ �� ���� ����
	int GetScore();//����� ������� ���������� ��� ���� ����
	void SetScore(int scores);//����� ������� ���������� ��� ���� ����
	void ScoreField();//������ ���� ����
	//int OurColor();//��� ����� ����� ������� (����� 16)
	//int OurBlack();//��� ������ ����
	//Box(Box (*playField[8][8]));//������������������� ����������� �1
};