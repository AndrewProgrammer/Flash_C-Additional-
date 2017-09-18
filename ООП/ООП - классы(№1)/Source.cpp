#include <iostream>
#include "Account.h"
using namespace std;
void main(int argc, char ** argv)
{
	setlocale(0, "ru");
	Account a;
	a.setBalance(124);
	a.setID("#43152");
	a.setName("Denis");
	cout << "ID: " << a.getID() << endl;
	cout << "Name: " << a.getName() << endl;
	cout << "Balance: " << a.getBalance() << endl;
	system("pause");
}