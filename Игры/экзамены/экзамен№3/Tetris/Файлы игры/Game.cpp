#include "Game.h"
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//����������� �������������������, ������� ��������� ������ � ������(������� �������� ������� � ��� ����� ��� ������ bool � ����� �������� ��������) ����, ����� ��������� ���� ���� �� ������ � ������, ��������� ������ ������( ����� �� �����, ����� ��� ����������� ����� ������ ������� �� ����), ��������� ������, ���������� �� ������, � ���� ������������.
Game::Game() : vecField(WidthField, vector <bool>(HightField, false)), vecFieldColor(WidthField, vector <int>(HightField, 0)), indexFigure(0), indexRandom(0), score(0)
{
	for (int i = 0; i < HightField; i++)
	{
		for (int j = 0; j < HightField; j++)
		{
			//��������� ����
			if (i == 0 || i == (WidthField - 1) || j == 0 || j == (HightField - 1))
			{
				vecField[i][j] = true;
			}
		}
	}
	//��������� ����� ��������� ������� � ������ �� ���� ��� ���� �������� �������� � ����� �������
	for (int i = 0; i < AllSells; i++)
	{
		randomFigure.push_back(rand() % (8 - 1) + 1);
	}
}
int Game::GetScore()
{
	return score;
}
void Game::ShowRules()
{
	char Left = 60, Right = 62, ChangeFSpecial = 87;
	COORD PositionLeftControl = { 25, 3 };
	COORD PositionRightControl = {35, 3 };
	COORD PositionChangeFSpecial = { 25 , 5 };
	COORD PositionRuleString = { 25, 7 };
	SetConsoleTextAttribute(h, 11);
	SetConsoleCursorPosition(h, PositionLeftControl);
	cout << "Left - " << Left;
	SetConsoleTextAttribute(h, 11);
	SetConsoleCursorPosition(h, PositionRightControl);
	cout << "Right - " << Right;
	SetConsoleTextAttribute(h, 15);
	SetConsoleCursorPosition(h, PositionChangeFSpecial);
	cout << "SpecialChange - " << ChangeFSpecial;
	SetConsoleTextAttribute(h, 14);
	SetConsoleCursorPosition(h, PositionRuleString);
	cout << "Collect 100 points to go on the next level";
}
void Game::ShowField()
{
	for (int i = 0; i < WidthField; i++)
	{
		for (int j = 0; j < HightField; j++)
		{
			if (i == 0)
			{
				HANDLE OutPutTopField = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(OutPutTopField, 14);
				cout << TopField;
			}
			else if (i == (WidthField - 1))
			{
				HANDLE OutPutBottomField = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(OutPutBottomField, 14);
				cout << BottomField;
			}
			else if (j == 0)
			{
				HANDLE OutPutLeftField = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(OutPutLeftField, 12);
				cout << LeftField;
			}
			else if (j == (HightField - 1))
			{
				HANDLE OutPutRightField = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(OutPutRightField, 12);
				cout << RightField;
			}
			else if (vecField[i][j] == true)
			{
				HANDLE OutPutCellsOnField = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(OutPutCellsOnField, vecFieldColor[i][j]);
				cout << SymbolCell;
			}
			else
			{
				HANDLE OutPutCellsOnField = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(OutPutCellsOnField, vecFieldColor[i][j]);
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl << "Your score: " << score << endl;
}
void Game::SetFigureCoordinates(shared_ptr<Figure> Figure, int Position_YF, int Position_XF)
{
	for (int x = 0; x < WidthField; x++)
	{
		for (int y = 0; y < HightField; y++)
		{
			//������������ ������� ����� ������ � ����� ����������� ����
			if (x == Position_XF && y == Position_YF)
			{
				for (int i = 0; i < FIGURE_SIZE; i++)
				{
					for (int j = 0; j < FIGURE_SIZE; j++)
					{
						//������������ ������, � ���� �� ���� ������, ������������
						if (Figure->GetCells(i, j) == true)
						{
							//������������ �� ���� ���� ������ ��� � ��������
							vecField[i + x][j + y] = Figure->GetCells(i, j);
							//������ ���� ����� ������
							vecFieldColor[i + x][j + y] = Figure->GetColor();
						}
					}
				}
			}
		}
	}
}
void Game::ClearFigureCoordinates(shared_ptr<Figure> Figure, int Position_YF, int Position_XF)
{
	for (int x = 0; x < WidthField; x++)
	{
		for (int y = 0; y < HightField; y++)
		{
			//������������ ������� ����� ������ � ����� ����������� ����
			if (x == Position_XF && y == Position_YF)
			{
				for (int i = 0; i < FIGURE_SIZE; i++)
				{
					for (int j = 0; j < FIGURE_SIZE; j++)
					{
						//������������ ������, � ���� �� ���� ������, ������������
						if (Figure->GetCells(i, j) == true)
						{
							//������� ��� ���� ���� �� ����������
							vecField[i + x][j + y] = false;
							//������� ���� ����
							vecFieldColor[i + x][j + y] = 0;
						}
					}
				}
			}
		}
	}
}
shared_ptr<Figure> Game::nextFigure()
{
	switch (randomFigure[indexRandom++])
	{
	default:
	case 1:
		vecFigures.push_back(shared_ptr <Figure>(new FigureLine));//��������� � ����� ������� �� ����� � ������� ����� ������(�����)(��� �������� ����� �������)
		return vecFigures[indexFigure++];//������� �� � ������ ����� � ���������� ������, ��� ������� �������� � ���������� ���(�� ���� �������)
		break;
		case 2:
			vecFigures.push_back(shared_ptr <Figure>(new FigureSquare));//��������� � ����� ������� �� ����� � ������� ����� ������(�������)(��� �������� ����� �������)
			return vecFigures[indexFigure++];//������� �� � ������ ����� � ���������� ������, ��� ������� �������� � ���������� ���(�� ���� �������)
			break;
		case 3:
			vecFigures.push_back(shared_ptr <Figure>(new FigureS));//��������� � ����� ������� �� ����� � ������� ����� ������(��������� ����� �������)(��� �������� ����� �������)
			return vecFigures[indexFigure++];//������� �� � ������ ����� � ���������� ������, ��� ������� �������� � ���������� ���(�� ���� �������)
			break;
		case 4:
			vecFigures.push_back(shared_ptr <Figure>(new FigureZ));//��������� � ����� ������� �� ����� � ������� ����� ������(��������� ��������� ������� �����)(��� �������� ����� �������)
			return vecFigures[indexFigure++];//������� �� � ������ ����� � ���������� ������, ��� ������� �������� � ���������� ���(�� ���� �������)
			break;
		case 5:
			vecFigures.push_back(shared_ptr <Figure>(new FigureL));//��������� � ����� ������� �� ����� � ������� ����� ������(� ����)(��� �������� ����� �������)
			return vecFigures[indexFigure++];//������� �� � ������ ����� � ���������� ������, ��� ������� �������� � ���������� ���(�� ���� �������)
			break;
		case 6:
			vecFigures.push_back(shared_ptr <Figure>(new FigureJ));//��������� � ����� ������� �� ����� � ������� ����� ������(������� � ���������)(��� �������� ����� �������)
			return vecFigures[indexFigure++];//������� �� � ������ ����� � ���������� ������, ��� ������� �������� � ���������� ���(�� ���� �������)	
			break;
		case 7:
			vecFigures.push_back(shared_ptr <Figure>(new FigureT));//��������� � ����� ������� �� ����� � ������� ����� ������(����� T ���� ���������� ����)(��� �������� ����� �������)
			return vecFigures[indexFigure++];//������� �� � ������ ����� � ���������� ������, ��� ������� �������� � ���������� ���(�� ���� �������)
			break;
		}
}
bool Game::CheckFigureCoordinatesLeftToRight(shared_ptr<Figure> figure, int position_x, int position_y) //�������� �������� ���� �� ������� �����, ����� �� �����
{
	//�� ������ ����� ������� ������� ������ ��������� �����,� �������� ��������� ������� �� ���� ��������� �� �������� �� ��� ���� ������
	//��� �������� � ���� �� �����, ����� ��������� ��� ������������ �� ������������� X � Y
	//����  % 2 ! = 0 �������� ��� ������ �����������.
	//���� % 2 == 0 �� �� �������� �� � ������������ �������
	//���� %(3,4,5) == 0 �� �� �������� � �������� ������� ����� ������� � ������� ������������, � ������� �� �����������, �� ��� ������ ����� ����� ������ ����� �������.
	//���� %(3,4,5) != 0 ������ �����������
	//����� �����
	if (figure->GetColor() == COLOR_OF_LINE)
	{
		if (figure->getPosition() % 2 != 0 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 3][position_y])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 3][position_y + 2])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y + 4])
			return true;

		else
			return false;
	}
	//����� ��������
	if (figure->GetColor() == COLOR_OF_SQUARE)
	{
		if (vecField[position_x + 1][position_y])
			return true;
		if (vecField[position_x + 2][position_y])
			return true;
		if (vecField[position_x + 1][position_y + 3])
			return true;
		if (vecField[position_x + 2][position_y + 3])
			return true;

		else
			return false;
	}
	//����� ������ S
	if (figure->GetColor() == COLOR_OF_S)
	{
		if (figure->getPosition() % 2 != 0 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 2][position_y + 3])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 2][position_y - 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 2][position_y + 2])
			return true;

		else
			return false;
	}
	//����� ������ Z
	if (figure->GetColor() == COLOR_OF_Z)
	{
		if (figure->getPosition() % 2 != 0 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 2][position_y - 1])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 2][position_y + 3])
			return true;

		else
			return false;
	}
	//����� ������ L
	if (figure->GetColor() == COLOR_OF_L)
	{
		if (figure->getPosition() == 2 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y + 3])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x][position_y + 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x][position_y + 3])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x][position_y - 1])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y - 1])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y + 1])
			return true;
		else
			return false;
	}
	if (figure->GetColor() == COLOR_OF_J)
	{
		if (figure->getPosition() == 2 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y - 1])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x][position_y - 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x][position_y + 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x][position_y + 3])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y + 3])
			return true;
		else
			return false;
	}
	//����� ����� T
	if (figure->GetColor() == COLOR_OF_T)
	{
		if (figure->getPosition() == 2 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y - 1])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x][position_y])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x][position_y + 2])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y + 3])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y + 2])
			return true;
		else
			return false;
	}


}
bool Game::CheckFigureCoordinatesBottom(shared_ptr<Figure> figure, int position_x, int position_y) //�������� �������� ���� �� ������� �����, �� ����
{
	//�� ������ ����� ������� ������� ������ ��������� �����,� �������� ��������� ������� �� ���� ��������� �� �������� �� ��� ���� ������
	//����� �����
	//����  % 2 ! = 0 �������� ��� ������ �����������.
	//���� % 2 == 0 �� �� �������� �� � ������������ �������
	//���� %(3,4,5) == 0 �� �� �������� � �������� ������� ����� ������� � ������� ������������, � ������� �� �����������, �� ��� ������ ����� ����� ������ ���� �������.
	//���� %(3,4,5) != 0 ������ �����������
	if (figure->GetColor() == COLOR_OF_LINE)
	{
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 3][position_y + 1] && vecField[position_x + 4][position_y + 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y] && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y + 1] && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y + 2] && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y + 3] && vecField[position_x + 2][position_y + 3])
			return true;
		else
			return false;
	}
	//����� ��������
	if (figure->GetColor() == COLOR_OF_SQUARE)
	{
		if (vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (vecField[position_x + 2][position_y + 2] && vecField[position_x + 3][position_y + 2])
			return true;

		else
			return false;
	}
	//����� ������ S
	if (figure->GetColor() == COLOR_OF_S)
	{
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 1][position_y + 1] && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 2][position_y + 2] && vecField[position_x + 3][position_y + 2])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 2][position_y] && vecField[position_x + 3][position_y])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y + 2] && vecField[position_x + 2][position_y + 2])
			return true;

		else
			return false;
	}
	//����� ������ Z
	if (figure->GetColor() == COLOR_OF_Z)
	{
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 2][position_y] && vecField[position_x + 3][position_y])
			return true;
		if (figure->getPosition() % 2 != 0 && vecField[position_x + 1][position_y + 1] && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 1][position_y] && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() % 2 == 0 && vecField[position_x + 2][position_y + 2] && vecField[position_x + 3][position_y + 2])
			return true;
		else
			return false;
	}
	//����� ������ L
	if (figure->GetColor() == COLOR_OF_L)
	{
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y + 2] && vecField[position_x + 3][position_y + 2])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y] && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y + 1] && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y + 2] && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x][position_y] && vecField[position_x + 1][position_y])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y] && vecField[position_x + 3][position_y])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y + 1] && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y + 2] && vecField[position_x + 2][position_y + 2])
			return true;
		else
			return false;
	}
	//����� J
	if (figure->GetColor() == COLOR_OF_J)
	{
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y] && vecField[position_x + 3][position_y])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y] && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y + 1] && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y + 2] && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x][position_y + 2] && vecField[position_x + 1][position_y + 2])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y] && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y + 1] && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y + 2] && vecField[position_x + 3][position_y + 2])
			return true;
		else
			return false;
	}
	// ����� ����� T
	if (figure->GetColor() == COLOR_OF_T)
	{
		if (figure->getPosition() == 2 && vecField[position_x + 1][position_y] && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() == 2 && vecField[position_x + 1][position_y + 2] && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 1][position_y] && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 3 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y] && vecField[position_x + 2][position_y])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y + 1] && vecField[position_x + 2][position_y + 1])
			return true;
		if (figure->getPosition() == 4 && vecField[position_x + 1][position_y + 2] && vecField[position_x + 2][position_y + 2])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 2][position_y + 1] && vecField[position_x + 3][position_y + 1])
			return true;
		if (figure->getPosition() == 5 && vecField[position_x + 1][position_y + 2] && vecField[position_x + 2][position_y + 2])
			return true;

		else
			return false;
	}
}

void Game::ClearLines() 
{
	for (int x = WidthField - 2; x > 0; x--)
	{
		int countDot = 0;
		for (int y = HightField - 2; y > 0; y--)
		{
			if (vecField[x][y] == true)
			{
				countDot++;
			}
			if (countDot == (HightField - 2))
			{
				score += 100;
				for (int i = x; i > 1; i--)
				{
					for (int j = HightField - 2; j > 0; j--)
					{
						vecField[i][j] = vecField[i - 1][j];
						vecFieldColor[i][j] = vecFieldColor[i - 1][j];
					}
				}
			}
		}
	}
}

bool Game::ControlsAndStartGame(shared_ptr<Figure> Figure, int Position_XF, int Position_YF)
{
	while (1)
	{
		char key;
		if (_kbhit())
		{
			key = _getch();
			//������� ������
			switch (key)
			{
			case 'D':
			case 'd':
			{
				if (!CheckFigureCoordinatesLeftToRight(Figure, Position_YF, Position_XF))
				{
					Position_XF++;
				}
				break;
			}
			case 'A':
			case 'a':
			{
				if (!CheckFigureCoordinatesLeftToRight(Figure, Position_YF, Position_XF))
				{
					Position_XF--;
				}
				break;
			}
			case 'W':
			case 'w':
			{
				if (!CheckFigureCoordinatesLeftToRight(Figure, Position_YF, Position_XF) && !CheckFigureCoordinatesBottom(Figure, Position_YF, Position_XF))
				{
					Figure->ChangeFigure();
				}
				break;
			}
			case 27: // Escape
				system("clr");
				exit(0);
				break;
			default:
			{
				system("clr");
				cout << "Something went wrong!" << endl;
				break;
			}
			}

		}
		//����������� ����� �������� � �����
		SetFigureCoordinates(Figure, Position_XF, Position_YF);
		ShowField();
		cout << endl << "X: " << Position_XF << ' ' << "Y: " << Position_YF;
		ShowRules();
		Sleep(200);
		system("cls");
		//���� �� ��������� ��� ����������, �� ����������� ���� �������
		if (CheckFigureCoordinatesBottom(Figure, Position_YF, Position_XF) == true)
		{
			break;
		}
		ClearFigureCoordinates(Figure, Position_XF, Position_YF);
		Position_YF++;
	}
	// � ����������� �� ����� �������� ������
	if (Position_YF == 4 || Position_YF == 3 || Position_YF == 2)
	{
		return true;
	}
	ClearLines();
	return false;
}