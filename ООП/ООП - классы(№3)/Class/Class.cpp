#include <iostream>
#include "Test.h"
using namespace std;
using Program::Account;
using Program::Stack1;
using Program::Stack2;
using Program::queue2;
void main(int argc, char ** argv)
{
	setlocale(0, "ru");
	queue2 q;
	for (int i = 0; i < 5; i++)
	{
		q.Push(i + 1);
	}
	for (int j = 0; j < 5; j++)
	{
		cout << q.Pop() << " ";
	}
	/*Stack1 st(5);

	for (int i = 0; i < 4; i++)
	{
		st.Push(i + 1);
	}

	for (int i = 0; i < 4; i++)
	{
		cout << st.Pop() << endl;
	}*/
	/*st.Push(2);
	st.Pish(14);
	st.Push(3);
	cout << st.Pop() << endl;
	cout << st.Pop() << endl;
	cout << st.Pop() << endl;
	Account a("#12421","Denis" , 1000);
	Account b("#12421", "Denis", 2000);
	Account c();
	cout << "Your Balance is: " << a.getBalance() << endl;
	cout << "Your Balance is: " << b.getBalance() << endl;
	cout << "Balance of higher object: " << (a.MAX(b)).getBalance();*/

	system("pause");
}