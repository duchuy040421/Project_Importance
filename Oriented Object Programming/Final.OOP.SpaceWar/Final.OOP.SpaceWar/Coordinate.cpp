#include "Header.h"



void Coordinate::Draw(char c)
{
	GotoXY(x, y);
	cout << c;
}
int Coordinate::getX()
{
	return x;
}
int Coordinate::getY()
{
	return y;
}
void Coordinate::setCoord(int x, int y)
{
	this->x = x;
	this->y = y;
}