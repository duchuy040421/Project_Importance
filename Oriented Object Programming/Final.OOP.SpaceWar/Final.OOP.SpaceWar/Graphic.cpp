#include "Header.h"

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Announce()
{
	int count = 0;
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (!enemy[i].state)
			count++;
	TextColor(11);
	GotoXY(5, HEIGH_CONSOLE - 2);
	cout << "Coin:                  ";
	GotoXY(5, HEIGH_CONSOLE - 2);
	cout << "Coin : " << coin << " coins";
	GotoXY(WIDTH_CONSOLE - 20, HEIGH_CONSOLE - 2);
	cout << "Enemy left:        ";
	GotoXY(WIDTH_CONSOLE - 20, HEIGH_CONSOLE - 1);
	cout << "Bullet lef         ";
	GotoXY(WIDTH_CONSOLE - 20, HEIGH_CONSOLE - 3);
	cout << "Life:           ";
	GotoXY(WIDTH_CONSOLE - 20, HEIGH_CONSOLE - 2);
	if (Round == 1)
		cout << "Enemy left: " << NUMs_ENEMY - count;
	else if (Round == 2 && HP > 0)
		cout << "Enemy left: " << 1;
	else
		cout << "Enemy left: " << 0;
	GotoXY(WIDTH_CONSOLE - 20, HEIGH_CONSOLE - 1);
	cout << "Bullet left: " << BULLETS - nums_bullet;
	GotoXY(WIDTH_CONSOLE - 20, HEIGH_CONSOLE - 3);
	cout << "Life: " << Life;
	GotoXY(5, HEIGH_CONSOLE - 1);
	cout << "Score:         ";
	GotoXY(5, HEIGH_CONSOLE - 1);
	cout << "Score: " << Score;
	GotoXY(5, HEIGH_CONSOLE - 3);
	cout << "Time : ";
	printTime();
}
void GraphicNextRound()
{
	int x = space.getX();
	int y = space.getY();
	int Distance = abs(COORD_SPACE_Y - enemy[NUMs_ENEMY - 1].getY() - 1);
	int e_y = enemy[NUMs_ENEMY - 1].getY();

	system("cls");
	DrawFrame();
	Announce();
	DrawStar();
	space.Draww();
	for (int i = 0; i < NUMs_ENEMY; i++)
	{
		enemy[i].setCoord(enemy[i].getX(), enemy[i].getY() - e_y);
		enemy[i].state = false;
	}

	// hieu ung chuyen round
	space.Erase();
	SetColor(9);
	for (int i = 0; i < 3; i++)
	{
		GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 6);
		cout << "                                _       _____";
		GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 5);
		cout << "                               | |     / __  \\ ";
		GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 4);
		cout << " _ __  ____  _    _  __   _  __| |    |__| | |";
		GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 3);
		cout << "| '__|/ __ \\| |  | ||  \\ | |/ _` |        / /";
		GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 2);
		cout << "| |   |(__)|| |__| || |\\\\| ||(_| |       / /__ ";
		GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 1);
		cout << "|_|   \\____/\\______/|_| \\__|\\__,_|      /_,___|";
		Sleep(400);
		for (int j = 0; j < 6; j++)
		{
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 6 + j);
			cout << "                                                            ";
		}
		Sleep(200);
	}
	int speed = 500;

	while (space.getY() != 2)
	{
		DrawStar();
		space.Erase();
		space.Up();
		space.Draww();
		speed -= 50;
		if (speed <= 50)
			speed = 50;
		Sleep(speed);
	}
	space.Erase();
	Sleep(300);
	// hieu ung space va tau dich ha xuong
	while (space.getY() != COORD_SPACE_Y)
	{
		while (space.getY() != Distance)
		{
			DrawStar();
			space.Erase();
			space.Down();
			space.Draww();
			Sleep(speed);
			speed += 20;
			if (speed >= 120)
				speed = 120;
		}

		while (space.getY() != COORD_SPACE_Y)
		{
			for (int i = 0; i < NUMs_ENEMY; i++)
			{
				enemy[i].setCoord(enemy[i].getX(), enemy[i].getY() + 1);
				if (enemy[i].getY() == 3)
					enemy[i].state = true;
			}

			int x_min = enemy[0].getX(), x_max = x_min, y_max = enemy[0].getY();
			for (int i = 1; i < NUMs_ENEMY; i++)
			{
				if (enemy[i].state)
				{
					if (enemy[i].getX() > x_max) x_max = enemy[i].getX();
					else
						if (enemy[i].getX() < x_min) x_min = enemy[i].getX();
					if (enemy[i].getY() > y_max) y_max = enemy[i].getY();
				}
			}
			for (int i = x_min; i <= x_max; i++)
				for (int j = 3; j <= y_max; j++)
				{
					int count = 0;
					for (int k = 0; k < NUMs_ENEMY; k++)
						if (enemy[k].getX() == i && enemy[k].getY() == j && enemy[k].state)
							count++;
					if (count == 0)
					{
						GotoXY(i, j);
						cout << " ";
					}
				}
			DrawStar();
			EraseEnemy();
			DrawEnemy();
			space.Down();
			space.Draww();
			Sleep(120);
		}
	}
	BossHP();
	//hieu ung dich nhap nhay
	for (int i = 0; i < 4; i++)
	{
		EraseEnemy();
		DrawEnemy();
		Sleep(100);
	}
}
void BossHP()
{
	char c = 177;
	char khung;
	GotoXY(WIDTH_CONSOLE / 2 - 50, 1);
	SetColor(13);
	for (int r = 1; r <= HP; r++)
		cout << c;
	SetColor(15);
	for (int r = 100; r >= HP; r--)
	{
		GotoXY(WIDTH_CONSOLE / 2 - 50 + r, 1);
		cout << " ";
	}
	GotoXY(WIDTH_CONSOLE / 2 - 50, 0);
	khung = 205;
	for (int i = WIDTH_CONSOLE / 2 - 50; i < WIDTH_CONSOLE / 2 + 50; i++)
		cout << khung;
	GotoXY(WIDTH_CONSOLE / 2 - 51, 1);
	khung = 186;
	cout << khung;
	GotoXY(WIDTH_CONSOLE / 2 + 50, 1);
	cout << khung;

	GotoXY(WIDTH_CONSOLE / 2 - 51, 2);
	khung = 200;
	cout << khung;
	khung = 205;
	for (int i = WIDTH_CONSOLE / 2 - 50; i < WIDTH_CONSOLE / 2 + 50; i++)
		cout << khung;
	khung = 188;
	cout << khung;
}
void LoadGame()
{
	EndSoundGame();
	SoundLoading();
	char c = 178;
	char khung;
	SetColor(10);
	GotoXY(54, 11);
	printf("Loading...");
	GotoXY(34, 12);
	SetColor(9);
	khung = 201;
	cout << khung;
	khung = 205;
	for (int i = 35; i < 85; i++)
		cout << khung;
	khung = 187;
	cout << khung;
	GotoXY(34, 13);
	khung = 186;
	cout << khung;
	GotoXY(85, 13);
	cout << khung;

	GotoXY(34, 14);
	khung = 200;
	cout << khung;
	khung = 205;
	for (int i = 35; i < 85; i++)
		cout << khung;
	khung = 188;
	cout << khung;
	GotoXY(35, 13);
	SetColor(7);
	for (int i = 0; i < 50; i++)
	{
		Sleep(rand() % 200); //to display the character slowly
		cout << c;
	}
	EndSoundGame();
	Sleep(100);
}
void MenuDie()
{
	GotoXY(WIDTH_CONSOLE / 2 - 3, HEIGH_CONSOLE - 8);
	cout << "               ";
	GotoXY(WIDTH_CONSOLE / 2 - 3, HEIGH_CONSOLE - 8);
	cout << "YOU DIE !!";
	GotoXY(WIDTH_CONSOLE / 2 - 9, HEIGH_CONSOLE - 6);
	cout << "                           ";
	GotoXY(WIDTH_CONSOLE / 2 - 9, HEIGH_CONSOLE - 6);
	cout << "You have " << Life << " Life left.";
	string st;
	while (true)
	{
		SetColor(15);
		GotoXY(WIDTH_CONSOLE / 2 - 18, HEIGH_CONSOLE - 5);
		cout << "                                       ";
		GotoXY(WIDTH_CONSOLE / 2 - 18, HEIGH_CONSOLE - 5);
		cout << "Do you want to play again. (Yes:1/No:2): ";
		cin >> st;
		if (!atoi(st.c_str()) || (atoi(st.c_str())!=2 && atoi(st.c_str())!=1)) {
			chon = 3;
			GotoXY(WIDTH_CONSOLE / 2 + 23, HEIGH_CONSOLE - 5);
			for (int i = 0; i < st.length(); i++)
				cout << " ";
		}
		else
		{
			chon = atoi(st.c_str());
			break;
		}
	}
	if (Life != 0)
	{
		switch (chon)
		{
		case 1:
			Life--;
			HP = 100;
			nums_bullet = 0;
			FlatPAgain = true;
			space.state = true;	// Allow for Thread run
			for (int i = 0; i < NUMs_ENEMY; i++)
				enemy[i].state = true;
			if (Round >= 2)
			{
				SetCoordEnemy_R2(enemy);
			}
			PlayGame();
			chon = 3;
			break;
		case 2:
			ByeBye();
			break;
		}
	}
	else {
		ByeBye();
	}
	chon = 4;
}
void MenuWin()
{
	EndSoundGame();
	SoundGameWin();
	GraphicEarthSafe();
	Sleep(50);
	system("cls");
	ByeBye();
}
void Menu()
{
	GotoXY(27, 4); TextColor(9); cout << "___  ____  __ _  ___  ____      ___  _ _ _  ____  ____  ________  ___  _ __ \n";
	GotoXY(25, 5); TextColor(9); cout << "/___  ____  __ _  ___  ____/|   /___  _ _ _  ____  ____  ________  ___  _ __/| \n";
	GotoXY(25, 6); TextColor(10); cout << "/ __|/  _`\\/ _` |/ __|/ _ \\ |   / __|| |_| |/ __ \\/ __ \\|__    __|/ _ \\| '__||\n";
	GotoXY(25, 7); TextColor(11); cout << "\\__ \\| |_) |(_| ||(__ | __/ |   \\__\\ |  _  ||(__)||(__)|   |  |   | __/| |   |\n";
	GotoXY(25, 8); TextColor(12); cout << "|___/| __ /\\__,_|\\___|\\___|_/   |___/|_| |_|\\____/\\____/   |__|   \\___||_|___/   \n";
	GotoXY(25, 9); TextColor(12); cout << "     |_|";

	TextColor(17);
	GotoXY(41, 11); cout << "==========================================";
	GotoXY(41, 22); cout << "==========================================";

	for (int i = 12; i < 22; i++)
	{
		GotoXY(41, i);
		cout << "||";
		GotoXY(81, i);
		cout << "||";
	}

	TextColor(11);
	GotoXY(23, 6); cout << " /";
	GotoXY(23, 7); cout << "//";
	GotoXY(22, 8); cout << "//";
	GotoXY(21, 9); cout << "//";
	GotoXY(20, 10); cout << "//";
	GotoXY(19, 11); cout << "//";
	GotoXY(18, 12); cout << "//";
	GotoXY(17, 13); cout << "//";
	GotoXY(16, 14); cout << "//";
	GotoXY(16, 15); cout << "\\\\";
	GotoXY(17, 16); cout << "\\\\";
	GotoXY(18, 17); cout << "\\\\";
	GotoXY(19, 18); cout << "\\\\";
	GotoXY(20, 19); cout << "\\\\";
	GotoXY(21, 20); cout << "\\\\";
	GotoXY(22, 21); cout << "\\\\";
	GotoXY(23, 22); cout << "\\\\";
	GotoXY(24, 23); cout << "\\\\";
	GotoXY(25, 24); cout << "\\\\";
	GotoXY(26, 25); cout << "\\\\";
	GotoXY(27, 26); cout << "\\\\";
	GotoXY(28, 27); cout << "\\\\";
	GotoXY(29, 28); cout << "\\\\";
	GotoXY(30, 29); cout << "\\\\";

	GotoXY(103, 5); cout << "\\";
	GotoXY(103, 6); cout << "\\\\";
	GotoXY(104, 7); cout << "\\\\";
	GotoXY(105, 8); cout << "\\\\";
	GotoXY(106, 9); cout << "\\\\";
	GotoXY(107, 10); cout << "\\\\";
	GotoXY(108, 11); cout << "\\\\";
	GotoXY(109, 12); cout << "\\\\";
	GotoXY(110, 13); cout << "\\\\";
	GotoXY(111, 14); cout << "\\\\";
	GotoXY(111, 15); cout << "//";
	GotoXY(110, 16); cout << "//";
	GotoXY(109, 17); cout << "//";
	GotoXY(108, 18); cout << "//";
	GotoXY(107, 19); cout << "//";
	GotoXY(106, 20); cout << "//";
	GotoXY(105, 21); cout << "//";
	GotoXY(104, 22); cout << "//";
	GotoXY(103, 23); cout << "//";
	GotoXY(102, 24); cout << "//";
	GotoXY(101, 25); cout << "//";
	GotoXY(100, 26); cout << "//";
	GotoXY(99, 27); cout << "//";
	GotoXY(98, 28); cout << "//";
	GotoXY(97, 29); cout << "//";

	GotoXY(32, 29); cout << "========================";
	GotoXY(72, 29); cout << "=========================";

	TextColor(14);
	GotoXY(55, 25); cout << "    ||     ||     ";
	GotoXY(55, 26); cout << "   |  |___|  |    ";
	GotoXY(55, 27); cout << "  [    |_|    ]    ";
	GotoXY(55, 28); cout << " [_____________]   ";
	GotoXY(55, 29); cout << "[_______________]";
	GotoXY(55, 30); cout << "    ||     ||       ";

	GotoXY(43, 12);
	TextColor(11);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	GotoXY(53, 13);
	cout << "GAME: SPACE WAR";
	int idx = 15, idx_t = 15;
	GotoXY(53, idx);
	TextColor(14);
	cout << (char)175;
	GotoXY(56, 15);
	cout << "Start Game    " << endl;
	GotoXY(56, 16);
	TextColor(7);
	cout << "Rule       " << endl;
	GotoXY(50, 17);
	cout << "      About      " << endl;
	GotoXY(50, 18);
	cout << "      Score      " << endl;
	GotoXY(56, 19);
	cout << "Quit Game      " << endl;

	while (true)
	{
		char s = toupper(_getch());
		TextColor(11);
		idx_t = idx;
		if (s == 'W' || s == 72)
			idx--;
		else
			if (s == 'S' || s == 80)
				idx++;
		if (idx > 19)
			idx = 15;
		else
			if (idx < 15)
				idx = 19;
		GotoXY(53, idx_t);
		cout << "  ";
		GotoXY(53, idx);
		TextColor(14);
		cout << (char)175;
		GotoXY(56, 15);
		TextColor(7);
		if (idx == 15)
			TextColor(14);
		cout << "Start Game" << endl;
		GotoXY(56, 16);
		TextColor(7);
		if (idx == 16)
			TextColor(14);
		cout << "Rule" << endl;
		GotoXY(56, 17);
		TextColor(7);
		if (idx == 17)
			TextColor(14);
		cout << "About" << endl;
		GotoXY(56, 18);
		TextColor(7);
		if (idx == 18)
			TextColor(14);
		cout << "Score" << endl;
		TextColor(7);
		if (idx == 19)
			TextColor(14);
		GotoXY(56, 19);
		cout << "Quit Game" << endl;
		if (s == 13)
		{
			idx -= 14;
			break;
		}
	}
	switch (idx)
	{
	case 1:

		Menu1();
		break;
	case 2:
		MenuRule();
		break;
	case 3:
		MenuAbout();
		break;
	case 4:
		MenuScore();
		break;
	}

	ByeBye();
}
void Menu1()
{
	int idx = 15, idx_t = 15;
	GotoXY(53, idx);
	TextColor(14);
	cout << (char)175;
	GotoXY(56, 15);
	cout << "New Game  " << endl;
	GotoXY(56, 16);
	TextColor(7);
	cout << "Continue" << endl;
	GotoXY(56, 17);
	cout << "Menu " << endl;
	GotoXY(56, 18);
	cout << "                 " << endl;
	GotoXY(56, 19);
	cout << "                 " << endl;

	while (true)
	{
		char s = toupper(_getch());
		TextColor(11);
		idx_t = idx;
		if (s == 'W' || s == 72)
			idx--;
		else
			if (s == 'S' || s == 80)
				idx++;
		if (idx > 17)
			idx = 15;
		else
			if (idx < 15)
				idx = 17;
		GotoXY(53, idx_t);
		cout << "  ";
		GotoXY(53, idx);
		TextColor(14);
		cout << (char)175;
		GotoXY(56, 15);
		TextColor(7);
		if (idx == 15)
			TextColor(14);
		cout << "New Game" << endl;
		GotoXY(56, 16);
		TextColor(7);
		if (idx == 16)
			TextColor(14);
		cout << "Continue" << endl;
		GotoXY(56, 17);
		TextColor(7);
		if (idx == 17)
			TextColor(14);
		cout << "Menu" << endl;
		TextColor(7);

		if (s == 13)	//press Enter
		{
			idx -= 14;
			break;
		}
	}
	switch (idx)
	{
	case 1:
		Round = 1;
		PlayGame();
		break;
	case 2:
		FlatContinue = true;
		PlayGame();
		break;
	case 3:
		Menu();
		break;
	}
}
void MenuShop()
{
	int idx = 11, idx_t = idx;
	system("cls");
	TextColor(11);
	for (int j = 0; j < HEIGH_CONSOLE; j++) {
		for (int i = 0; i <= WIDTH_CONSOLE; i++) {
			cout << ".";
		}
	}
	for (int i = 5; i <= 17; i++) {
		GotoXY(41, i);
		for (int i = 1; i < 43; i++) {
			cout << " ";
		}
	}
	for (int i = 18; i < 21; i++) {
		GotoXY(49, i);
		for (int i = 1; i < 24; i++) {
			cout << " ";
		}
	}
	SetColor(3);
	GotoXY(43, 5);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	GotoXY(53, 6);
	cout << "  GAME: SPACE WAR";
	GotoXY(54, 8);
	SetColor(5);	cout << "    ===";
	SetColor(10);	cout << "SHOP";
	SetColor(5);	cout << "=== ";
	GotoXY(45, 10);
	SetColor(4);	cout << "    Use coin to buy these item: ";
	GotoXY(47, 11);
	TextColor(14);
	cout << (char)175;
	GotoXY(48, 11);
	TextColor(14);
	cout << " +1 Life         : 60 coins";
	SetColor(7);
	GotoXY(48, 12);
	cout << " +1 Bullet       : 1  coin";
	GotoXY(48, 13);
	cout << " Change SpaceShip: 30 coins";
	GotoXY(48, 14);
	cout << " Skill Shot (||) : 30 coins";
	GotoXY(48, 15);
	cout << " Back";
	SetColor(9);
	GotoXY(54, 19);
	cout << "You have: " << coin << " coin";
	GotoXY(51, 20);
	cout << "Bullet: " << BULLETS - nums_bullet << "\t Life: " << Life;
	GotoXY(51, 17);

	TextColor(50);

	for (int i = 1; i < 43; i++)
	{
		GotoXY(40 + i, 4);
		cout << "=";
		GotoXY(40 + i, 18);
		cout << "=";
	}

	for (int i = 5; i <= 17; i++) {
		GotoXY(41, i);
		cout << "||";
		GotoXY(81, i);
		cout << "||";
	}


	TextColor(17);

	for (int i = 49; i <= 73; i++) {
		GotoXY(i, 21);
		cout << "=";
	}

	GotoXY(49, 19);
	cout << "||";
	GotoXY(49, 20);
	cout << "||";
	GotoXY(72, 19);
	cout << "||";
	GotoXY(72, 20);
	cout << "||";
	TextColor(15);
	do
	{
		while (true)
		{
			char s = toupper(_getch());
			TextColor(11);
			idx_t = idx;
			if (s == 'W' || s == 72)
				idx--;
			else
				if (s == 'S' || s == 80)
					idx++;
			if (idx > 15)
				idx = 11;
			else
				if (idx < 11)
					idx = 15;
			GotoXY(47, idx_t);
			cout << " ";
			GotoXY(47, idx);
			TextColor(14);
			cout << (char)175;
			GotoXY(48, 11);
			TextColor(7);
			if (idx == 11)
				TextColor(14);
			cout << " +1 Life         : 60 coins" << endl;
			GotoXY(48, 12);
			TextColor(7);
			if (idx == 12)
				TextColor(14);
			cout << " +1 Bullet       : 1  coin" << endl;
			GotoXY(48, 13);
			TextColor(7);
			if (idx == 13)
				TextColor(14);
			cout << " Change SpaceShip: 30 coins" << endl;
			GotoXY(48, 14);
			TextColor(7);
			if (idx == 14)
				TextColor(14);
			cout << " Skill Shot (||) : 30 coins" << endl;
			TextColor(7);
			if (idx == 15)
				TextColor(14);
			GotoXY(48, 15);
			cout << " Back" << endl;
			if (s == 13)
			{
				idx -= 10;
				break;
			}
		}
		SetColor(10);
		switch (idx)
		{
		case 1:
			if (coin < 60)
			{
				GotoXY(54, 17);
				cout << "Not enough coin";
				Sleep(400);
			}
			else
			{
				Life += 1;
				coin -= 60;
				GotoXY(52, 17);
				cout << "You had bought 1 life";
				Sleep(600);
			}
			break;
		case 2:
			if (coin < 1)
			{
				GotoXY(54, 17);
				cout << "Not enough coin";
				Sleep(400);
			}
			else
			{
				int num;
				do
				{
					GotoXY(44, 17);
					cout << "                                ";
					GotoXY(44, 17);
					cout << "Enter number of bullets (0-" << coin << "):";
					cin >> num;
					if (num > coin || num < 0) {
						GotoXY(44, 17);
						cout << "Enter number of bullets (0-" << coin << "):    ";
					}
				} while (num<0 || num>coin);
				if (num != 0)
				{
					nums_bullet -= 1 * num;
					coin -= num;
				}
				GotoXY(44, 17);
				cout << "                                ";
				GotoXY(44, 17);
				cout << "       You had bought " << num << " bullets     ";
				Sleep(600);
			}
			break;
		case 3:
			if (coin < 30)
			{
				GotoXY(54, 17);
				cout << "Not enough coin";
				Sleep(400);
			}
			else
			{
				numSkin++;
				coin -= 30;
				GotoXY(44, 17);
				cout << "                                ";
				GotoXY(51, 17);
				cout << "You had bought new Skin";
				Sleep(600);
			}
			break;
		case 4:
			if (coin < 30)
			{
				GotoXY(54, 17);
				cout << "Not enough coin";
				Sleep(400);
			}
			else
			{
				SkillShot++;
				coin -= 30;
				GotoXY(44, 17);
				cout << "                                ";
				GotoXY(50, 17);
				cout << "You had bought Skill Shot";
				Sleep(600);
			}
			break;
		}
		if (idx != 5)
			idx += 10;
		GotoXY(43, 17);
		cout << "                                      ";
		SetColor(9);
		GotoXY(54, 19);
		cout << "You have: " << coin << " coin";
		GotoXY(51, 20);
		cout << "Bullet: " << BULLETS - nums_bullet << "\t Life: " << Life;
	} while (idx != 5);
	system("cls");
}
void MenuScore()
{
	fstream f;
	int count;
	int idx, idx_t;

	do
	{
		count = 0;
		f.open(FILENAME, ios::in);
		system("cls");
		while (!f.eof())
		{
			string s;
			getline(f, s);
			count++;
			if (s.length() <= 3)
			{
				if (count == 1)
				{
					GotoXY(WIDTH_CONSOLE / 2 - 8, count + 11);
					cout << "!!! NO DATA LOAD !!!";
				}
				break;
			}

			vector <string> data = parse(s, " ", true);
			Score = atoi(data[1].c_str());
			Life = atoi(data[2].c_str());
			Round = atoi(data[3].c_str());
			coin = atoi(data[4].c_str());
			Sec = atoi(data[11].c_str());
			Min = atoi(data[12].c_str());

			GotoXY(WIDTH_CONSOLE / 2 - 27, 15 + count);
			cout << data[0];
			GotoXY(WIDTH_CONSOLE / 2 + 10, 15 + count);
			cout << TotalScore();
			GotoXY(WIDTH_CONSOLE / 2 + 28, 15 + count);
			int time = modernization(Sec, Min);
			if (time < 60) {
				cout << time << " s";
			}
			else
				cout << time / 60 << " m " << time - (time / 60) * 60 << " s";
		}
		f.close();

		GotoXY(27, 4); TextColor(9); cout << "___  ____  __ _  ___  ____      ___  _ _ _  ____  ____  ________  ___  _ __ \n";
		GotoXY(25, 5); TextColor(9); cout << "/___  ____  __ _  ___  ____/|   /___  _ _ _  ____  ____  ________  ___  _ __/| \n";
		GotoXY(25, 6); TextColor(10); cout << "/ __|/  _`\\/ _` |/ __|/ _ \\ |   / __|| |_| |/ __ \\/ __ \\|__    __|/ _ \\| '__||\n";
		GotoXY(25, 7); TextColor(11); cout << "\\__ \\| |_) |(_| ||(__ | __/ |   \\__\\ |  _  ||(__)||(__)|   |  |   | __/| |   |\n";
		GotoXY(25, 8); TextColor(12); cout << "|___/| __ /\\__,_|\\___|\\___|_/   |___/|_| |_|\\____/\\____/   |__|   \\___||_|___/   \n";
		GotoXY(25, 9); TextColor(12); cout << "     |_|";
		SetColor(10);
		GotoXY(WIDTH_CONSOLE / 2 - 10, 9);
		cout << " ___  ___  ____  _ __  ___ ";
		GotoXY(WIDTH_CONSOLE / 2 - 10, 10);
		cout << "/ __|/ __|/ __ \\| '__|/ _ \\";
		GotoXY(WIDTH_CONSOLE / 2 - 10, 11);
		cout << "\\__ \\|(__ |(__)|| |   | __/";
		GotoXY(WIDTH_CONSOLE / 2 - 10, 12);
		cout << "|___/\\___|\\____/|_|   \\___|";
		{
			SetColor(14);
			GotoXY(WIDTH_CONSOLE / 2 - 25, 14);
			cout << "Player";
			GotoXY(WIDTH_CONSOLE / 2 + 9, 14);
			cout << "Score";
			GotoXY(WIDTH_CONSOLE / 2 + 30, 14);
			cout << "Time";
			char c;

			SetColor(1);
			GotoXY(WIDTH_CONSOLE / 2 - 42, 13);
			c = 220;
			for (int i = 0; i <= 83; i++)
				cout << c;
			GotoXY(WIDTH_CONSOLE / 2 - 41, 15);
			c = 223;
			for (int i = 0; i < 82; i++)
				cout << c;

			c = 220;
			GotoXY(WIDTH_CONSOLE / 2 - 41, 16 + count);
			for (int i = 0; i < 82; i++)
				cout << c;
			c = 219;
			for (int i = 0; i <= count + 2; i++)
			{
				GotoXY(WIDTH_CONSOLE / 2, 14 + i);
				cout << c;
				GotoXY(WIDTH_CONSOLE / 2 + 41, 14 + i);
				cout << c;
				GotoXY(WIDTH_CONSOLE / 2 - 42, 14 + i);
				cout << c;
				GotoXY(WIDTH_CONSOLE / 2 + 21, 14 + i);
				cout << c;
			}
		}
		count--;
		idx = 19 + count, idx_t = idx;
		GotoXY(53, idx);
		TextColor(14);
		cout << (char)175;
		GotoXY(56, idx);
		cout << "Clear data score" << endl;
		GotoXY(56, idx + 1);
		TextColor(7);
		cout << "Back" << endl;
		while (true)
		{
			char s = toupper(_getch());
			TextColor(11);
			idx_t = idx;
			if (s == 'W' || s == 72)
				idx--;
			else
				if (s == 'S' || s == 80)
					idx++;
			if (idx > 20 + count)
				idx = 19 + count;
			else
				if (idx < 19 + count)
					idx = 20 + count;
			GotoXY(53, idx_t);
			TextColor(14);
			cout << "  ";
			GotoXY(53, idx);
			TextColor(14);
			cout << (char)175;
			GotoXY(56, 19 + count);
			TextColor(7);
			if (idx == 19 + count)
				TextColor(14);
			cout << "Clear data score" << endl;
			GotoXY(56, 20 + count);
			TextColor(7);
			if (idx == 20 + count)
				TextColor(14);
			cout << "Back" << endl;
			if (s == 13)
			{
				idx = idx - 18 - count;
				break;
			}
		}
		switch (idx)
		{
		case 1:
			f.open(FILENAME, ios::out);
			f.close();
			SetColor(4);
			GotoXY(WIDTH_CONSOLE / 2 - 9, count + 18);
			cout << "!!! Data has been clear !!!";
			Sleep(1000);
			GotoXY(WIDTH_CONSOLE / 2 - 9, count + 18);
			cout << "                                  ";
			break;
		case 2:
			system("cls");
			Menu();
			break;
		}
	} while (idx != 2);
}
void MenuRule()
{
	GotoXY(41, 11);
	cout << "                                                    ";
	GotoXY(41, 12);
	cout << "  ";
	GotoXY(81, 12);
	cout << "  ";
	GotoXY(41, 13);
	cout << "  ";
	GotoXY(81, 13);
	cout << "  ";
	GotoXY(41, 14);
	cout << "  ";
	GotoXY(81, 14);
	cout << "  ";
	GotoXY(36, 15);
	SetColor(7);	cout << "    QUICK KEY                                                 ";
	GotoXY(36, 16);
	cout << "                                                                 ";
	GotoXY(30, 17);
	SetColor(14);	cout << "Space:";
	SetColor(3);	cout << " Pass round 1 (hack)                                   ";
	GotoXY(30, 18);
	SetColor(14);	cout << "  I  :";
	SetColor(3);	cout << " Quick kill Boss in round 2(hack)";
	GotoXY(30, 19);
	SetColor(14);	cout << "  L  :";
	SetColor(3);	cout << " Save game                                                      ";
	GotoXY(30, 20);
	SetColor(14);	cout << "  P  :";
	SetColor(3);	cout << " Pause game";
	GotoXY(30, 21);
	SetColor(14);	cout << "  K  :";
	SetColor(3);	cout << " Shop   ";
	GotoXY(30, 22);
	SetColor(14);	cout << " Esc :";
	SetColor(3);	cout << " Exit                                                          ";
	GotoXY(30, 23);
	SetColor(4);	cout << "       Kill all enemies to win";


	GotoXY(78, 15);
	SetColor(7);	cout << "MOVE";

	GotoXY(75, 18);
	SetColor(14);	cout << "     W   ";

	GotoXY(75, 19);
	SetColor(9);	cout << "     ^";

	GotoXY(75, 20);
	SetColor(14);	cout << " A ";

	GotoXY(78, 20);
	SetColor(9);	cout << "<   >";

	GotoXY(80, 20);
	SetColor(4);	cout << "O";

	GotoXY(84, 20);
	SetColor(14);	cout << "D";

	GotoXY(75, 21);
	SetColor(9);	cout << "     v   ";

	GotoXY(75, 22);
	SetColor(14);	cout << "     S";
	SetColor(14);

	GotoXY(93, 15);
	SetColor(7);	cout << "SHOT";
	GotoXY(95, 18);
	SetColor(9);
	cout << "O";
	GotoXY(95, 19);
	cout << "O";
	GotoXY(95, 20);
	cout << "O";
	GotoXY(92, 22);
	SetColor(14);	cout << "5:";
	SetColor(3);	cout << " Shot";

	TextColor(17);
	char c = 219;
	for (int i = 15; i < 24; i++) {
		GotoXY(72, i);
		cout << c;
		GotoXY(88, i);
		cout << c;
	}
	TextColor(11);
	SetColor(0);
	GotoXY(44, 24);
	system("pause");
	system("cls");
	Menu();
}

void MenuAbout()
{
	GotoXY(41, 11);
	cout << "                                                    ";
	GotoXY(41, 12);
	cout << "  ";
	GotoXY(81, 12);
	cout << "  ";
	GotoXY(41, 13);
	cout << "  ";
	GotoXY(81, 13);
	cout << "  ";
	GotoXY(41, 14);
	cout << "  ";
	GotoXY(81, 14);
	cout << "  ";
	GotoXY(40, 15);
	SetColor(14);
	printf("  Lecture:                                       ");
	SetColor(7);
	GotoXY(41, 16);
	printf("     - Nguyen Van Vu                        ");
	GotoXY(41, 17);
	printf("     - Tran Duy Quang                       ");
	GotoXY(41, 18);
	printf("     - Nguyen Le Hoang Dung                  ");
	GotoXY(41, 19);
	SetColor(14);
	printf("  Code by:                                          ");
	GotoXY(41, 20);
	SetColor(7);
	printf("     - 19127525: Nguyen Thanh Quan                 ");
	GotoXY(41, 21);
	printf("     - 19127422: Nguyen Duc Huy                    ");
	GotoXY(41, 22);
	printf("                                                     ");
	GotoXY(40, 23);
	SetColor(9);
	printf("  HCMUS _ Ho Chi Minh University of Sience.");
	GotoXY(59, 24);
	cout << "2019-2020";
	GotoXY(45, 22);
	SetColor(0);
	system("pause");
	system("cls");
	Menu();
}
void draw_bye1() {
	SetColor(10);
	GotoXY(20, 113);
	cout << " ____ ";
	GotoXY(20, 114);
	cout << "|  _ \\                        ";
	GotoXY(20, 115);
	cout << "| |_)|  __  __ ____";
	GotoXY(20, 116);
	cout << "|  __`\\ \\ \\/ // __ \\";
	GotoXY(20, 117);
	cout << "| |__)|  \\  / | ___/";
	GotoXY(20, 118);
	cout << "|_____/  /_/  \\____|";
}
void draw_bye2() {
	SetColor(10);
	GotoXY(82, 113);
	cout << " ____ ";
	GotoXY(82, 114);
	cout << "|  _ \\                        ";
	GotoXY(82, 115);
	cout << "| |_)|  __  __ ____";
	GotoXY(82, 116);
	cout << "|  __`\\ \\ \\/ // __ \\";
	GotoXY(82, 117);
	cout << "| |__)|  \\  / | ___/";
	GotoXY(82, 118);
	cout << "|_____/  /_/  \\____|";
}
void ByeBye()
{
	system("cls");

	const char rocket[] =
		"\t\t\t\t\t\t           _\n\t\t\t\t\t\t\
          /^\\\n\t\t\t\t\t\t\
          |-|\n\t\t\t\t\t\t\
          |B|\n\t\t\t\t\t\t\
          |Y|\n\t\t\t\t\t\t\
          |E|\n\t\t\t\t\t\t\
          | |\n\t\t\t\t\t\t\
          |B|\n\t\t\t\t\t\t\
         /|Y|\\\n\t\t\t\t\t\t\
        / |E| \\\n\t\t\t\t\t\t\
       |  | |  |\n\t\t\t\t\t\t\
        `-\"\"\"-`\n\t\t\t\t\t\t\
";

	GotoXY(27, 101); TextColor(9); cout << "___  ____  __ _  ___  ____      ___  _ _ _  ____  ____  ________  ___  _ __ \n";
	GotoXY(25, 102); TextColor(9); cout << "/___  ____  __ _  ___  ____/|   /___  _ _ _  ____  ____  ________  ___  _ __/| \n";
	GotoXY(25, 103); TextColor(10); cout << "/ __|/  _`\\/ _` |/ __|/ _ \\ |   / __|| |_| |/ __ \\/ __ \\|__    __|/ _ \\| '__||\n";
	GotoXY(25, 104); TextColor(11); cout << "\\__ \\| |_) |(_| ||(__ | __/ |   \\__\\ |  _  ||(__)||(__)|   |  |   | __/| |   |\n";
	GotoXY(25, 105); TextColor(12); cout << "|___/| __ /\\__,_|\\___|\\___|_/   |___/|_| |_|\\____/\\____/   |__|   \\___||_|___/   \n";
	GotoXY(25, 106); TextColor(12); cout << "     |_|";

	GotoXY(43, 107);
	TextColor(11);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	GotoXY(53, 108);
	cout << "GAME: SPACE WAR";
	SetColor(12);
	GotoXY(49, 111);
	cout << "  *******     *******";
	GotoXY(49, 112);
	cout << " *       *   *       *";
	GotoXY(49, 113);
	cout << "*         ***         *";
	GotoXY(49, 114);
	cout << " *                   *";
	GotoXY(49, 115);
	cout << "  *";
	GotoXY(53, 115);
	SetColor(14);
	cout << " SEE YOU AGAIN ";
	GotoXY(68, 115);
	SetColor(12);
	cout << " *";
	GotoXY(49, 116);
	cout << "    *             *";
	GotoXY(49, 117);
	cout << "      *         *";
	GotoXY(49, 118);
	cout << "        *     *";
	GotoXY(49, 119);
	cout << "          ***";
	GotoXY(49, 120);

	draw_bye1();
	draw_bye2();
	TextColor(14);
	GotoXY(0, 67);
	cout << rocket;
	SetColor(12);
	GotoXY(WIDTH_CONSOLE / 2 - 7, 78);
	cout << "  /";
	GotoXY(WIDTH_CONSOLE / 2 + 5, 78);
	cout << "\\\\";
	GotoXY(WIDTH_CONSOLE / 2 - 7, 79);
	cout << "/  /";
	GotoXY(WIDTH_CONSOLE / 2 + 5, 79);
	cout << "\\ \\";
	GotoXY(WIDTH_CONSOLE / 2 - 7, 80);
	cout << "\\   \\ \\ /   / /";
	GotoXY(WIDTH_CONSOLE / 2 - 7, 81);
	cout << "  \\    \\  /  /";
	GotoXY(WIDTH_CONSOLE / 2 - 7, 82);
	cout << "  \\_ \\    /  /";
	GotoXY(WIDTH_CONSOLE / 2 - 7, 83);
	cout << "     \\  \\  _/ ";
	GotoXY(WIDTH_CONSOLE / 2 - 7, 84);
	cout << "       \\ _/";
	GotoXY(WIDTH_CONSOLE / 2 - 7, 85);
	cout << "       \\/ ";
	SetColor(4);
	GotoXY(WIDTH_CONSOLE / 2 + 5, 78);
	cout << "\\";
	GotoXY(WIDTH_CONSOLE / 2 - 4, 79);
	cout << "/";
	GotoXY(WIDTH_CONSOLE / 2 + 5, 79);
	cout << "\\";
	GotoXY(WIDTH_CONSOLE / 2 - 3, 80);
	cout << "\\   /";
	GotoXY(WIDTH_CONSOLE / 2 + 3, 81);
	cout << "/";
	GotoXY(WIDTH_CONSOLE / 2 - 4, 82);
	cout << "_ \\";
	GotoXY(WIDTH_CONSOLE / 2 + 1, 83);
	cout << "\\";
	GotoXY(0, 0);	cout << " ";
	TextColor(11);
	int j = 300;
	EndSoundGame();
	SoundRocket();
	for (int i = 0; i < 63; i++) {
		Sleep(j); // move faster and faster,
		j -= 30; // so sleep less each time
		if (j <= 40)
			j = 40;
		GotoXY(0, 66 + i);
		printf(" "); // move rocket a line upward
	}
	EndSoundGame();
	Sleep(200);
	SoundByeBye();
	SetColor(0);
	Sleep(1500);
	GotoXY(0, 122);
	exit(0);
}
void GraphicBossDie()
{

	for (int i = 0; i < 8; i++)
	{
		EraseEnemy();
		MoveRight(enemy);
		DrawEnemy();
		GotoXY(enemy[83].getX() + 1, enemy[83].getY());
		cout << "wwwwwwwwwww";
		for (int i = 30; i < 34; i++)
		{
			GotoXY(enemy[i].getX(), enemy[i].getY());
			cout << "*";
			GotoXY(enemy[i + 4].getX(), enemy[i + 4].getY());
			cout << "*";
		}
		GotoXY(enemy[40].getX(), enemy[40].getY());
		cout << "*@@";
		GotoXY(enemy[41].getX(), enemy[41].getY());
		cout << "*";
		GotoXY(enemy[42].getX(), enemy[42].getY());
		cout << "*@@";
		GotoXY(enemy[43].getX(), enemy[43].getY());
		cout << "*";
		GotoXY(enemy[46].getX(), enemy[46].getY());
		cout << "**";
		GotoXY(enemy[48].getX(), enemy[48].getY());
		cout << "**";
		GotoXY(enemy[82].getX() + 2, enemy[82].getY());
		cout << "NOOOOOOOOO !!!!";
		Sleep(130);
		EraseEnemy();
		MoveLeft(enemy);
		DrawEnemy();
		GotoXY(enemy[83].getX() + 1, enemy[83].getY()); //56->68=57->67=11
		cout << " --------- ";
		for (int i = 30; i < 34; i++)
		{
			GotoXY(enemy[i].getX(), enemy[i].getY());
			cout << "@";
			GotoXY(enemy[i + 4].getX(), enemy[i + 4].getY());
			cout << "@";
		}
		GotoXY(enemy[40].getX(), enemy[40].getY());
		cout << "@  ";
		GotoXY(enemy[41].getX(), enemy[41].getY());
		cout << "@";
		GotoXY(enemy[42].getX(), enemy[42].getY());
		cout << "@  ";
		GotoXY(enemy[43].getX(), enemy[43].getY());
		cout << "@";
		GotoXY(enemy[46].getX(), enemy[46].getY());
		cout << "@@";
		GotoXY(enemy[48].getX(), enemy[48].getY());
		cout << "@@";
		GotoXY(enemy[82].getX() + 2, enemy[82].getY());
		cout << "                 ";
		Sleep(130);
	}
	Sleep(300);
	GotoXY(WIDTH_CONSOLE / 2 - 8, 1);
	cout << "YOU DEFEAT THE BOSS";
	SoundGameWin();
	TextColor(62);
	for (int i = 3; i <= COORD_SPACE_Y; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 1; j < WIDTH_CONSOLE; j++)
			{
				GotoXY(j, i);
				cout << " ";
				Sleep(1);
			}
		}
		else
		{
			for (int j = WIDTH_CONSOLE - 1; j > 0; j--)
			{
				GotoXY(j, i);
				cout << " ";
				Sleep(1);
			}
		}

	}
	GotoXY(7, 8);
	cout << "  ___      ____  __________      ___      ___       ____                       ____  ___   ___ ______";
	GotoXY(7, 9);
	cout << "  \\yyy\\   /yyy/ /oooooooooo\\    |uuu|    |uuu|      \\www\\                     /www/ |iii| |nnn\\nnnnnnn\\";
	GotoXY(7, 10);
	cout << "   \\yyy\\ /yyy/ /oooooooooooo\\   |uuu|    |uuu|       \\www\\                   /www/  |iii| |nnnnnnnnnnnn\\";
	GotoXY(7, 11);
	cout << "    \\yyy/yyy/ /ooo/      \\ooo\\  |uuu|    |uuu|        \\www\\      _____      /www/   |iii| |nnn|    \\nnnn|";
	GotoXY(7, 12);
	cout << "     \\yyyy/  /ooo\\        /ooo/ |uuu|    |uuu|         \\www\\    /wwwww\\    /www/    |iii| |nnn|     |nnn|";
	GotoXY(7, 13);
	cout << "     /yyy/    \\ooo\\______/ooo/  |uuu|____|uuu|          \\www\\  /www/www\\  /www/     |iii| |nnn|     |nnn|";
	GotoXY(7, 14);
	cout << "    /yyy/      \\oooooooooooo/   |uuuuuuuuuuuu|           \\www\\/www/ \\www\\/www/      |iii| |nnn|     |nnn|";
	GotoXY(7, 15);
	cout << "   /yyy/        \\oooooooooo/     \\uuuuuuuuuu/             \\wwwwww/   \\wwwwww/       |iii| |nnn|     |nnn|";
	Sleep(1100);
}
void GraphicEnemyDie(int x, int y)
{
	SetColor(10);
	//			. .
	//		   . * .	
	//			 '
	// ve
	GotoXY(x, y);
	cout << "*";
	GotoXY(x - 2, y);
	cout << ".";
	GotoXY(x + 2, y);
	cout << ".";
	GotoXY(x, y + 2);
	cout << ".";
	GotoXY(x - 1, y - 1);
	cout << ".";
	GotoXY(x + 1, y - 1);
	cout << ".";
	Sleep(40);
	// xoa
	GotoXY(x, y);
	cout << " ";
	GotoXY(x - 2, y);
	cout << " ";
	GotoXY(x + 2, y);
	cout << " ";
	GotoXY(x, y + 2);
	cout << " ";
	GotoXY(x - 1, y - 1);
	cout << " ";
	GotoXY(x + 1, y - 1);
	cout << " ";
}
void GraphicImpact()
{
	SetColor(14);
	GotoXY(space.getX(), space.getY());
	cout << "X";
	GotoXY(space.getX() - 2, space.getY());
	cout << "==";
	GotoXY(space.getX() + 1, space.getY());
	cout << "==";
	GotoXY(space.getX(), space.getY() + 1);
	cout << "|";
	GotoXY(space.getX(), space.getY() - 1);
	cout << "|";
	GotoXY(space.getX() - 2, space.getY() + 1);
	cout << "//";
	GotoXY(space.getX() - 2, space.getY() - 1);
	cout << "\\\\";
	GotoXY(space.getX() + 1, space.getY() - 1);
	cout << "//";
	GotoXY(space.getX() + 1, space.getY() + 1);
	cout << "\\\\";
}
void DrawFrame()
{
	TextColor(15);
	char c = 186;
	for (int i = 1; i < HEIGH_CONSOLE; i++)
	{
		GotoXY(0, i);
		cout << c;
		GotoXY(WIDTH_CONSOLE, i);
		cout << c;
	}

	c = 205;
	for (int i = 1; i < WIDTH_CONSOLE; i++)
	{

		GotoXY(i, HEIGH_CONSOLE);
		cout << c;
		GotoXY(i, HEIGH_CONSOLE - 4);
		cout << c;
	}
	for (int i = 1; i < 8; i++)
	{
		GotoXY(i, 0);
		cout << c;
	}
	for (int i = 9; i <= WIDTH_CONSOLE - 11; i++)
	{
		GotoXY(i, 0);
		cout << c;
	}
	for (int i = WIDTH_CONSOLE - 9; i < WIDTH_CONSOLE; i++)
	{
		GotoXY(i, 0);
		cout << c;
	}
	if (Round == 2)
	{
		c = 203;
		GotoXY(8, 0);
		cout << c;
		GotoXY(WIDTH_CONSOLE - 10, 0);
		cout << c;
	}
	else
	{
		c = 205;
		GotoXY(8, 0);
		cout << c;
		GotoXY(WIDTH_CONSOLE - 10, 0);
		cout << c;
	}
	c = 201;
	GotoXY(0, 0);
	cout << c;
	c = 204;
	GotoXY(0, HEIGH_CONSOLE - 4);
	cout << c;
	c = 200;
	GotoXY(0, HEIGH_CONSOLE);
	cout << c;

	c = 187;
	GotoXY(WIDTH_CONSOLE, 0);
	cout << c;
	c = 185;
	GotoXY(WIDTH_CONSOLE, HEIGH_CONSOLE - 4);
	cout << c;
	c = 188;
	GotoXY(WIDTH_CONSOLE, HEIGH_CONSOLE);
	cout << c;
}
void GraphicEarthSafe()
{
	TextColor(0);
	for (int i = 0; i <= HEIGH_CONSOLE; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j <= WIDTH_CONSOLE; j++)
			{
				GotoXY(j, i);
				cout << " ";
			}
		}
		else
		{
			for (int j = WIDTH_CONSOLE; j >= 0; j--)
			{
				GotoXY(j, i);
				cout << " ";
			}
		}

	}
	EndSoundGame();
	SoundCheering();
	//draw rim
	SetColor(15);
	GotoXY(20, 5);
	cout << "                           _______________________________                   ";
	GotoXY(20, 6);
	cout << "                         _/                               \\_              ";
	GotoXY(20, 7);
	cout << "                     ___/                                   \\___              ";
	GotoXY(20, 8);
	cout << "                   _/                                           \\_            ";
	GotoXY(20, 9);
	cout << "                __/	                                              \\__              ";
	GotoXY(20, 10);
	cout << "               /                                                     \\              ";
	GotoXY(20, 11);
	cout << "            __|                                                       |__          ";
	GotoXY(20, 12);
	cout << "           /'                                                            \\             ";
	GotoXY(20, 13);
	cout << "         _|                                                               |_              ";
	GotoXY(20, 14);
	cout << "        /                                                                   \\              ";
	GotoXY(20, 15);
	cout << "       |                                                                     |            ";
	GotoXY(20, 16);
	cout << "      /                                                                       \\            ";
	GotoXY(20, 17);
	cout << "      |                                                                        |          ";
	GotoXY(20, 18);
	cout << "      \\                                                                        /           ";
	GotoXY(20, 19);
	cout << "       |                                                                      |           ";
	GotoXY(20, 20);
	cout << "        \\_                                                                  _/                    ";
	GotoXY(20, 21);
	cout << "          |                                                                |             ";
	GotoXY(20, 22);
	cout << "           \\__                                                          __/              ";
	GotoXY(20, 23);
	cout << "              |                                                        |                 ";
	GotoXY(20, 24);
	cout << "               \\__                                                  __/                 ";
	GotoXY(20, 25);
	cout << "                  \\_                                              _/                  ";
	GotoXY(20, 26);
	cout << "                    \\___                                      ___/                   ";
	GotoXY(20, 27);
	cout << "                        \\_                                  _/                       ";
	GotoXY(20, 28);
	cout << "                          \\________________________________/                   ";


	// draw plane
	SetColor(10);
	GotoXY(47, 6);
	cout << "///////////////////////////////";
	GotoXY(45, 7);
	cout << "///  _/////////////////////////////";
	GotoXY(41, 8);
	cout << "//////  ////////////   /////////";
	GotoXY(51, 9);
	cout << "/////////    _////_";
	GotoXY(43, 10);
	cout << "________________    ///////";
	GotoXY(41, 11);
	cout << "_/////////////////_         __________________";
	GotoXY(39, 12);
	cout << "_////////////////////  ___   ///////////////////______";
	GotoXY(38, 13);
	cout << "//////////////////////__///    ////////////////////////";
	GotoXY(37, 14);
	cout << "///////////////////////////      ////////////////////";
	GotoXY(38, 15);
	cout << "////////////////////////        ///////////////////";
	GotoXY(39, 16);
	cout << "/////////////////////           __///////////////";
	GotoXY(40, 17);
	cout << "///////  _/////////          _////////////////__";
	GotoXY(40, 18);
	cout << "////// _/////////           ////////////////////_";
	GotoXY(30, 19);
	cout << " _____          /////////            //////////////////////";
	GotoXY(30, 20);
	cout << "//////         ////////               //////////";
	GotoXY(31, 21);
	cout << "/////____     /////                  ////         ____";
	GotoXY(33, 22);
	cout << "///////      //                    //        __//////____";
	GotoXY(35, 23);
	cout << "///_                      _              _/////////////_";
	GotoXY(37, 24);
	cout << "//           __        //             /////// ///////";
	GotoXY(49, 25);
	cout << "///_                         ///   ///";
	GotoXY(50, 26);
	cout << "///             __";
	GotoXY(63, 27);
	cout << "  ///";

	for (int i = 0; i < 6; i++)
	{
		GotoXY(8, 0);
		cout << "                                                                                                                            ";
		GotoXY(8, 1);
		cout << "                                                                                                                                       ";
		GotoXY(8, 2);
		cout << "                                                                                                                                       ";
		GotoXY(8, 3);
		cout << "                                                                                                                                       ";
		GotoXY(8, 4);
		cout << "                                                                                                                                       ";
		Sleep(300);
		GotoXY(8, 0);
		cout << "                                                                                                       _                          ";
		GotoXY(8, 1);
		SetColor(9);
		cout << "   ____   __ _   ___    _     _           _       _   __ _   ___       ___   __ _   _    _   ____   __| |                        ";
		GotoXY(8, 2);
		cout << "  / __ \\ / _` | | __| _| |   | |__       | | ___ | | /  ` | / __|     / __| /  ` | | |  | | / __ \\ / _  |                    ";
		GotoXY(8, 3);
		cout << "  | ___/ |(_| | | |  |_  |_  |  _ \\      \\ \\/ _ \\/ / |(_| | \\__ \\     \\__ \\ |(_| |  \\ \\/ /  | ___/ |(_| |";
		GotoXY(8, 4);
		cout << "  \\____| \\__,_| |_|    \\___| |_| |_|      \\__/ \\__/  \\__,_| |___/     |___/ \\__,_|   \\__/   \\____| \\____|";
		Sleep(470);
	}
}