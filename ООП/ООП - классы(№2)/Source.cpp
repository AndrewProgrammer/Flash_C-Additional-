#include <iostream>
#include "Account.h"
using namespace std;
using Program::Account;
using Program::Stack1;
using Program::Stack2;
void main(int argc, char ** argv)
{
	setlocale(0, "ru");
	Account a("#12421","Denis" , 1000);
	Account b("#12421", "Denis", 2000);
	cout << "Your Balance is: " << a.getBalance() << endl;
	cout << "Your Balance is: " << b.getBalance() << endl;
	cout << "Balance of higher object: " << (a.MAX(b)).getBalance();

	system("pause");
}