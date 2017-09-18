#pragma once
#include "Console.h"
#include "MainScoreManager.h"
#include <iostream>
typedef unsigned int uint;
class Gems
{
private:
	color ColorForGems;
protected:
	char SymbolOfGem;
	int SwitcherForCoolGems;
public:
	Gems();
	Gems(color ColorForGems);
	color GetColorForGems();
	void PrintOurGems(int x, int y, int SizeOfOurGems) const;
	int EffectWithGems(IScoreManager & score, IScoreManager & bonus);
	bool operator == (Gems & right);
};