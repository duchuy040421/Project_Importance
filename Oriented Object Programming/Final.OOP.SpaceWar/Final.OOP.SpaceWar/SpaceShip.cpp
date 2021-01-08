#include "Header.h"



SpaceShip::SpaceShip()
{
	this->x = COORD_SPACE_X;
	this->y = COORD_SPACE_Y;
}

void SpaceShip::Draww()
{
	char canh_p, canh_t, than;
	SetColor(10);
	if (numSkin == 1)
	{
		GotoXY(x - 1, y);
		than = 219;
		cout << "<" << than << ">";
	}
	else
	{
		canh_p = canh_t = 223; than = 219;
		char canh_dp = 220, canh_dt = canh_dp, dau = 254;
		GotoXY(x, y - 1);
		cout << dau;
		GotoXY(x - 2, y);
		cout << canh_dt << canh_t << than << canh_p << canh_dp;
	}

}
void SpaceShip::Erase()
{
	GotoXY(x - 1, y);
	cout << "   ";
}

void SpaceShip::Left()
{

	if (numSkin == 1)
	{
		GotoXY(this->x + 1, this->y);
		cout << " ";
		if (this->x > 2)
			--this->x;
	}
	if (numSkin == 2)
	{
		GotoXY(this->x + 2, this->y);
		cout << " ";
		GotoXY(this->x, this->y - 1);
		cout << " ";
		if (this->x > 3)
			--this->x;
	}
}
void SpaceShip::Down()
{
	if (numSkin == 1)
	{
		GotoXY(this->x - 1, this->y);
		cout << "   ";

	}
	else
		if (numSkin == 2)
		{
			GotoXY(this->x - 2, this->y);
			cout << "     ";
			GotoXY(this->x, this->y - 1);
			cout << " ";

		}
	if (this->y != HEIGH_CONSOLE - 5)
		++this->y;

}
void SpaceShip::Up()
{
	if (numSkin == 1)
	{
		GotoXY(this->x - 1, this->y);
		cout << "   ";
		if (this->y > 1)
			--this->y;
	}
	else
		if (numSkin == 2)
		{
			GotoXY(this->x - 2, this->y);
			cout << "     ";
			GotoXY(this->x, this->y - 1);
			cout << " ";
			if (this->y > 2)
				--this->y;
		}

}
void SpaceShip::Right()
{
	if (numSkin == 1)
	{
		GotoXY(this->x - 1, this->y);
		cout << " ";

		if (this->x < WIDTH_CONSOLE - 2)
			++this->x;
	}
	else
		if (numSkin == 2)
		{
			GotoXY(this->x - 2, this->y);
			cout << " ";
			GotoXY(this->x, this->y - 1);
			cout << " ";
			if (this->x < WIDTH_CONSOLE - 3)
				++this->x;
		}
}

void Shot(int x, int y)
{
	bool flatt = false;
	if (nums_bullet != BULLETS)
	{
		for (int i = 0; i < nums_bullet; i++)
			if (bullet[i].getX() == x && bullet[i].getY() == y - 1)
				flatt = true;
		if (!flatt && SkillShot == 1)
		{
			bullet[nums_bullet].setCoord(x, y - 1);
			bullet[nums_bullet++].state = true;
		}
		else
		{
			if (!flatt && SkillShot == 2)
			{
				bullet[nums_bullet].setCoord(x - 1, y - 1);
				bullet[nums_bullet++].state = true;
				bullet[nums_bullet].setCoord(x + 1, y - 1);
				bullet[nums_bullet++].state = true;
			}
		}
	}
	else
	{
		GotoXY(WIDTH_CONSOLE / 2 - 35, HEIGH_CONSOLE);
		cout << "You run out of Bullet";
	}
}