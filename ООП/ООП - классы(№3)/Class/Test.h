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
	struct queue
	{
		int key;
		queue* next;
		queue* back;
	};
	class queue2
	{
	private:
		queue*begin;
	public:
		queue2()
		{
			begin = 0;
		}
		void Push(int d)
		{
			queue*p = new queue;
			p->key = d;
			p->next = 0;
			if (begin == 0)
			{
				begin = p;
				(begin)->back = 0;
			}
			else
				while (1)
				{
					if ((begin)->next == 0)
					{
						begin->next = p;
						break;
					}
					queue* temp = begin;
					begin = (begin)->next;
					(begin)->back = temp;
				}
			while (1)
			{
				if (begin->back == 0)
					break;
				begin = begin->back;
			}
		}
			int Pop()
			{
				int temp = begin->key;
				queue *pv = begin;
				begin = begin->next;
				delete pv;
				return temp;
			}
	};
	class Queue
	{
	private:
		int *arr;
		int index;
		int top;
		int min;
	public:
		Queue(int size)
		{
			top = size;
			index = 0;
			min = 0;
			arr = new int[size]; 
		}
		~Queue()
		{
			delete[] arr;
		}
		void Push(int k)
		{
			if (index < top)
			{
				arr[index] = k;
				index++;
			}
		}
		int Pop()
		{
			if (min < index)
			{
				return arr[min++];
			}
		}
		void resize()
		{
			min = 0;
			index = 0;
		}
	};

}
