#pragma once
	typedef unsigned int  ui;
	class Account
	{
	private:
		char * ID;
		char * Name;
		ui Balance;
	public:
		Account();
		~Account(void);
	/*	Account(char* id ="¹", char* name ="", ui balance = 0);*/
		void	setID(char*);
		char*   getID();
		void	setName(char*);
		char*   getName();
		ui		getBalance();
		void    setBalance(ui);
	};
