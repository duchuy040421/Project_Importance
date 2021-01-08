#include "Function.h"


#define SUITS 4
#define RANKS 13

int main()
{
	srand(time(NULL));

	int deck[SUITS][RANKS], n;
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	shuffleCards(deck);
	int choose, chooseplay;
	TextColor(244);
	do
	{

		do
		{
			system("cls");
			MenuMain();
			gotoxy(48, 18);
			printf("Choose: ");
			scanf_s("%d", &choose);
		} while (choose > 4 || choose < 1);
		switch (choose)
		{
		case (1):
			do
			{
				do
				{
					system("cls");
					NewGame();
					gotoxy(48, 18);
					printf("Choose: ");
					scanf_s("%d", &chooseplay);
				} while (chooseplay > 7 || chooseplay < 1);
				PlayGame(chooseplay, deck);
			} while (chooseplay != 7);
			break;
		case (2):
			Rule();
			break;
		case (3):
			About();
			break;
		}
	} while (choose != 4);

	return 0;
}
