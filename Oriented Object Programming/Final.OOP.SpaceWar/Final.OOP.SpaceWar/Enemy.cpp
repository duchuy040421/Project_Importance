#include "Header.h"

Enemy::Enemy()
{
	this->x = COORD_ENEMY_X;
	this->y = COORD_ENEMY_Y;
}
bool Enemy::TouchBoundary()
{
	if (this->x == WIDTH_CONSOLE - 1 || this->x == 1)
		return true;

	return false;
}
void SetCoordEnemy_R1(Enemy e[])
{


	int height = 1;
	int count = 0;
	int width = 19;
	for (int i = 0; i < NUMs_ENEMY; i++)
	{
		e[i].setCoord(WIDTH_CONSOLE / 2 - (width - 2 * count) * 2, height);
		++count;
		if (count == width && i != 0)
		{
			height++;
			width--;
			count = 0;
		}
	}
}
//                 ************************		
//                *                        *
//               *                          * 
//              *    ****           ****     *
//             *     *  *           *  *      *
//            *       **             **        *
//            *               **               *
//             **             **             **
//               **                        **
//                 **    *************   **
//                   *   *           *  * 
//                   *   *************  *
//                   *                  *
//                    *                *
//                     ****************  


void SetCoordEnemy_R2(Enemy e[])
{

	for (int i = 50; i < 50 + 24; i++)
		enemy[i - 50].setCoord(i, 2);
	enemy[24].setCoord(49, 3);
	enemy[25].setCoord(74, 3);

	enemy[26].setCoord(48, 4);
	enemy[27].setCoord(75, 4);
	enemy[28].setCoord(47, 5);
	enemy[29].setCoord(76, 5);
	for (int i = 30; i < 34; i++)
	{
		enemy[i].setCoord(i + 24, 5);
		enemy[i + 4].setCoord(i + 36, 5);
	}
	enemy[38].setCoord(46, 6);
	enemy[39].setCoord(77, 6);
	enemy[40].setCoord(54, 6);
	enemy[41].setCoord(57, 6);
	enemy[42].setCoord(66, 6);
	enemy[43].setCoord(69, 6);

	enemy[44].setCoord(45, 7);
	enemy[45].setCoord(78, 7);
	enemy[46].setCoord(55, 7);
	enemy[47].setCoord(56, 7);
	enemy[48].setCoord(67, 7);
	enemy[49].setCoord(68, 7);

	enemy[50].setCoord(45, 8);
	enemy[51].setCoord(78, 8);
	enemy[52].setCoord(61, 8);
	enemy[53].setCoord(62, 8);

	enemy[54].setCoord(46, 9);
	enemy[55].setCoord(77, 9);
	enemy[56].setCoord(47, 9);
	enemy[57].setCoord(76, 9);
	enemy[58].setCoord(61, 9);
	enemy[59].setCoord(62, 9);

	enemy[60].setCoord(48, 10);
	enemy[61].setCoord(75, 10);
	enemy[62].setCoord(49, 10);
	enemy[63].setCoord(74, 10);

	enemy[64].setCoord(50, 11);
	enemy[65].setCoord(73, 11);
	enemy[66].setCoord(51, 11);
	enemy[67].setCoord(72, 11);
	for (int i = 68; i < 81; i++)
		enemy[i].setCoord(i - 12, 11);

	enemy[81].setCoord(52, 12);
	enemy[82].setCoord(71, 12);
	enemy[83].setCoord(56, 12);		// dau mieng
	enemy[84].setCoord(68, 12);

	enemy[85].setCoord(52, 13);
	enemy[86].setCoord(71, 13);
	for (int i = 87; i < 100; i++)
		enemy[i].setCoord(i - 31, 13);

	enemy[100].setCoord(52, 14);
	enemy[101].setCoord(71, 14);

	enemy[102].setCoord(53, 15);
	enemy[103].setCoord(70, 15);

	for (int i = 104; i < 120; i++)
		enemy[i].setCoord(i - 50, 16);
}
void DrawEnemy()
{
	if (Round >= 2)
		BossHP();
	TextColor(68);
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (enemy[i].state)
			enemy[i].Draw('M');
	TextColor(11);

}
void EraseEnemy()
{
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (enemy[i].state)
			enemy[i].Draw(' ');
}
