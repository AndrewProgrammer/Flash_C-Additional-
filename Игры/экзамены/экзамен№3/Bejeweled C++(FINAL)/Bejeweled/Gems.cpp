#include "Gems.h"
using namespace std;
Gems::Gems() : SymbolOfGem(219), SwitcherForCoolGems(0)
{
	ColorForGems = static_cast<color>(rand() % 7 + 8);
}

Gems::Gems(color color)
{
	ColorForGems = color;
	SymbolOfGem = 219;
	SwitcherForCoolGems = 0;
}
color Gems::GetColorForGems()
{
	return ColorForGems;
}

void Gems::PrintOurGems(int x, int y, int size) const
{
	Console::SetColor(ColorForGems);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	for (size_t i = 0; i < size; i++)
	{
		Console::SetCur(pos);
		for (size_t j = 0; j < size; j++)
		{
			cout << SymbolOfGem;
		}
		pos.Y++;
	}
}

int Gems::EffectWithGems(IScoreManager & score, IScoreManager & bonus)
{
	score.IncreaseScore(10);
//	bonus.IncreaseBonus(1);
	return SwitcherForCoolGems;
}
bool Gems::operator == (Gems & right)
{
	return this->GetColorForGems() == right.GetColorForGems();
}