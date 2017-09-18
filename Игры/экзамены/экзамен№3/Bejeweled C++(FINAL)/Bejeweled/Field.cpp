#include "Field.h"

using namespace std;

Field::~Field()
{
	for (uint i = 0; i < SizeOfAllGems; i++)
	{
		delete field[i];
	}
	delete[] field;
}

Field::Field() : field(new Gems*[SizeOfAllGems]), Newlevel(1)
{
	for (uint i = 0; i < SizeOfAllGems; i++)
	{
		field[i] = new Gems;
	}
}

void Field::PrintOurPlayField(const IScoreProvider & score, const IScoreProvider & bonus) const
{
	for (uint i = 0; i < SizeOfAllGems; i++)
	{
		PrintCheckBox(i);
	}
	PrintNewLevel();
	PrintScore(score);
	//PrintBonus(bonus);
}

void Field::PrintCheckBox(uint index) const
{
	int x, y;
	x = (index % SizeField)*m_size;
	y = (index / SizeField % SizeField)*m_size;
	field[index]->PrintOurGems(x, y, m_size);
}

void Field::PrintScore(const IScoreProvider & score) const
{
	Console::SetColor(LightRed);
	Console::SetCur(SizeMiddleOfFeild * m_size, SizeField * m_size);
	std::cout << "Score: " << score.GetScore();
}
//void Field::PrintBonus(const IScoreProvider & bonus) const
//{
//	Console::SetColor(LightRed);
//	Console::SetCur(16, 33);
//	cout << "Bonus: " << bonus.GetBonus();
//}
void Field::PrintNewLevel() const
{
	Console::SetColor(LightRed);
	Console::SetCur(4, 32);
	std::cout << "Level: " << Newlevel;
}

void Field::SwapOurGems(Gems *& pick, Gems *& dest)
{
	Gems * temp = pick;
	pick = dest;
	dest = temp;
}

Gems *& Field::operator [](unsigned int index)
{
	return field[index];
}
void Field::CheckOnGameOver()
{
	if (!IsEmptyGems())
	{
		system("cls");
		Console::SetColor(Magenta);
		Console::SetCur(15, 16);
		cout << "YOU";
		Console::SetCur(15, 17);
		cout << "LOSE";
		Sleep(2000);
		exit(0);
	}
}

bool Field::GoToNextLevel(const IScoreProvider & score)
{
	if (score.GetScore() >= Newlevel * 500)
	{
		system("cls");
		Console::SetColor(Magenta);
		Console::SetCur(12, 16);
		cout << "LEVEL UP";
		Sleep(2000);
		++Newlevel;
		return true;
	}
	else
		return false;
}
void Field::PrintOurCursor(uint index) const
{
	COORD pos;
	pos.X = (index % SizeField)*m_size + 1;
	pos.Y = (index / SizeField % SizeField)*m_size + 1;
	for (uint x = 0; x < m_size - 2; x++)
	{
		Console::SetColor(LightRed);
		Console::SetCur(pos);
		for (uint y = 0; y < m_size - 2; y++)
		{
			cout << '*';
		}
		pos.Y++;
	}
}

uint Field::PickFirst(uint & choose)
{
	int code = 0;
	while (code != ESCAPE && code != ENTER)
	{
		PrintOurCursor(choose);
		code = _getch();
		switch (code)
		{
		case UP:
			if (choose > 7)
			{
				PrintCheckBox(choose);
				choose -= SizeField;
			}
			break;
		case LEFT:
			if ((choose % SizeField) != 0)
			{
				PrintCheckBox(choose);
				--choose;
			}
			break;
		case RIGHT:
			if ((choose % SizeField) != 7)
			{
				PrintCheckBox(choose);
				++choose;
			}
			break;
		case DOWN:
			if (choose < 56)
			{
				PrintCheckBox(choose);
				choose += SizeField;
			}
			break;
		}
	}
	return choose;
}

uint Field::PickSecond(uint & choose)
{
	int code = 0;
	while (code != UP && code != LEFT && code != RIGHT && code != DOWN)
	{
		code = _getch();
		switch (code)
		{
		case UP:
			if (choose > 7)
			{
				choose -= SizeField;
			}
			break;
		case LEFT:
			if ((choose % SizeField) != 0)
			{
				--choose;
			}
			break;
		case RIGHT:
			if ((choose % SizeField) != 7)
			{
				++choose;
			}
			break;
		case DOWN:
			if (choose < 56)
			{
				choose += SizeField;
			}
			break;
		}
	}
	return choose;
}
bool Field::AddEffectForGems(vector<int> & matches, int trigger, int index, uint index_in_vector)
{
	switch (trigger)
	{
	case 1:
		for (uint i = (index / SizeField) * SizeField; i < (index / SizeField) * SizeField + SizeField; i++)//adding line
		{
			if (!VectorContains(matches, i))
				matches.push_back(i);
		}
		for (uint i = index % SizeField; i < SizeOfAllGems; i += SizeField)//adding column
		{
			if (!VectorContains(matches, i))
				matches.push_back(i);
		}
		break;
	default:
		return false;
		break;
	}
	return true;
}
void Field::UltraRareGemFor5(uint first_pick, uint second_pick, IScoreManager & score, IScoreManager & bonus)
{
	int trigger;
	vector<int> matches;
	uint iter_count;
	color color_SizeMiddleOfFeild_remove;
	if (field[first_pick]->GetColorForGems() == Black)
	{
		color_SizeMiddleOfFeild_remove = field[second_pick]->GetColorForGems();
	}
	else
	{
		color_SizeMiddleOfFeild_remove = field[first_pick]->GetColorForGems();
	}
	for (uint i = 0; i < SizeOfAllGems; i++)
	{
		if (field[i]->GetColorForGems() == color_SizeMiddleOfFeild_remove || field[i]->GetColorForGems() == Black)
		{
			matches.push_back(i);
		}
	}
	iter_count = matches.size();
	for (uint i = 0; i < iter_count; i++)
	{
		trigger = field[matches[i]]->EffectWithGems(score, bonus);
		if (AddEffectForGems(matches, trigger, matches[i], i))
		{
			iter_count = matches.size();
		}
		delete field[matches[i]];
		field[matches[i]] = nullptr;
	}
	FallAnGenerateNewGems();
	PrintOurPlayField(score, bonus);
}

void Field::UltraRareGemFor4(vector<int> & matches, IScoreManager & score, IScoreManager & bonus)
{
	uint counter = 0;
	uint prev = 0;
	uint it_count = 0;
	auto it = matches.begin();
	auto end = matches.end();
	while (it != end)
	{
		if (*it != -1)
		{
			++counter;
			prev = *it;
		}
		else
		{
			if (counter == SizeMiddleOfFeild)
			{
				field[prev]->EffectWithGems(score, bonus);
				color color = field[prev]->GetColorForGems();
				delete field[prev];
				field[prev] = new CheckBox(color);
				matches[it_count - 1] = -1;
			}
			else if (counter > SizeMiddleOfFeild)
			{
				field[prev]->EffectWithGems(score, bonus);
				delete field[prev];
				field[prev] = new ColorForOurRemoveGem(Black);
				matches[it_count - 1] = -1;
			}
			counter = 0;
		}
		++it;
		++it_count;
	}
}
void Field::CheckAndRemoveOurGems(IScoreManager & score, IScoreManager & bonus)
{
	int switcher;
	vector<int> matches = LookForOurEmptyGems();
	UltraRareGemFor4(matches, score, bonus);
	uint iter_count = matches.size();
	for (uint i = 0; i < iter_count; i++)
	{
		if (matches[i] != -1)
		{
			switcher = field[matches[i]]->EffectWithGems(score, bonus);
			if (AddEffectForGems(matches, switcher, matches[i], i))
			{
				iter_count = matches.size();
			}
			delete field[matches[i]];
			field[matches[i]] = nullptr;
		}
	}
	FallAnGenerateNewGems();
}


vector<int> Field::LookForOurEmptyGems()
{
	vector<int> matches;
	for (uint i = 0; i < SizeOfAllGems; i++)
	{
		if ((i % SizeField) < 6)
		{
			if (*(field[i]) == *(field[i + 1]) && *(field[i]) == *(field[i + 2]) && *(field[i + 1]) == *(field[i + 2]))
			{
				for (uint j = i; j < SizeField*(i / SizeField + 1) && *(field[i]) == *(field[j]); ++j)
				{
					if (*(field[i]) == *(field[j]))
					{
						if (!VectorContains(matches, j))
							matches.push_back(j);
					}
				}
				matches.push_back(-1);
			}
		}
		if ((i / SizeField % SizeField) < 6)
		{
			if (*(field[i]) == *(field[i + SizeField]) && *(field[i]) == *(field[i + 16]) && *(field[i + SizeField]) == *(field[i + 16]))
			{
				for (uint j = i; j < SizeOfAllGems && *(field[i]) == *(field[j]); j += SizeField)
				{
					if (*(field[i]) == *(field[j]))
					{
						if (!VectorContains(matches, j))
							matches.push_back(j);
					}
				}
				matches.push_back(-1);
			}
		}
	}
	return matches;
}

void Field::FallAnGenerateNewGems()
{
	while (ExistEmptyGems())
	{
		for (uint i = 0; i < SizeOfAllGems; i++)
		{
			if (i < SizeField && field[i] == nullptr)
			{
				field[i] = new Gems;
			}
			else if (field[i] == nullptr)
			{
				SwapOurGems(field[i], field[i - SizeField]);
			}
		}
	}
}

bool Field::IsEmptyGems()
{
	bool flag = false;
	for (uint i = 0; i < SizeOfAllGems; i++)
	{
		if ((i % SizeField) < 5)
		{
			if ((*(field[i]) == *(field[i + 1]) && *(field[i]) == *(field[i + 3])) 
				|| (*(field[i]) == *(field[i + 2]) && *(field[i]) == *(field[i + 3])))
			{
				flag = true;
				break;
			}
		}
		if ((i / SizeField % SizeField) < 5)
		{
			if ((*(field[i]) == *(field[i + SizeField]) && *(field[i]) == *(field[i + 24])) 
				|| (*(field[i]) == *(field[i + 16]) && *(field[i]) == *(field[i + 24])))
			{
				flag = true;
				break;
			}
		}
		if ((i % SizeField) > 0 && (i / SizeField % SizeField) < 6)
		{
			if ((*(field[i]) == *(field[i + SizeField - 1]) && *(field[i]) == *(field[i + 16])) 
				|| (*(field[i]) == *(field[i + SizeField]) && *(field[i]) == *(field[i + 16 - 1])) 
				|| (*(field[i]) == *(field[i + SizeField - 1]) && *(field[i]) == *(field[i + 16 - 1])))
			{
				flag = true;
				break;
			}
		}
		if ((i % SizeField) < 7 && (i / SizeField % SizeField) < 6)
		{
			if ((*(field[i]) == *(field[i + SizeField + 1]) && *(field[i]) == *(field[i + 16])) 
				|| (*(field[i]) == *(field[i + SizeField]) && *(field[i]) == *(field[i + 16 + 1])) 
				|| (*(field[i]) == *(field[i + SizeField + 1]) && *(field[i]) == *(field[i + 16 + 1])))
			{
				flag = true;
				break;
			}
		}
		if ((i / SizeField % SizeField) > 0 && (i % SizeField) < 6)
		{
			if ((*(field[i]) == *(field[i - SizeField + 1]) && *(field[i]) == *(field[i + 2])) 
				|| (*(field[i]) == *(field[i + 1]) && *(field[i]) == *(field[i - SizeField + 2])) 
				|| (*(field[i]) == *(field[i - SizeField + 1]) && *(field[i]) == *(field[i - SizeField + 2])))
			{
				flag = true;
				break;
			}
		}
		if ((i / SizeField % SizeField) < 7 && (i % SizeField) < 6)
		{
			if ((*(field[i]) == *(field[i + SizeField + 1]) && *(field[i]) == *(field[i + 2])) 
				|| (*(field[i]) == *(field[i + 1]) && *(field[i]) == *(field[i + SizeField + 2])) 
				|| (*(field[i]) == *(field[i + SizeField + 1]) && *(field[i]) == *(field[i + SizeField + 2])))
			{
				flag = true;
				break;
			}
		}
	}
	return flag;
}

bool Field::IsOurExistGems()
{
	bool flag = false;
	for (uint i = 0; i < SizeOfAllGems; i++)
	{
		if ((i % SizeField) < 6)
		{
			if (*(field[i]) == *(field[i + 1]) && *(field[i]) == *(field[i + 2]))
			{
				flag = true;
				break;
			}
		}
		if ((i / SizeField % SizeField) < 6)
		{
			if (*(field[i]) == *(field[i + SizeField]) && *(field[i]) == *(field[i + 16]))
			{
				flag = true;
				break;
			}
		}
	}
	return flag;
}

bool VectorContains(vector<int> nums, int num)
{
	for (uint i = 0; i < nums.size(); i++)
	{
		if (nums[i] == num)
			return true;
	}
	return false;
}
bool Field::ExistEmptyGems()
{
	bool flag = false;
	for (uint i = 0; i < SizeOfAllGems; i++)
	{
		if (field[i] == nullptr)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
void Field::NewFieldAfterNextLevelField()
{
	while (!IsEmptyGems() || IsOurExistGems())
	{
		for (uint i = 0; i < SizeOfAllGems; i++)
		{
			delete field[i];
			field[i] = new Gems;
		}
	}
	field[1] = new Gems(Yellow);
	field[2] = new Gems(Yellow);
	field[10] = new Gems(Yellow);
	field[3] = new Gems(Yellow);
	field[4] = new Gems(Yellow);
	field[5] = new Gems(Yellow);
}