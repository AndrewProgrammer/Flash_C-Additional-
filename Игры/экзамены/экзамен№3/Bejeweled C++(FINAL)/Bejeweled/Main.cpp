#include "Field.h"
#include "Console.h"
#include "MainScoreManager.h"
#include <vector>
typedef unsigned int uint;
void main()
{
	srand(time(nullptr));

	Console::ResizeConsole();

	ScoreManager score;
	ScoreManager bonus;
	Field field;

	field.NewFieldAfterNextLevelField();
	field.PrintOurPlayField(score, bonus);

	uint choose = 0;
	uint first_pick = 0;
	uint second_pick = 0;
	while (1)
	{
		first_pick = field.PickFirst(choose);
		second_pick = field.PickSecond(choose);
		field.SwapOurGems(field[first_pick], field[second_pick]);
		field.PrintOurPlayField(score, bonus);
		Sleep(1000);
		if (field.IsOurExistGems())
		{
			while (1)
			{
				if (field.IsOurExistGems())
				{
					field.CheckAndRemoveOurGems(score, bonus);
				}
				else
				{
					break;
				}
				field.PrintOurPlayField(score, bonus);
				if (field.GoToNextLevel(score))
				{
					field.NewFieldAfterNextLevelField();
					field.PrintOurPlayField(score, bonus);
				}
				Sleep(1000);
			}
			field.CheckOnGameOver();
		}
		else
		{
			field.SwapOurGems(field[second_pick], field[first_pick]);
			field.PrintOurPlayField(score, bonus);
		}
		if (field[first_pick]->GetColorForGems() == Black || field[second_pick]->GetColorForGems() == Black)
		{
			field.UltraRareGemFor5(first_pick, second_pick, score, bonus);
		}
	}
}