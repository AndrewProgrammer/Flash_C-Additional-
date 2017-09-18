#include "Box.h"
Box::Box() : playField(new Gems*[FieldSize])
{
	for (size_t i = 0; i < FieldSize; i++)
	{
		playField[i] = new Gems;
	}
}
Box::~Box()
{
	for (size_t i = 0; i < FieldSize; i++)
	{
		delete playField[i];
	}
	delete[] playField;
}
Gems *& Box:: operator[](uint index)
{
	return playField[index];
}

void Box::DrawGrid() const
{
	Console::SetCur(0, 0);
	char grid[m_height][m_width];
	for (int y = 0; y < m_height; ++y)
	{
		for (int x = 0; x < m_width; ++x)
		{
			if (x == 0 || y == 0 || x == m_width - 1 || y == m_height - 1 || y % 4 == 0 || x % 8 == 0)
			{
				grid[y][x] = 219;
				Console::SetColor(Yellow, Black);
				cout << grid[y][x];
			}
			else
			{
				grid[y][x] = 32;
				cout << grid[y][x];
			}
		}
		cout << endl;
	}
}
void Box::Swap(Gems *& our, Gems *& dest)
{
	Gems * temp = our;
	our = dest;
	dest = temp;
}
bool Box::isFull(Gems ** playField)
{
	for (int x = 0; x < FieldSize; x++)//два условия которые будут возвращать нам два параметра с одинаковыми типами данных и тогда мы сможем их сравнить
	{
		for (int y = 0; y < FieldSize; y++)
		{
			if (playField[x][y].m_color = color::Black)//пишет что должно быть modifiable lvalue
			{
				return false;
			}
		}
	}
	return true;
}
void Box::PrintCheckBox()
{
		COORD c = { 5, 5 };
		bool flag = true;
		int dx = 0, dy = 0;//управляющие координаты
		do
		{
			COORD t = c;
			for (int y = 0; y < 7; y++)
			{
				SetConsoleCursorPosition(Console::hConsole, t);
				for (int x = 0; x < 7; x++)
					if (x == 0 || y == 0 || x == 6 || y == 6)
						cout << '*';
					else
						cout << ' ';
				t.Y++;
			}
			int k = _getch();//считываем код нажатой клавиши
			if (k == 0 || k == 224)//если была нажата управляющая клавиша
				k = _getch();//то считываем второй код из буфера
			switch (k)//отправляем результат для управления оператором выбора
			{
			case 'S':
			case 's':
			case DOWN://если была нажата клавиша вниз
				dy = 1;//то приращение по оси ординат будет положительным
				dx = 0;//по оси абсцисс приращение нулевое
				break;
			case 'W':
			case 'w':
			case UP://если вверх
				dy = -1;//аналогично согласно геометрической логике
				dx = 0;
				break;
			case 'A':
			case 'a':
			case LEFT://есди влево
				dy = 0;
				dx = -1;
				break;
			case 'D':
			case 'd':
			case RIGHT://если вправо
				dy = 0;
				dx = 1;
				break;
			case 27://если была нажата клавиша ESC
				flag = false;//устанавливаем флажок на ЛОЖЬ
				//break пропускаем специально, чтоб сработал default
			default:
				dx = dy = 0;//если была нажата любая иная клавиша, то приращения равны нулю
				c.X += dx;//приращаем абсциссу
				c.Y += dy;//приращаем ординату
				if (c.X < 0)//проверяем на выход за левую границу консоли
					c.X = 0;//и устанавливаем минимально допустимое значение абсциссы
				else if (c.X>FieldSize)
					c.X = FieldSize;
				if (c.Y < 0)//то же самое для ординаты
					c.Y = 0;
				else if (c.Y > FieldSize)
					c.Y = FieldSize;
			}
		} while (flag);
}