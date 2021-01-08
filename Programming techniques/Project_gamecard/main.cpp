#include "Function.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <time.h>

using namespace std;

#define SUITS 4
#define RANKS 13

int main()
{
		srand(time(NULL));

		int deck[SUITS][RANKS], n;
		const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

		shuffleCards(deck);
		int** hand = dealingForHand(deck);

		do
		{
			printf("Enter number of player (1-10): ");
			scanf_s("%d", &n);
		} while (n > 10 || n < 1);

		int*** player = dealingForHands(deck, n);
		//print_dealingforhands(player, n);

		//int* a = rankingHands(player, n);
	//	evaluateHands(a, 1);   //time is 2
	GameForDealer(deck, n);

	return 0;
}
