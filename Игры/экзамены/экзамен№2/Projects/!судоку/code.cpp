#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include"Initialization.h"
#include"Game features.h"

short game_mode=0;//0 - меню 1 - игра 2 - загрузка 3 - опции  4 - таблица рекордов			

bool Save(int game[][9], int a_check[][9]);
int game[9][9]={0},a_check[9][9]={0};
//дл€ меню. нач. кнопка

//рисуем менюшку
void Draw_Menu()
{ 
	short n=13;
	SetConsoleTextAttribute(h_out,10);
	c.X=2; c.Y=5;  
	for(short i=0; i<n; ++i)
	{
		SetConsoleCursorPosition(h_out,c);
		cout<<title[i]<<"\n";
		c.Y++;
	}
	if(opt_keyboard==1)
				{		c.X=20; c.Y=23; SetConsoleTextAttribute(h_out,12);SetConsoleCursorPosition(h_out,c);	cout<<char(26);		}
	SetConsoleTextAttribute(h_out,15);
	c.X=22; c.Y=22; int ymax=25;
	for(short buttons=0; buttons<5; ++buttons)
	{
		
		for(short i=0,height=c.Y; height<ymax; ++i,++height)
		{
			for(short j=0,width=c.X; width<53; ++j,++width)
			{
				SetConsoleCursorPosition(h_out,c);
				if(c.Y==23&&width==33&&game_now==0)
				{
					
					cout<<"НЃҐ†п И£а†";
					c.X+=10;
					width+=9;
				}
				else if(c.Y==23&&width==33&&game_now)
				{
					cout<<"ПаЃ§ЃЂ¶®вм";
					c.X+=10;
					width+=9;
				}
				else if(c.Y==27&&width==31)
				{
					cout<<"З†£агІ®вм И£агг";
					c.X+=14;
					width+=13;
				}
				else if(c.Y==31&&width==30)
				{
					cout<<"Т†°Ђ®ж† Р•™Ѓа§ЃҐ";
					c.X+=16;
					width+=15;
				}
				else if(c.Y==35&&width==35)
				{
					cout<<"Оѓж®®";
					c.X+=5;
					width+=4;
				}
				else if(c.Y==39&&width==35)
				{
					cout<<"ВлеЃ§";
					c.X+=5;
					width+=4;
				}
				else if(j==0&&i==0)
				{
					cout<<char(0xDB);
					c.X++;
				}
				else if(i>0&&i<ymax&&j==0)
				{
					cout<<char(0xDD);
					c.X++;
				}
				else if(j>0&&j<52&&i==0)
				{
					cout<<char(0xDF);
					c.X++;
				}
				else 
				{
					cout<<" ";
					c.X++;
				}
			}
			c.X=22;
			
			cout<<endl;
			c.Y++;
		}
		c.Y++;
		ymax++;
		cout<<endl;
		ymax+=3; 
	}
}

//ћенюшка дорисовалась

void New_Game(int game[][9],int a_check[][9], int difficult)
{
	cls(15);
	c.X=18; c.Y=19;
	SetConsoleTextAttribute(h_out,4);
	SetConsoleCursorPosition(h_out,c);	cout<<"…ЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌї"; c.Y++;
	SetConsoleCursorPosition(h_out,c);  cout<<"Ї";
	SetConsoleTextAttribute(h_out,11);   cout<<"                                   ";
	SetConsoleTextAttribute(h_out,4); cout<<"Ї"; c.Y++;
	SetConsoleCursorPosition(h_out,c);  cout<<"»ЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЌЉ";

	c.X=31; c.Y=17;
	SetConsoleTextAttribute(h_out,10);
	SetConsoleCursorPosition(h_out,c);
	cout<<"ПЃ§£ЃвЃҐ™†...";
	Sleep(100);

	InitMas(a_check);

	c.X=19; c.Y=20;
	SetConsoleCursorPosition(h_out,c); SetConsoleTextAttribute(h_out,11);   cout<<"≤≤≤≤≤";

	c.X=25; c.Y=17;
	SetConsoleTextAttribute(h_out,10);
	SetConsoleCursorPosition(h_out,c);
	cout<<"И≠®ж®†Ђ®І†ж®п ђ†бб®Ґ†...";
	Sleep(100);

    Initializate(a_check);

	c.X=24; c.Y=20;
	SetConsoleCursorPosition(h_out,c); SetConsoleTextAttribute(h_out,11);   cout<<"≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤";

	c.X=25; c.Y=17;
	SetConsoleTextAttribute(h_out,10);
	SetConsoleCursorPosition(h_out,c);
	cout<<" Па®ђ•"<<char(0xAD)<<"•≠®• ≠†бваЃ•™...   ";
	Sleep(100);
	GameMas(a_check,game,difficult);   

	c.X=42; c.Y=20;
	SetConsoleCursorPosition(h_out,c); SetConsoleTextAttribute(h_out,11);   cout<<"≤≤≤≤≤≤≤≤≤≤≤≤";
	Sleep(100);

	cls(122);
	c.X=30; c.Y=15;
	SetConsoleCursorPosition(h_out,c);
	ShowMas(game);
		if(opt_keyboard)
		{c.X=23; c.Y=23; SetConsoleCursorPosition(h_out,c);position=1;}
}

//будущий счетчик
DWORD WINAPI
f(void*p)
{
	int s=0;
	while(1) 
	{
		if(game_mode==1)
		{
			/*Beep(276.00,500);
			++s;
			c.X=5; c.Y=5;
			SetConsoleCursorPosition(h_out,c);
			cout<<s;
			Sleep(1000);*/
		}
	}
	return 0;
}

bool Save(int game[][9], int a_check[][9])
{
	if(FILE *f = fopen("Sudoku.sav","w+"))
	{
		char *str = new char [200];
		short temp;
		for(short i=0; i<9; ++i)
		{
			for(short j=0; j<9; ++j)
			{
				temp=game[i][j];
				itoa(temp,str,10);
				strcat(str,"\0");
				fputs(str,f);
				fputs("\n",f);
				temp=a_check[i][j];
				itoa(temp,str,10);
				strcat(str,"\0");
				fputs(str,f);
				fputs("\n",f);
			}
		}
		fclose(f);
		return true;
	}
	return false;
}

bool Load(int game[][9], int a_check[][9])
{
	if(FILE *f = fopen("Sudoku.sav","r+"))
	{
		char *str = new char [200];
		short temp;
		for(short i=0; i<9; ++i)
		{
			for(short j=0; j<9; ++j)
			{
				fgets(str,200,f);
				game[i][j]=atoi(str);
				fgets(str,200,f);
				a_check[i][j]=atoi(str);
			}
		}
		fclose(f);
		game_mode=1;game_now=1;
		cls(122);
		ShowMas(game);
		return true;
	}
	return false;
}

void main()
{
	system("title Sudoku v. 0.7 by ReaLgressA");
	startup();
	srand(time(0));
	Draw_Menu();
	INPUT_RECORD ir;
    DWORD recordsRead;
    CONSOLE_CURSOR_INFO curinfo;
    curinfo.bVisible = true;
    curinfo.dwSize = 100;
    SetConsoleCursorInfo(h_out, &curinfo);
	CreateThread(0,0,f,0,0,0);
	while(1)
	{
		SetConsoleMode(h_in,ENABLE_MOUSE_INPUT);
		INPUT_RECORD all_events[256];//массив событий
		DWORD read_event;
		bool Iwin=false;
		short Button=0;
		while(1)
			{
				ReadConsoleInput(h_in,all_events,256,&read_event);
				for(int i=0; i<read_event; i++)
				{
					c.X=all_events[i].Event.MouseEvent.dwMousePosition.X;
					c.Y=all_events[i].Event.MouseEvent.dwMousePosition.Y;
					COORD temp={0,0};
					SetConsoleCursorPosition(h_out,temp);
					cout<<"\t\t"; 
					SetConsoleCursorPosition(h_out,temp);
					cout<<c.X<<"\t"<<c.Y<<"\t"<<game_mode;
					//Ќачинаем обработку событий мыши
					if(!opt_keyboard)
					{
							if(game_mode==0)//–ежим меню
							{
								if(c.X>21 && c.X<53 && c.Y<41 && c.Y>21)
								{
									if(c.Y<25)
									{
										if(Button!=1)
										{
											short r1=rand()%16,r2=rand()%16;
											while(r1==r2||r1*r2==0)
											{r1=rand()%16;r2=rand()%16;}
											SetConsoleTextAttribute(h_out,r1*r2);
											Button=1;
											c.Y=22;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDF);	}cout<<char(0xDB);
											c.Y=23;c.X=22; SetConsoleCursorPosition(h_out,c);
											if(!game_now)
											{cout<<char(0xDD);cout<<"          НЃҐ†п И£а†         ";cout<<char(0xDE);}
											else
											{cout<<char(0xDD);cout<<"          ПаЃ§ЃЂ¶®вм         ";cout<<char(0xDE);}
											c.Y=24;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDC);	}cout<<char(0xDB);
										}
									}
									else if(c.Y>25 && c.Y<29)
									{
										if(Button!=2)
										{
											short r1=rand()%16,r2=rand()%16;
											while(r1==r2||r1*r2==0)
											{r1=rand()%16;r2=rand()%16;}
											SetConsoleTextAttribute(h_out,r1*r2);
											Button=2;
											c.Y=26;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDF);	}cout<<char(0xDB);
											c.Y=27;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDD);cout<<"        З†£агІ®вм И£аг       ";cout<<char(0xDE);
											c.Y=28;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDC);	}cout<<char(0xDB);
										}
									}
									else if(c.Y>29 && c.Y<33)
									{
										if(Button!=3)
										{
											short r1=rand()%16,r2=rand()%16;
											while(r1==r2||r1*r2==0)
											{r1=rand()%16;r2=rand()%16;}
											SetConsoleTextAttribute(h_out,r1*r2);
											Button=3;
											c.Y=30;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDF);	}cout<<char(0xDB);
											c.Y=31;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDD);cout<<"       Т†°Ђ®ж† Р•™Ѓа§ЃҐ      ";cout<<char(0xDE);
											c.Y=32;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDC);	}cout<<char(0xDB);
										}
									}
									else if(c.Y>33 && c.Y<37)
									{
										if(Button!=4)
										{
											short r1=rand()%16,r2=rand()%16;
											while(r1==r2||r1*r2==0)
											{r1=rand()%16;r2=rand()%16;}
											SetConsoleTextAttribute(h_out,r1*r2);
											Button=4;
											c.Y=34;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDF);	}cout<<char(0xDB);
											c.Y=35;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDD);cout<<"            Оѓж®®            ";cout<<char(0xDE);
											c.Y=36;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDC);	}cout<<char(0xDB);
										}
									}
									else if(c.Y>37 &&c.Y<41)
									{
										if(Button!=5)
										{
											short r1=rand()%16,r2=rand()%16;
											while(r1==r2||r1*r2==0)
											{r1=rand()%16;r2=rand()%16;}
											SetConsoleTextAttribute(h_out,r1*r2);
											Button=5;
											c.Y=38;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDF);	}cout<<char(0xDB);
											c.Y=39;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDD);cout<<"            ВлеЃ§            ";cout<<char(0xDE);
											c.Y=40;c.X=22; SetConsoleCursorPosition(h_out,c);
											cout<<char(0xDB);
											for(short i=23; i<52; ++i)
											{	cout<<char(0xDC);	}cout<<char(0xDB);
										}
									}
								}
								if(c.X>21 && c.X<53 && c.Y<41 && c.Y>21 &&all_events[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED )
								{
									if(c.Y<25)
									{
										if(game_now==0)
										{
											if(opt_music){	cout<<char(7);	}
											game_mode=11; //уровень сложности
											Draw_diff();
											Sleep(500);
										}
										else
										{
											if(opt_music){	cout<<char(7);	}
											game_mode=1;
											cls(122);
											c.X=30; c.Y=15;
											SetConsoleCursorPosition(h_out,c);
											ShowMas(game);
											Win(game,a_check);
										}
									}
									else if(c.Y>25 && c.Y<29)
									{
										Load(game,a_check);
									}
									else if(c.Y>29&&c.Y<33)
									{
										c.X=5; c.Y=25; SetConsoleCursorPosition(h_out,c);SetConsoleTextAttribute(h_out,14);
										cout<<char(1)<<"Тгв ≠®з•£Ѓ ≠•в!"<<char(1);
									}
									else if(c.Y>33 && c.Y<37)
									{
										if(opt_music){	cout<<char(7);	}
										game_mode=3;
										Draw_Options();
									}
									else if(c.Y>37)
									{
										if(opt_music){	cout<<char(7);	}
										return;
									}
								}
							}
							else if(game_mode==1)//–ежим »гры
							{
								if(c.X>33 && c.X<47 && c.Y<38 && c.Y>34 &&all_events[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
								{
									if(Win(game,a_check))
											{
												c.X=37; c.Y=10;
												SetConsoleCursorPosition(h_out,c);
												cout<<"Success!";
												if(opt_music)
												{
													Beep(200.00,200);Beep(320.00,350);Beep(216.00,100);Beep(360.00,800);
												}
												Draw_Win(a_check);
												game_mode=10;
											}
											else
											{
												c.X=37; c.Y=10;
												SetConsoleCursorPosition(h_out,c);
												SetConsoleTextAttribute(h_out,16*7+12);
												cout<<"Fail!";					
												if(opt_music)
												{
													Beep(276.00,100);Beep(246.00,100);Beep(216.00,100);Beep(176.00,100);Beep(120.00,400);
													continue;
												}
											}
								}
								else if(c.X>33 && c.X<47 && c.Y<42 && c.Y>38 &&all_events[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
								{
									c.X=37; c.Y=10;
									SetConsoleCursorPosition(h_out,c);
									SetConsoleTextAttribute(h_out,16*7+12);
									if(Save(game,a_check))
										cout<<"Fine!";
									else
										cout<<"Error!";
								}
								else if(c.X>63 && c.X<76 && c.Y<8 && c.Y>4 &&all_events[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
								{
									if(opt_music){	cout<<char(7);	}
									cls(15);
									game_mode=0;
									Draw_Menu();
								}
								else if(c.X>30 && c.X<48 && c.Y<33 && c.Y>15 &&all_events[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
								{
									if(c.X%2==1 && c.Y%2==0)
									{
										if(game[(c.Y-16)/2][(c.X-30)/2]<10)
										{
											Open(c.X,c.Y,game,a_check);
										}
									}	
								}
								else if(c.X>30 && c.X<48 && c.Y<33 && c.Y>15 &&all_events[i].Event.MouseEvent.dwButtonState==RIGHTMOST_BUTTON_PRESSED)
								{
									if(c.X%2==1 && c.Y%2==0) 
									{
										if(game[(c.Y-16)/2][(c.X-30)/2]<10&&game[(c.Y-16)/2][(c.X-30)/2]!=0)
										{
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,115);
											cout<<" "; game[(c.Y-16)/2][(c.X-30)/2]=0;
										}
									}	
								}
							}
							else if(game_mode==3)//–ежим ќпций
							{
								if(c.X>21 && c.X<53 && c.Y<33 && c.Y>21 &&all_events[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED )
								{
									if(c.Y<25)//музыка
									{
										c.X=50; c.Y=23;
										SetConsoleCursorPosition(h_out,c);
										if(opt_music==0)
										{					
											SetConsoleTextAttribute(h_out,15);
											cout<<char(14); opt_music=1;
											if(opt_music){	cout<<char(7);	}
										}
										else
										{
											SetConsoleTextAttribute(h_out,0);
											cout<<char(14); opt_music=0;
											if(opt_music){	cout<<char(7);	}
										}
									}
									else if(c.Y>25 && c.Y<29)//клава\мышь
									{
										if(opt_music){	cout<<char(7);	}
										if(opt_keyboard)
										{
											c.X=50; c.Y=27;
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,0);
											cout<<char(15); opt_keyboard=0;
											c.X=21; c.Y=8;
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,12);
											cout<<"  Уѓа†ҐЂ•≠®• ђлимо †™в®Ґ®аЃҐ†≠Ѓ      ";
										}
										else
										{
											c.X=50; c.Y=27;
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,15);
											cout<<char(15); opt_keyboard=1;
											c.X=21; c.Y=8;
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,12);
											cout<<"Уѓа†ҐЂ•≠®• ™Ђ†Ґ®†вгаЃ© †™в®Ґ®аЃҐ†≠Ѓ";
											position=1;
											c.X=20; c.Y=23; SetConsoleTextAttribute(h_out,12);SetConsoleCursorPosition(h_out,c);	cout<<char(26);
										}
									}
									else 
									{
										if(opt_music){	cout<<char(7);	}
										cls(15);
										game_mode=0;
										Draw_Menu();
									}
								}
							}
							else if(game_mode==10)//ќкно победы
							{
								if(c.X>14 && c.X<30 && c.Y<27 && c.Y>19 &&all_events[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED )
								{
									if(c.Y<23)
									{
										if(opt_music){	cout<<char(7);	}
										game_mode=11; //уровень сложности
										Draw_diff();
										game_now=1;
										Sleep(100);
									}
									else 
									{
										if(opt_music){	cout<<char(7);	}
										cls(15);
										game_now=0;
										game_mode=0;
										Draw_Menu();
									}
								}
							}
							else if(game_mode==11)//ќкно сложности
							{
								if(c.X>29 && c.X<45 && c.Y<32 && c.Y>18 &&all_events[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED )
								{
									if(c.Y<22)
									{
										if(opt_music){	cout<<char(7);	}
										for(short i=0; i<9; ++i)
											{
												for(short j=0; j<9; ++j)
												{
													game[i][j]=0;
												}
											}
											game_now=1;
											game_mode=1;
											New_Game(game,a_check,1);
									}
									else if(c.Y>28)
									{
										if(opt_music){	cout<<char(7);	}
										for(short i=0; i<9; ++i)
											{
												for(short j=0; j<9; ++j)
												{
													game[i][j]=0;
												}
											}
											game_now=1;
											game_mode=1;
											New_Game(game,a_check,3);
									}
									else
									{
										if(opt_music){	cout<<char(7);	}
										for(short i=0; i<9; ++i)
											{
												for(short j=0; j<9; ++j)
												{
													game[i][j]=0;
												}
											}
											game_now=1;
											game_mode=1;
											New_Game(game,a_check,2);
									}
								}
							}//конец проверок мыши
						}//конец if(!opt_keyboard)
						//начинаем провер€ть клаву
						else
						{
							bool while_keyboard=true;
							short cx=0,cy=0, button=1; 
							while(while_keyboard)
							{
							short key;//переменна€-буфер клавы
							short x=0, y=0;// переменные-координаты курсора на поле
							if(game_mode==0)//–ежим меню
							{
								key=getch();
								if(key==0 || key==224)
									key=getch();
								if(key==72)//вверх
								{
									if(position>1)
									{
										c.X=20; c.Y=19+position*4;
										SetConsoleCursorPosition(h_out,c);
										cout<<" ";
										--position;
										c.X=20; c.Y=19+position*4;
										SetConsoleCursorPosition(h_out,c);
										SetConsoleTextAttribute(h_out,12);
										cout<<char(26);
									}
									else
										continue;
								}
								else if(key==80)//вниз
								{
									if(position<5)
									{
										c.X=20; c.Y=19+position*4;
										SetConsoleCursorPosition(h_out,c);
										cout<<" ";
										++position;
										c.X=20; c.Y=19+position*4;
										SetConsoleCursorPosition(h_out,c);
										SetConsoleTextAttribute(h_out,12);
										cout<<char(26);
									}
									else
										continue;
								}
								else if(key==13)//Enter
								{
									if(position==1)//нова€ игра/продолжить
									{
										if(game_now==0)
										{
											if(opt_music){	cout<<char(7);	}
											game_mode=11; //уровень сложности
											Draw_diff();
										}
										else
										{
											if(opt_music){	cout<<char(7);	}
											game_mode=1;
											cls(122);
											c.X=30; c.Y=15;
											SetConsoleCursorPosition(h_out,c);
											ShowMas(game);
											Win(game,a_check);
											c.X=62; c.Y=6;SetConsoleCursorPosition(h_out,c);cout<<" ";
											c.X=30; c.Y=36;SetConsoleCursorPosition(h_out,c);cout<<" ";
											c.X=30; c.Y=40;SetConsoleCursorPosition(h_out,c);cout<<" ";
										}
									}
									else if(position==2)//загрузка
									{
										position=1;
										if(opt_music){	cout<<char(7);	}
									}
									else if(position==3)//рекорды
									{
										position=1;
										if(opt_music){	cout<<char(7);	}
									}
									else if(position==4)//опции
									{
										if(opt_music){	cout<<char(7);	}
										game_mode=3;
										position=1;
										Draw_Options();
									}
									else if(position==5)//выход
									{
										if(opt_music){	cout<<char(7);	}
										return;
									}
								}//конец нажати€ на enter
							}//конец game_mode==0
							//game_mode==1
							 if(game_mode==1)//–ежим »гры
							{
								//curinfo.bVisible = true;
								 if(position==1)//add number
								{
									if(key==0)
									{
										cx=0;cy=0;c.X=31+cx*2; c.Y=16+cy*2;SetConsoleCursorPosition(h_out,c);
									}
								key=getch();
								if(key==0 || key==224)
									key=getch();
								else if(key==9)//если tab измен€ем позицию
								{
									key=0;
									position=2;
							}
									
									else if(key==32)
									{
										if(game[cy][cx]<10)
										{
											game[cy][cx]=0;
											SetConsoleTextAttribute(h_out,115);
											cout<<" ";
											SetConsoleCursorPosition(h_out,c);
											continue;
										}
										else
											continue;
									}
									else if(key>=49&&key<=57)
									{
										if(game[cy][cx]<10)
										{
											game[cy][cx]=key-48;
											SetConsoleTextAttribute(h_out,115);
											cout<<key-48;
											SetConsoleCursorPosition(h_out,c);
											continue;
										}
										else
											continue;
									}
									switch(key)
									{
									case 75:
										if(cx>0)
										{
											--cx;
											c.X=31+cx*2; c.Y=16+cy*2;
											SetConsoleCursorPosition(h_out,c);
										}
										break;
									case 77:
										if(cx<8)
										{
											++cx;
											c.X=31+cx*2; c.Y=16+cy*2;
											SetConsoleCursorPosition(h_out,c);	
										}
										break;
									case 72:
										if(cy>0)
										{
											--cy;
											c.X=31+cx*2; c.Y=16+cy*2;
											SetConsoleCursorPosition(h_out,c);
										}
										break;
									case 80:
										if(cy<8)
										{
											++cy;
											c.X=31+cx*2; c.Y=16+cy*2;
											SetConsoleCursorPosition(h_out,c);
										}
										break;
									}
								}
								else if(position==2)// check button
								{
									if(key==0)
									{
										SetConsoleTextAttribute(h_out,16*7+12);
										button=1;
										c.X=30; c.Y=36;// 40      62 6   
										SetConsoleCursorPosition(h_out,c);
										cout<<char(26);
									}
									key=getch();
									if(key==0 || key==224)
									key=getch();
									else if(key==9)//если tab измен€ем позицию
									{
										c.X=62; c.Y=6;SetConsoleCursorPosition(h_out,c);cout<<" ";
										c.X=30; c.Y=36;SetConsoleCursorPosition(h_out,c);cout<<" ";
										c.X=30; c.Y=40;SetConsoleCursorPosition(h_out,c);cout<<" ";
										key=0;
										position=1;
									}
									//else if(key==75||key==77||key==72||key==80)
									//{
									
										switch(key)
										{
										case 75:
											if(button==3)
											{
												button=1;
												c.X=62; c.Y=6;SetConsoleCursorPosition(h_out,c);cout<<" ";
												c.X=30; c.Y=36;SetConsoleCursorPosition(h_out,c);cout<<char(26);
											}
											break;
										case 77:
											if(button==1||button==2)
											{
												button=3;
												c.X=30; c.Y=36;SetConsoleCursorPosition(h_out,c);cout<<" ";
												c.X=30; c.Y=40;SetConsoleCursorPosition(h_out,c);cout<<" ";
												c.X=62; c.Y=6;SetConsoleCursorPosition(h_out,c);cout<<char(26);
											}
											break;
										case 72:
											c.X=62; c.Y=6;SetConsoleCursorPosition(h_out,c);cout<<" ";
											c.X=30; c.Y=36;SetConsoleCursorPosition(h_out,c);cout<<" ";
											c.X=30; c.Y=40;SetConsoleCursorPosition(h_out,c);cout<<" ";
											if(button>1)
												button--;
											else
												button=3;
											if(button==1)
											{	c.X=30; c.Y=36;SetConsoleCursorPosition(h_out,c);cout<<char(26);}
											else if(button==2)
											{	c.X=30; c.Y=40;SetConsoleCursorPosition(h_out,c);cout<<char(26);}
											if(button==3)
											{	c.X=62; c.Y=6;SetConsoleCursorPosition(h_out,c);cout<<char(26);}
											break;
										case 80:
											c.X=62; c.Y=6;SetConsoleCursorPosition(h_out,c);cout<<" ";
											c.X=30; c.Y=36;SetConsoleCursorPosition(h_out,c);cout<<" ";
											c.X=30; c.Y=40;SetConsoleCursorPosition(h_out,c);cout<<" ";
											if(button<3)
												button++;
											else
												button=1;
											if(button==1)
											{	c.X=30; c.Y=36;SetConsoleCursorPosition(h_out,c);cout<<char(26);}
											else if(button==2)
											{	c.X=30; c.Y=40;SetConsoleCursorPosition(h_out,c);cout<<char(26);}
											if(button==3)
											{	c.X=62; c.Y=6;SetConsoleCursorPosition(h_out,c);cout<<char(26);}
											break;
										case 13:
											if(key==13&&button==1)
											{
												if(Win(game,a_check))
												{
													c.X=37; c.Y=10;
													SetConsoleCursorPosition(h_out,c);
													cout<<"Success!";
													game_mode=10;
													if(opt_music)
													{
														Beep(200.00,200);Beep(320.00,350);Beep(216.00,100);Beep(360.00,800);
													}
													Draw_Win(a_check);
												}
												else
												{
													c.X=37; c.Y=10;
													SetConsoleCursorPosition(h_out,c);
													cout<<"Fail!";					
													if(opt_music)
													{
														Beep(276.00,100);Beep(246.00,100);Beep(216.00,100);Beep(176.00,100);Beep(120.00,400);
													}
													continue;
												}
											}
											else if(key==13&&c.Y==40)
											{
												c.X=37; c.Y=10;
													SetConsoleCursorPosition(h_out,c);
												if(opt_music){	cout<<char(7);	}
												if(Save(game,a_check))
													cout<<"Fine!";
												else
													cout<<"Error!";
											}																		
											else if(key==13&&c.Y==6)
											{
												if(opt_music){	cout<<char(7);	}
												cls(15);
												game_mode=0;
												Draw_Menu();
											}
											break;
								}
							}
							else
								position=1;
							}
							
							// END game_mode==1
							else if(game_mode==3)//–ежим ќпций
							{
								key=getch();
								if(key==0 || key==224)
									key=getch();
								if(key==72)//вверх
								{
									if(position>1)
									{
										c.X=20; c.Y=19+position*4;
										SetConsoleCursorPosition(h_out,c);
										cout<<" ";
										--position;
										c.X=20; c.Y=19+position*4;
										SetConsoleCursorPosition(h_out,c);
										SetConsoleTextAttribute(h_out,12);
										cout<<char(26);
									}
									else
										continue;
								}
								else if(key==80)//вниз
								{
									if(position<3)
									{
										c.X=20; c.Y=19+position*4;
										SetConsoleCursorPosition(h_out,c);
										cout<<" ";
										++position;
										c.X=20; c.Y=19+position*4;
										SetConsoleCursorPosition(h_out,c);
										SetConsoleTextAttribute(h_out,12);
										cout<<char(26);
									}
									else
										continue;
								}
								else if(key==13)//Enter
								{
									if(position==1)//музыка
									{
										c.X=50; c.Y=23;
										SetConsoleCursorPosition(h_out,c);
										if(opt_music==0)
										{					
											SetConsoleTextAttribute(h_out,15);
											cout<<char(14); opt_music=1;
											if(opt_music){	cout<<char(7);	}
										}
										else
										{
											SetConsoleTextAttribute(h_out,0);
											cout<<char(14); opt_music=0;
											if(opt_music){	cout<<char(7);	}
										}
									}
									else if(position==2)//клава\мышь
									{
										if(opt_music){	cout<<char(7);	}
										if(opt_keyboard)
										{
											c.X=50; c.Y=27;
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,0);
											cout<<char(15); opt_keyboard=0;
											c.X=21; c.Y=8;
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,12);
											cout<<"  Уѓа†ҐЂ•≠®• ђлимо †™в®Ґ®аЃҐ†≠Ѓ      ";
											c.X=20; c.Y=27;
											SetConsoleCursorPosition(h_out,c);cout<<" ";
											while_keyboard=false;
										}
									else
										{
											c.X=50; c.Y=27;
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,15);
											cout<<char(15); opt_keyboard=1;
											c.X=21; c.Y=8;
											SetConsoleCursorPosition(h_out,c);
											SetConsoleTextAttribute(h_out,12);
											cout<<"Уѓа†ҐЂ•≠®• ™Ђ†Ґ®†вгаЃ© †™в®Ґ®аЃҐ†≠Ѓ";
										}
									}
									else 
									{
										if(opt_music){	cout<<char(7);	}
										cls(15);
										game_mode=0;
										position=1;
										Draw_Menu();
									}
								}
							}//конец game_mode==3
							else if(game_mode==10)//ќкно победы
							{
								key=getch();
								if(key==0 || key==224)
									key=getch();
								if(key==72)//вверх
								{
									if(position>1)
									{
										c.X=13; c.Y=17+position*4;
										SetConsoleCursorPosition(h_out,c);
										cout<<" ";
										--position;
										c.X=13; c.Y=17+position*4;
										SetConsoleCursorPosition(h_out,c);
										SetConsoleTextAttribute(h_out,12);
										cout<<char(26);
									}
									else
										continue;
								}
								else if(key==80)//вниз
								{
									if(position<2)
									{
										c.X=13; c.Y=17+position*4;
										SetConsoleCursorPosition(h_out,c);
										cout<<" ";
										++position;
										c.X=13; c.Y=17+position*4;
										SetConsoleCursorPosition(h_out,c);
										SetConsoleTextAttribute(h_out,12);
										cout<<char(26);
									}
									else
										continue;
								}
								else if(key==13)//Enter
								{
									if(position==1)
									{
										if(opt_music){	cout<<char(7);	}
										game_mode=11; //уровень сложности
										Draw_diff();
										game_now=1;
										Sleep(100);
									}
									else 
									{
										if(opt_music){	cout<<char(7);	}
										cls(15);
										game_now=0;
										game_mode=0;
										position=1;
										Draw_Menu();
									}
								}
							}//конец окна победы
							//ќкно сложности
							else if(game_mode==11)
							{
								while(!_kbhit())
								{
									Sleep(1);
								}
								key=getch();
								if(key==0 || key==224)
									key=getch();
								if(key==72)//вверх
								{
									if(position>1)
									{
										c.X=28; c.Y=15+position*5;
										SetConsoleCursorPosition(h_out,c);
										cout<<" ";
										--position;
										c.X=28; c.Y=15+position*5;
										SetConsoleCursorPosition(h_out,c);
										SetConsoleTextAttribute(h_out,12);
										cout<<char(26);
									}
									else
										continue;
								}
								else if(key==80)//вниз
								{
									if(position<3)
									{
										c.X=28; c.Y=15+position*5;
										SetConsoleCursorPosition(h_out,c);
										cout<<" ";
										++position;
										c.X=28; c.Y=15+position*5;
										SetConsoleCursorPosition(h_out,c);
										SetConsoleTextAttribute(h_out,12);
										cout<<char(26);
									}
									else
										continue;
								}
								else if(key==13)//Enter
								{
									if(position==1)
										{
										if(opt_music){	cout<<char(7);	}
										for(short i=0; i<9; ++i)
											{
												for(short j=0; j<9; ++j)
												{
													game[i][j]=0;
												}
											}
											game_now=1;
											game_mode=1;
											position=1;
											x=1; y=1;
											New_Game(game,a_check,1);
											c.X=31+cx*2; c.Y=16+cy*2;SetConsoleCursorPosition(h_out,c);
									}
									else if(position==3)
									{
										if(opt_music){	cout<<char(7);	}
										for(short i=0; i<9; ++i)
											{
												for(short j=0; j<9; ++j)
												{
													game[i][j]=0;
												}
											}
											game_now=1;
											game_mode=1;
											position=1;
											x=1; y=1;
											New_Game(game,a_check,3);
											c.X=31+cx*2; c.Y=16+cy*2;SetConsoleCursorPosition(h_out,c);
									}
									else
									{
										if(opt_music){	cout<<char(7);	}
										for(short i=0; i<9; ++i)
											{
												for(short j=0; j<9; ++j)
												{
													game[i][j]=0;
												}
											}
											game_now=1;
											game_mode=1;
											position=1;
											x=1; y=1;
											New_Game(game,a_check,2);
											c.X=31+cx*2; c.Y=16+cy*2;SetConsoleCursorPosition(h_out,c);
									}
								}
							}//конец выбора сложности
							}//конец while клавы
						}//конец проверок на клаву
					}
				}
		}		
}