#include <iostream>
#include <fstream>
#include "Vector_cls_Ex.h"
using namespace std;
void main()
{
	setlocale(0, "ru");
	Vector_cls_Ex v1(30, 50);
	Vector_cls_Ex v2(6.56, 1.34, Polar);
	cout << v1 + v2;
	system("pause");
}