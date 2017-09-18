#include "Test.h"
namespace Program
{
	Account::Account(void)
	{
		Name = "";
		ID = "¹ 0";
		Balance = 0;
		Max = 999999;
	}
	Account::Account(char*id, char*name, ui balance)
	{
		Max = 999999;
		ID = id;
		Name = name;
		if (balance < Max)
			Balance = balance;
		else Balance = 0;
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
		if (b < Max)
			Balance = b;
		else Balance = 0;
	}
	void Account::AddBalance(ui add)
	{
		if (Balance + add < Max)
		{
			Balance += add;
		}
		else Balance = Balance;
	}
	void Account::TakeMoney(ui take)
	{
		if (take <= Balance)
			Balance -= take;
	}
	Account Account::MAX(Account& object)
	{
		if (Balance < object.getBalance())
		{
			return object;
		}
		else return *this;
	}
}
