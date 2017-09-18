#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include "Console.h"
#include "Box.h"
#include "Settings.h"
#include "JustJewels.h"
#include "FallDownAndGenerateNewJewels.h"
#include "MainEngineOfGame.h"
#include "ScoreField.h"
#include "DisplayCombo.h"
#include "Gems.h"
#include "CheckBox.h"
using namespace std;
void main()
{
	srand(time(nullptr));
	//Settings s;
	//s.AllSettings();
	//Score c;
//	c.ScoreField();
	//Box b;
	//Gems g;
	//b.DrawGrid();
	//b.PrintPlayField();
	//g.InitBox(3);
	//g.DrawBox();
	//b.Engine();
	//b.Swap(playField[1], playField[2]);
	//Combo d;
//	d.DisplayCombo(3);
	Box B;
	B.PrintCheckBox();
	//b.FallAndGenerate();
}