#pragma once
#include <iostream>
using namespace std;
namespace Program
{
	typedef unsigned int  ui;
	class Account
	{
	private:
		char * ID;
		char * Name;
		ui Balance;
		ui Max;
	public:
		Account(void);
		Account(char* id, char* name = "", ui balance = 0);
		void	setID(char*);
		char*   getID();
		void	setName(char*);
		char*   getName();
		ui		getBalance();
		void    setBalance(ui);
		void AddBalance(ui);
		void TakeMoney(ui);
		Account MAX(Account&);
		~Account(void);
	};
	class Stack1
	{
	private:
		int* arr;
		int Max;
		int index;
	public:
		Stack1(int number)
		{
			Max = 1000;
			index = 0;
			if (number <= Max)
			{
				arr = new int[number];
				Max = number;
			}
			else cout << "������������ �����!" << endl;
		}
		~Stack1()
		{
			delete[] arr;
		};
		bool Push(int n) // ��������� ������� � ����
		{
			if (index == Max)
				return false;
			else
			{
				arr[index] = n;
				index++;
				return true; //EXIT_SUCCESS
			}
		}
		int Pop() //����������� ������� �� �����
		{
			if (index < 0)
				return -1;
			else
			{
				return arr[--index];
			}
		}
		bool is_Empty() // ��������� �� �� ��� ���� ����
		{
			if (index < 0)
				return true;
			else return false;
		}
		bool is_Full() // �������� �� ������������
		{
			if (index == Max)
				return true;
			else return false;
		}
	};
	struct Stek
	{
		int key;
		Stek* next;
	};
	class Stack2
	{
	private:
		Stek * next;
	public:
		Stack2();
		void Push(int d)
		{
			Stek*pv = new Stek; //��������� ����� ������������ ���������� ���� stek
			pv->key = d; //���������� ��������, ������� ����������� � ����
			pv->next = next; // ��������� ����� ������� ����� � ����������
			next = pv; // ����� ������� ����� ���������� ��� ��������	
		}
		int Pop()
		{
			int temp = next->key; // ��������� � ���������� temp �������� � ������� �����
			Stek *pv = next; // ���������� ��������� �� ������� �����, ����� �����
			next = next->next; // ���������� ���������� ��� ���� ������
			delete pv; // ����������� ������, ��� ����� ������� �������
			return temp; // ���������� ��������, ������� ���� � �������
		}
	};

}
