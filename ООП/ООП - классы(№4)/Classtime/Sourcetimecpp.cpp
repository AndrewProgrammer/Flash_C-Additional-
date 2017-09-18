#include <iostream>
#include "Time.h"
using namespace std;
void main(int argc, char ** argv)
{
	setlocale(0, "ru");
	time t1(4500);
	time t2(2, 35, 21);
	time t3;
	t3 = t1 + t2;//t1.operator+(t2);
	cout << "Полученное время: " << t3 << "-> dsadf" << endl;
	system("pause");
}