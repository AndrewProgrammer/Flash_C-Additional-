#include "Account.h"
	Account::Account()
	{

	}
	//Account::Account(char*id, char*name, ui balance)
	//{
	//	ID = id;
	//	Name = name;
	//	Balance = balance;
	//}
	Account::~Account(void)
	{

	}
	char* Account::getID()
	{
		return ID;
	}
	void Account::setID(char* id)
	{
		ID = id;
	}
	void Account::setName(char* name)
	{
		Name = name;
	}
	char* Account::getName()
	{
		return Name;
	}
	ui Account::getBalance()
	{
		return Balance;
	}
	void Account::setBalance(ui b)
	{
		Balance = b;
	}
