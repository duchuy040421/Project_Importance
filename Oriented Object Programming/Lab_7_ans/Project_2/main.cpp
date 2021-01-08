#include"Dice.h"

int main()
{
	Dice temp;
	cout << "-----------------------------------------------------------\n";
	cout << "The number of times a dice has been rolled: " << temp.RollCount() << endl;
	cout << "The average number that we get from all the rolls: " << temp.averageRollCount() << endl;
	cout << "All the counts for all the values of one dice:\n";
	temp.getRollCount();
}