#include "Settings.h"
void Settings::AllSettings()
{
	system("title Bejeweled");// Заголовок окна
	system("mode con cols=225 lines=60");// Изменение размера окна
	CONSOLE_CURSOR_INFO x;// Скрытие мигающего курсора
	x.bVisible = false;
	x.dwSize = 100;
}