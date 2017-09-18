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
		return EXIT_FAILURE;		// EXIT_FAILURE - ������ �� ������������� ����� cstdlib.
	}


	char buf[100];

	/*
		������� fgets (������ gets ��� ������) ������������ ��� ������ ������ �� �����.
		
			char * fgets ( char * str, int num, FILE * stream ); - ��������� ������ �� ����� � ���������� �
				� ������ �� ��������� str. 

				str - ��������� �� ������� ������� �������, � ������� ����� �������� ��������� ������
				num - ������������ ���-�� �������� ������� ����� �������� � ������ (������� �������)
				stream - ��������� �� ������ ��������� FILE, ������� ��������� �������� ����

			fgets ������� ��������� ������, ���� � ����� �� ��������� num, ���� ������� num-1 ��������, ���� �����
				������ ������.

			����� ����� ��������� ����� ����� ������� ������ ������� ���������.

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