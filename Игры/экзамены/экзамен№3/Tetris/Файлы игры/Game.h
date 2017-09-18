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
#include <memory> //Библиотека необходимая для подключения умного указателя

const int StartPositionX = 9;//9 - стартовые координаты падения фигурок
const int StartPositionY = 2;//2 - стартовые кординаты падения фигурок (чтоб не было бага, если линия, которая имеет найбольшую высоту,столкнется с верхней гранью)
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
	vector <vector <bool>> vecField; //Наше Главное поле (Вектор векторов, так как как нужно записать тип данных bool и расставить значения на этапе написания кода)
	vector <vector <int>> vecFieldColor;//Цвет наших кубиков на поле (Заполнение по цвету вектором векторов)
	vector<shared_ptr<Figure>> vecFigures;//Вектор умного указателя класса фигуры - наши фигуры
	vector <int> randomFigure;//Задаем рандомные значения фигуре)так как это вектор векторов который  будет зависеть от индекса
	int indexRandom;//индекс для рандомной отображению фигур
	int indexFigure;//индекс фигуры отвечающий за расположение фигур 
	int score;
public:
	//Конструктор параметризированный, который принимает за поле Ширину, и высоту(которая является высотой и еще имеет тип данных bool и также является вектором)
	Game();
	shared_ptr <Figure> nextFigure(); //Создание следующий фигуры после действия
	void ShowField();// показание нашего поля
	void ShowRules(); // Правила игры
	void SetFigureCoordinates(shared_ptr<Figure> Figure, int Position_YF, int Position_XF); //Выставление координат нашего поля 
	void ClearFigureCoordinates(shared_ptr<Figure> Figure, int Position_YF, int Position_XF); //Очистка координат нашего поля // 4 - ПУНКТ ПЛАНА
	bool ControlsAndStartGame(shared_ptr <Figure> figure, int  Position_XF, int Position_YF); // Управление фигурами и стартовые значения для запуска игры
	bool CheckFigureCoordinatesLeftToRight(shared_ptr<Figure> Figure, int Position_XF, int Position_YF); // проверка нашей фигуры вместе с полем на правильное место расположение между двумя фигурами
	bool CheckFigureCoordinatesBottom(shared_ptr<Figure> figure, int Position_XF, int Position_YF); // проверка нашей фигуры на достижение дна поля.
	void ClearLines(); //Очистка заполенной линии и начисление очков // 5 - ПУНКТ ПЛАНА
	int GetScore(); // 3 - ПУНКТ ПЛАНА
};