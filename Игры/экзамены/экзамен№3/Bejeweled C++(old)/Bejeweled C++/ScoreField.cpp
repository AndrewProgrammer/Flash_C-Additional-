#include "ScoreField.h"
int Score::GetScore()
{
	return score;
}
void Score::SetScore(int scores)
{
	score += scores;
}
void Score::ScoreField()
{
	Console::SetCur(0, 35);
	Console::SetColor(White, Black);
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	Console::SetCur(1, 36);
	cout << "Score = " << score;
	Console::SetCur(20, 35);
}