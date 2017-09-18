#pragma once
#include "Console.h"
#include <iostream>
using namespace std;
class Score
{
private:
	int score = 0;
public:
	Score(){};
	~Score(){};
	void ScoreField();
	int GetScore();
	void SetScore(int scores);
};