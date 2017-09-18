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
	color m_color;//Цвет нашего шара
	Gems();
	~Gems() = default;
	Gems(color color);
	int GetLenght(int size);//Размер массивов
	void PrintGem(int x, int y,int size)const;//Выводит на экран наш кубик с рандомным цветом
	void ActionWithScore(Score & score);//Выполняет показ на экран очков
	bool operator == (Gems & right);//Перегрузка оператора равно
};