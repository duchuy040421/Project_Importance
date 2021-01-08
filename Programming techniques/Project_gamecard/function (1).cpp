#include "Function.h"

#define SUITS 4
#define RANKS 13
#define FACES 13

const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

void shuffleCards(int deck[][RANKS])
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
	int stt = 1,i,j;
	do
	{
		for (i = 0; i < SUITS; i++)
		{
			for (j = 0; j < RANKS; j++)
				if (deck[i][j] == stt)
				{
					gotoxy(28, stt+2);
					SetColor(4);
					printf("%2d.",stt);
					SetColor(3);
					printf(" (% s, % s)\n", suits[i], faces[j]);
					stt++;
					break;
				}
		}
	} while (stt <= 26);
	do
	{
	for (i = 0; i < SUITS; i++)
		{
			if (stt == 53) break;
			for (j = 0; j < RANKS; j++)
				if (deck[i][j] == stt)
				{
					gotoxy(60, stt - 24);
					SetColor(4);
					printf(" %2d. ",stt);
					SetColor(3);
					printf("(% s, % s)\n", suits[i], faces[j]);
					stt++;
					break;
				}
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
	SetColor(4);
	cout << "The hand is:\n";

	for (card = 1; card < 6; ++card)
		for (row = 0; row < SUITS; ++row)
			for (column = 0; column < FACES; ++column)
				if (deck[row][column] == card)
				{
					hand[r][0] = row;
					hand[r][1] = column;
					++r;
				}

	return hand;
}
void printHand(int** hand, const char* suits[], const char* faces[])
{
	SetColor(3);
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
int** createHandTest(int deck[SUITS][FACES], int a[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Card [" << i + 1 << "] : ";
		cin >> a[i];
	}

	int** hand = new int* [5];

	for (int i = 0; i < 5; ++i)
		hand[i] = new int[2];

	int r = 0;
	int row, column;

	for (int i = 0; i < 5; i++)
		for (row = 0; row < SUITS; ++row)
			for (column = 0; column < FACES; ++column)
				if (deck[row][column] == a[i])
				{
					hand[r][0] = row;
					hand[r][1] = column;
					++r;
				}
	return hand;
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
		SetColor(4);
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
	for (int i = 0; i < n; i++)
	{
		a[b[i][0]] = i + 1;
	}

	return a;
}
int** sum_of_two_handget(int** a, int** b, int n)
{
	int** c = new int* [n];
	for (int i = 0; i < n; i++)
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
int* evaluateHands(int* ranked_hands, int n, int s)
{
	int* ranked_last = new int[n];
	int deck[SUITS][FACES];

	int** c = new int* [n];
	for (int i = 0; i < n; i++)
		c[i] = new int[2];

	int** sum = new int* [n];
	for (int i = 0; i < n; i++)
		sum[i] = new int[2];

	for (int i = 0; i < n; i++)
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
		SetColor(3);
		print_dealingforhands(temp, n);
		SetColor(4);
		cout << "----------------------------------------------------------------------------------------" << endl;

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
	SetColor(4);
	cout << "     ********************** Congratulate the winner is player " << *(ranked_last) <<" **********************" <<endl;
	return ranked_last;
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
	SetColor(13);
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
		SetColor(4);
		printf("\n\nPlayer [%d]:", i+1);
		SetColor(3);
		printHand(player[i], suits, ranks);
	}
	SetColor(4);
	printf("\n\nDealer :");
	SetColor(3);
	printHand(player[n - 1], suits, ranks);
	do
	{
		SetColor(4);
		printf("\n\nEnter numbers of card does Dealer want draw (0-3): ");	// draw number card
		scanf_s("%d", &num);
	} while (num < 0 || num >3);
	int** draw = Draw(deck, num, n);
	SetColor(4);
	printf("\nThe %d draw card: ", num);
	SetColor(3);
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
				SetColor(4);
				printf("\n\nDealer decide (1-3): ");
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
		if(a[i]==1 && i!=n-1) printf("\n\n                  ----------- Congratulate the winner is Player %d -----------\n\n",i+1);
		else
			if (a[i] == 1 && i == n - 1) printf("\n\n                  ----------- Congratulate the winner is Dealer -----------\n\n");
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
	SetColor(4);
	printf("\nAfter Random Replace, Card of dealer :\n");
	SetColor(3);
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
			}SetColor(4);
			printf("Better Sittuation: ");
			SetColor(3);
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
				SetColor(4);
				printf("Better Sittuation: ");
				SetColor(3);
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
					SetColor(4);
					printf("Better Sittuation: ");
					SetColor(3);
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
						SetColor(4);
						printf("Better Sittuation: ");
						SetColor(3);
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
						SetColor(4);
						printf("Better Sittuation: ");
						SetColor(3);
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
			SetColor(4);
			printf("Better Sittuation: ");
			SetColor(3);
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
				SetColor(4);
				printf("Better Sittuation: ");
				SetColor(3);
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
					SetColor(4);
					printf("Better Sittuation: ");
					SetColor(3);
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
						SetColor(4);
						printf("Better Sittuation: ");
						SetColor(3);
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
							SetColor(4);
							printf("Better Sittuation: ");
							SetColor(3);
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
			SetColor(4);
			printf("Better Sittuation:");
			SetColor(3);
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
				SetColor(4);
				printf("Better Sittuation: ");
				SetColor(3);
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
					SetColor(4);
					printf("Better Sittuation: ");
					SetColor(3);
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
						SetColor(4);
						printf("Better Sittuation: ");
						SetColor(3);
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
			SetColor(4);
			printf("Better Sittuation: ");
			SetColor(3);
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
				SetColor(4);
				printf("Better Sittuation: ");
				SetColor(3);
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
					SetColor(4);
					printf("Better Sittuation: ");
					SetColor(3);
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
			SetColor(4);
			printf("Better Sittuation: ");
			SetColor(3);
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
				SetColor(4);
				printf("Better Sittuation: ");
				SetColor(3);
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
			SetColor(4);
			printf("Better Sittuation: ");
			SetColor(3);
			for (int i = 0; i < 5; i++)
				printf("(% s, % s)  ", suits[dealer[i][0]], ranks[dealer[i][1]]);
		}
		else
			printf("That is the best case.");
		break;
	}
}
bool check(int *b, int number) 	// check for RandomReplace function 
{
	for (int i = 0; i < 5; i++)
		if (b[i] == number) return false;
	return true;
}

// 4***----------------------------------------------------
int*** two_hand_to_hands(int** player, int** dealer)
{
	int*** hands = new int** [2];
	for (int i = 0; i < 2; i++)
		hands[i] = new int* [5];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			hands[i][j] = new int[2];

	int p = 0, d = 1;
	for (int i = 0; i < 5; i++)
	{
		hands[p][i][0] = player[i][0];
		hands[p][i][1] = player[i][1];
		hands[d][i][0] = dealer[i][0];
		hands[d][i][1] = dealer[i][1];
	}
	return hands;
}
void dealer_player(int deck[SUITS][RANKS], const char* suits[], const char* faces[])
{
	srand(time(NULL));

	int  num, decide = 0;
	int change[5] = { 0 };

	//player
	int** player = new int* [5];
	for (int i = 0; i < 5; i++)
		player[i] = new int[2];
	//dealer
	int** dealer = new int* [8];
	for (int i = 0; i < 8; i++)
		dealer[i] = new int[2];

	int j = 0;

	//deal 5-card poker hand 
	for (int card = 1, i = 0; card <= 10; card++, i++) {
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 13; column++) {
				if (deck[row][column] == card && i < 5) {
					player[i][0] = row;
					player[i][1] = column;
				}
				else if (deck[row][column] == card && i > 4) {
					dealer[j][0] = row;
					dealer[j][1] = column;
					j++;
				}
			}
		}
	}

	//poker hand of dealer
	num = rand() % 3 + 1;

	int** draw = Draw(deck, num, 2);
	for (int i = 0; i < num; i++)
	{
		dealer[i + 5][0] = draw[i][0];
		dealer[i + 5][1] = draw[i][1];
	}
//	printf("The Dealer contain Card: ");
	//printHand(dealer, suits, faces);
	decide = rand() % 3 + 1;
	if (decide == 1)	num = 0;		//check random decide =1 mean there is no change

	switch (decide)
	{
	case (1):
		SetColor(4);
		cout << "\n\nThe Dealer contain Card After Draw:" << endl;
		printHand(dealer, suits, faces);
		break;
	case (2): // random replace		
		SetColor(4);
		//cout << "\n\nThe Dealer contain Card After Draw:" << endl;
		RandomReplace(dealer, num);
		break;
	case (3):	// get better situation
		SetColor(4);
		//cout << "\n\nThe Dealer contain Card After Draw:" << endl;
		BetterSituation(dealer, num);
		break;
	}

	//poker hand of player
	SetColor(4);
	cout << "\n\nThe Player contain Card :";
	printHand(player, suits, faces);
	SetColor(4);
	cout << "\n\nWhich card you wanna change? You can change maximum 3 card in your hand (1 = change, 0 = don't change)\n\n";

	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		do {
			SetColor(4);
			cout << "Card " << i + 1<<": " ;
			cin >> change[i];
		} while (change[i] < 0 || change[i]>1);

		if (change[i] == 1)
		{
			change[i] = 1;
			count++;
		}
		if (count >= 3)
			break;
	}

	//check if any modification needed

	if (count != 0) {
		for (int card = 10 + num + 1; card < (11 + count + num); card++) {
			for (int row = 0; row < 4; row++) {
				for (int column = 0; column < 13; column++) {
					if (deck[row][column] == card) {
						for (j = 0; j < 5; j++) {
							if (change[j] == 1) {
								player[j][0] = row;
								player[j][1] = column;
								change[j] = 0;
								break;
							}
						}
					}
				}
			}
		}
	}
	else {
		SetColor(4);
		cout << "\n\nNo modification made.\n\n";
	}
	SetColor(4);
	cout << "The Player contain Card After Draw:" << endl;
	printHand(player, suits, faces);

	int*** hands = two_hand_to_hands(player, dealer);
	int* a = rankingHands(hands, 2);

	cout << endl;
	SetColor(4);
	cout << "\nRESULT:-----------------------------------------------------------------------------------\n";

	if (*(a) == 1)
	{
		SetColor(4);
		cout << "\nThe Player contain:\n" << endl;
		printHand(player, suits, faces);
		cout << endl;
		SetColor(4);
		cout << "\nThe Dealer contain:\n" << endl;
		printHand(dealer, suits, faces);
		SetColor(4);
		cout << "\n\n        ******************* The Player win ***********************\n" << endl;
	}
	else
	{
		SetColor(4);
		cout << "\nThe Player contain:\n" << endl;
		printHand(player, suits, faces);
		cout << endl;
		SetColor(4);
		cout << "\nThe Dealer contain:\n" << endl;
		printHand(dealer, suits, faces);
		SetColor(4);
		cout << "\n\n         ******************* The Dealer win ***********************\n" << endl;
	}
}

//---------------------------------------------------------
void SetColor(int ForgC)
{	//reference: https://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks
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
void gotoxy(int x, int y)		// C khong co lenh gotoxy --> tu viet 
{								// gotoxy de di chuyen con tro den vi tri x y	
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void MenuMain()
{
	system("cls");
	gotoxy(44, 5); SetColor(4);
	printf("CSC10002 - PROGRAMMING TECHNIQUES");
	gotoxy(48, 6);
	printf("MIDTERM PROJECT - POINTERS");
	gotoxy(48, 8);
	printf("CARD GAME: FIVE-CARD POKER");
	gotoxy(54, 10); SetColor(3);
	printf("(1) New game.");
	gotoxy(54, 11);
	printf("(2) Rule.");
	gotoxy(54, 12);
	printf("(3) About.");
	gotoxy(54, 13);
	printf("(4) Quit game.");
	gotoxy(40, 25); SetColor(4);
}
void About()
{
	system("cls");
	gotoxy(44, 5); SetColor(4);
	printf("CSC10002 - PROGRAMMING TECHNIQUES");
	gotoxy(48, 6);
	printf("MIDTERM PROJECT - POINTERS");
	gotoxy(48, 8);
	printf("CARD GAME: FIVE-CARD POKER");
	
	gotoxy(40, 10); SetColor(4);	//Red
	printf("Class  : ");
	gotoxy(49, 10); SetColor(3);	//Red
	printf("19CLC6 ");
	gotoxy(40, 11); SetColor(4);
	printf("Lecture:");
	gotoxy(44, 12); SetColor(3);
	printf("- Nguyen Thanh Phuong");
	gotoxy(44, 13);
	printf("- Bui Huy Thong");
	gotoxy(44, 14);
	printf("- Nguyen Ngoc Thao");
	gotoxy(40, 15); SetColor(4);	//Red
	printf("Code by: ");
	gotoxy(44, 16); SetColor(3);	//Cyan	
	printf("- 19127422: Nguyen Duc Huy");
	gotoxy(44, 17);
	printf("- 19127525: Nguyen Thanh Quan");
	gotoxy(40, 20); SetColor(4);	//Red
	printf("HCMUS _ Ho Chi Minh University of Sience.");
	SetColor(15);	//white
	gotoxy(40, 25);
	system("pause");
}
void NewGame()
{
	system("cls");
	gotoxy(44, 5); SetColor(4);
	printf("CSC10002 - PROGRAMMING TECHNIQUES");
	gotoxy(48, 6);
	printf("MIDTERM PROJECT - POINTERS");
	gotoxy(48, 8);
	printf("CARD GAME: FIVE-CARD POKER");
	gotoxy(50, 10); SetColor(3);
	printf("(1) Game for 1 player only.");
	gotoxy(50, 11);
	printf("(2) Game for multiple player.");
	gotoxy(50, 12);
	printf("(3) Game for dealer side.");
	gotoxy(50, 13);
	printf("(4) Game for player and dealer compete.");
	gotoxy(50, 14);
	printf("(5) View deck (52 card).");
	gotoxy(50, 15);
	printf("(6) Shuffling deck.");
	gotoxy(50, 16);
	printf("(7) Home.");
	gotoxy(20, 25);
	SetColor(4);
}
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void Rule()
{
	SetColor(4);	//Red
	system("cls");
	gotoxy(50, 2);
	printf("THE RULE OF POKER");
	gotoxy(4, 4);
	SetColor(3);	//Cyan
	printf("Poker is a game of chance. However, when you introduce the concept of betting, poker gains quite a bit of skill ");
	printf("\nand psychology. (This isn't to say that there isn't skill at poker when nothing is at risk, there just isn't nearly");
	printf("\nas much).This is meant as a very basic primer into the rules of poker, for more information, get a book on the");
	printf("\ngame(or start playing with a group of people who know how. It's more expensive than reading a book, but the group");
	printf("\nwon't mind).");
	gotoxy(1, 10);
	SetColor(4);
	printf("THE VERY BASIC:");
	gotoxy(4, 11);
	SetColor(3);
	printf("Poker is played from a standard pack of 52 cards. (Some variant games use multiple packs). The cards are ranked");
	printf("\n(from high to low) ");
	SetColor(13);
	printf("2, Ace, King, Queen, Jack, 10, 9, 8, 7, 6, 5, 4, 3. ");
	SetColor(3);
	printf("There are four suits(hearts, diamonds, clubs");
	printf("\nand spades). All poker hands contain five cards, the highest hand wins.");
	gotoxy(1, 15);
	SetColor(4);
	printf("HOW THE HANDS ARE RANKED:");
	gotoxy(4, 16);
	SetColor(3);
	printf("Hands are ranked as follows (from high to low):");
	gotoxy(4, 17);
	SetColor(13); printf(" - Straight flush:"); SetColor(3);printf(" a hand that contains five cards of sequential rank, all of the same suits.");
	gotoxy(4, 18);
	SetColor(13); printf(" - Four of a kind or quads:"); SetColor(3); printf(" a hand that contains four cards of one rank and one card of another rank");
	gotoxy(4, 19);
	SetColor(13); printf(" - Full house:"); SetColor(3);printf(" a hand that contains three cards of one rankand two cards of another rank");
	gotoxy(4, 20);
	SetColor(13); printf(" - Flush:"); SetColor(3); printf(" a hand that contains five cards all of the same suit, not all of sequential rank");
	gotoxy(4, 21);
	SetColor(13); printf(" - Straight:"); SetColor(3); printf(" a hand that contains five cards of sequential rank, not all of the	same suit");
	gotoxy(4, 22);
	SetColor(13); printf(" - Three of a kind:"); SetColor(3);printf(" a hand that contains three cards of one rankand two cards of two other ranks.");
	gotoxy(4, 23);
	SetColor(13); printf(" - Two pairs:"); SetColor(3); printf(" a hand that contains two cards of one rank, two cards of another rankand one card of a third rank.");
	gotoxy(4, 24);
	SetColor(13); printf(" - Pair:"); SetColor(3);printf(" a hand that contains two cards of one rankand three cards of three other ranks");
	gotoxy(4, 25); SetColor(13);
	printf(" - None of the above categories:"); SetColor(3);printf(" the highest card is taken as a representative.");
	gotoxy(1, 27);
	SetColor(4);
	printf("GAME MODE:");
	gotoxy(4, 28);
	SetColor(4);
	printf(" - Game for 1 player only:\n");
	SetColor(3);
	printf("         _The player will take 5 first card of deck and Game will count how mark does he/she has.\n");
	printf("         _Game will let player choose (or auto choose) 5 card he/she want (he/she can look the deck in");
	SetColor(13);
	printf(" 1.New Game -> \n5.View Deck");
	SetColor(3);
	printf(" or");
	SetColor(13);
	printf(" 3.View Deck");
	SetColor(3);
	printf(").\n ");
	SetColor(4);
	printf("     - Game for multiple player:\n");
	SetColor(3);
	printf("         _The User will input ");
	SetColor(13);
	printf("The number of player ");
	SetColor(3);
	printf("and ");
	SetColor(13);
	printf("The number round do they play.\n");
	SetColor(3);
	printf("         _Game will print the Winner\n");
	SetColor(4);
	printf("     - Game for dealer side:\n");
	SetColor(3);
	printf("         _Game will let user enter Number of player (in this, Dealer is the last player), and number of card does\n");
	printf("Dealer want draw.\n");
	printf("         _Atfer that, Dealer can sort card by 2 way:");
	SetColor(13);
	printf(" Random");
	SetColor(3);
	printf(" or");
	SetColor(13);
	printf(" Better\n");
	SetColor(3);
	printf("         _After sort, press 1 to print the Winner\n");
	SetColor(4);
	printf("     - Game for player and dealer compete:\n");
	SetColor(3);
	printf("         _Dealer: will auto draw and shuffle card of his hand\n");
	printf("         _Player: can replace card of his hand ");
	SetColor(13);
	printf("(1. Change / 0. Not change) ");
	SetColor(3);
	printf("and max change 3 card\n\n");
	printf("          ***************************************** END *****************************************");
	SetColor(15);	//white
	gotoxy(20, 1);
	system("pause");
}
void PlayGame(int& choose, int deck[SUITS][RANKS])
{
	system("cls");
	int* b;
	int** a;
	int*** player;
	int n,times;
	switch (choose)
	{
	case (1):
		int c[6], chon;
		do
		{
			do
			{
				system("cls"); SetColor(4);
				gotoxy(46, 5);
				printf("GAME FOR 1 PLAYER (ONLY).");
				gotoxy(46, 7); SetColor(3);
				printf("(1) Choose 5 first card of the deck.\n ");
				gotoxy(46, 8);
				printf("(2) Choose 5 card yourself.\n");
				gotoxy(46, 9);
				printf("(3) View deck");
				gotoxy(46, 10);
				printf("(4) Shuffling deck");
				gotoxy(46, 11);
				printf("(5) Exit.");
				gotoxy(46, 14); SetColor(4);
				printf("Choose: ");
				scanf_s("%d", &chon);

			} while (chon > 5 || chon < 1);
			switch (chon)
			{
			case (1):
				a = dealingForHand(deck);
				printHand(a, suits, ranks);
				SetColor(4);
				printf("\n\n\n              ******************* Player has %d mark ******************* \n\n", getStatusOfHand(a));
				gotoxy(20, 25);
				SetColor(15);	//white
				system("pause");
				break;
			case (2):
				a = createHandTest(deck, c);
				printHand(a, suits, ranks);
				SetColor(4);
				printf("\n\n\n              ******************* Player has %d mark ******************* \n\n", getStatusOfHand(a));
				gotoxy(20, 28);
				SetColor(15);	//white
				system("pause");
				break;
			case (3):
				system("cls");
				SetColor(4);
				printf("\n                             *******************  DECK  *******************");
				SetColor(3);
				printCardsShuffling(deck, suits, ranks);
				gotoxy(20,2);
				SetColor(15);	//white
				system("pause");
				break;
			case(4):
				system("cls");
				reset_deck(deck);
				shuffleCards(deck);
				printf("\n                             *******************  DECK AFTER SHUFFLE *******************");
				SetColor(3);
				printCardsShuffling(deck, suits, ranks);
				gotoxy(20,2);
				SetColor(15);	//white
				system("pause");
				break;
			}
		}while (chon != 5);
		break;
	case (2):
		do
		{
			printf("Enter number of player (1-10): ");
			scanf_s("%d", &n);
		} while (n > 10 || n < 1);
		player = dealingForHands(deck, n);
		b = rankingHands(player, n);
		do
		{
			printf("What time do you want to play: ");
			scanf_s("%d", &times);
		} while (time < 0);
		evaluateHands(b, n,times);
		printf("\n\n");
		SetColor(15);	//white
		system("pause");
		break;
	case (3):
		do
		{
			printf("Enter number of player (1-10): ");
			scanf_s("%d", &n);
		} while (n > 10 || n < 1);
		GameForDealer(deck, n);
		SetColor(15);	//white
		system("pause");
		break;
	case (4):
		dealer_player(deck, suits, ranks);
		SetColor(15);	//white
		system("pause");
		break;
	case(5):
		SetColor(4);
		printf("\n                             *******************  DECK  *******************");
		SetColor(3);
		printCardsShuffling(deck, suits, ranks);
		gotoxy(20, 2);
		SetColor(15);	//white
		system("pause");
		break;
	case(6):
		system("cls");
		reset_deck(deck);
		shuffleCards(deck);
		printf("\n                             *******************  DECK AFTER SHUFFLE *******************");
		SetColor(3);
		printCardsShuffling(deck, suits, ranks);
		gotoxy(20, 2);
		SetColor(15);	//white
		system("pause");
		break;

	}
}