//#include "FallDownAndGenerateNewJewels.h"
//bool FallDownAndGenerateNewJewels::FindBoxesForRemove(Box playField[m_sizefield][m_sizefield])
//{
//	int currentSeq = 1;
//	int bestSeq = -2147483648;//����� ����������� ����� ����� ����� �� ����� �� �������
//	int bestSeqX = 0;
//	int bestSeqY = 0;
//	int bestSeqDirection = 1;
//	bool finishFlag = false;
//	bool selectedCells[playField.GetLenght(0)][playField.GetLenght(1)];//�������� �� ����� playField(������������ ��� ��� ������)
//	do
//	{
//		//�������������� ������ ������� � � ������ = horizontal sequence - left to right
//		for (int x = 0; x < playField.GetLenght(0); x++)
//		{
//			for (int y = 0; y < playField.GetLenght(1) - 1; y++)
//			{
//				if (playField[x][y].OurColor == playField[x][y + 1].OurColor && selectedCells[x][y] = false)//�������������� ������
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
//				if (playField[x][y].OurColor == playField[x + 1][y].OurColor && selectedCells[x][y] = false)//�������������� ������
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
//		bestSeq = -2147483648;//����� ����������� ����� ����� ����� �� ����� �� �������
//		bestSeqX = 0;
//		bestSeqY = 0;
//		bestSeqDirection = 1;
//	} while (finishFlag == false);
//	return selectedCells;
//}
//void FallDownAndGenerateNewJewels::FallAndGenerate()
//{
//	do
//	{
//		bool BoxesToRemove[8][8] = FindBoxesForRemove(playField);//�� ����� playField
//		int jewelCount = 0;
//		for (int y = 0; y < BoxesToRemove.GetLenght(0); y++)//�� ����� BoxesToRemove ���� �� ��������
//		{
//			for (int x = 0; x < BoxesToRemove.GetLenght(1); x++)//�� ����� BoxesToRemove ���� �� ��������
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
//					//���� ��� Jewel �� ������ � Jewel ��� ��� ������ - �� ������ ������� � ������� SWAP
//					if (playField[x][y].OurColor != Console::SetColor(Black, Black) && playField[x][y + 1].OurBlack == Console::SetColor(Black, Black))
//					{
//						Sleep(50);
//						lastSelection[0] = x;
//						lastSelection[1] = y;
//						cursorX = x;
//						cursorY = y + 1;
//						Box::Swap(playField[x][y], playField[x][y + 1], playField);
//					}
//					//���� �� ��� ���� ������ �� ������ Jewel �� ������ ��� ���� � ������� ���
//					if (y == 0 && playField[x][y].OurBlack == Console::SetColor(Black, Black))
//					{
//						playField[x][y].OurColor = rand() % 15;
//						Sleep(50);
//						playField[x][y].InitBox('\2591');//LIGHT SHADE UNICODE(�� ����� ����������� ������� � ������� ASCII(����� ��������� 219))
//						playField[x][y].DrawBox();
//						Sleep(50);
//						playField[x][y].InitBox('\2592');//MEDIUM SHADE UNICODE(�� ����� ����������� ������� � ������� ASCII(����� ��������� 219))
//						playField[x][y].DrawBox();
//						Sleep(50);
//						playField[x][y].InitBox('\u2593');//DARK SHADE UNICODE(�� ����� ����������� ������� � ������� ASCII(����� ��������� 219))
//						playField[x][y].DrawBox();
//						Sleep(50);
//						playField[x][y].InitBox('\u2588');//���� char(219) // FULL BLOCK
//						playField[x][y].DrawBox();
//					}
//				}
//			}
//		}
//		delete[] BoxesToRemove;
//	} while (!isEmpty(FindBoxesForRemove(playField)));
//}
//void FallDownAndGenerateNewJewels::DestroyJewels(Box playField[m_sizefield][m_sizefield], bool BoxesToRemove[8][8])
//{
//	Sleep(400);//�������� �������� ���������� ������� ������ � ������� ������� ��� ����� ���������
//	for (int y = 0; y < playField.GetLenght(0); y++)
//	{
//		for (int x = 0; x < playField.GetLenght(1); y++)
//		{
//			if (BoxesToRemove[x][y] == true)
//			{
//				playField[x][y].InitBox('\u2593');//DARK SHADE UNICODE(�� ����� ����������� ������� � ������� ASCII(����� ��������� 219))
//				playField[x][y].DrawBox();
//				Sleep(50);
//				playField[x][y].InitBox('\2592');//MEDIUM SHADE UNICODE(�� ����� ����������� ������� � ������� ASCII(����� ��������� 219))
//				playField[x][y].DrawBox();
//				Sleep(50);
//				playField[x][y].InitBox('\2591');//LIGHT SHADE UNICODE(�� ����� ����������� ������� � ������� ASCII(����� ��������� 219))
//				playField[x][y].DrawBox();
//				Sleep(50);
//				Console::SetColor(Black, Black);//������ ����� - ������ ����
//
//				playField[x][y];
//				Sleep(50);
//				playField[x][y].InitBox('\u2588');//���� char(219) // FULL BLOCK
//				playField[x][y].DrawBox();
//			}
//		}
//	}
//}