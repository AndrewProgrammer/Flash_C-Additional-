#include "Settings.h"
void Settings::AllSettings()
{
	system("title Bejeweled");// ��������� ����
	system("mode con cols=225 lines=60");// ��������� ������� ����
	CONSOLE_CURSOR_INFO x;// ������� ��������� �������
	x.bVisible = false;
	x.dwSize = 100;
}