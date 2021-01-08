#include "Header.h"


//bool STATE=true;
char MOVING = 'D';
SpaceShip space;
Enemy enemy[NUMs_ENEMY];
Bullet bullet[BULLETS];
Star star[STAR];
bool Right = true;
bool Up = true;
int nums_bullet = 0;
int Round = 1;
int HP = 100;
int Score = 0;
int coin = 0;
int Life = 2;
bool FlatContinue = false;
bool FlatPAgain = false;
bool FlatImpact = false;
int chon = 3;
int SkillShot = 1;
int numSkin = 1;
int countt = 0;
int Sec = 0;
int Min = 0;

int main()
{
	srand(time(NULL));
	FixConsoleWindow();
	SoundBackground();
	Menu();
	return 0;

}


