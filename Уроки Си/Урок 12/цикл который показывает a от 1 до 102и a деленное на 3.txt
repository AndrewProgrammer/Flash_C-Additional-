#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int a = 0;
	while (cout << (a += 3) << endl && a <= 100);
}