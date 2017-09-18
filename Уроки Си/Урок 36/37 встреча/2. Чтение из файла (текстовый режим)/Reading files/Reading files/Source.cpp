#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <iostream>
using namespace std;


int main (int argc, char **argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *fMySongList = nullptr;
	if (fopen_s (&fMySongList, "music.txt", "r"))
	{
		printf ("Error in opening file!\n");
		perror ("Error text: ");
		return EXIT_FAILURE;		// EXIT_FAILURE - макрос из заголовочного файла cstdlib.
	}


	char buf[100];

	/*
		Функция fgets (аналог gets для файлов) используется для чтения строки из файла.
		
			char * fgets ( char * str, int num, FILE * stream ); - Считывает строку из файла и записывает её
				в массив по указателю str. 

				str - указатель на нулевой элемент массива, в который будет записана считанная строка
				num - максимальное кол-во символов которое можно записать в массив (включая нулевой)
				stream - указатель на объект структуры FILE, который описывает открытый файл

			fgets считает полностью строку, если её длина не превышает num, либо считает num-1 символов, если длина
				строки больше.

			Когда будет достигнут конец файла функция вернет нулевой указатель.

	*/

	while (fgets (buf, 100, fMySongList))
	{
		cout << buf;
		//printf ("%s", buf);
		//Sleep (20);
	}

	printf ("\n\n");

	fclose (fMySongList);

	return EXIT_SUCCESS;
}