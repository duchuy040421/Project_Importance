#include"Random.h"

int main()
{
	srand(time(0));
	Random rng;
	
	cout << "Random integer number: "<<rng.next() << endl;
	cout << "Random integer from 0-9: "<<rng.next(10) << endl;
	cout << "Random interger from 1-6: " << rng.next(1, 6) << endl;
}