#pragma once
#include <math.h>
#include <fstream>
#include <iostream>
using namespace std;
enum vec {Decart,Polar};
class Vector_cls_Ex
{
	typedef unsigned int ui;
private:
	const char symbol_grad = 248;
	double x;
	double y;
	double angle; // полярная система координат
	double modul;
	void Dec_to_polar()
	{
		modul = sqrt(x*x + y*y);
		angle = atan2(x,y);
	}
	void polar__to_Dec()
	{
		x = cos(angle) * modul;
		y = sin(angle) * modul;
	}
	vec Mode;
public:
	Vector_cls_Ex()
	{
		Mode = Decart;
		x = 0;
		y = 0;
		Dec_to_polar();
	}
	Vector_cls_Ex(double a, double b,vec mode = Decart)
	{
		if (mode == Decart)
		{
			Mode = mode;
			x = a;
			y = b;
			Dec_to_polar();
		}
		else if (mode == Polar)
		{
			Mode = mode;
			modul = a;//растояние
			angle = b;// угол
			polar__to_Dec();
		}
	}
	double operator+()
	{
		return modul;
	}
	void ChangeMode(vec mode)
	{
		Mode = mode;
	}
	Vector_cls_Ex operator+(const Vector_cls_Ex& v) const
	{
		Vector_cls_Ex result;
		result.x = x + v.x;
		result.y = y + v.y;
		result.Dec_to_polar();
		return result; // без типа данных оператор (Vector_cls_Ex) работать не будет так как невозможно преобразовать тип данных void к double
	}
	Vector_cls_Ex operator-()const
	{
		return Vector_cls_Ex(-x, -y, Decart);
	}
	Vector_cls_Ex operator *(double A)const
	{
		return Vector_cls_Ex(x * A, y * A);
	}
	friend  Vector_cls_Ex operator *(double A, const Vector_cls_Ex & v1)//служит для смены местами объектов
	{
		return v1*A;//Реализует вот такой пример 3 * v1 будет преобразовано в (-> v1*3(Такая операция уже возможна))
	}
	friend ostream& operator <<(ostream & os, const Vector_cls_Ex& v1)
	{
		if (v1.Mode == Decart)
		{
			os << "X: " << v1.x << " , Y: " << v1.y;
		}
		else os << "Module: " << v1.modul << ", angle" << v1.symbol_grad <<": " << v1.angle * (180 / 3.14159265358979323846); // 3.14159265358979323846 - число M_PI(ПИ)
		return os;
	}
};

