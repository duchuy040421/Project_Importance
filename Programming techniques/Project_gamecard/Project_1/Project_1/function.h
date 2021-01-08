#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<iostream>
#include <Windows.h>


using namespace std;

#pragma once
#define SUITS 4
#define RANKS 13
#define FACES 13 

//function require--------
void shuffleCards(int deck[][RANKS]);
void printCardsShuffling(int deck[][RANKS], const char* suits[], const char* faces[]);
int** dealingForHand(int deck[SUITS][FACES]);
void printHand(int** hand, const char* suits[], const char* faces[]);
int** createHandTest(int deck[SUITS][FACES], int a[]);
int isFourOfAKind(int** hand);
int isFullHouse(int** hand);
int isFlush(int** hand);
int isStraight(int** hand);
int isStraightFlush(int** hand);
int isThreeOfAKind(int** hand);
int isTwoPairs(int** hand);
int isPair(int** hand);
int getHighestCard(int** hand);
int*** dealingForHands(int deck[SUITS][FACES], int n);
int getStatusOfHand(int** hand);
int* rankingHands(int*** hands, int n);
int* evaluateHands(int* ranked_hands, int n, int s);

//--------------------------------------
bool SameNum(int deck[][RANKS], int num);
int** Copy_hands_into_onehand(int*** hands, int k);
int prepare_2hand(int** play1, int** play2);
void sort_same(int*** hands, int pos, int n, int** handget);
int** sum_of_two_handget(int** a, int** b, int n);
void delete_matrix(int** a);
void reset_deck(int deck[][RANKS]);
void print_dealingforhands(int*** hands, int n);

//3*-----------------------------------------------
int** Draw(int deck[SUITS][RANKS], int num, int n); // draw one, two or three
void Menu3();
void GameForDealer(int deck[SUITS][RANKS], int n);
void RandomReplace(int** dealer, int num);
bool check(int* b, int number);
void BetterSituation(int** dealer, int num);

//4***----------------------------------------------
void dealer_player(int deck[SUITS][RANKS], const char* suits[], const char* faces[]);
int*** two_hand_to_hands(int** player, int** dealer);
int prepare_four_kind(int** play1, int** play2);
void reset_hand(int** hand);
int prepare_fullhouse(int** play1, int** play2);
int prepare_two_pair(int** play1, int** play2);
int prepare_pair(int** play1, int** play2);

//------------------MENU MAIN --------------------
void gotoxy(int x, int y);
void TextColor(int x);
void SetColor(int ForgC);
void MenuMain();
void About();
void NewGame();
void Rule();
void PlayGame(int& choose, int deck[SUITS][RANKS]);
//------------------------------------------------