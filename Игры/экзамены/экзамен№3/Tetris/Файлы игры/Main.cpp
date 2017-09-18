#include <iostream>
#include <ctime>
#include "Game.h"
#include "Console.h"
#include "Figura.h"
#include "FigureT.h"
#include "FigureJ.h"
#include "FigureL.h"
#include "FigureLine.h"
#include "FigureS.h"
#include "FigureSquare.h"
#include "FigureZ.h"
using namespace std;
void main()
{
	srand(time(nullptr));
	/*Game g;
	g.ShowField();
	FigureT t;
	t.ShowFigure(14);
	cout << endl;
	FigureJ j;
	j.ShowFigure(10);
	cout << endl;
	FigureL l;
	l.ShowFigure(11);
	cout << endl;
	FigureLine Line;
	Line.ShowFigure(12);
	cout << endl;
	FigureS s;
	s.ShowFigure(9);
	cout << endl;
	FigureSquare sq;
	sq.ShowFigure(6);
	cout << endl;
	FigureZ z;
	z.ShowFigure(7);
	cout << endl;*/
	Game Tetris;
	while (1)
	{
		shared_ptr<Figure> figure = Tetris.nextFigure();
		if (Tetris.ControlsAndStartGame(figure, StartPositionX, StartPositionY))
		{
			break;
		}
	}
	cout << "Game over!" << endl;
	cout << "Your score - " << Tetris.GetScore();
}