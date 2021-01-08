#include"Random.h"

int Random::next()
{
	return rand();
}

int Random::next(int i)
{
	return rand() % i;
}

int Random::next(int i, int j)
{
	return  (i > j ? j : i) + (rand() % (abs(i - j) + 1));
}