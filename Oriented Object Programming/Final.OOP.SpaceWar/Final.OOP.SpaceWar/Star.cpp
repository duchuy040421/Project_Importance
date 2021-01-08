#include "Header.h"


Star::Star()
{
	x = 0; y = 0;
}

void SetCoordStar(Star star[STAR])
{
	for (int i = 0; i < STAR; i++)
	{
		star[i].setCoord(rand() % (WIDTH_CONSOLE - 2) + 1, rand() % (HEIGH_CONSOLE - 6) + 1);
		star[i].state = true;
	}
}
void DrawStar()
{
	TextColor(15);
	for (int i = 0; i < STAR; i++)
		if (star[i].state)
			star[i].Draw('.');
}
void EraseStar()
{
	for (int i = 0; i < STAR; i++)
		if (star[i].state)
			star[i].Draw(' ');
}