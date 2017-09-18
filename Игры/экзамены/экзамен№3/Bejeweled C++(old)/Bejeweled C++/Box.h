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
	Gems ** playField = new Gems*[64];//Наш динамический массив поля состоящей из массивов
	int gridField[m_height][m_width];//Параметры сетки
public:
	Box();//Конструктор по умолчанию
	~Box();//Деструктор
	void PrintCheckBox();
	Box(int x, int y);//устанавливаем нашу зону по умолчанию
	Box(int x, int y, int randColor);//устанавливаем наше поле по умолчанию с цветом
	Box(int x, int y, int cursorX, int cursorY);//Устнавливает наш чекбокс
	//void DrawBox() const;//Выводим ее на экран наше поле
	void DrawGrid() const;//Выводит нам границу (сетку) на экран
	//void InitBox(char symbol);//Вводим значения для нашего поля
	Gems** PrintPlayField();//Метод который задает нам поле playField
	void Swap(Gems first, Gems second, Gems ** playField);//Метод обмена полями выбраными
	void Swap(Gems first, Gems second, Gems *& playField);//Метод обмена полями выбраными
	void Swap(Gems *& our, Gems *& dest);//Еще один Swap
	void Swap(Gems first, Gems second, Gems playField);//Еще один Swap
	Gems *& operator[](uint index);//Перегруженный оператор [] нужен для объявляения массивов[]
	void Engine();//Главный код игры(смена наших совпашивих с CheckBoxom позиций с нашим полем)
	bool FindBoxesForRemove(Gems **playField);//Найти и уничтожить пустые клетки
	void FallAndGenerate();//Найти пустые и создать новын
	void DestroyJewels(Gems ** playField, bool **BoxesToRemove);//Разрушаем клетки
	bool isEmpty(bool **BoxesToRemove);//Проверка на пустой ли наш массив удаленных клеток
	bool isEmpty(bool BoxesToRemove);
	//bool isEmpty(Gems ** playField);//Проверка на пустое ли наше поле
	//bool isEmpty(Gems *& playField);//Еще одна перегрузка isEmpty
	bool isFull(Gems **playField);//Полное ли наше поле
	int GetScore();//Метод который возвращает нам очки наши
	void SetScore(int scores);//Метод который выставляет нам наши очки
	void ScoreField();//Выводи наши очки
	//int OurColor();//Все цвета кроме черного (Всего 16)
	//int OurBlack();//Наш черный цвет
	//Box(Box (*playField[8][8]));//параметризированный конструктор №1
};