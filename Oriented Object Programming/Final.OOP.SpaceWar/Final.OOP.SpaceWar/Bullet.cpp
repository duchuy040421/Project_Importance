#include "Header.h"


Bullet::Bullet()
{
	this->x = 0;
	this->y = 0;
	this->state = false;
}

void DrawBullet()
{
	for (int i = 0; i < nums_bullet; i++)
		if (bullet[i].state) {
			TextColor(14);
			bullet[i].Draw('o');
		}
}