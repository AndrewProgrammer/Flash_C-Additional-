#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;
void main()
{
	srand(time(0));
	const int size = 15;
	char a[size] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', ' ', ' ', ' ' };

	while (true)
	{
		char temp = a[0];
		for (int i = 0; i < size - 1; i++)
			a[i] = a[i + 1];
		a[size - 1] = temp;

		for (int i = 0; i < size; i++)
			cout << a[i];
		Sleep(100);
		cout << '\r';
	}
}