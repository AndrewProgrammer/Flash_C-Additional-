#include <iostream>
#include <Windows.h>
using namespace std;

struct instrument
{
	COORD pos;
	char sym;
};


void main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE h_in = GetStdHandle(STD_INPUT_HANDLE);

	CONSOLE_CURSOR_INFO cc;
	cc.bVisible = false;
	cc.dwSize = 100;
	SetConsoleCursorInfo(h, &cc);

	COORD c;
	c.X =2;
	c.Y = 2;
	// vkluchenie regima mishki v konsoli
	SetConsoleMode(h_in, ENABLE_MOUSE_INPUT);
	INPUT_RECORD all_events[256];
	DWORD read_event;

	/*instrument items[5];
	for (size_t i = 0; i <5; i++)
	{
		items[i].pos = {2*i+1, 2 };
		items[i].sym = i + 2;
		c.X = items[i].pos.X;
		c.Y = items[i].pos.Y;
		SetConsoleCursorPosition(h, c);
		cout << items[i].sym;
	}*/

	

/*
	SetConsoleCursorPosition(h,c);
	cout << "*";
	c.X = 4;
	c.Y = 2;
	SetConsoleCursorPosition(h, c);
	cout << char( 177);
	c.X = 6;
	c.Y = 2;
	SetConsoleCursorPosition(h, c);
	cout << "-";*/

	char sym = ' ';
	while (1)
	{
		ReadConsoleInput(h_in, all_events, 256, &read_event);
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;
			
			/*for (size_t i = 0; i < 5; i++)
			{
				SetConsoleCursorPosition(h, COORD{ 1, 1 });
				cout << "\t\t";
				SetConsoleCursorPosition(h, COORD{ 1, 1 });
				cout << c.X << " " << c.Y << endl;
				if (items[i].pos.X == c.X
					&&items[i].pos.Y == c.Y
					&& all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					sym = items[i].sym;
				}
			}*/
			/*if (c.X == 2 && c.Y == 2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				sym = '*';
			}
			if (c.X == 4&& c.Y == 2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				sym = char(177);
			}
			if (c.X == 6 && c.Y == 2 && all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				sym = '-';
			}*/

			if (c.X >= 5 && c.X <= 20 && c.Y >= 5 && c.Y <= 20)
			{
				if (all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					SetConsoleCursorPosition(h, c);
					SetConsoleTextAttribute(h, (DWORD)4 << 4 | 6);
					cout << sym;
				}
				if (all_events[i].Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
				{
					SetConsoleCursorPosition(h, c);
					SetConsoleTextAttribute(h, (DWORD)4 << 4 | 6);
					cout << " ";
				}
			}

		}
	}
	
}
