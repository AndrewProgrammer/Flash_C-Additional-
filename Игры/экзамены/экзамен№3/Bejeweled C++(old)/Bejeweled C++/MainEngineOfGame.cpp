//#include"MainEngineOfGame.h"
//void MainEngineOfGame::Engine()
//{
//	int direction = UP;// Направление движения
//	int banDirection = DOWN;// Запрещенное направление движения
//	char key = 0;
//	while (_kbhit())// Отлавливание нажатия клавиш
//	{
//		key = _getch();
//		if (key == 0 || key == 224)// Правильный перехват при нажатии на стрелки или F клавиши 
//		{
//			key = _getch();
//		}
//		if (key == LEFT)//Сдвиг рамки влево
//		{
//			if (cursorX > 0)
//			{
//				cursorX--;
//			}
//			if (selectionExist)
//			{
//				Swap(playField[lastSelection[0], lastSelection[1]], playField[cursorX, cursorY], playField);
//				if (isEmpty(FindBoxesForRemove(playField)))
//				{
//					Swap(playField[lastSelection[0], lastSelection[1]], playField[cursorX, cursorY], playField);
//				}
//				else
//				{
//					playField[cursorX, cursorY].isCursorPosition = false;
//					playField[cursorX, cursorY].DrawBox();
//					FallAndGenerate();
//				}
//			}
//		}
//		if (key == RIGHT)//Сдвиг рамки вправо
//		{
//			if (cursorX < 7)
//			{
//				cursorX++;
//			}
//			if (selectionExist)
//			{
//				Swap(playField[lastSelection[0], lastSelection[1]], playField[cursorX, cursorY], playField);
//				if (isEmpty(FindBoxesForRemove(playField)))
//				{
//					Swap(playField[lastSelection[0], lastSelection[1]], playField[cursorX, cursorY], playField);
//				}
//				else
//				{
//					playField[cursorX, cursorY].isCursorPosition = false;
//					playField[cursorX, cursorY].DrawBox();
//					FallAndGenerate();
//				}
//			}
//
//		}
//		if (key == UP)//Сдвиг Рамки вверх
//		{
//			if (cursorY > 0)
//			{
//				cursorY--;
//			}
//			if (selectionExist)
//			{
//				Swap(playField[lastSelection[0], lastSelection[1]], playField[cursorX, cursorY], playField);
//				if (isEmpty(FindBoxesForRemove(playField)))
//				{
//					Swap(playField[lastSelection[0], lastSelection[1]], playField[cursorX, cursorY], playField);
//				}
//				else
//				{
//					playField[cursorX, cursorY].isCursorPosition = false;
//					playField[cursorX, cursorY].DrawBox();
//					FallAndGenerate();
//				}
//			}
//		}
//		if (key == DOWN)//Сдвиг Рамки вниз
//		{
//			if (cursorY < 7)
//			{
//				cursorY++;
//			}
//			if (selectionExist)
//			{
//				Swap(playField[lastSelection[0], lastSelection[1]], playField[cursorX, cursorY], playField);
//				if (isEmpty(FindBoxesForRemove(playField)))
//				{
//					Swap(playField[lastSelection[0], lastSelection[1]], playField[cursorX, cursorY], playField);
//				}
//				else
//				{
//					playField[cursorX, cursorY].isCursorPosition = false;
//					playField[cursorX, cursorY].DrawBox();
//					FallAndGenerate();
//				}
//			}
//		}
//		if (key == PROBEL)//Рамка выбрана
//		{
//			playField[cursorX, cursorY].isSelected = true;
//			playField[cursorX, cursorY].DrawBox();
//			selectionExist = true;
//			lastSelection[0] = cursorX;
//			lastSelection[1] = cursorY;
//		}
//		else
//		{
//			for (int i = 0; i < playField.GetLenght(0); i++)
//			{
//				for (int j = 0; j < playField.GetLenght(1); j++)
//				{
//					if (playField[i][j].isCursorPosition)
//					{
//						playField[i][j].isCursorPosition = false;
//					}
//					playField[i][j].DrawBox();
//				}
//			}
//			playField[cursorX, cursorY].isCursorPosition = true;
//			playField[cursorX, cursorY].DrawBox();
//		}
//
//	}
//}
//bool MainEngineOfGame::FindBoxesForRemove(Box playField[m_sizefield][m_sizefield])
//{
//	int currentSeq = 1;
//	int bestSeq = -2147483648;//Самое минимальное число чтобы рамка не вышла за пределы
//	int bestSeqX = 0;
//	int bestSeqY = 0;
//	int bestSeqDirection = 1;
//	bool finishFlag = false;
//	bool selectedCells[playField.GetLenght(0)][playField.GetLenght(1)];//Проблема не видит playField(Воспринимает его как объект)
//	do
//	{
//		//Горизонтальные строки ровняем с к правым = horizontal sequence - left to right
//		for (int x = 0; x < playField.GetLenght(0); x++)
//		{
//			for (int y = 0; y < playField.GetLenght(1) - 1; y++)
//			{
//				if (playField[x][y].OurColor == playField[x][y + 1].OurColor && selectedCells[x][y] = false)//Следовательные ошибки
//				{
//					currentSeq++;
//				}
//				else
//				{
//					currentSeq--;
//				}
//				if (currentSeq > bestSeq)
//				{
//					bestSeq = currentSeq;
//					bestSeqX = x;
//					bestSeqY = y + 1;
//					bestSeqDirection = 1;
//				}
//			}
//			currentSeq = 1;
//		}
//		for (int y = 0; y < playField.GetLenght(1); y++)
//		{
//			for (int x = 0; x < playField.GetLenght(0) - 1; x++)
//			{
//				if (playField[x][y].OurColor == playField[x + 1][y].OurColor && selectedCells[x][y] = false)//Следовательные ошибки
//				{
//					currentSeq++;
//				}
//				else
//				{
//					currentSeq = 1;
//				}
//				if (currentSeq > bestSeq)
//				{
//					bestSeq = currentSeq;
//					bestSeqY = y;
//					bestSeqX = x + 1;
//					bestSeqDirection = 2;
//				}
//			}
//			currentSeq = 1;
//		}
//		if (bestSeq >= 3)
//		{
//			switch (bestSeqDirection)
//			{
//			case 1: // horizontal
//				for (int i = bestSeqY; i >= abs(bestSeq - bestSeqY - 1); i--)
//				{
//					selectedCells[bestSeqX, i] = true;
//				}
//				break;
//			case 2: // 2 - down
//				for (int i = bestSeqX; i >= abs(bestSeq - bestSeqX - 1); i--)
//				{
//					selectedCells[i, bestSeqY] = true;
//				}
//				break;
//			default:
//				break;
//			}
//		}
//		else
//		{
//			finishFlag = true;
//		}
//		currentSeq = 1;
//		bestSeq = -2147483648;//Самое минимальное число чтобы рамка не вышла за пределы
//		bestSeqX = 0;
//		bestSeqY = 0;
//		bestSeqDirection = 1;
//	} while (finishFlag == false);
//	return selectedCells;
//}
//void MainEngineOfGame::FallAndGenerate()
//{
//	do
//	{
//		bool BoxesToRemove[8][8] = FindBoxesForRemove(playField);//Не видит playField
//		int jewelCount = 0;
//		for (int y = 0; y < BoxesToRemove.GetLenght(0); y++)//Не видит BoxesToRemove хотя он объявлен
//		{
//			for (int x = 0; x < BoxesToRemove.GetLenght(1); x++)//Не видит BoxesToRemove хотя он объявлен
//			{
//				if (BoxesToRemove[x][y])
//				{
//					jewelCount += 10;
//				}
//			}
//		}
//		bonus = jewelCount / 30;
//		DisplayCombo(bonus);
//		score += jewelCount * bonus;
//		ScoreField();
//
//		DestroyJewels(playField, BoxesToRemove);
//		while (!isFull(playField))
//		{
//			for (int y = playField.GetLenght(0) - 2; y >= 0; y--)
//			{
//				for (int x = playField.GetLenght(1) - 1; x >= 0; x--)
//				{
//					//Если наш Jewel не черный и Jewel под ним черный - то меняем местами с помощью SWAP
//					if (playField[x][y].OurColor != Console::SetColor(Black, Black) && playField[x][y + 1].OurBlack == Console::SetColor(Black, Black))
//					{
//						Sleep(50);
//						lastSelection[0] = x;
//						lastSelection[1] = y;
//						cursorX = x;
//						cursorY = y + 1;
//						Box::Swap(playField[x][y], playField[x][y + 1], playField);
//					}
//					//Если мы все таки попали на черный Jewel то выдаем ему цвет и удаляем его
//					if (y == 0 && playField[x][y].OurBlack == Console::SetColor(Black, Black))
//					{
//						playField[x][y].OurColor = rand() % 15;
//						Sleep(50);
//						playField[x][y].InitBox('\2591');//LIGHT SHADE UNICODE(не нашел нормального символа в таблице ASCII(можно поставить 219))
//						playField[x][y].DrawBox();
//						Sleep(50);
//						playField[x][y].InitBox('\2592');//MEDIUM SHADE UNICODE(не нашел нормального символа в таблице ASCII(можно поставить 219))
//						playField[x][y].DrawBox();
//						Sleep(50);
//						playField[x][y].InitBox('\u2593');//DARK SHADE UNICODE(не нашел нормального символа в таблице ASCII(можно поставить 219))
//						playField[x][y].DrawBox();
//						Sleep(50);
//						playField[x][y].InitBox('\u2588');//Либо char(219) // FULL BLOCK
//						playField[x][y].DrawBox();
//					}
//				}
//			}
//		}
//		delete[] BoxesToRemove;
//	} while (!isEmpty(FindBoxesForRemove(playField)));
//}
//void MainEngineOfGame::DestroyJewels(Box playField[m_sizefield][m_sizefield], bool BoxesToRemove[8][8])
//{
//	Sleep(400);//Анимация удаления происходит слишком быстро с помощью времени это можно исправить
//	for (int y = 0; y < playField.GetLenght(0); y++)
//	{
//		for (int x = 0; x < playField.GetLenght(1); y++)
//		{
//			if (BoxesToRemove[x][y] == true)
//			{
//				playField[x][y].InitBox('\u2593');//DARK SHADE UNICODE(не нашел нормального символа в таблице ASCII(можно поставить 219))
//				playField[x][y].DrawBox();
//				Sleep(50);
//				playField[x][y].InitBox('\2592');//MEDIUM SHADE UNICODE(не нашел нормального символа в таблице ASCII(можно поставить 219))
//				playField[x][y].DrawBox();
//				Sleep(50);
//				playField[x][y].InitBox('\2591');//LIGHT SHADE UNICODE(не нашел нормального символа в таблице ASCII(можно поставить 219))
//				playField[x][y].DrawBox();
//				Sleep(50);
//				Console::SetColor(Black, Black);//Пустое место - Черный блок
//
//				playField[x][y];
//				Sleep(50);
//				playField[x][y].InitBox('\u2588');//Либо char(219) // FULL BLOCK
//				playField[x][y].DrawBox();
//			}
//		}
//	}
//}
//bool MainEngineOfGame::isEmpty(bool BoxesToRemove[8][8])
//{
//	for (int y = 0; y < 8; y++)
//	{
//		for (int x = 0; x < 8; x++)
//		{
//			if (BoxesToRemove[x][y])
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//bool MainEngineOfGame::isFull(Box playField[m_sizefield][m_sizefield])
//{
//	for (int y = 0; y < playField.GetLenght(0); y++)
//	{
//		for (int x = 0; x < playField.GetLenght(0); x++)//два условия которые будут возвращать нам два параметра с одинаковыми типами данных и тогда мы сможем их сравнить
//		{
//			if (playField[x][y].OurColor == Console::SetColor(Black, Black))
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}