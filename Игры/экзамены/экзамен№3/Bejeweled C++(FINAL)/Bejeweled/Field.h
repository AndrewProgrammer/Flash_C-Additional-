#include "CheckBox.h"
#include "ColorForOurRemoveGem.h"
#include "Gems.h"
#include <vector>
#include <conio.h>
#include <ctime>
#include <iostream>
using namespace std;
typedef unsigned int uint;
const int SizeField = 8;
const int SizeMiddleOfFeild = 4;
const int SizeOfAllGems = 64;
class Field
{
private:
	Gems ** field;
	static const int m_size = 4;
	uint Newlevel;
public:
	Field();
	~Field();
	void PrintOurPlayField(const IScoreProvider & score , const IScoreProvider & bonus) const;
	void PrintCheckBox(uint index) const;
	void PrintScore(const IScoreProvider & score) const;
	//void PrintBonus(const IScoreProvider & bonus) const;
	void PrintNewLevel() const;
	void SwapOurGems(Gems *& pick, Gems *& dest);
	Gems *& operator [](unsigned int index);
	void CheckAndRemoveOurGems(IScoreManager & score, IScoreManager & bonus);
	vector<int> LookForOurEmptyGems();
	bool AddEffectForGems(vector<int> & emptygems, int switcher, int index, uint index_in_vector);
	void UltraRareGemFor5(uint first_pick, uint second_pick, IScoreManager & score, IScoreManager & bonus);
	void UltraRareGemFor4(vector<int> & emptygems, IScoreManager & score,IScoreManager & bonus);
	void FallAnGenerateNewGems();
	bool IsEmptyGems();
	bool ExistEmptyGems();
	bool IsOurExistGems();
	void NewFieldAfterNextLevelField();
	void PrintOurCursor(uint index) const;
	uint PickFirst(uint & choose);
	uint PickSecond(uint & choose);
	void CheckOnGameOver();
	bool GoToNextLevel(const IScoreProvider & score);
};
bool VectorContains(vector<int> nums, int num);