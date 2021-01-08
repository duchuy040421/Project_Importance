#include "Header.h"

void MoveRight(Enemy enemy[NUMs_ENEMY])
{
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (enemy[i].state)
			enemy[i].setCoord(enemy[i].getX() + 1, enemy[i].getY());
}
void MoveLeft(Enemy enemy[NUMs_ENEMY])
{
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (enemy[i].state)
			enemy[i].setCoord(enemy[i].getX() - 1, enemy[i].getY());
}
void MoveUp(Enemy enemy[NUMs_ENEMY])
{
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (enemy[i].state)
			enemy[i].setCoord(enemy[i].getX(), enemy[i].getY() - 1);
}
void MoveDown(Enemy enemy[NUMs_ENEMY])
{
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (enemy[i].state)
			enemy[i].setCoord(enemy[i].getX(), enemy[i].getY() + 1);
}
void MoveEnemy()
{
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (enemy[i].TouchBoundary() && Right)
		{
			Right = false;
			MoveLeft(enemy);
			break;
		}
		else if (enemy[i].TouchBoundary() && !Right)
		{
			Right = true;
			MoveRight(enemy);
			break;
		}
	if (Right)
		MoveRight(enemy);
	else
		MoveLeft(enemy);
	if (Round == 2)
	{
		for (int i = 0; i < NUMs_ENEMY; i++)
		{
			if (enemy[i].getY() == 3 && Up)
			{
				Up = false;
				MoveDown(enemy);
				break;
			}
			else if (enemy[i].getY() == HEIGH_CONSOLE - 5 && !Up)
			{
				Up = true;
				MoveUp(enemy);
				break;
			}
		}
		countt++;
		if (countt % 5 == 0)
		{
			if (Up)
				MoveUp(enemy);
			else
				if (!Up)
					MoveDown(enemy);
		}
	}
}

void MoveBullets()
{
	for (int i = 0; i < nums_bullet; i++)
	{
		if (bullet[i].state)
		{
			bullet[i].Draw(' ');
			bullet[i].setCoord(bullet[i].getX(), bullet[i].getY() - 1);
			if (Kill(bullet[i]))
			{
				Score += 15;
				coin++;
				GraphicEnemyDie(bullet[i].getX(), bullet[i].getY());
				bullet[i].Draw(' ');
			}
		}
		if (Round == 1)
			if (bullet[i].getY() == 0)
			{
				bullet[i].state = false;
			}
		if (Round == 2)
			if (bullet[i].getY() == 2)
			{
				bullet[i].state = false;
			}
	}
}

void MoveStar()
{
	for (int i = 0; i < STAR; i++)
	{
		int count = 0;
		star[i].setCoord(star[i].getX(), star[i].getY() + 1);
		if (star[i].getY() == (HEIGH_CONSOLE - 4))
			if (Round == 2)
				star[i].setCoord(rand() % (WIDTH_CONSOLE - 2) + 1, 3);
			else
				star[i].setCoord(rand() % (WIDTH_CONSOLE - 2) + 1, 1);
		for (int j = 0; j < NUMs_ENEMY; j++)
			if ((enemy[j].getX() == star[i].getX() && enemy[j].getY() == star[i].getY() + 1) || (enemy[j].getX() == star[i].getX() && enemy[j].getY() == star[i].getY()))
			{
				count++;
				star[i].state = false;
				break;
			}
		if (count == 0)
			star[i].state = true;
		if (Round == 2)
		{
			if (star[i].getY() == 4 && (star[i].getX() >= enemy[26].getX() && star[i].getX() <= enemy[27].getX()))
				star[i].state = false;
			else
				if (star[i].getY() == 5 && (star[i].getX() >= enemy[28].getX() && star[i].getX() <= enemy[29].getX()))
					star[i].state = false;
				else
					if (star[i].getY() == 6 && (star[i].getX() >= enemy[38].getX() && star[i].getX() <= enemy[39].getX()))
						star[i].state = false;
					else
						if (star[i].getY() == 7 && (star[i].getX() >= enemy[44].getX() && star[i].getX() <= enemy[45].getX()))
							star[i].state = false;
						else
							if (star[i].getY() == 8 && (star[i].getX() >= enemy[50].getX() && star[i].getX() <= enemy[51].getX()))
								star[i].state = false;
							else
								if (star[i].getY() == 9 && (star[i].getX() >= enemy[54].getX() && star[i].getX() <= enemy[55].getX()))
									star[i].state = false;
								else
									if (star[i].getY() == 10 && (star[i].getX() >= enemy[60].getX() && star[i].getX() <= enemy[61].getX()))
										star[i].state = false;
									else
										if (star[i].getY() == 11 && (star[i].getX() >= enemy[64].getX() && star[i].getX() <= enemy[65].getX()))
											star[i].state = false;
										else
											if ((star[i].getY() >= 12 && star[i].getY() <= 14) && (star[i].getX() >= enemy[81].getX() && star[i].getX() <= enemy[82].getX()))
												star[i].state = false;
											else
												if (star[i].getY() == 15 && (star[i].getX() >= enemy[102].getX() && star[i].getX() <= enemy[103].getX()))
													star[i].state = false;




		}
	}
}