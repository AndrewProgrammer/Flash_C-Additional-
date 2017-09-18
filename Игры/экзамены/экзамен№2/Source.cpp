#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //����������� �����-������
#include <stdlib.h> //��������� ������� ������ ����������
#include <time.h> //��������� ���� � �������, ��������� � ����� � ��������
#include <conio.h>//���������� ����-�����
#include <windows.h>//����������� �������, ��������� ���������
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void SetCur(int x, int y);// ����������� ������� � �������� �����
void mainMenu();// ������� ���� ����
void setColor(int text, int background);// ������� �����
void Level(int n);// �������� ���������� ������ � ������
void editorLvl();// �������� �������
void Gameprocces(bool career);//����
void addApple();// ���������� ������
void line(int n, char s);// ������ ����� ������������ ����� � �������
void showLevelNumber(int n);// ����� �������� ������
void addDiz(int k);// ��������� ��������� ����� ��������������
void addLife();// ��������� ����� �� ������� ����
void addSuperSpeed(int k);// ��������� ������������� �� ������� ����

enum directions{ UP, RIGHT, DOWN, LEFT };// ������������ �����������
enum color{
	BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKPURPLE, DARKYELLOW,
	LOWWHITE, GREY, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE
};// ������������ ������
const int width = 80;// ������ �������� ����
const int height = 40;// ������ �������� ����
int field[height][width];// ������� ����
const int startLengthSnake = 3;// ��������� ����� ����
const int startSpeed = 120;// ��������� �������� ��������
bool debug = 0;// ���������� �����
COORD *snake;// ���������� ����
COORD apple;// ���������� ������
COORD *diz;// ���������� ���������������
COORD *superSpeed;// ���������� ��������������
COORD life;// ���������� �����
COORD *delete2; // ������� �� 2
void SetCur(int X, int Y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = X;
	pos.Y = Y;
	SetConsoleCursorPosition(h, pos);
}
void setColor(int text, int background)
{
	int ConsoleColor = text + background * 16;
	SetConsoleTextAttribute(h, ConsoleColor);
}
void main()
{
	system("title SNAKE");// ��������� ����
	system("mode con cols=120 lines=50");// ��������� ������� ����
	CONSOLE_CURSOR_INFO x;// ������� ��������� �������
	x.bVisible = false;
	x.dwSize = 100;
	SetConsoleCursorInfo(h, &x);
	while(1)
	{
		mainMenu();
	}
	system("pause");
}
void PrintLogo()
{
	system("mode con lines=120 lines=50");
	cout << R"XXX( 
           .----------------.  .-----------------. .----------------.  .----------------.  .----------------. 
          | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
          | |    _______   | || | ____  _____  | || |      __      | || |  ___  ____   | || |  _________   | |
          | |   /  ___  |  | || ||_   \|_   _| | || |     /  \     | || | |_  ||_  _|  | || | |_   ___  |  | |
          | |  |  (__ \_|  | || |  |   \ | |   | || |    / /\ \    | || |   | |_/ /    | || |   | |_  \_|  | |
          | |   '.___`-.   | || |  | |\ \| |   | || |   / ____ \   | || |   |  __'.    | || |   |  _|  _   | |
          | |  |`\____) |  | || | _| |_\   |_  | || | _/ /    \ \_ | || |  _| |  \ \_  | || |  _| |___/ |  | |
          | |  |_______.'  | || ||_____|\____| | || ||____|  |____|| || | |____||____| | || | |_________|  | |
          | |              | || |              | || |              | || |              | || |              | |
          | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
           '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 
)XXX";
}
void PrintLogo2()
{
	COORD c1 = { 20, 24 };
	SetConsoleCursorPosition(h, c1);
	cout << R"XXX(                                                                                                                                                                                                                                                                                           
                             +-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+-+
                             |C|r|e|a|t|e|d| |b|y| |A|n|d|r|e|w| |L|y|k|i|a|n|c|h|i|k|o|v|
                             +-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+-+ )XXX";

}
void mainMenu()
{
	char keyMenu = 0;// ������� ������� � ����
	short menuPos = 1;// ������� � ����
	short menuMaxElem = 3;// ���������� ��������� � ���� 
	SetConsoleTextAttribute(h, 10);
	PrintLogo();
	PrintLogo2();
	while (true)
	{
		SetCur(55, 15);
		setColor(CYAN, BLACK);
		cout << "~~~~~~~~~~~~~~";
		SetCur(55, 16);
		setColor(YELLOW, BLACK);
		cout << "   NEW GAME     ";
		SetCur(55, 17);
		setColor(CYAN, BLACK);
		cout << "~~~~~~~~~~~~~~";
		SetCur(55, 18);
		setColor(YELLOW, BLACK);
		cout << "Desing Levels";
		SetCur(55, 19);
		setColor(CYAN, BLACK);
		cout << "~~~~~~~~~~~~~~";
		SetCur(55, 20);
		setColor(YELLOW, BLACK);
		cout << "     Exit     ";
		SetCur(55, 21);
		setColor(CYAN, BLACK);
		cout << "~~~~~~~~~~~~~~";
		switch (menuPos)// ����������� ������ ���� � ����������� �� �������
		{

		case 1:
			SetCur(55, 15);
			setColor(CYAN, BLACK);
			cout << "~~~~~~~~~~~~~~";
			SetCur(55, 16);
			setColor(GREEN, BLACK);
			cout << "   NEW GAME     ";
			SetCur(55, 17);
			setColor(CYAN, BLACK);
			cout << "~~~~~~~~~~~~~~";
			break;
		case 2:
			SetCur(55, 18);
			setColor(GREEN, BLACK);
			cout << "Desing Levels";
			SetCur(55, 19);
			setColor(CYAN, BLACK);
			cout << "~~~~~~~~~~~~~~";
			break;
		case 3:
			SetCur(55, 20);
			setColor(GREEN, BLACK);
			cout << "     Exit     ";
			SetCur(55, 21);
			setColor(CYAN, BLACK);
			cout << "~~~~~~~~~~~~~~";
			break;
		}
		keyMenu = _getch();
		if (keyMenu == 0 || keyMenu == 224)// ���������� �������� ��� ������� �� ������� ��� F ������� 
			keyMenu = _getch();

		switch (keyMenu)// �������� ������� �������
		{
		case 72:// ������� �����
			if (menuPos == 1)
				menuPos = menuMaxElem;
			else
				--menuPos;
			break;
		case 80:// ������� ����
			if (menuPos == menuMaxElem)
				menuPos = 1;
			else
				++menuPos;
			break;
		case 13:// Enter
			if (menuPos == 1)
			{
				short menuPosGame = 1;// ������� � ����
				short menuMaxElemGame = 3;// ���������� ��������� � ���� 
				while (true)
				{
					setColor(WHITE, BLACK);
					SetCur(55, 16);
					setColor(YELLOW, BLACK);
					cout << "    Career               ";
					SetCur(55, 18);
					cout << "Survival mode            ";
					SetCur(55, 20);
					setColor(YELLOW, BLACK);
					cout << "     Back               ";
					switch (menuPosGame)// ����������� ������ ���� � ����������� �� �������
					{
					case 1:
						SetCur(55, 16);
						setColor(GREEN, BLACK);
						cout << "    Career       ";
						break;
					case 2:
						SetCur(55, 18);
						setColor(GREEN, BLACK);
						cout << "Survival mode    ";
						break;
					case 3:
						SetCur(55, 20);
						setColor(GREEN, BLACK);
						cout << "     Back        ";
						break;
					}

					keyMenu = _getch();
					if (keyMenu == 0 || keyMenu == 224)// ���������� �������� ��� ������� �� ������� ��� F ������� 
						keyMenu = _getch();

					switch (keyMenu)// �������� ������� �������
					{
					case 72:// ������� �����
						if (menuPosGame == 1)
							menuPosGame = menuMaxElemGame;
						else
							--menuPosGame;
						break;
					case 80:// ������� ����
						if (menuPosGame == menuMaxElemGame)
							menuPosGame = 1;
						else
							++menuPosGame;
						break;
					case 13:// Enter
						if (menuPosGame == 1)
						{
							Gameprocces(1);
							return;
						}
						else if (menuPosGame == 2)
						{
							Gameprocces(0);
							return;
						}
						else if (menuPosGame == 3)
						{
							return;
						}
						break;
					case 27:
						return;
					}
				}
			}
			else if (menuPos == 2)
			{
				editorLvl();
				return;
			}
			else if (menuPos == 3)
			{
				exit(0);
			}
			break;
		case 27:
			exit(0);
		}
	}
}

void ADDDELETE2(int k)
{
	delete[]delete2;
	delete2 = new COORD[k];
	for (int i = 0; i < k; i++)
	{
		while (true)
		{
			delete2[i].X = rand() % width + 1;
			delete2[i].Y = rand() % height + 8;
			if (field[delete2[i].Y - 8][delete2[i].X - 1] == 0)
			{
				SetConsoleCursorPosition(h, delete2[i]);
				setColor(YELLOW, BLACK);
				cout << char(47);
				setColor(GREEN, BLACK);
				field[delete2[i].Y - 8][delete2[i].X - 1] = 7;
				break;
			}
		}
	}
}
void Loading()
{
	system("cls");
	setColor(GREY, BLACK);
	SetCur(0, 0);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false };
	SetConsoleCursorInfo(h, &cci);
	int x = 0, y = 25;
	char s = 219;
	COORD c = { 0, 24 };
	SetConsoleCursorPosition(h, c);
	cout << "LOADING...";

	SetConsoleTextAttribute(h, 10);
	while (x < 120)
	{
		c.X = x, c.Y = 25;
		SetConsoleCursorPosition(h, c);
		cout << s;
		c.Y++;
		SetConsoleCursorPosition(h, c);
		cout << s;
		c.Y++;
		SetConsoleCursorPosition(h, c);
		cout << s;
		x++;
		Sleep(30);
	}

	SetConsoleTextAttribute(h, 10);
	c.X = 0, c.Y = 24;
	SetConsoleCursorPosition(h, c);
	cout << "LOADING DONE";
	SetCur(0, 28);
	setColor(GREEN, BLACK);
	cout << "Press any button to start";
	_getch();
	system("cls");
}
void LOGOSNAKE()
{
	SetCur(0, 0);
	cout << R"XXX(
                             ____  ____,   ___,   __  _, ____,
                            (-(__`(-|  |  (-|_\_,(-|_/  (-|_, 
                             ____) _|  |_, _|  )  _| \_, _|__,
)XXX";
}
void LOGOEDITOR()
{
	SetCur(35, 0);
	setColor(YELLOW, BLACK);
	cout << R"XXX(
                     ___     ___     ___    _____    ___     ___              _     __   __   _     
                    | __|   |   \   |_ _|  |_   _|  / _ \   | _ \     o O O  | |    \ \ / /  | |    
                    | _|    | |) |   | |     | |   | (_) |  |   /    o       | |__   \ V /   | |__  
                    |___|   |___/   |___|   _|_|_   \___/   |_|_\   TS__[O]  |____|  _\_/_   |____| 
                   _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| {======|_|"""""|_| """"|_|"""""| 
                   "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'
)XXX";
}
void Level(int n)
{
	FILE *f;
	int c = 0;// �������� �������� ���������� �������
	char *path = new char[MAX_PATH];
	if (n == 0)// ����� �� ���������
	{
		strcpy(path, "levels/mylevel.txt");
		f = fopen(path, "a+");
	}
	else// ����� �������
	{
		char *numlev = new char[3];
		strcpy(path, "levels/level");
		_itoa(n, numlev, 10); // ������� itoa ����������� ����� ����� value � ������ string. � ������ ����� value ����������� ANSI ������� ���� char � ������������ � ������ string.
		strcat(path, numlev);// ��������� ���� ������ � ������
		strcat(path, ".txt");
		f = fopen(path, "a+");
		delete[]numlev;
	}
	SetCur(0, 7);// ��������� �������� ����
	setColor(GREEN, BLACK);
	for (int y = 0; y < height + 2; ++y)
	{
		for (int x = 0; x < width + 2; ++x)
		{
			if (x == 0 || y == 0 || x == width + 1 || y == height + 1)
				cout << char(219);
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < height; ++i)// ��������� �������
	{
		for (int j = 0; j < width; ++j)
		{
			field[i][j] = 0;
		}
	}
	bool error = 0;
	for (int i = 0; i < height; ++i)// ���������� � �����
	{
		for (int j = 0; j < width; ++j)
		{
			if (feof(f))// ��������������� ����� �����
			{
				fclose(f);// �������� �����
				f = fopen(path, "w+");// �������� � ���������� �����
				for (int i = 0; i < height; ++i)// ��������� �������
				{
					for (int j = 0; j < width; ++j)
					{
						field[i][j] = 0;
					}
				}
				for (int i = 0; i < height; ++i)// ���������� ����� ������
				{
					for (int j = 0; j < width; ++j)
					{
						fputc('0', f);//������� fputc ���������� ������ � ����� � ���������� ������� ���������� ���������.
					}
					if (i == height)
						break;
					fputc('\n', f);
				}
				SetCur(0, 0);
				cout << " Error" << path << "\nPress anykey for continue";
				_getch();
				SetCur(0, 0);
				line(100, ' ');
				SetCur(0, 1);
				line(100, ' ');
				fclose(f);
				error = 1;
				break;
			}
			c = fgetc(f);//������� fgetc ���������� ������ �� ������� ��������� ���������� ��������� ������� ����� ���������� ������
			if ((int)c != 13 && (int)c != 10)// ������ ������� �������� ������ � �������� �������
			{
				field[i][j] = c - 48;// �.� ����������� ��� �������, ����� ������ 48 ��� ��������� �����
			}
			else
				--j;// ������� �������� ���� ���������� ������ �������� ������ � �������� �������
		}
		if (error)// ��� ������ ���������� ����������
			break;
	}
	field[27][39] = 0;// ������������ ����� ������� ����
	field[26][39] = 0;
	field[25][39] = 0;
	field[28][39] = 0;
	delete[]path;// ���������� ������
	fclose(f);// ������� ����

	setColor(GREEN, BLACK);
	for (int y = 8; y < height + 8; ++y)// ��������� ������
	{
		for (int x = 1; x < width + 1; ++x)
		{
			SetCur(x, y);
			if (field[y - 8][x - 1] == 1)
			{
				setColor(WHITE, BLACK);
				cout << '*';
				setColor(GREEN, BLACK);
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
}
void editorLvl()
{
	Loading();
	LOGOEDITOR();
	SetCur(0, 7);
	setColor(GREEN, BLACK);
	for (int y = 0; y < height + 2; ++y)
	{
		for (int x = 0; x < width + 2; ++x)
		{
			if (x == 0 || y == 0 || x == width + 1 || y == height + 1)
				cout << char(219);
			else
				cout << " ";
		}
		cout << "\n";
	}
	FILE *f;
	char *path = new char[MAX_PATH];// ���� � �����
	strcpy(path, "levels/mylevel.txt");
	f = fopen(path, "ab+");

	bool error = 0;
	int s = 0;
	for (int i = 0; i < height; i++)// ���������� � �����
	{
		for (int j = 0; j < width; j++)
		{
			if (feof(f))// ��������������� ����� �����
			{
				fclose(f);// �������� �����
				f = fopen(path, "wb+");// �������� � ���������� �����
				for (int i = 0; i < height; i++)// ��������� �������
				{
					for (int j = 0; j < width; j++)
					{
						field[i][j] = 0;
					}
				}
				for (int i = 0; i < height; i++)// ���������� ����� ������
				{
					for (int j = 0; j < width; j++)
					{
						fputc('0', f);
					}
					if (i == height)
						break;
					fputc('\n', f);
				}
				SetCur(0, 0);
				cout << " Error" << path << "\nPress anykey for continue";
				_getch();
				SetCur(0, 0);
				line(100, ' ');
				SetCur(0, 1);
				line(100, ' ');
				fclose(f);
				error = 1;
				break;
			}
			s = fgetc(f);
			if (s != 13 && s != 10)// ������ ������� �������� ������ � �������� �������
			{
				field[i][j] = s - 48;// �.� ����������� ��� �������, ����� ������ 48 ��� ��������� �����
				SetCur(j + 1, i + 8);
				if (field[i][j] == 1)
				{
					setColor(WHITE, BLACK);
					cout << '*';
					setColor(GREEN, BLACK);
				}
				else
					cout << " ";
			}
			else
				--j;// ������� �������� ���� ���������� ������ �������� ������ � �������� �������
		}
		if (error)
			break;
	}
	HANDLE h2 = GetStdHandle(STD_INPUT_HANDLE);// ���������� �����
	SetConsoleMode(h2, ENABLE_MOUSE_INPUT);// �������� ����� ������������� ����
	INPUT_RECORD all_events[256];// ������  ������������ �������
	DWORD e;// ���������� ������������ �������
	COORD c;
	char brush = '*';

	SetCur(86, 8);
	setColor(YELLOW, BLACK);
	cout << "Controls";

	SetCur(86, 10);
	setColor(GREEN, BLACK);
	cout << "Save your work";

	SetCur(86, 14);
	setColor(WHITE, BLACK);
	cout << "Brush";

	SetCur(86, 18);
	setColor(PURPLE, BLACK);
	cout << "Delete";

	SetCur(86, 22);
	setColor(RED, BLACK);
	cout << " Esc";

	SetCur(0, 0);
	setColor(WHITE, BLACK);
	while (true)
	{
		ReadConsoleInput(h2, all_events, 256, &e);
		for (int i = 0; i < e; ++i)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;
			if (all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y > 7 && c.Y < 48 && c.X > 0 && c.X < 81)// ��������� �� ����
			{
				if (brush == '*')
				{
					SetConsoleCursorPosition(h, c);
					field[c.Y - 8][c.X - 1] = 1;
					cout << brush;
				}
				else
				{
					SetConsoleCursorPosition(h, c);
					field[c.Y - 8][c.X - 1] = 0;
					cout << ' ';
				}
			}
			else if (all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y == 14 && c.X >= 86 && c.X <= 94)// ����� �����������
			{
				if (brush == '*')
				{
					SetCur(86, 14);
					setColor(WHITE, BLACK);
					cout << "Paint  ";
					brush = '#';
				}
				else
				{
					SetCur(86, 14);
					setColor(WHITE, BLACK);
					cout << "Brush";
					brush = '*';
				}
			}
			else if (all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y == 18 && c.X >= 86 && c.X <= 94)// �������� �����
			{
				SetCur(86, 14);
				setColor(WHITE, BLACK);
				cout << "Brush";
				brush = '*';
				for (int i = 0; i < height; ++i)
				{
					for (int j = 0; j < width; ++j)
					{
						field[i][j] = 0;
					}
				}
				SetCur(0, 7);
				setColor(GREEN, BLACK);
				for (int y = 0; y < height + 2; ++y)
				{
					for (int x = 0; x < width + 2; ++x)
					{
						if (x == 0 || y == 0 || x == width + 1 || y == height + 1)
							cout << char(219);
						else
							cout << " ";
					}
					cout << "\n";
				}
				setColor(WHITE, BLACK);
			}
			else if (all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y == 22 && c.X >= 86 && c.X <= 94)// �����
			{
				system("cls");
				return;
			}
			else if (all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y == 10 && c.X >= 86 && c.X <= 94)// ���������
			{
				FILE *f;
				char *ps = "\n";
				SetCur(1, 3);

				f = fopen("levels/mylevel.txt", "w+");
				for (int i = 0; i < height; ++i)
				{
					for (int j = 0; j < width; ++j)
					{
						char *s = new char[2];
						_itoa(field[i][j], s, 10);
						fputs(s, f);
						delete s;
					}
					if (i == height - 1)
						break;
					fputc(*ps, f);
				}
				fclose(f);
				system("cls");
				return;
			}
		}
	}
}
void Gameprocces(bool career)
{
	system("cls");
	srand(time(0));
	Loading();
	int lengthSnake = startLengthSnake;// ������� ����� ����
	int speed = 70;// ������� ��������
	int speed2 = 50;
	int Delete2 = 2;
	int direction = UP;// ����������� ��������
	int banDirection = DOWN;// ����������� ����������� ��������
	char key = 0;// ��� ������� �������
	int pointsTemp = 0;
	bool flag = 1;// ��������� ����, 1 �������, 0 ��������
	int level = 1;// ������� �������
	int appleslost = 1;// ������� ����� �� ������
	int livessnake = 5;// ���������� ������
	int dizCount = 2;// ���������� ����������������
	bool dizflag = 0;// ������ ������ ���������������
	int Super_Speed_Count = 2;// ������ ������ �������������
	bool SuperSpeedflag = 0;// ���������� ��������������
	int delete2_Count = 2;//���������� ����������
	bool delete2flag = 0;//������ ����������
	int lifeTime = 0;// ����� ����������� ����� �����
	snake = new COORD[lengthSnake];// �������� ����

	if (career)
	{
		SetCur(84, 12);
		setColor(RED, BLACK);
		cout << char(4);
		setColor(WHITE, BLACK);
		cout << "  Apples";

		SetCur(84, 14);
		setColor(GREEN, BLACK);
		cout << char(3);
		setColor(WHITE, BLACK);
		cout << "  Lifes";

		SetCur(84, 16);
		setColor(BLUE, BLACK);
		cout << char(15);
		setColor(WHITE, BLACK);
		cout << "  Dizing";

		SetCur(84, 18);
		setColor(YELLOW, BLACK);
		cout << char(15);
		setColor(WHITE, BLACK);
		cout << "  Fastspeed";

		SetCur(84, 20);
		setColor(CYAN, BLACK);
		cout << char(253);
		setColor(WHITE, BLACK);
		cout << "  Delete/2";
	}
	setColor(GREEN, BLACK);
	SetCur(86, 22);
	cout << " Controls";
	setColor(YELLOW, BLACK);
	SetCur(90, 24);
	cout << char(24);
	SetCur(94, 26);
	cout << char(26);
	SetCur(86, 26);
	cout << char(27);
	SetCur(90, 28);
	cout << char(25);

	SetCur(84, 30);
	setColor(CYAN, BLACK);
	cout << "Pause:";
	SetCur(92, 30);
	setColor(WHITE, BLACK);
	cout << "Enter";

	SetCur(84, 32);
	setColor(RED, BLACK);
	cout << "ESC:";
	SetCur(92, 32);
	setColor(WHITE, BLACK);
	cout << "Escape";

	if (career)
	{
		setColor(WHITE, BLACK);
		SetCur(6, 5);
		cout << "Level: ";
		setColor(RED, BLACK);
		SetCur(21, 5);
		cout << "Apples left: ";
		setColor(PURPLE, BLACK);
		SetCur(49, 5);
		cout << "Snake lives: ";
	}

	SetCur(71, 5);
	setColor(GREEN, BLACK);
	cout << "Score: ";

	SetCur(0, 7);// ��������� �������� ����
	setColor(GREEN, BLACK);
	setlocale(0, "C");
	for (int y = 0; y < height + 2; ++y)
	{
		for (int x = 0; x < width + 2; ++x)
		{
			if (x == 0 || y == 0 || x == width + 1 || y == height + 1)
				cout << char(219);
			else
				cout << " ";
		}
		cout << "\n";
	}
	if (career)
	{
		showLevelNumber(1);//�������� ������
	}

	SetCur(27, 2);// �������� ������������
	setColor(CYAN, BLACK);
	cout << "For starting press Probel";
	while (_getch() != 32);
	SetCur(22, 2);// �������� ������
	line(50, ' ');

	// ��������� ��������� ����
	snake[0].X = 40;
	snake[0].Y = 37;
	snake[1].X = 40;
	snake[1].Y = 38;
	snake[2].X = 40;
	snake[2].Y = 39;
	field[snake[0].Y - 8][snake[0].X - 1] = 3;
	field[snake[1].Y - 8][snake[1].X - 1] = 3;
	field[snake[2].Y - 8][snake[2].X - 1] = 3;
	if (career == 1)
		Level(1);
	else
	{
		Level(0);
		if (pointsTemp % 5 == 0)
		{
			speed % 10;
		}
		else if (pointsTemp % 10 == 0)
		{
			line(1, 'B');
		}
	}
	addApple();
	if (career)// ���������� ������� ���������
	{
		diz = new COORD[dizCount];
		addDiz(dizCount);
		superSpeed = new COORD[Super_Speed_Count];
		addSuperSpeed(Super_Speed_Count);
		delete2 = new COORD[delete2_Count];
		ADDDELETE2(delete2_Count);
	}
	LOGOSNAKE();
	while (true)// ������� ����
	{
		if (debug)
		{
			setColor(7, BLACK);
			SetCur(83, 20);
			cout << "Apple X.Y";
			SetCur(83, 21);
			cout << apple.X << " " << apple.Y << " ";
			SetCur(83, 22);
			cout << "Snake X.Y";
			SetCur(83, 23);
			cout << snake[0].X << " " << snake[0].Y << " ";
			SetCur(84, 24);
			cout << "Lifetime = " << lifeTime << " ";
			SetCur(83, 25);
			cout << "Speed: " << speed << " ";
			SetCur(83, 26);
			cout << "Key code = " << (int)key;
			SetCur(83, 27);
			cout << "\'n\' = next level";
		}
		if (lifeTime < 10 && lifeTime > 1)// ������� ������ �����
		{
			SetConsoleCursorPosition(h, life);
			if (lifeTime % 2)
				cout << " ";
			else
				cout << char(3);
		}

		if (lifeTime > 1)// ���������� ������� ������ �����
			--lifeTime;
		else if (lifeTime == 1)// �������� �����
		{
			SetConsoleCursorPosition(h, life);
			cout << " ";
			field[life.Y - 8][life.X - 1] = 0;
			life.X = 0;
			life.Y = 0;
			--lifeTime;
		}

		SetCur(77, 5);// ������� ���� ������
		setColor(GREEN, BLACK);
		cout << pointsTemp << "    ";
		if (career)
		{
			setColor(PURPLE, BLACK);
			SetCur(61, 5);// ���������� ���������� ������
			cout << livessnake;
			SetCur(33, 5);// ������� �����
			setColor(RED, BLACK);
			cout << appleslost << " ";
			setColor(WHITE, BLACK);// �������
			SetCur(12, 5);
			cout << level;
		}

		if (direction == UP)// ����� ���������� ��������
			banDirection = DOWN;
		else if (direction == RIGHT)
			banDirection = LEFT;
		else if (direction == DOWN)
			banDirection = UP;
		else if (direction == LEFT)
			banDirection = RIGHT;

		while (_kbhit())// ������������ ������� ������
		{
			key = _getch();
			if (key == 0 || key == 224)// ���������� �������� ��� ������� �� ������� ��� F ������� 
			{
				key = _getch();
			}
			if (key == 119 || key == 72 && direction != DOWN && banDirection != UP)
				direction = UP;
			else if (key == 77 && direction != LEFT && banDirection != RIGHT)
				direction = RIGHT;
			else if (key == 80 && direction != UP && banDirection != DOWN)
				direction = DOWN;
			else if (key == 75 && direction != RIGHT && banDirection != LEFT)
				direction = LEFT;
			else if (key == 27)// Esc
			{
				system("cls");
				return;
			}
			else if (key == 13)// ������
			{
				SetCur(3, 2);
				cout << "Pause";
				_getch();
				SetCur(3, 2);
				cout << "     ";
			}

			else if (key == 96)// ������, ��������� � ���������� ����������� ������
			{
				if (debug)
				{
					SetCur(83, 20);
					line(16, ' ');
					SetCur(83, 21);
					line(16, ' ');
					SetCur(83, 22);
					line(16, ' ');
					SetCur(83, 23);
					line(16, ' ');
					SetCur(83, 24);
					line(16, ' ');
					SetCur(83, 25);
					line(16, ' ');
					SetCur(83, 26);
					line(16, ' ');
					SetCur(83, 27);
					line(16, ' ');
					debug = 0;
				}
				else
					debug = 1;
			}
			else if (key == 110 && debug && career)// ������� n, ������� �� ��������� ������� ��� �������
			{
				appleslost = 0;
			}
		}
		SetConsoleCursorPosition(h, snake[0]);// �������� ������ ������
		cout << " ";
		field[snake[0].Y - 8][snake[0].X - 1] = 0;
		SetConsoleCursorPosition(h, snake[lengthSnake - 1]);// �������� ����� ������
		cout << " ";
		field[snake[lengthSnake - 1].Y - 8][snake[lengthSnake - 1].X - 1] = 0;
		for (int i = lengthSnake - 1; i > 0; i--)// ���������� ���������
		{
			snake[i].Y = snake[i - 1].Y;
			snake[i].X = snake[i - 1].X;
		}

		if (!dizflag)// ���������� ��������
		{
			if (direction == UP)// ��������� ��������� ������ � ����������� �� �����������
				--snake[0].Y;
			else if (direction == RIGHT)
				++snake[0].X;
			else if (direction == DOWN)
				++snake[0].Y;
			else if (direction == LEFT)
				--snake[0].X;
		}
		else// �������� � ���������������
		{
			if (direction == UP)// ��������� ��������� ������ � ����������� �� �����������
				++snake[0].Y;
			else if (direction == RIGHT)
				--snake[0].X;
			else if (direction == DOWN)
				--snake[0].Y;
			else if (direction == LEFT)
				++snake[0].X;
		}

		if (career && appleslost <= 0)// �������� ������ ������
		{
			++level;
			if (level == 10)// ��������
			{
				showLevelNumber(10);
				system("cls");
				return;
			}
			// ��������� ��������� ����
			snake[0].X = 40;
			snake[0].Y = 37;
			snake[1].X = 40;
			snake[1].Y = 38;
			snake[2].X = 40;
			snake[2].Y = 39;
			field[snake[0].Y - 8][snake[0].X - 1] = 3;
			field[snake[1].Y - 8][snake[1].X - 1] = 3;
			field[snake[2].Y - 8][snake[2].X - 1] = 3;
			showLevelNumber(level);// �������� �������� ������
			SetCur(12, 2);
			setColor(WHITE, BLACK);
			cout << "You won this level Congratulation" << level << ", press button Probel to start";
			while (_getch() != 32);
			SetCur(3, 2);
			line(80, ' ');
			Level(level);
			LOGOSNAKE();
			appleslost = level * 1;
			Delete2 = 2;
			lengthSnake = 3;
			direction = UP;
			speed -= 3;
			pointsTemp += 1;
			addApple();
			if (career)
			{
				for (int i = 0; i < dizCount; ++i)// �������� ������ ��������������
					field[diz[i].Y - 8][diz[i].X - 1] = 0;
				addDiz(++dizCount);// ���������� ����� ��������������
				if (life.Y != 0)// ���� �������� ������ ����� �� ����
				{
					field[life.Y - 8][life.X + 1] = 0;// �������� ����� � ����
					life.X = 0;
					life.Y = 0;
					lifeTime = 0;
				}
				for (int i = 0; i < Super_Speed_Count; ++i)// �������� ������ ��������������
					field[superSpeed[i].Y - 8][superSpeed[i].X - 1] = 0;
				addSuperSpeed(++Super_Speed_Count);// ���������� ����� ��������������
				for (int i = 0; i < delete2_Count; ++i)// �������� ������ ��������������
					field[delete2[i].Y - 8][delete2[i].X - 1] = 0;
				ADDDELETE2(++delete2_Count);// ���������� ����� ��������������
			}
			continue;
		}
		for (int i = 0; career && (i < dizCount); ++i)// ��������� �� �����������
		{
			if (snake[0].X == diz[i].X && snake[0].Y == diz[i].Y && field[diz[i].Y - 8][diz[i].X - 1] == 4)
			{
				if (direction == UP)// ����� �����������
					direction = RIGHT;
				else if (direction == RIGHT)
					direction = DOWN;
				else if (direction == DOWN)
					direction = LEFT;
				else if (direction == LEFT)
					direction = UP;
				field[diz[i].Y - 8][diz[i].X - 1] == 0;// �������� ��������������
				dizflag = 1;// ��������� ������ ��������������
				break;
			}
		}

		for (int i = 0; career && (i < dizCount); ++i)// ��������� �� �������������
		{
			if (snake[0].X == superSpeed[i].X && snake[0].Y == superSpeed[i].Y && field[superSpeed[i].Y - 8][superSpeed[i].X - 1] == 6)
			{
				field[superSpeed[i].Y - 8][superSpeed[i].X - 1] == 0;// �������� �������������
				SuperSpeedflag = 1;// ��������� ������ �������������
				break;
			}
		}
		for (int i = 0; career && (i < dizCount); ++i)// ��������� �� �������������
		{
			if (snake[0].X == delete2[i].X && snake[0].Y == delete2[i].Y && field[delete2[i].Y - 8][delete2[i].X - 1] == 7)
			{
				field[delete2[i].Y - 8][delete2[i].X - 1] == 0;// �������� �������������
				delete2flag = 1;// ��������� ������ �������������
				break;
			}
		}

		if (snake[0].X == life.X && snake[0].Y == life.Y)// ���� ������� �����
		{
			field[life.Y - 8][life.X + 1] = 0;
			++livessnake;
			life.X = 0;
			life.Y = 0;
			lifeTime = 0;
		}
		if (snake[0].X == apple.X && snake[0].Y == apple.Y)// ���� ������� ������
		{
			if (career)// ����� �������
			{
				--appleslost;
				int t = 0;// ����� ���������� �� ���� � ������ 1/3
				t = rand() % 3;
				if (t == 1)
				{
					SetConsoleCursorPosition(h, life);
					cout << " ";
					addLife();
					lifeTime = 32;
				}
			}
			else
				speed -= 3;
			pointsTemp += 1;
			if (dizflag)
			{
				if (direction == UP)// ����� �����������
					direction = RIGHT;
				else if (direction == RIGHT)
					direction = DOWN;
				else if (direction == DOWN)
					direction = LEFT;
				else if (direction == LEFT)
					direction = UP;
			}
			dizflag = 0;// ���������� �������
			SuperSpeedflag = 0;
			delete2flag = 0;

			COORD *temp = new COORD[lengthSnake];// ��������� ������ ���������
			for (int i = 0; i < lengthSnake; ++i)// ���������� ���� �� ��������� ������
			{
				temp[i] = snake[i];
			}
			delete[]snake;// �������� ������� �������
			snake = new COORD[++lengthSnake];// �������� ������ ������� �� ���� ������� ������ �����������
			for (int i = 0; i < (lengthSnake - 1); ++i)// ������ � ����� ������
			{
				snake[i] = temp[i];
			}
			snake[lengthSnake - 1].X = snake[lengthSnake - 2].X;// ������� ��������� ������ ��������
			snake[lengthSnake - 1].Y = snake[lengthSnake - 2].Y;
			delete[]temp;// �������� ���������� �������

			field[apple.Y - 8][apple.X - 1] = 0;// ������� ���� � �������
			if (appleslost > 0)
				addApple();// ��������� ������ ������
		}
		for (int i = 1; i < lengthSnake; ++i)// �������� �� ������������ � �����
		{
			if (snake[0].X == snake[i].X && snake[0].Y == snake[i].Y)
			{
				flag = 0;
			}
		}
		if (field[snake[0].Y - 8][snake[0].X - 1] == 1 || snake[0].Y <= 7 || snake[0].Y >= height + 8 || snake[0].X <= 0 || snake[0].X >= width + 1 || flag == 0)// �������� �� ������������ � ������������ ��� �����
		{
			--livessnake;// ������ �����
			pointsTemp = 0;
			if (livessnake && career)// ������ ������� ������
			{
				for (int i = 0; i < lengthSnake; i++)// ��������� �������� ����
				{
					SetConsoleCursorPosition(h, snake[i]);
					if (i == 0)
					{
						setColor(DARKCYAN, BLACK);
						cout << char(1);
					}
					else
					{
						setColor(DARKGREEN, BLACK);
						cout << char(253);
					}
				}

				SetCur(12, 2);
				setColor(YELLOW, BLACK);
				cout << "Left lives = " << livessnake;
				if (livessnake == 1)
					cout << " Life =  ";
				else
					cout << " Lifes =  ";
				cout << "Press Probel to start again";
				while (_getch() != 32);
				SetCur(3, 2);
				line(80, ' ');
				if (career)
				{
					Level(level);
					for (int i = 0; career && (i < dizCount); ++i)// �������� ������ ��������������
					{
						field[diz[i].Y - 8][diz[i].X - 1] = 0;
					}
					addDiz(dizCount);
					if (life.Y != 0)// ���� �������� ������ ����� �� ����
					{
						field[life.Y - 8][life.X + 1] = 0;// �������� ����� � ����
						life.X = 0;
						life.Y = 0;
						lifeTime = 0;
					}
					for (int i = 0; i < Super_Speed_Count; ++i)// �������� ������ ��������������
						field[superSpeed[i].Y - 8][superSpeed[i].X - 1] = 0;
					addSuperSpeed(Super_Speed_Count);
					for (int i = 0; i < delete2_Count; ++i)// �������� ������ ��������������
						field[delete2[i].Y - 8][delete2[i].X - 1] = 0;
					ADDDELETE2(delete2_Count);
				}
				else
					Level(0);
				addApple();
				LOGOSNAKE();
				appleslost = level * 5;
				dizflag = 0;
				SuperSpeedflag = 0;
				delete2flag = 0;
				lengthSnake = startLengthSnake;
				direction = UP;
				flag = 1;
				delete[]snake;
				snake = new COORD[lengthSnake];
				// ��������� ��������� ����
				snake[0].X = 40;
				snake[0].Y = 37;
				snake[1].X = 40;
				snake[1].Y = 38;
				snake[2].X = 40;
				snake[2].Y = 39;
				field[snake[0].Y - 8][snake[0].X - 1] = 3;
				field[snake[1].Y - 8][snake[1].X - 1] = 3;
				field[snake[2].Y - 8][snake[2].X - 1] = 3;
				continue;// ���������� ����
			}
			SetCur(13, 2);
			setColor(RED, BLACK);
			cout << "You lose press Probel to menu. \n";
			for (int i = 0; i < lengthSnake; i++)// ��������� ������� ����
			{
				SetConsoleCursorPosition(h, snake[i]);
				if (i == 0)
				{
					setColor(RED, BLACK);
					cout << char(1);
				}
				else
				{
					setColor(DARKGREEN, BLACK);
					cout << char(253);
				}
			}
			while (_getch() != 32);// �������� ������� Probel
			system("cls");
			delete[]snake;
			return;
		}

		for (int i = 0; i < lengthSnake; ++i)// ��������� ����
		{
			field[snake[i].Y - 8][snake[i].X - 1] = 3;
			SetConsoleCursorPosition(h, snake[i]);
			if (i == 0)
			{
				if (dizflag)
					setColor(CYAN, BLACK);
				else if (SuperSpeedflag)
					setColor(YELLOW, BLACK);
				else if (delete2flag)
					setColor(BLUE, BLACK);
				else
					setColor(GREEN, BLACK);
				cout << char(1);
			}
			else
			{
				if (dizflag)
					setColor(BLUE, BLACK);
				else if (SuperSpeedflag)
					setColor(DARKYELLOW, BLACK);
				else if (delete2flag)
					setColor(DARKBLUE, BLACK);
				else
					setColor(DARKGREEN, BLACK);
				cout << char(253);
			}
		}
		if (SuperSpeedflag)
			Sleep(speed2);
		else
			Sleep(speed);
		if (delete2flag)
			if (lengthSnake % 2 == 0)
			{
				lengthSnake / 2;
				pointsTemp = -1;
				livessnake = 1;
			}
			else
				lengthSnake = startLengthSnake;
	}
}
void addApple()
{
	while (true)
	{
		apple.X = rand() % width + 1;
		apple.Y = rand() % height + 8;
		if (field[apple.Y - 8][apple.X - 1] == 0)
		{
			SetConsoleCursorPosition(h, apple);
			setColor(RED, BLACK);
			cout << char(4);
			setColor(GREEN, BLACK);
			field[apple.Y - 8][apple.X + 1] = 2;
			break;
		}
		else
			continue;
	}
}

void addDiz(int k)
{
	delete[]diz;
	diz = new COORD[k];
	for (int i = 0; i < k; i++)
	{
		while (true)
		{
			diz[i].X = rand() % width + 1;
			diz[i].Y = rand() % height + 8;
			if (field[diz[i].Y - 8][diz[i].X - 1] == 0)
			{
				SetConsoleCursorPosition(h, diz[i]);
				setColor(BLUE, BLACK);
				cout << char(15);
				setColor(GREEN, BLACK);
				field[diz[i].Y - 8][diz[i].X - 1] = 4;
				break;
			}
		}
	}
}

void addSuperSpeed(int k)
{
	delete[]superSpeed;
	superSpeed = new COORD[k];
	for (int i = 0; i < k; i++)
	{
		while (true)
		{
			superSpeed[i].X = rand() % width + 1;
			superSpeed[i].Y = rand() % height + 8;
			if (field[superSpeed[i].Y - 8][superSpeed[i].X - 1] == 0)
			{
				SetConsoleCursorPosition(h, superSpeed[i]);
				setColor(YELLOW, BLACK);
				cout << char(15);
				setColor(GREEN, BLACK);
				field[superSpeed[i].Y - 8][superSpeed[i].X - 1] = 6;
				break;
			}
		}
	}
}

void addLife()
{
	while (true)
	{
		life.X = rand() % width + 1;
		life.Y = rand() % height + 8;
		if (field[life.Y - 8][life.X - 1] == 0)
		{
			SetConsoleCursorPosition(h, life);
			setColor(GREEN, BLACK);
			cout << char(3);
			field[life.Y - 8][life.X + 1] = 5;
			break;
		}
	}
}

void line(int n, char s)
{
	for (; n > 0; --n)
		cout << s;
}
void showLevelNumber(int n)
{
	SetConsoleTextAttribute(h, 10);
	for (int y = 8; y < height + 8; y++)// ������� ����
	{
		for (int x = 1; x < width + 1; x++)
		{
			SetCur(x, y);
			cout << " ";
		}
		cout << endl;
	}
	SetCur(0, 10);
	if (n == 1)
	{
		cout << R"XXX(
                                       1111111   
                                      1::::::1 
                                     1:::::::1   
                                     111:::::1   
                                       1::::1   
                                       1::::1   
                                       1::::1   
                                       1::::l   
                                       1::::l   
                                       1::::l   
                                       1::::l   
                                       1::::l   
                                    111::::::111
                                    1::::::::::1
                                    1::::::::::1
                                    111111111111
)XXX";
	}
	if (n == 2)
	{
		cout << R"XXX( 
                                    222222222222222    
                                  2:::::::::::::::22  
                                  2::::::222222:::::2 
                                  2222222     2:::::2 
                                           2:::::2 
                                          2:::::2 
                                       2222::::2  
                                    22222::::::22   
                                  22::::::::222     
                                  2:::::22222        
                                  2:::::2             
                                  2:::::2             
                                  2:::::2       222222
                                  2::::::2222222:::::2
                                  2::::::::::::::::::2
                                  22222222222222222222
)XXX";
	}
	if (n == 3)
	{
		cout << R"XXX(
                                   333333333333333   
                                 3:::::::::::::::33 
                                 3::::::33333::::::3
                                 3333333     3:::::3
                                             3:::::3
                                             3:::::3
                                 3333333333333:::::3 
                                 3333333:::::::::::3  
                                 3333333333333:::::3 
                                             3:::::3
                                             3:::::3
                                             3:::::3
                                 3333333     3:::::3
                                 3::::::33333::::::3
                                 3:::::::::::::::33 
                                  333333333333333  
)XXX";
	}
	if (n == 4)
	{
		cout << R"XXX(
                                     444444444  
                                    4::::::::4  
                                   4:::::::::4  
                                  4::::44::::4  
                                 4::::4 4::::4  
                                4::::4  4::::4  
                               4::::4   4::::4  
                            4::::444444::::444
                            4::::::::::::::::4
                            4444444444:::::444
                                        4::::4  
                                        4::::4  
                                        4::::4  
                                    44::::::44
                                    4::::::::4
                                    4444444444
)XXX";
	}
	if (n == 5)
	{
		cout << R"XXX(
                            555555555555555555 
                            5::::::::::::::::5 
                            5::::::::::::::::5 
                            5:::::555555555555 
                            5:::::5            
                            5:::::5            
                            5:::::5555555555   
                            5:::::::::::::::5  
                            555555555555:::::5 
                                        5:::::5
                                         5:::::5
                            5555555     5:::::5
                            5::::::55555::::::5
                             55:::::::::::::55 
                               55:::::::::55   
                                 555555555    
)XXX";
	}
	if (n == 6)
	{
		cout << R"XXX(
                                 66666666   
                                6::::::6    
                               6::::::6     
                              6::::::6      
                             6::::::6       
                           6::::::6        
                          6::::::6         
                        6::::::::66666    
                        6::::::::::::::66  
                        6::::::66666:::::6 
                        6:::::6     6:::::6
                        6:::::6     6:::::6
                        6::::::66666::::::6
                         66:::::::::::::66 
                           66:::::::::66   
                             666666666     
)XXX";
	}
	if (n == 7)
	{
		cout << R"XXX(
                         77777777777777777777
                         7::::::::::::::::::7
                         7::::::::::::::::::7
                         777777777777:::::::7
                                    7::::::7 
                                   7::::::7  
                                  7::::::7   
                                 7::::::7    
                                7::::::7     
                               7::::::7      
                              7::::::7       
                             7::::::7        
                            7::::::7         
                           7::::::7          
                          7::::::7           
                         77777777            
)XXX";
	}
	if (n == 8)
	{
		cout << R"XXX(
                             888888888     
                           88:::::::::88   
                         88:::::::::::::88 
                        8::::::88888::::::8
                        8:::::8     8:::::8
                        8:::::8     8:::::8
                         8:::::88888:::::8 
                          8:::::::::::::8  
                         8:::::88888:::::8 
                        8:::::8     8:::::8
                        8:::::8     8:::::8
                        8:::::8     8:::::8
                        8::::::88888::::::8
                         88:::::::::::::88 
                           88:::::::::88   
                             888888888     
)XXX";
	}
	if (n == 9)
	{
		cout << R"XXX(
                             999999999     
                           99:::::::::99   
                         99:::::::::::::99 
                        9::::::99999::::::9
                        9:::::9     9:::::9
                        9:::::9     9:::::9
                         9:::::99999::::::9
                          99::::::::::::::9
                            99999::::::::9 
                                 9::::::9  
                                9::::::9   
                               9::::::9    
                              9::::::9     
                             9::::::9      
                            9::::::9       
                           99999999       
)XXX";
	}
	if (n == 10)
	{
		system("cls");
		int r = 0;
		while (true)
		{
			r = rand() % (16 - 9) + 9;
			SetCur(0, 0);
			setColor(r, BLACK);
			if (_kbhit())
			{
				if (_getch() == 32)
					break;
			}
			cout << R"XXX(
                     1111111        000000000     
                    1::::::1      00:::::::::00   
                   1:::::::1    00:::::::::::::00 
                   111:::::1   0:::::::000:::::::0
                      1::::1   0::::::0   0::::::0
                      1::::1   0:::::0     0:::::0
                      1::::1   0:::::0     0:::::0
                      1::::l   0:::::0 000 0:::::0
                      1::::l   0:::::0 000 0:::::0
                      1::::l   0:::::0     0:::::0
                      1::::l   0:::::0     0:::::0
                      1::::l   0::::::0   0::::::0
                   111::::::1110:::::::000:::::::0
                   1::::::::::1 00:::::::::::::00 
                   1::::::::::1   00:::::::::00   
                   111111111111     000000000     
)XXX";
			SetCur(23, 49);
			cout << "����������, �� ������ ��� ����, ��� ������ ������� Enter.";
			Sleep(50);
		}
		return;
	}
	SetCur(0, 30);
	cout << R"XXX(
                   ___      _______  __   __  _______  ___     
                  |   |    |       ||  | |  ||       ||   |    
                  |   |    |    ___||  |_|  ||    ___||   |    
                  |   |    |   |___ |       ||   |___ |   |    
                  |   |___ |    ___||       ||    ___||   |___ 
                  |       ||   |___  |     | |   |___ |       |
                  |_______||_______|  |___|  |_______||_______|
)XXX";
	for (int i = 7; i < height + 8; ++i)// ��������� ����� ������� ����
	{
		SetCur(0, i);
		cout << char(219);
	}
}