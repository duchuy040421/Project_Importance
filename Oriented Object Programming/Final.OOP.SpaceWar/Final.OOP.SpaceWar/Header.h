#pragma comment(lib, "Winmm.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include<MMsystem.h>		//include library for playing sound

using namespace std::chrono;
//using namespace std::literals::chrono_literals;
using namespace std;

extern bool Right;
extern bool Up;
extern char MOVING;
extern int nums_bullet;
extern int Round;
extern int HP;
extern int Score;
extern int coin;
extern int Life;
extern bool FlatContinue;
extern bool FlatPAgain;
extern bool FlatImpact;
extern int chon;
extern int SkillShot;
extern int numSkin;
extern int countt;
extern int Sec;
extern int Min;
//static steady_clock::time_point start;

//static int choice;
#define WIDTH_CONSOLE 119
#define HEIGH_CONSOLE 29
#define COORD_SPACE_X  (WIDTH_CONSOLE/2)
#define COORD_SPACE_Y  24
#define COORD_ENEMY_X  0
#define COORD_ENEMY_Y  0
#define BULLETS 300
#define NUMs_ENEMY 120
#define SPEED 20
#define STAR 70
#define FILENAME "Data.txt"

//banphaohoa
#define minx 1
#define maxx 79
#define miny 1
#define maxy 50

class Coordinate
{
protected:
	int x;
	int y;
public:
	void Draw(char);
	int getX();
	int getY();
	void setCoord(int, int);
	bool state = true;
};
class SpaceShip :public Coordinate
{
public:
	SpaceShip();
	void Left();
	void Down();
	void Up();
	void Right();
	void Draww();
	void Erase();

};
class Bullet :public Coordinate
{
public:
	Bullet();
};
class Enemy :public Coordinate
{
public:
	Enemy();
	bool TouchBoundary();
};
class Star :public Coordinate
{
public:
	Star();
};
extern SpaceShip space;
extern Enemy enemy[NUMs_ENEMY];
extern Bullet bullet[BULLETS];
extern Star star[STAR];

//Spaceship.cpp
void Shot(int, int);		// let spaceship fire

//Bullet.cpp
void DrawBullet();			// draw bullets

//Enemy.cpp
void SetCoordEnemy_R1(Enemy e[NUMs_ENEMY]);	// set Shape of enemy of round1
void SetCoordEnemy_R2(Enemy e[NUMs_ENEMY]);	// set Shape of enemy of round2
void DrawEnemy();							// Draw enemy whose state = true
void EraseEnemy();							// Erase ennemy

//Star.cpp
void SetCoordStar(Star star[STAR]);
void DrawStar();
void EraseStar();

//Graphic.cpp
void FixConsoleWindow();	// co dinh man hinh console
void Announce();			// anounce information: life, bullets, enemies left,...
void GraphicNextRound();	// Graphic when you win round 1
void BossHP();				// show Boss's HP
void LoadGame();			// Graphic Load game when you Enter game
void MenuDie();				// Menu when you die
void MenuWin();				// Menu when you Win game
void Menu();				// Menu when enter game
void Menu1();				// Menu when choose Start game on Menu()
void MenuShop();			// Menu when you enter shop
void MenuScore();			// Menu when you enter Score
void MenuRule();			// Menu when you enter Rule
void MenuAbout();			// Menu when you enter About
void draw_bye1();
void draw_bye2();
void ByeBye();				// Menu when you Exit game
void GraphicBossDie();		// Graphic when boss die
void GraphicEnemyDie(int x, int y);
void GraphicImpact();		// graphic when you impact
void DrawFrame();			// Draw Frame game play
void GraphicEarthSafe();

//Function.cpp
vector<string> parse(string, string, bool);
void ResetData();			// reset data
void StartGame();			// set all infor defaut
void GotoXY(int x, int y);	// move to coordinate (x,y)
void ExitGame(HANDLE t);
void SetColor(int ForgC);	// change text color
void TextColor(int x);      // change text color
bool Kill(Bullet& bullet);	// check whether bullet kill enemy
bool checkDie();			// Check whether you die
bool isImpact();			// Check whether you impact enemy
void PauseGame(HANDLE t);	// Pause game
void Pause(HANDLE t);	// Pause game
void PlayGame();			// Play game
void SubThread();			// run multi thread
bool checkRound1();			// check whether you pass Round1
bool CheckName(string name);// Check whether name you save have same with name had saved before
int TotalScore();			// count Total Score
void SaveGame();			// save game
void Continue();			// function to continue game had saved before

//Sound.cpp
void SoundGame();           //Sound Game when you play
void SoundBossDie();          //Sound Game when boss die
void SoundLoading();        //Sound Game loading data
void SoundExplosion();		//Sound explosion
void SoundBackground();
void SoundGameOver();		//Sound Game over when you lost
void SoundGameWin();		//Sound Gamw when you win the game
void SoundCheering();       //Sound cheering
void SoundByeBye();
void SoundRocket();
void EndSoundGame();         //End sound game

//Move.cpp
void MoveRight(Enemy enemy[NUMs_ENEMY]);	// move enemy right
void MoveLeft(Enemy enemy[NUMs_ENEMY]);		// move enemy left
void MoveUp(Enemy enemy[NUMs_ENEMY]);
void MoveDown(Enemy enemy[NUMs_ENEMY]);
void MoveEnemy();							// move enemy
void MoveBullets();			// move bullets
void MoveStar();

//Time.cpp
int modernization(int sec, int min);
void printTime();
void startTime();