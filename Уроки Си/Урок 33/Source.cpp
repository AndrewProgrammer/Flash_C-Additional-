#include "Header.h"

void main()
{
	while (1)
	{
		PrintLogo();
		PrintMenuList();

		switch (MenuPrc())
		{
		case 1:
			system("cls");
			GamePrc();
			break;
		case 2:
			system("cls");
			GamePrc();
			break;
		case 3:
			system("cls");
			GamePrc();
			break;
		case 4:
			exit(0);
			break;
		}
	}

	system("pause");
}