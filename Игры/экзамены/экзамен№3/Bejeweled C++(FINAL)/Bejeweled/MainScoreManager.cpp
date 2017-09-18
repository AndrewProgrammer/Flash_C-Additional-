#include "MainScoreManager.h"

int ScoreManager::GetScore() const
{
	return m_score;
}
int ScoreManager::GetBonus() const
{
	return m_bonus;
}
void ScoreManager::IncreaseScore(int score)
{
	m_score += score;
}
void ScoreManager::IncreaseBonus(int bonus)
{
	m_bonus += bonus;
}