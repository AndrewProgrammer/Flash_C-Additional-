#include "SnakeLib.h"

void Level()
{
	SetConsoleTextAttribute(h,7); // ����������� ����� ����
	rezultat.X=61; // ���������� ����� ���������� �� ����� - ��� �������, ���� �� �����������
	rezultat.Y=22;
	infa.X=61;
	infa.Y=5;

	setlocale(0,"C"); // ����������� ���������
	system("cls");//������� �����
	COORD c; 
	int x,y; 
	bool flag=0; //���� ��������� �������� �� ������ ������	��� ���������� ������ 

	//������������� ������� ����
	for (int i=up; i<down; i++)
	{
		for (int j=_left; j<_right; j++)
		{			
			if (i==up&&j==_left)
				cout <<(char)218; //����� ������� ����
			else if (i==up&&j==_right-1)
				cout <<(char)191;//������ ������� ����
			else if (i==down-1&&j==0)
				cout <<(char)192;//����� ������ ����
			else if (i==down-1&&j==_right-1)
				cout <<(char)217;//������ ������ ����			
			else if (i==up||i==down-1)
				cout<<(char)196;//�������������� �����
			else if(j==_left||j==_right-1)
				cout<<(char)179;//������������ �����
			else cout <<' ';//��������� ��������� ���������
		}
		cout <<"\n";
	}

	SetConsoleCursorPosition(h,rezultat);//������������� ������ � ��������� ����������
	setlocale(0,""); // ����� ���������
	SetConsoleTextAttribute(h,4); // ���� ����� ����
	cout<<"������� �����: ";
	SetConsoleTextAttribute(h,12); // ���� ����� ����
	cout<<sum;//������� �� ����� ��������� ������
	//setlocale(0,"�"); // ����� ��������� �� �����������
	SetConsoleCursorPosition(h,infa);//������������� ������ � ��������� ������ ���������� �� ������� ��������
	int color1=1; // ������ ����� �������
	int color2=9; // ������ ������� �������
	SetConsoleTextAttribute(h,color1); // ���� ����� ����
	cout<<"��������:";//������� �� �����
	infa.Y+=2;//�������� ���������� ��������� ����������
	SetConsoleCursorPosition(h,infa);//���������� �� ������ ����
	//������� �� ����� ��������� �� ������� ��������
	SetConsoleTextAttribute(h,color2);
	cout <<"    "<<(char)24;
	infa.Y++;
	SetConsoleCursorPosition(h,infa);
	cout <<(char)27<<"       "<<(char)26; //������� �������
	infa.Y++;
	SetConsoleCursorPosition(h,infa);
	cout <<"    "<<(char)25;
	infa.Y+=2;
	SetConsoleCursorPosition(h,infa);
	SetConsoleTextAttribute(h,color1);
	cout<<"����� - ";
	SetConsoleTextAttribute(h,color2);
	cout<<"������";
	infa.Y+=2;
	SetConsoleCursorPosition(h,infa);
	SetConsoleTextAttribute(h,color1);
	cout<<"����� - ";
	SetConsoleTextAttribute(h,color2);
	cout<<"Escape";
	infa.Y+=2;
	SetConsoleCursorPosition(h,infa);
	SetConsoleTextAttribute(h,color1);
	cout<<"�������� - ";
	SetConsoleTextAttribute(h,color2);
	cout<<"Enter";
	infa.Y+=2;

	snake_length=2;//��������� ����� ���� ����� 2��
	snake=new Point[snake_length];	//������� ������ ������������ ����� ����
	snake[0].c.X=1;//������ ���������� � ���������� ��������� ������ ����
	snake[0].c.Y=2;//���������� �
	snake[0].symbol=(char)15; //������ ������ ������ ����

	snake[1].c.X=1;//������ ���������� ��������� ������
	snake[1].c.Y=1;
	snake[1].symbol='*';//������ ������ ������ ���� 
	//������������� ���������� ����� � �������� �������� ��� ������� ������ ����
	//if (level==1) 
	//{
	apples_count=level*20; // +20 ����� �� ������ ������
	speed=130-level*20;
	if(speed<15) speed=15; // ����� ����� ���� ������
	//}
	/*else if (level==2) // ����� ��������� �������� �� ������ ������.. �� ����� ������������� - ���� �����������
	{ 
	apples_count=40;
	speed=90; 
	}
	else if (level==3)
	{ 
	apples_count=80; 
	speed=50; 
	}*/

	//�������� ������ ������ ������ ���������� ����� � ������ ����
	apple=new Point[apples_count];
	int n=0; //������� ����������� �� ���� �����
	while(n<apples_count)//���� �� ��������� ��� ������
	{ 
		x=rand()%(_right-3)+1;//����������� ��������� ���������� � �������� ������� ����
		y=rand()%(down-3)+1;// ���� �� ����� �� �����������
		flag=0;//������������� ���� � ����
		for (int i=0; i<snake_length; i++)
		{
			if (snake[i].c.X==x&&snake[i].c.Y==y)
			{ 
				flag=1; //���� ���������� ������ ������� � ���������� ����, ������������� ���� � 1
				break;
			}
		}

		if (flag==0)
		{ 
			for (int i=0; i<n; i++)
			{ 
				if (apple[i].c.X==x&&apple[i].c.Y==y)
				{
					flag=1; //���� ��������� ������� � ��� ������������ �������, ������������� ���� � 1
					break;
				}
			}
		}
		if (flag==0)//���� ���������� ���-���� �������� - ��������� ������
		{ 
			apple[n].c.X=x;
			apple[n].c.Y=y;
			apple[n].symbol=(char)1;
			n++; 
		}
	}
	for (int i=0; i<snake_length; i++)//������ ���� �������� �����
	{
		if(i==0)
			SetConsoleTextAttribute(h,snake_head_color);
		else 
			SetConsoleTextAttribute(h,snake_head_body);
		SetConsoleCursorPosition(h,snake[i].c);
		cout <<snake[i].symbol; 
	}

	SetConsoleTextAttribute(h,12);
	for (int i=0; i<apples_count; i++)//������ ������� ������
	{	
		SetConsoleCursorPosition(h,apple[i].c);//������������� ������ � ������ ���������
		cout <<apple[i].symbol;//������� ������
	}
}

bool Move(int x, int y)
{
	Point  tail; //��������� ��� ������
	bool eda=0; //������� �� ������
	bool xarakiri=0;//1, ���� ���� ����������
	tail=snake[snake_length-1];//����� - ��������� ������� �������
	//����������� ���� 
	for (int i=snake_length-1; i>0; i--)
	{ 
		snake[i].c.X=snake[i-1].c.X;
		snake[i].c.Y=snake[i-1].c.Y;
	}
	//������������� ����� ��������� ������
	snake[0].c.X+=x;
	snake[0].c.Y+=y;
	//��������� ������ ������ ����������� ��������� �������� �� ������
	SetConsoleCursorPosition(h,tail.c);
	cout <<' ';
	//���������� ��� ������
	for (int i=0; i<apples_count; ++i)
	{
		//���� ���� ������� ������
		if (snake[0].c.X==apple[i].c.X&&snake[0].c.Y==apple[i].c.Y)
		{
			apple[i]=apple[apples_count-1];//������������ �������� � �������
			apples_count--;//�������� ����� �����
			eda=1; //������������� ����, ��� ���� ����� ������
			break;
		}
	}
	if (eda==1)
	{
		snake_length++;//�������� ����� ����
		Point *temp_snake;	//������� ��������������� ������ ��� ����������	
		temp_snake=new Point [snake_length];
		//�������� ������ ���� �� ��������� ����������
		for (int i=0; i<snake_length-1; i++)
			temp_snake[i]=snake[i];
		//������� ������ ������ ���� � ������� �����, ������� �����
		delete [] snake;
		snake=new Point[snake_length];
		//��������� ��� ������� �� ��������� ����������
		for (int i=0; i<snake_length; i++) 
			snake[i]=temp_snake[i]; 
		//����������� ������ ��������� ����������
		delete [] temp_snake;
		//�������� ������� ���� ����� �������� �����
		if (snake[snake_length-2].c.X>snake[snake_length-3].c.X&&snake[snake_length-2].c.Y==snake[snake_length-3].c.Y)
		{
			snake[snake_length-1].c.X=snake[snake_length-2].c.X+1; 
			snake[snake_length-1].c.Y=snake[snake_length-2].c.Y; 
		}
		else if (snake[snake_length-2].c.X<snake[snake_length-3].c.X&&snake[snake_length-2].c.Y==snake[snake_length-3].c.Y)
		{ 
			snake[snake_length-1].c.X=snake[snake_length-2].c.X-1;
			snake[snake_length-1].c.Y=snake[snake_length-2].c.Y;
		}
		else if (snake[snake_length-2].c.X==snake[snake_length-3].c.X&&snake[snake_length-2].c.Y>snake[snake_length-3].c.Y)
		{
			snake[snake_length-1].c.X=snake[snake_length-2].c.X;
			snake[snake_length-1].c.Y=snake[snake_length-2].c.Y+1; 
		}

		else if (snake[snake_length-2].c.X==snake[snake_length-3].c.X&&snake[snake_length-2].c.Y<snake[snake_length-3].c.Y)
		{
			snake[snake_length-1].c.X=snake[snake_length-2].c.X;
			snake[snake_length-1].c.Y=snake[snake_length-2].c.Y-1;
		}
		//��������� ������ � ����
		snake[snake_length-1].symbol='*';
		//������������� ���� � �������
		for (int i=0; i<snake_length; i++)
		{
			SetConsoleCursorPosition(h,snake[i].c);
			if(i==0)
				SetConsoleTextAttribute(h,snake_head_color);
			else 
				SetConsoleTextAttribute(h,snake_head_body);
			cout <<snake[i].symbol;

		}
		//����������� ����
		sum++; 
		//������� ����� ��������� �� �����
		SetConsoleCursorPosition(h,rezultat);
		setlocale(0,"");
		SetConsoleTextAttribute(h,4);
		cout<<"������� �����: ";
		SetConsoleTextAttribute(h,12);
		cout<<sum;
		setlocale(0,"C");
		return 0; //�������� �������� ���������
	}
	//���� ���� ���� ����������
	for (int i=1; i<snake_length-1; i++)
	{ 
		if (snake[0].c.X==snake[i].c.X&&snake[0].c.Y==snake[i].c.Y)
			xarakiri=1;
	}
	//�� ���������
	if (xarakiri==1)
	{ 
		return 1;
	}

	//���� ���� ����� �� ����
	if (snake[0].c.X==_left||snake[0].c.X==_right-1||snake[0].c.Y==up||snake[0].c.Y==down-1)
	{
		return 1;//�������� ��������� � ���������
	}
	//���� �� ������ ������������� �� ����, �������� ��������� ���� � �������������� ��
	for (int i=0; i<snake_length; i++)
	{ 
		SetConsoleCursorPosition(h,snake[i].c);
		if(i==0)
			SetConsoleTextAttribute(h,snake_head_color);
		else 
			SetConsoleTextAttribute(h,snake_head_body);
		cout <<snake[i].symbol;

	}
	SetConsoleCursorPosition(h,tail.c);
	cout <<' ';	
	return 0;
}

void NewGame(){
	delete [] snake; 
	delete [] apple;

	char*str=new char[200];
	strcpy(str,"title Snake - Level ");
	char*num=new char[10];
	_itoa(level,num,10); // ������� ������ � �����
	strcat(str,num);
	system(str); // �������� ����� ���������

	Level();
	getch();
}

void main()
{
	system("title Snake - Level 1");
	srand(time(NULL));//������ ��������� ��������� ��������� �����
	CONSOLE_CURSOR_INFO cursor;//��������� � ���������� � ���������� �������
	cursor.bVisible=false;//������ �� �����
	cursor.dwSize=100;//������������� ������ �������
	SetConsoleCursorInfo(h,&cursor);//�������� ��������� �������

	int x=1,y=0; //���������������� ������ ������� �������
	Level();//�������� ��������� ��� ������ ������ - ����� �����, ����� � ��������� ����

	getch(); // ���� ���� �� �������� - ���� ������������

	while (1)
	{ 
		while (kbhit())//��������� ������� �� ���� ������� �������
		{
			int k=getch();//�������� ��� ������� �������
			if(k==224||k==0) k=getch(); //���� ��� ���� ������� ��� ����
			switch (k)//���������, ����� ������� ������
			{
			case 72://����
				if (snake[0].c.Y-1==snake[1].c.Y) // ���� ���� � ��� ��������� ���� (��� �����) ������ �� ������
					continue;				
				y=-1; // ���� ������ ���� ����� ������� ������ ��� �������
				x=0;
				break;
			case 80://�����
				if (snake[0].c.Y+1==snake[1].c.Y)
					continue; 
				y=1; 
				x=0;
				break;
			case 75://�����
				if (snake[0].c.X-1==snake[1].c.X)
					continue; 
				x=-1;  
				y=0;
				break;
			case 77://������
				if (snake[0].c.X+1==snake[1].c.X) 
					continue; 
				x=1;
				y=0; 
				break;
			case 32://������ - �����
				k=getch();
				while(k!=32)
					k=getch();
				break;
			case 27://�����
				{
					//COORD c={0,24}; 
					//SetConsoleCursorPosition(h,c);
					system("cls");
					setlocale(0,"");
					cout <<"������� ��� ��������!";
					getch();
					system("taskkill -im cmd.exe");
					SetConsoleTextAttribute(h,0);
				}
				return;	
			case 13://�������� �������� ��������
				{
					COORD c={60,1}; // ����� ��� ���������
					SetConsoleTextAttribute(h,7); // ����� ����
					SetConsoleCursorPosition(h,c); // ��������� �������
					setlocale(0,""); // ����� ���������
					cout <<"����� ��������: ";
					SetConsoleTextAttribute(h,15); // ����� ����
					cin >>speed; // �������� � �������������
					SetConsoleCursorPosition(h,c); // ��������� ��������� ������� � ��� ����� ����� �������� ���������
					SetConsoleTextAttribute(h,0); // ������ ����
					cout <<"����� ��������: 9999"; // �������� ��
					SetConsoleTextAttribute(h,10);
					break;
				}
			}
		} 
		if(Move(x,y)==1)//�������� ��������� � ��������� ���� � ��������� ��������, ���� ��������� 1 - �� ���������
		{
			//������������� ���������� � ������ ���������, ������� ��������� � ��������� � ��������� ���������
			COORD c={18,23}; 
			SetConsoleCursorPosition(h,c);
			SetConsoleTextAttribute(h,12);
			system("echo  �� ��������!!! ������!!! ");
			getch();
			if(level>1) level--;
			NewGame();
			//break;
		}
		Sleep(speed);
		//���� �� ������� ������� ��� ������
		if (apples_count==0)
		{
			level++;//�������� �������

			NewGame();

		}
	}
	SetConsoleTextAttribute(h,0);
}