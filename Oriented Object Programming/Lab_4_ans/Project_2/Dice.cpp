#include"Dice.h"

Dice::Dice()
{
	srand(time(0));
	value[0] = -1;

	this->rollCount = 0;
	this->sum = 0;

	int choice;

	cout << "First Random...\n\n";
	int first = rng.next(1, 6);
	this->rollCount++;
	sum += first;
	value[first]++;

	while (true)
	{ 
		cout << "1:tiep tuc\n0:thoat\n\n";
		cin >> choice;
		while (choice > 1 || choice < 0)
		{
			cout << "Please enter number 0 or 1\n";
			cin >> choice;
		}
		if (1 == choice)
		{
			int result= rng.next(1, 6);
			this->sum += result;
			this->rollCount++;
			value[result]++;
		}
		else
			break;
	}
}

int Dice::RollCount()
{
	return this->rollCount;
}

float Dice::averageRollCount() {
	return 1.0 * this->sum / this->rollCount;
}

void Dice::getRollCount()
{
	for (int i = 1; i <= 6; i++)
		cout << i << ": " << value[i] << " times, ";
}