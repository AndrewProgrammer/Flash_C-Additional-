#include "Gems.h"
Gems::Gems()
{
	m_color = static_cast<color>(rand() % 7 + 8);
}
Gems::Gems(color colors) : m_color(colors){}
void Gems::PrintGem(int x, int y,int size) const
{
	Console::SetColor(m_color);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	for (size_t i = 0; i < size; i++)
	{
		Console::SetCur(pos);
		for (size_t j = 0; j < size; j++)
		{
			cout << char(219);
		}
		cout << endl;
		pos.Y++;
	}
}
int Gems::GetLenght(int size)
{
	return size;
}
bool Gems::operator ==(Gems & right)
{
	return this->m_color == right.m_color;
}
void Gems::ActionWithScore(Score & score)
{
	score.SetScore(10);
}