#include "Header.h"

vector<string> parse(string haystack, string seperator = " ", bool RemoveEmptyEntries = false)
{
	//string st = "hello new  world";
	size_t startPos = 0;
	vector<string> result;
	size_t Pos;
	size_t Pos2;
	while (true)
	{
		Pos = haystack.find(seperator, startPos);
		if (Pos != string::npos)
		{
			if (!RemoveEmptyEntries)
			{
				result.push_back(haystack.substr(startPos, Pos - startPos));
				startPos = Pos + seperator.length();
			}
			else
			{
				result.push_back(haystack.substr(startPos, Pos - startPos));
				startPos = Pos + seperator.length();
				Pos2 = haystack.find(seperator, startPos);
				while (true)
				{
					if (Pos2 - Pos == seperator.length())
					{
						Pos = Pos2;
						startPos = Pos + seperator.length();
						Pos2 = haystack.find(seperator, startPos);
					}
					else break;
				}
			}
		}
		else
			break;
	}
	result.push_back(haystack.substr(startPos, haystack.length() - Pos));

	return result;

}
void ResetData()
{
	if (Round == 1)
	{
		SetCoordEnemy_R1(enemy);
	}
	else
	{
		SetCoordEnemy_R2(enemy);
	}
	space.setCoord(COORD_SPACE_X, COORD_SPACE_Y);
	SetCoordStar(star);
	SkillShot = 1;
	numSkin = 1;
}
void StartGame() {
	system("cls");
	ResetData();	// Creater original data
	space.state = true;	// Allow for Thread run
	for (int i = 0; i < NUMs_ENEMY; i++)
		enemy[i].state = true;
	nums_bullet = 0;
	FlatImpact = false;
	TextColor(11);
	startTime();
	SoundGame();
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ExitGame(HANDLE t) {
	system("cls");
	TerminateThread(t, 0);
}
void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}
void TextColor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

bool Kill(Bullet& bullet)
{
	for (int i = 0; i < NUMs_ENEMY; i++)
	{
		if (enemy[i].getX() == bullet.getX() && enemy[i].getY() == bullet.getY() && enemy[i].state)
		{
			if (Round == 1)
				enemy[i].state = false;
			else if (Round == 2)
				HP--;
			bullet.state = false;
			return true;
		}
	}
	return false;
}
bool checkDie()
{
	int count = 0;
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (!enemy[i].state)
			count++;
	if (count == NUMs_ENEMY && BULLETS - nums_bullet >= 0 && Round == 1)
		return false;
	if (BULLETS - nums_bullet == 0 && Round == 2 && HP > 0)
		return true;
	if (BULLETS - nums_bullet == 0)
		return true;
	if (isImpact())
		return true;
	return false;
}
bool isImpact()
{
	for (int i = 0; i < NUMs_ENEMY; i++)
	{
		if ((enemy[i].getX() == space.getX() || enemy[i].getX() == space.getX() - 1 || enemy[i].getX() == space.getX() + 1) && enemy[i].getY() == space.getY() && enemy[i].state)
		{
			FlatImpact = true;
			return true;
		}
		if (numSkin == 2)
			if ((enemy[i].getX() == space.getX() - 2 || enemy[i].getX() == space.getX() + 2) && enemy[i].getY() == space.getY() - 1 && enemy[i].state)
			{
				FlatImpact = true;
				return true;
			}
	}

	FlatImpact = false;
	return false;

}
void PauseGame(HANDLE t) {
	Pause(t);
	SetColor(9);
	GotoXY(40, 12);
	cout << "                                        _ ";
	GotoXY(40, 13);
	cout << " ____   __ _   _    _   ___   ___    __| |";
	GotoXY(40, 14);
	cout << "/  _`\\ / _` | | |  | | / __| / _ \\  / _  | ";
	GotoXY(40, 15);
	cout << "| |_)| |(_| | | |__| | \\___  | __/ | (_| |  ";
	GotoXY(40, 16);
	cout << "| ___/ \\__,_| \\______/ |___/ \\___|  \\____| ";
	GotoXY(40, 17);
	cout << "|_|";

}
void Pause(HANDLE t) {
	SuspendThread(t);
}
void PlayGame()
{
	char temp;
	if (!FlatPAgain)
		StartGame();
	else {
		if (Round == 1) {
			SetCoordEnemy_R1(enemy);
		}
		else {
			SetCoordEnemy_R2(enemy);
		}
		space.state = true;
		space.setCoord(COORD_SPACE_X, COORD_SPACE_Y);
		for (int i = 0; i < NUMs_ENEMY; i++)
			enemy[i].state = true;
		nums_bullet = 0;
		FlatImpact = false;
		TextColor(11);
		SoundGame();
		FlatPAgain = false;	
	}
	if (FlatContinue)
	{
		FlatContinue = false;
		Continue();
	}
	system("cls");
	LoadGame();
	EndSoundGame();
	SoundGame();
	if (Round == 1)
	{
		system("cls");
		for (int i = 0; i < 8; i++)
		{
			DrawFrame();
			SetColor(9);
			GotoXY(WIDTH_CONSOLE / 2 - 8, HEIGH_CONSOLE - 2);
			cout << "LET'S PLAYYYYYYY !!";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 6);
			cout << "                                _        ____";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 5);
			cout << "                               | |      / ,. | ";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 4);
			cout << " _ __  ____  _    _  __   _  __| |     /_/ | |";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 3);
			cout << "| '__|/ __ \\| |  | ||  \\ | |/ _` |         | |";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 2);
			cout << "| |   |(__)|| |__| || |\\\\| ||(_| |       __| |_";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 1);
			cout << "|_|   \\____/\\______/|_| \\__|\\__,_|      |______|";
			Sleep(400);
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 6);
			cout << "                                                          ";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 5);
			cout << "                                                          ";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 4);
			cout << "                                                          ";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 3);
			cout << "                                                          ";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 2);
			cout << "                                                          ";
			GotoXY(WIDTH_CONSOLE / 2 - 20, HEIGH_CONSOLE / 2 - 1);
			cout << "                                                          ";
			Sleep(219);
		}
		GotoXY(WIDTH_CONSOLE / 2 - 8, HEIGH_CONSOLE - 2);
		cout << "                    ";
	}
	else
	{
		GraphicNextRound();
	}
	thread t1(SubThread);

	bool flat_pause = false;
	while (true)
	{

		temp = toupper(_getch());
		if (space.state)
		{
			if (flat_pause && temp != 'P')
			{
				GotoXY(40, 12);
				cout << "                                          ";
				GotoXY(40, 13);
				cout << "                                          ";
				GotoXY(40, 14);
				cout << "                                               ";
				GotoXY(40, 15);
				cout << "                                               ";
				GotoXY(40, 16);
				cout << "                                               ";
				GotoXY(40, 17);
				cout << "            ";
				ResumeThread(t1.native_handle());
				flat_pause = false;
			}
			else if (temp == 'I' && Round == 2)		// skip round 2
			{
				Pause(t1.native_handle());
				HP = 0;
				EndSoundGame();
				SoundBossDie();
				GraphicBossDie();
				MenuWin();
			}
			else if (temp == 27) {
				Pause(t1.native_handle());
				EndSoundGame();
				ByeBye();
			}
			else if (temp == 'P') {
				flat_pause = true;
				PauseGame(t1.native_handle());
			}
			else if (temp == 'K')		// open shop
			{
				Pause(t1.native_handle());
				MenuShop();
				ResumeThread((HANDLE)t1.native_handle());
			}
			else if (temp == 53)		// press 5 to shot
			{
				Shot(space.getX(), space.getY());
			}
			else if (temp == 32)		//CheckRound1() true - skip round 1
			{
				for (int i = 0; i < NUMs_ENEMY; i++)
					enemy[i].state = false;
				HP = 100;
			}
			else if (temp == 'L')			//save game
			{
				Pause(t1.native_handle());
				SaveGame();
				ResumeThread((HANDLE)t1.native_handle());
			}
			else if (FlatImpact)
			{
				MenuDie();
				FlatImpact = false;
			}
			else {
				ResumeThread((HANDLE)t1.native_handle());
				if (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S') {
					MOVING = temp;
				}
			}
		}
	}
}

void SubThread()
{
	while (true) {
		if (space.state) // if passer alive
		{
			switch (MOVING) // check moving var
			{
			case 'A':
				space.Left();
				break;
			case 'D':
				space.Right();
				break;
			case 'W':
				space.Up();
				break;
			case 'S':
				space.Down();
				break;
			}
			MOVING = ' ';// temporary dont allow move, wait to receive keyboard in main function
			if (checkRound1())
			{
				Round++;
				SetCoordEnemy_R2(enemy);
				GraphicNextRound();
			}
			DrawFrame();

			EraseStar();
			MoveStar();
			DrawStar();

			EraseEnemy();
			MoveEnemy();
			DrawEnemy();

			MoveBullets();
			DrawBullet();
			Announce();
			space.Draww();
			if (isImpact() || checkDie())
			{
				SetColor(10);
				GotoXY(22, 11);
				cout << " ______                                    __________         ";
				GotoXY(22, 12);
				cout << "/  ____\\                                  / ________ \\";
				GotoXY(22, 13);
				cout << "| /  ___   __ _    __ _ __    ____       / /        \\ \\ _     _   ____    _ __";
				GotoXY(22, 14);
				cout << "| | |__ \\ / _` |  / _` `_ \\  / __ \\      | |        | | \\ \\  / / / __ \\  | V _|";
				GotoXY(22, 15);
				cout << "| \\___/ / |(_| | | / | / | | | ___/      \\ \\________/ /  \\ \\/ /  | ___/  |  / ";
				GotoXY(22, 16);
				cout << "\\______/  \\__,_| |_| |_| |_| \\_____|      \\__________/    \\__/   \\_____| |_|";
				EndSoundGame();
				if (isImpact()) {
					GotoXY(53, 18);
					SetColor(9);
					cout << "You impact enemy";
					GraphicImpact();
					SoundExplosion();
					Sleep(750);
				}
				else {
					GotoXY(50, 18);
					SetColor(9);
					cout << "You run out of ammo";
				}
				EndSoundGame();
				SoundGameOver();
				FlatImpact = true;
				GotoXY(WIDTH_CONSOLE / 2 - 18, HEIGH_CONSOLE - 5);
				cout << "       Press any key to continue... ";
				while (chon <= 3);
			}
			if (HP <= 0)		// skip round 2
			{
				HP = 0;
				Sleep(200);
				EndSoundGame();
				SoundBossDie();
				GraphicBossDie();
				MenuWin();
			}
			Sleep(SPEED);
		}
	}
}

bool checkRound1()
{
	for (int i = 0; i < NUMs_ENEMY; i++)
		if (enemy[i].state)
			return false;
	return true;
}
bool CheckName(string name)
{
	fstream fs;
	fs.open(FILENAME, ios::in);
	if (!fs)
	{
		cout << "cant open file";
	}
	else
	{
		while (!fs.eof())
		{
			string s;
			getline(fs, s);
			vector <string> data = parse(s, " ", true);
			if (data[0] == name) return false;
		}
	}
	return true;
}
int TotalScore()
{
	return coin * 3 + Score + (BULLETS - nums_bullet);
}
void SaveGame()
{
	fstream fs;
	fs.open(FILENAME, ios::app);
	string name;
	time_t info = time(NULL);
	tm* now = localtime(&info);
	int s = now->tm_sec, m = now->tm_min;

	if (!fs)
		cout << "cant open file";
	else
	{
		do
		{
			GotoXY(WIDTH_CONSOLE / 2 - 25, HEIGH_CONSOLE - 2);
			cout << "                                                        ";
			GotoXY(WIDTH_CONSOLE / 2 - 16, HEIGH_CONSOLE - 3);
			cout << "Enter name (length <=20):                               ";
			GotoXY(WIDTH_CONSOLE / 2 - 16, HEIGH_CONSOLE - 3);
			cout << "Enter name (length <=20): ";
			cin >> name;
			if (!CheckName(name))
			{
				GotoXY(WIDTH_CONSOLE / 2 - 25, HEIGH_CONSOLE - 2);
				cout << "This name had saved before, please enter another name.";
				Sleep(1000);
			}
		} while (!CheckName(name) || name.length() > 20);
		GotoXY(WIDTH_CONSOLE / 2 - 3, HEIGH_CONSOLE - 2);
		cout << "Saved";
		Sleep(750);
		GotoXY(WIDTH_CONSOLE / 2 - 16, HEIGH_CONSOLE - 3);
		cout << "                                                        ";
		GotoXY(WIDTH_CONSOLE / 2 - 3, HEIGH_CONSOLE - 2);
		cout << "        ";
		Sleep(400);
		//name score life round coin nums_bullet hp Coord_Space state numSkin Sec Min Coord_Enemy state
		fs << name << " " << Score << " " << Life << " " << Round << " " << coin << " " << nums_bullet << " " << HP << " " << space.getX() << " " << space.getY() << " ";
		if (space.state)
			fs << "t ";
		else fs << "f ";
		fs << numSkin << " " << s - Sec << " " << m - Min << " ";
		for (int i = 0; i < NUMs_ENEMY; i++)
		{
			fs << enemy[i].getX() << " " << enemy[i].getY() << " ";
			if (enemy[i].state)
				fs << "t ";
			else
				fs << "f ";
		}
		fs << SkillShot << endl;
		fs.close();
	}
}

void Continue()
{
	fstream f;
	int count = 0;
	vector <string> data;
	time_t info = time(NULL);
	tm* now = localtime(&info);
	f.open(FILENAME, ios::in);
	system("cls");
	EndSoundGame();
	while (!f.eof())
	{
		string s;
		getline(f, s);

		count++;

		if (s.length() <= 3)
		{
			if (count == 1)
			{
				SetColor(14);
				GotoXY(WIDTH_CONSOLE / 2 - 10, HEIGH_CONSOLE / 2 - 3);
				cout << "NO DATA TO CONTINUE";
				GotoXY(WIDTH_CONSOLE / 2 - 10, HEIGH_CONSOLE / 2 - 2);
				cout << "-------------------";
				GotoXY(WIDTH_CONSOLE / 2 - 10, HEIGH_CONSOLE / 2);
				cout << "..ENTER NEW GAME.." << endl;
				SetColor(4);
				GotoXY(WIDTH_CONSOLE / 2 - 14, HEIGH_CONSOLE / 2 + 2);
				system("pause");
				break;
			}
			else if (count != 1)
			{

				Score = atoi(data[1].c_str());
				Life = atoi(data[2].c_str());
				Round = atoi(data[3].c_str());
				coin = atoi(data[4].c_str());
				nums_bullet = atoi(data[5].c_str());
				HP = atoi(data[6].c_str());
				SkillShot = atoi(data[data.size() - 1].c_str());
				space.setCoord(atoi(data[7].c_str()), atoi(data[8].c_str()));
				if (data[9] == "t")
					space.state = true;
				else
					space.state = false;
				numSkin = atoi(data[10].c_str());
				Sec = atoi(data[11].c_str());
				Sec = now->tm_sec - Sec + 1;
				Min = atoi(data[12].c_str());
				Min = now->tm_min - Min;
				for (int i = 0; i < NUMs_ENEMY; i++)
				{
					enemy[i].setCoord(atoi(data[3 * i + 13].c_str()), atoi(data[3 * i + 14].c_str()));
					if (data[3 * i + 15] == "t")
						enemy[i].state = true;
					else
						enemy[i].state = false;
				}
			}
		}
		data = parse(s, " ", true);
	}
	f.close();
}