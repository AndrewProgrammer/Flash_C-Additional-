#pragma once

class IScoreProvider
{
public:
	virtual int GetScore() const = 0;
	virtual int GetBonus() const = 0;
};

class IScoreManager : public IScoreProvider
{
public:
	virtual void IncreaseScore(int score) = 0;
	virtual void IncreaseBonus(int bonus) = 0;
};

class ScoreManager : public IScoreManager
{
private:
	int m_score = 0;
	int m_bonus = 1;
public:
	virtual int GetScore() const override;
	virtual int GetBonus() const override;
	virtual void IncreaseScore(int score) override;
	virtual void IncreaseBonus(int bonus) override;

};