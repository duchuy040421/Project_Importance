#include <stdio.h>
#include "Function.h"
#include <time.h>
#include <stdlib.h>
#include<iostream>
#include <Windows.h>
using namespace std;

#define SUITS 4
#define RANKS 13
#define FACES 13

const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

void shuffleCards(int deck[][RANKS])	//processing
{
	int num;
	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
		{
			do
			{
				num = rand() % 52 + 1;
			} while (SameNum(deck, num));
			deck[i][j] = num;
		}
}
void printCardsShuffling(int deck[SUITS][RANKS], const char* suits[], const char* faces[])	//done
{
	int stt = 1;
	do
	{
		for (int i = 0; i < SUITS; i++)
			for (int j = 0; j < RANKS; j++)
				if (deck[i][j] == stt)
				{
					printf("%2d. (%s,%s)\n", stt, suits[i], faces[j]);
					stt++;
					break;
				}
	} while (stt <= 52);
}
bool SameNum(int deck[SUITS][RANKS], int num)
{
	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
			if (deck[i][j] == num) return true;
	return false;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int** dealingForHand(int deck[SUITS][FACES])
{
	int** hand = new int* [5];

	for (int i = 0; i < 5; ++i)
		hand[i] = new int[2];

	int r = 0;
	int card, row, column;
	cout << "The hand is:\n";

	for (card = 1; card < 6; ++card)
		for (row = 0; row < SUITS; ++row)
			for (column = 0; column < FACES; ++column)
				if (deck[row][column] == card)
				{
					hand[r][0] = row;
					hand[r][1] = column;
					++r;
				}//end if

	return hand;
}
void printHand(int** hand, const char* suits[], const char* faces[])
{
	for (int r = 0; r < 5; ++r)
		cout << "(" << suits[hand[r][0]] << "," << faces[hand[r][1]] << ")" << "\t";
}
int isFourOfAKind(int** hand)
{
	//counter that records how many cards of each rank are in the hand
	int counter[FACES] = { 0 };

	for (int r = 0; r < 5; ++r)
		++counter[hand[r][1]];

	for (int k = 0; k < FACES; ++k)
		if (counter[k] == 4)
			return true;

	return false;
}
int isFullHouse(int** hand)
{
	int counter[FACES] = { 0 };
	int pair = 0, three = 0;

	for (int r = 0; r < 5; ++r)
		++counter[hand[r][1]];

	for (int k = 0; k < FACES; ++k)
	{
		if (counter[k] == 2)
			pair = 1;
		if (counter[k] == 3)
			three = 1;
	}

	if (pair == 1 && three == 1)
		return true;

	return false;
}
int isFlush(int** hand)
{
	//counter that records how many cards of each suit are in a hand
	int count[SUITS] = { 0 };

	for (int r = 0; r < 5; ++r)
		++count[hand[r][0]];
	for (int k = 0; k < SUITS; ++k)
		if (count[k] == 5)
			return true;
	return false;
}
int isThreeOfAKind(int** hand)
{
	//counter that records how many cards of each rank are in the hand
	int counter[FACES] = { 0 };

	for (int r = 0; r < 5; ++r)
		++counter[hand[r][1]];

	for (int k = 0; k < FACES; ++k)
		if (counter[k] == 3)
			return true;

	return false;

}
int isTwoPairs(int** hand)
{
	int counter[FACES] = { 0 };
	int NumPair = 0;
	for (int r = 0; r < 5; ++r)
		++counter[hand[r][1]];

	for (int k = 0; k < FACES; ++k)
		if (counter[k] == 2)
			NumPair++;
	if (NumPair == 2) return true;
	return false;

}
int isPair(int** hand)
{
	int counter[FACES] = { 0 };
	int NumPair = 0, NumAlone = 0;
	for (int r = 0; r < 5; ++r)
		++counter[hand[r][1]];

	for (int k = 0; k < FACES; ++k)
		if (counter[k] == 2)
			NumPair++;
		else
			NumAlone++;
	if ((NumPair == 1) && (NumAlone == 12)) return true;
	return false;
}
int isStraight(int** hand)
{
	int temp[5] = { 0 };
	for (int i = 0; i < 5; i++)
		temp[i] = hand[i][1];		//copy column 1 in the hand to array temp

	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
		{
			if (temp[i] > temp[j])
			{
				int t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}

	if (temp[4] == 12 && temp[0] == 0)			//in this case Ace is greatest in class 10
	{
		int t = temp[0];

		for (int i = 0; i < 4; i++)
		{
			temp[i] = temp[i + 1];
		}

		temp[4] = t;
	}

	int i = 4, count = 0;
	while (temp[i] - temp[i - 1] == 1 && i >= 1)
	{
		count++;
		--i;
	}

	if (count == 4)
		return true;

	return false;
}
int isStraightFlush(int** hand)
{
	if (isFlush(hand) && isStraight(hand)) return true;
	return false;
}
int getHighestCard(int** hand)	// True
{
	int a[] = { 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int b[] = { 4, 3, 2, 1 };
	int pi[5];
	int MaxRank = a[hand[0][1]];
	// find Max Rank
	for (int i = 1; i < 5; i++)
		if (a[hand[i][1]] > MaxRank) MaxRank = a[hand[i][1]];
	// counter Number of card has max rank
	int Counter = 0, o = 0;
	for (int i = 0; i < 5; i++)
		if (a[hand[i][1]] == MaxRank)
		{
			Counter++;
			pi[o] = i;
			o++;
		}
	if (Counter == 1)
		for (int i = 0; i < 5; i++)
			if (a[hand[i][1]] == MaxRank) return i;
	// Case deck has greater than 1 card has max rank
	int MaxSuits = b[hand[pi[0]][0]];
	for (int i = 1; i < o; i++)
		if (b[hand[pi[i]][0]] > MaxSuits) MaxSuits = b[hand[pi[i]][0]];
	for (int i = 0; i < 5; i++)
		if (b[hand[pi[i]][0]] == MaxSuits) return pi[i];
}

int** createHandTest(int a[]) // dont know Quote 1c
{

	return 0;
}
int*** dealingForHands(int deck[SUITS][FACES], int n)	// True
{
	int*** player = (int***)malloc(sizeof(int**) * n);
	for (int i = 0; i < n; ++i)
		player[i] = (int**)malloc(sizeof(int*) * 8);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 8; ++j)
			player[i][j] = (int*)malloc(sizeof(int) * 2);

	int r = 0;
	int card = 1, row, column;
	bool condition = true;
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		while (num < 5)
		{
			condition = true;
			for (row = 0; row < SUITS; ++row)
				if (!condition) break;
				else
					for (column = 0; column < FACES; ++column)
						if (deck[row][column] == card)
						{
							player[i][num][0] = row;
							player[i][num][1] = column;
							card += n;
							++num;
							condition = false;
							break;
						}
		}
		card = i + 2;
	}
	// printf card of player i_th
	/*for (int i = 0; i < n; i++)
	{
		printf("\nplayer [%d]: \n", i);
		for (int j = 0; j < 5; j++)
			printf(" (%d, %d)  \n", player[i][j][0], player[i][j][1]);
	}*/

	return player;
}
int** Copy_hands_into_onehand(int*** hands, int k)
{
	int** a = new int* [5];
	for (int i = 0; i < 5; i++)
		a[i] = new int[2];

	for (int i = 0; i < 5; i++)
	{
		a[i][0] = hands[k][i][0];
		a[i][1] = hands[k][i][1];
	}

	return a;
}
void print_dealingforhands(int*** hands, int n)
{
	for (int i = 0; i < n; i++)
	{
		int** temp = Copy_hands_into_onehand(hands, i);
		printf("\nplayer [%d]: \n", i + 1);
		printHand(temp, suits, ranks);
		cout << endl;
	}
}
int getStatusOfHand(int** hand)
{
	if (isStraightFlush(hand)) return 8;
	if (isFourOfAKind(hand)) return 7;
	if (isFullHouse(hand)) return 6;
	if (isFlush(hand)) return 5;
	if (isStraight(hand)) return 4;
	if (isThreeOfAKind(hand)) return 3;
	if (isTwoPairs(hand)) return 2;
	if (isPair(hand)) return 1;
	return 0;
	// the worst case is they dont fall any category
	// if players is 0 mark rank will base on THE HIGHEST CARD
}
void reset_hand(int** hand)
{
	for (int i = 0; i < 5; i++)
	{
		if (hand[i][1] == 13)	hand[i][1] = 0;
		if (hand[i][1] == 14)	hand[i][1] = 1;
	}
}
int prepare_2hand(int** play1, int** play2)
{
	reset_hand(play1);
	reset_hand(play2);

	int m = getHighestCard(play1);
	int k = getHighestCard(play2);

	for (int i = 0; i < 5; i++)
	{
		if (play1[i][1] == 0)	play1[i][1] = 13;
		if (play1[i][1] == 1)	play1[i][1] = 14;
		if (play2[i][1] == 0)	play2[i][1] = 13;
		if (play2[i][1] == 1)	play2[i][1] = 14;
	}

	if (play1[m][1] > play2[k][1])
		return 1;
	else
		if (play1[m][1] == play2[k][1])
		{
			if (play1[m][0] < play2[k][0])
				return 1;
			else
				return -1;
		}

	return -1;
}
void sort_same(int*** hands, int pos, int n, int** handget)
{
	for (int i = pos; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (prepare_2hand(hands[handget[i][0]], hands[handget[j][0]]) == -1)
			{
				swap(handget[i][1], handget[j][1]);
				swap(handget[i][0], handget[j][0]);
			}
		}
	}
}
int prepare_four_kind(int** play1, int** play2)
{
	reset_hand(play1);
	reset_hand(play2);

	int counter1[FACES] = { 0 }, pos1;
	int counter2[FACES] = { 0 }, pos2;

	for (int r = 0; r < 5; ++r)
	{
		++counter1[play1[r][1]];
		++counter2[play2[r][1]];
	}

	for (int k1 = 0; k1 < FACES; ++k1)
	{
		if (counter1[k1] == 4)
			pos1 = k1;
		if (counter2[k1] == 4)
			pos2 = k1;
	}

	if (pos1 == 0)	pos1 = 13;
	if (pos1 == 1)	pos1 = 14;
	if (pos2 == 0)	pos1 = 13;
	if (pos2 == 1)	pos1 = 14;

	if (pos1 > pos2)
		return 1;
	return -1;
}
int prepare_fullhouse(int** play1, int** play2)
{
	reset_hand(play1);
	reset_hand(play2);

	int counter1[FACES] = { 0 }, pos1;
	int counter2[FACES] = { 0 }, pos2;

	for (int r = 0; r < 5; ++r)
	{
		++counter1[play1[r][1]];
		++counter2[play2[r][1]];
	}

	for (int k1 = 0; k1 < FACES; ++k1)
	{
		if (counter1[k1] == 3)
			pos1 = k1;
		if (counter2[k1] == 3)
			pos2 = k1;
	}

	if (pos1 == 0)	pos1 = 13;
	if (pos1 == 1)	pos1 = 14;
	if (pos2 == 0)	pos1 = 13;
	if (pos2 == 1)	pos1 = 14;

	if (pos1 > pos2)
		return 1;
	return -1;
}
int prepare_two_pair(int** play1, int** play2)
{
	reset_hand(play1);
	reset_hand(play2);

	int counter1[FACES] = { 0 }, pos1, max1 = -1, temp1, temp3;
	int counter2[FACES] = { 0 }, pos2, max2 = -1, temp2, temp4;

	for (int r = 0; r < 5; ++r)
	{
		++counter1[play1[r][1]];
		++counter2[play2[r][1]];
	}

	for (int k1 = 0; k1 < FACES; ++k1)
	{
		if (counter1[k1] == 2)
			pos1 = k1;
		if (counter2[k1] == 2)
			pos2 = k1;
	}


	for (int k1 = 0; k1 < FACES; ++k1)
	{
		if (counter1[k1] == 2 && k1 < pos1)
			temp1 = k1;
		if (counter2[k1] == 2 && k1 < pos2)
			temp2 = k1;
	}


	for (int i = 0; i < 5, play1[i][1] != pos1, play1[i][1] != temp1; i++)
	{
		max1 = play1[i][1];
		temp3 = play1[i][0];
	}

	for (int i = 0; i < 5, play2[i][1] != pos2, play2[i][1] != temp2; i++)
	{
		max2 = play2[i][1];
		temp4 = play2[i][0];
	}

	if (pos1 == 0)	pos1 = 13;
	if (pos1 == 1)	pos1 = 14;
	if (pos2 == 0)	pos2 = 13;
	if (pos2 == 1)	pos2 = 14;

	if (pos1 > pos2)
		return 1;
	else
		if (pos1 == pos2)
		{
			if (temp1 > temp2)
				return 1;
			else
				if (temp1 == temp2)
				{
					if (max1 > max2)
						return 1;
					else
						if (max1 == max2)
							if (temp3 < temp4)
								return 1;
				}

		}
	return -1;
}
int prepare_pair(int** play1, int** play2)
{
	reset_hand(play1);
	reset_hand(play2);

	int counter1[FACES] = { 0 }, pos1, max1 = -1, temp1;
	int counter2[FACES] = { 0 }, pos2, max2 = -1, temp2;

	for (int r = 0; r < 5; ++r)
	{
		++counter1[play1[r][1]];
		++counter2[play2[r][1]];
	}

	for (int k1 = 0; k1 < FACES; ++k1)
	{
		if (counter1[k1] == 2)
			pos1 = k1;
		if (counter2[k1] == 2)
			pos2 = k1;
	}


	for (int i = 0; i < 5, play1[i][1] != pos1; i++)
	{
		if (play1[i][1] > max1)
		{
			max1 = play1[i][1];
			temp1 = play1[i][0];
		}
	}

	for (int i = 0; i < 5, play2[i][1] != pos2; i++)
	{
		if (play2[i][1] > max2)
		{
			max2 = play2[i][1];
			temp2 = play2[i][0];
		}
	}

	if (pos1 == 0)	pos1 = 13;
	if (pos1 == 1)	pos1 = 14;
	if (pos2 == 0)	pos1 = 13;
	if (pos2 == 1)	pos1 = 14;

	if (max1 == 0)	max1 = 13;
	if (max1 == 1)	max1 = 14;
	if (max2 == 0)	max2 = 13;
	if (max2 == 1)	max2 = 14;

	if (pos1 > pos2)
		return 1;
	else
	{
		if (pos1 == pos2)
		{
			if (max1 > max2)
				return 1;
			else
				if (max1 == max2)
					if (temp1 < temp2)
						return 1;
		}
	}

	return -1;
}
int* rankingHands(int*** hands, int n)
{
	int* a = new int[n];
	int** b = new int* [n];

	for (int i = 0; i < n; i++)
		b[i] = new int[2];

	for (int i = 0; i < n; i++)
	{
		int** temp = Copy_hands_into_onehand(hands, i);
		b[i][1] = getStatusOfHand(temp);
		b[i][0] = i;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (b[i][1] < b[j][1])
			{
				swap(b[i][1], b[j][1]);
				swap(b[i][0], b[j][0]);
			}

			if (b[i][1] == b[j][1])
			{
				if (b[i][1] == 8 && prepare_2hand(hands[b[i][0]], hands[b[j][0]]) == -1)
				{
					swap(b[i][1], b[j][1]);
					swap(b[i][0], b[j][0]);
				}
				if (b[i][1] == 7 && prepare_four_kind(hands[b[i][0]], hands[b[j][0]]) == -1)
				{
					swap(b[i][1], b[j][1]);
					swap(b[i][0], b[j][0]);
				}
				if ((b[i][1] == 6 || b[i][1] == 3) && prepare_fullhouse(hands[b[i][0]], hands[b[j][0]]) == -1)
				{
					swap(b[i][1], b[j][1]);
					swap(b[i][0], b[j][0]);
				}

				if (b[i][1] == 5 && prepare_2hand(hands[b[i][0]], hands[b[j][0]]) == -1)
				{
					swap(b[i][1], b[j][1]);
					swap(b[i][0], b[j][0]);
				}
				if (b[i][1] == 4 && prepare_2hand(hands[b[i][0]], hands[b[j][0]]) == -1)
				{
					swap(b[i][1], b[j][1]);
					swap(b[i][0], b[j][0]);
				}
				if (b[i][1] == 2 && prepare_two_pair(hands[b[i][0]], hands[b[j][0]]) == -1)
				{
					swap(b[i][1], b[j][1]);
					swap(b[i][0], b[j][0]);
				}
				if (b[i][1] == 1 && prepare_pair(hands[b[i][0]], hands[b[j][0]]) == -1)
				{
					swap(b[i][1], b[j][1]);
					swap(b[i][0], b[j][0]);
				}
				if (b[i][1] == 0 && prepare_2hand(hands[b[i][0]], hands[b[j][0]]) == -1)
				{
					swap(b[i][1], b[j][1]);
					swap(b[i][0], b[j][0]);
				}
			}
		}
	}

	/*for (int i = 1; i <= n; i++)
	{
		*(a + i) = b[i - 1][0] + 1;
	}

	*a = n;*/
	for (int i = 0; i < n; i++)
	{
		a[b[i][0]] = i + 1;
	}

	return a;
}
int** sum_of_two_handget(int** a, int** b, int n)
{
	int** c = new int* [5];
	for (int i = 0; i < 5; i++)
		c[i] = new int[2];

	for (int i = 0; i < n; i++)
	{
		c[i][1] = a[i][1] + b[i][1];
		c[i][0] = i;
	}

	return c;
}
void delete_matrix(int** a)
{
	for (int i = 0; i < 5; i++)
		delete[]a[i];
	delete[]a;
}
void reset_deck(int deck[][RANKS])
{
	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
		{
			deck[i][j] = -1;
		}
}
int* evaluateHands(int* ranked_hands, int s)
{
	int n = *ranked_hands;
	int* ranked_last = new int[n];
	int deck[SUITS][FACES];

	int** c = new int* [5];
	for (int i = 0; i < 5; i++)
		c[i] = new int[2];

	int** sum = new int* [5];
	for (int i = 0; i < 5; i++)
		sum[i] = new int[2];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++)
		{
			sum[i][0] = i;
			sum[i][1] = 0;
		}

	for (int k = 1; k <= s; k++)
	{
		shuffleCards(deck);
		int*** temp = dealingForHands(deck, n);
		for (int j = 0; j < n; j++)
		{
			int** temp1 = Copy_hands_into_onehand(temp, j);
			c[j][1] = getStatusOfHand(temp1);
		}

		sum = sum_of_two_handget(sum, c, n);

		print_dealingforhands(temp, n);
		cout << "---------------------------------------------------------------------------" << endl;

		reset_deck(deck);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sum[i][1] < sum[j][1])
			{
				swap(sum[i][1], sum[j][1]);
				swap(sum[i][0], sum[j][0]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		*(ranked_last + i) = sum[i][0] + 1;
	}

	cout << "Congratulate the winner is player " << *(ranked_last) << endl;
	return ranked_last;
}
void test()
{
	int deck[SUITS][FACES];
	for (int k = 1; k <= 2; k++)
	{
		shuffleCards(deck);
		cout << deck[1][1] << endl;
		reset_deck(deck);
	}
}

// 3* ----------------------------------------------------
int** Draw(int deck[SUITS][RANKS], int num, int n) // TRUE
{
	int** draw;
	draw = (int**)malloc(sizeof(int*) * num);
	for (int i = 0; i < num; i++)
		draw[i] = (int*)malloc(sizeof(int) * 2);
	int i = 0; // The first number of recent deck 
	bool condition = true;
	for (int card = n * 5 + 1; card < n * 5 + 1 + num; card++)
	{
		condition = true;
		for (int row = 0; row < SUITS; ++row)
			if (condition)
				for (int column = 0; column < FACES; ++column)
					if (deck[row][column] == card)
					{
						draw[i][0] = row;
						draw[i][1] = column;
						++i;
						condition = false;
						break;
					}
	}
	return draw;
}
void Menu3()
{
	
	printf("\n(1) Done.");
	printf("\n(2) Random replacement.");
	printf("\n(3) Replace to get better situation. ");
}
void GameForDealer(int deck[SUITS][RANKS], int n)	// 3*
{
	// Dealer is the last player (n)
	int  num, decide = 0;
	int*** player;
	int** da;
	int* a;
	a = (int*)malloc(sizeof(int) * (n));

	player = dealingForHands(deck, n);

	for (int i = 0; i < n - 1; i++)
	{
		printf("\n\nPlayer %d:", i);
		printHand(player[i], suits, ranks);
	}
	printf("\n\nDealer :");
	printHand(player[n - 1], suits, ranks);
	do
	{
		printf("\nEnter numbers of card does Dealer want draw (0-3): ");	// draw number card
		scanf_s("%d", &num);
	} while (num < 0 || num >3);
	int** draw = Draw(deck, num, n);
	printf("\nThe %d draw card: ", num);
	for (int i = 0; i < num; i++)
		printf("(%s, %s) ", suits[draw[i][0]], ranks[draw[i][1]]);
	for (int i = 0; i < num; i++)
	{
		player[n - 1][i + 5][0] = draw[i][0];
		player[n - 1][i + 5][1] = draw[i][1];
	}
	Menu3();
	do
	{
			do
			{
				printf("\nDealer decide (1-3): ");
				scanf_s("%d", &decide);
			} while (decide < 1 || decide>3);
		switch (decide)
		{
		case (2): // random replace		
			RandomReplace(player[n - 1], num);
			break;
		case (3):	// get better situation
			
			BetterSituation(player[n - 1], num);		
			break;
		}
	} while (decide != 1 );
	a = rankingHands(player, n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

}
void RandomReplace(int** dealer, int num)	//true
{
	int number;
	int a[5];
	for (int i = 0; i < 5; i++)	// lay random
		{
			do
			{
				number = rand() % (5 + num);
			} while (!check(a, number));
			a[i] = number; 
		}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		swap(dealer[i][0], dealer[a[i]][0]);
		swap(dealer[i][1], dealer[a[i]][1]);
	}
	printf("\nAfter Random Replace, Card of dealer :\n");
	for (int i = 0; i < 5; i++)
		printf("(%s, %s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
}
void BetterSituation(int** dealer, int num)
{
	int temp[8][2], a[8], b[8], cc[8], d[8];	// a,b,o cho rank _ cc,d,e cho suits
	int rank[] = { 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };	//ranks
	int suit[] = { 4, 3, 2, 1 };									//suits
	int o = 0, e = 0, numpair2 = 0, numpair3 = 0, numpair4 = 0, numpair5 = 0, suit5 = 0;
	for (int i = 0; i < 5 + num; i++)
	{
		temp[i][0] = dealer[i][0];
		temp[i][1] = dealer[i][1];
	}
	// dem xem bao nhieu cung rank:
	for (int i = 0; i < 5 + num; i++)
	{
		int dem = 0;
		if (dealer[i][1] != -1)
		{
			for (int j = i + 1; j < 5 + num; j++)
				if (dealer[i][1] == dealer[j][1])
				{
					dem++;
					dealer[j][1] = -1;
				}
			a[o] = dem + 1;
			b[o] = dealer[i][1];
			o++;
		}
	}
	for (int i = 0; i < 5 + num; i++)
	{
		dealer[i][0] = temp[i][0];
		dealer[i][1] = temp[i][1];
	}
	// dem xem bao nhieu cung suit:
	for (int i = 0; i < 5 + num; i++)
	{
		int dem = 0;
		if (dealer[i][0] != -1)
		{
			for (int j = i + 1; j < 5 + num; j++)
				if (dealer[i][0] == dealer[j][0])
				{
					dem++;
					dealer[j][0] = -1;
				}
			cc[e] = dem + 1;
			d[e] = dealer[i][0];
			e++;
		}
	}
	for (int i = 0; i < e; i++)
	{
		if (cc[i] == 5) suit5++;
	}
	for (int i = 0; i < 5 + num; i++)
	{
		dealer[i][0] = temp[i][0];
		dealer[i][1] = temp[i][1];
	}
	for (int i = 0; i < o; i++)
	{
		if (a[i] == 2) numpair2++;
		else if (a[i] == 3) numpair3++;
		else if (a[i] == 4) numpair4++;
		else if (a[i] == 5) numpair5++;
	}
	int mark = getStatusOfHand(dealer);
	switch (mark)
	{
	case (0):
		// 1 pair2 (day len 1d)
		if (numpair2 != 0)
		{
			int j, c = 0;
			for (j = 0; j < o; j++)
				if (a[j] == 2)
					break;

			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 2) break;
				if (dealer[i][1] == b[j])
				{

					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 5) break;
				if (dealer[i][1] != b[j])
				{
					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			printf("Better Sittuation: ");
			for (int i = 0; i < 5; i++)
				printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
		}
		else
			// 1 pair3 (day len 3d)
			if (numpair3 != 0)
			{
				int j, c = 0;
				for (j = 0; j < o; j++)
					if (a[j] == 3)	break;
				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 3) break;
					if (dealer[i][1] == b[j])
					{

						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 5) break;
					if (dealer[i][1] != b[j])
					{
						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				printf("Better Sittuation: ");
				for (int i = 0; i < 5; i++)
					printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
			}
			else
				// flush (day len 5)
				if (suit5 != 0)
				{
					int j, c = 0;
					for (j = 0; j < e; j++)
						if (cc[j] == 5)
							break;
					for (int i = 0; i < 5 + num; i++)
					{
						if (c == 5) break;
						if (dealer[i][0] == d[j])
						{
							swap(dealer[i][1], dealer[c][1]);
							swap(dealer[i][0], dealer[c][0]);
							c++;
						}
					}
					printf("Better Sittuation: ");
					for (int i = 0; i < 5; i++)
						printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
				}
				else
					//1 pair4 (day len 7d)
					if (numpair4 != 0)
					{
						int j, c = 0;
						for (j = 0; j < o; j++)
							if (a[j] == 4)
								break;
						for (int i = 0; i < 5 + num; i++)
						{
							if (c == 4) break;
							if (dealer[i][1] == b[j])
							{

								swap(dealer[i][1], dealer[c][1]);
								swap(dealer[i][0], dealer[c][0]);
								c++;
							}
						}
						for (int i = 0; i < 5 + num; i++)
						{
							if (c == 5) break;
							if (dealer[i][1] != b[j])
							{
								swap(dealer[i][1], dealer[c][1]);
								swap(dealer[i][0], dealer[c][0]);
								c++;
							}
						}
						printf("Better Sittuation: ");
						for (int i = 0; i < 5; i++)
							printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
					}
		// swap max and min (van giu 0d)
					else
					{

						int pi[5];
						int MaxRank = rank[dealer[5][1]];
						int MinRank = rank[dealer[0][1]];
						// find Max Rank
						for (int i = 5; i < 5 + num; i++)
							if (rank[dealer[i][1]] > MaxRank) MaxRank = rank[dealer[i][1]];
						for (int i = 1; i < 5; i++)
							if (rank[dealer[i][1]] < MinRank) MinRank = rank[dealer[i][1]];
						for (int i = 0; i < 5; i++)
							for (int j = 5; j < 5 + num; j++)
								if (rank[dealer[i][1]] == MinRank && rank[dealer[j][1]] == MaxRank && MaxRank > MinRank)
								{
									swap(dealer[i][1], dealer[j][1]);
									swap(dealer[i][0], dealer[j][0]);
								}
						printf("Better Sittuation: ");
						for (int i = 0; i < 5; i++)
							printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
					}

		break;
	case (1):
		// 2 pair2 ( day len 2)
		if (numpair2 >= 2)
		{
			int j, k, c = 0;
			for (j = 0; j < o; j++)
				if (a[j] == 2)
					break;

			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 2) break;
				if (dealer[i][1] == b[j])
				{

					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			for (k = 0; k < o; k++)
				if (a[k] == 2 && k != j)
					break;
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 4) break;
				if (dealer[i][1] == b[k])
				{
					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 5) break;
				if (dealer[i][1] != b[k] && dealer[i][1] != b[j])
				{
					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			printf("Better Sittuation: ");
			for (int i = 0; i < 5; i++)
				printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
		}
		else
			// day len 3
			if (numpair3 != 0)
			{
				int j, c = 0;
				for (j = 0; j < o; j++)
					if (a[j] == 3)
						break;
				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 3) break;
					if (dealer[i][1] == b[j])
					{

						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 5) break;
					if (dealer[i][1] != b[j])
					{
						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				printf("Better Sittuation: ");
				for (int i = 0; i < 5; i++)
					printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
			}
			else
				// flush (day len 5)
				if (suit5 != 0)
				{
					int j, c = 0;
					for (j = 0; j < e; j++)
						if (cc[j] == 5)
							break;
					for (int i = 0; i < 5 + num; i++)
					{
						if (c == 5) break;
						if (dealer[i][0] == d[j])
						{
							swap(dealer[i][1], dealer[c][1]);
							swap(dealer[i][0], dealer[c][0]);
							c++;
						}
					}
					printf("Better Sittuation: ");
					for (int i = 0; i < 5; i++)
						printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
				}
				else
					// full house (day len 6d)
					if (numpair2 != 0 && numpair3 != 0)
					{
						int j, k, c = 0;
						for (j = 0; j < o; j++)
							if (a[j] == 2)
								break;

						for (int i = 0; i < 5 + num; i++)
						{
							if (c == 2) break;
							if (dealer[i][1] == b[j])
							{

								swap(dealer[i][1], dealer[c][1]);
								swap(dealer[i][0], dealer[c][0]);
								c++;
							}
						}
						for (k = 0; k < o; k++)
							if (a[k] == 3 && k != j)
								break;
						for (int i = 0; i < 5 + num; i++)
						{
							if (c == 5) break;
							if (dealer[i][1] == b[k])
							{
								swap(dealer[i][1], dealer[c][1]);
								swap(dealer[i][0], dealer[c][0]);
								c++;
							}
						}
						printf("Better Sittuation: ");
						for (int i = 0; i < 5; i++)
							printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
					}
					else
						//1 pair4 (day len 7d)
						if (numpair4 != 0)
						{
							int j, c = 0;
							for (j = 0; j < o; j++)
								if (a[j] == 4)
									break;
							for (int i = 0; i < 5 + num; i++)
							{
								if (c == 4) break;
								if (dealer[i][1] == b[j])
								{

									swap(dealer[i][1], dealer[c][1]);
									swap(dealer[i][0], dealer[c][0]);
									c++;
								}
							}
							for (int i = 0; i < 5 + num; i++)
							{
								if (c == 5) break;
								if (dealer[i][1] != b[j])
								{
									swap(dealer[i][1], dealer[c][1]);
									swap(dealer[i][0], dealer[c][0]);
									c++;
								}
							}
							printf("Better Sittuation: ");
							for (int i = 0; i < 5; i++)
								printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
						}
						else
							printf("That is the best case.");
		break;
	case(2):
		// day len 3d
		if (numpair3 != 0)
		{
			int j, c = 0;
			for (j = 0; j < o; j++)
				if (a[j] == 3)
					break;
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 3) break;
				if (dealer[i][1] == b[j])
				{

					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 5) break;
				if (dealer[i][1] != b[j])
				{
					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			printf("Better Sittuation: ");
			for (int i = 0; i < 5; i++)
				printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
		}
		else
			// flush (day len 5)
			if (suit5 != 0)
			{
				int j, c = 0;
				for (j = 0; j < e; j++)
					if (cc[j] == 5)
						break;
				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 5) break;
					if (dealer[i][0] == d[j])
					{
						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				printf("Better Sittuation: ");
				for (int i = 0; i < 5; i++)
					printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
			}
			else
				// full house (day len 6d)
				if (numpair2 != 0 && numpair3 != 0)
				{
					int j, k, c = 0;
					for (j = 0; j < o; j++)
						if (a[j] == 2)
							break;

					for (int i = 0; i < 5 + num; i++)
					{
						if (c == 2) break;
						if (dealer[i][1] == b[j])
						{

							swap(dealer[i][1], dealer[c][1]);
							swap(dealer[i][0], dealer[c][0]);
							c++;
						}
					}
					for (k = 0; k < o; k++)
						if (a[k] == 3 && k != j)
							break;
					for (int i = 0; i < 5 + num; i++)
					{
						if (c == 5) break;
						if (dealer[i][1] == b[k])
						{
							swap(dealer[i][1], dealer[c][1]);
							swap(dealer[i][0], dealer[c][0]);
							c++;
						}
					}
					printf("Better Sittuation: ");
					for (int i = 0; i < 5; i++)
						printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
				}
				else
					// day len 7d
					if (numpair4 != 0)
					{
						int j, c = 0;
						for (j = 0; j < o; j++)
							if (a[j] == 4)
								break;
						for (int i = 0; i < 5 + num; i++)
						{
							if (c == 4) break;
							if (dealer[i][1] == b[j])
							{

								swap(dealer[i][1], dealer[c][1]);
								swap(dealer[i][0], dealer[c][0]);
								c++;
							}
						}
						for (int i = 0; i < 5 + num; i++)
						{
							if (c == 5) break;
							if (dealer[i][1] != b[j])
							{
								swap(dealer[i][1], dealer[c][1]);
								swap(dealer[i][0], dealer[c][0]);
								c++;
							}
						}
						printf("Better Sittuation: ");
						for (int i = 0; i < 5; i++)
							printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
					}
					else
						printf("That is the best case.");
		break;
		//---------------
	case (3):
		// flush (day len 5)
		if (suit5 != 0)
		{
			int j, c = 0;
			for (j = 0; j < e; j++)
				if (cc[j] == 5)
					break;
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 5) break;
				if (dealer[i][0] == d[j])
				{
					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			printf("Better Sittuation: ");
			for (int i = 0; i < 5; i++)
				printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
		}
		else
			// full house (day len 6d)
			if (numpair2 != 0 && numpair3 != 0)
			{
				int j, k, c = 0;
				for (j = 0; j < o; j++)
					if (a[j] == 2)
						break;

				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 2) break;
					if (dealer[i][1] == b[j])
					{

						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				for (k = 0; k < o; k++)
					if (a[k] == 3 && k != j)
						break;
				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 5) break;
					if (dealer[i][1] == b[k])
					{
						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				printf("Better Sittuation: ");
				for (int i = 0; i < 5; i++)
					printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
			}
			else
				// day len 7d
				if (numpair4 != 0)
				{
					int j, c = 0;
					for (j = 0; j < o; j++)
						if (a[j] == 4)
							break;
					for (int i = 0; i < 5 + num; i++)
					{
						if (c == 4) break;
						if (dealer[i][1] == b[j])
						{

							swap(dealer[i][1], dealer[c][1]);
							swap(dealer[i][0], dealer[c][0]);
							c++;
						}
					}
					for (int i = 0; i < 5 + num; i++)
					{
						if (c == 5) break;
						if (dealer[i][1] != b[j])
						{
							swap(dealer[i][1], dealer[c][1]);
							swap(dealer[i][0], dealer[c][0]);
							c++;
						}
					}
					printf("Better Sittuation: ");
					for (int i = 0; i < 5; i++)
						printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
				}
				else
					printf("That is the best case.");
		break;
	case (5):
		// full house (day len 6d)
		if (numpair2 != 0 && numpair3 != 0)
		{
			int j, k, c = 0;
			for (j = 0; j < o; j++)
				if (a[j] == 2)
					break;
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 2) break;
				if (dealer[i][1] == b[j])
				{

					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			for (k = 0; k < o; k++)
				if (a[k] == 3 && k != j)
					break;
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 5) break;
				if (dealer[i][1] == b[k])
				{
					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			printf("Better Sittuation: ");
			for (int i = 0; i < 5; i++)
				printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
		}
		else
			//1 pair4 (day len 7d)
			if (numpair4 != 0)
			{
				int j, c = 0;
				for (j = 0; j < o; j++)
					if (a[j] == 4)
						break;
				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 4) break;
					if (dealer[i][1] == b[j])
					{

						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				for (int i = 0; i < 5 + num; i++)
				{
					if (c == 5) break;
					if (dealer[i][1] != b[j])
					{
						swap(dealer[i][1], dealer[c][1]);
						swap(dealer[i][0], dealer[c][0]);
						c++;
					}
				}
				printf("Better Sittuation: ");
				for (int i = 0; i < 5; i++)
					printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
			}
			else
				printf("That is the best case.");
		break;
	case (6):
		//1 pair4 (day len 7d)
		if (numpair4 != 0)
		{
			int j, c = 0;
			for (j = 0; j < o; j++)
				if (a[j] == 4)
					break;
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 4) break;
				if (dealer[i][1] == b[j])
				{

					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			for (int i = 0; i < 5 + num; i++)
			{
				if (c == 5) break;
				if (dealer[i][1] != b[j])
				{
					swap(dealer[i][1], dealer[c][1]);
					swap(dealer[i][0], dealer[c][0]);
					c++;
				}
			}
			printf("Better Sittuation: ");
			for (int i = 0; i < 5; i++)
				printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
		}
		else
			printf("That is the best case.");
		break;
	}
}
bool check(int *b, int number) 	// check for RandomReplace function (de lam CHINH HOP)
{
	for (int i = 0; i < 5; i++)
		if (b[i] == number) return false;
	return true;
}


//---------------------------------------------------------


