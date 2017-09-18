#include <iostream>
using namespace std;
void main()
{
	int y;
	cout << "Enter year\n";
	cin >> y;
	if (y % 4 == 0 && (y / 100) % 4 == 0)
	{
		cout << "This is a leap year!\n" << endl;
	}
	else cout << "This year isn`t leap!\n" << endl;
}