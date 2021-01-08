#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;


int sum_of_digit(int n) {

	// use recursion to calculate all digit from number input
	if (n > 0) {
		// separate last digit from number input and give number (divide ten) for calling function again 
		return n % 10 + sum_of_digit(n / 10);
	}
	// if n isn't less than 0 then return 0 
	return 0;
}
int searchWinningLotteryTicket(int A, int B) {
	/*find a first number qualified all condition that is greater than A and less than B
	it just rounding from square root of A and then quare of it*/
	int find_smallest_number = pow(int(sqrt(A)), 2);
	int max_digit, pos = -1, i = int(sqrt(A));

	// if user'input is wrong then return -1
	if (B < A)
		return -1;

	if (find_smallest_number < A) {
		/* if the first number less than A that isn't qualified condition 
		then plus 1 before square it (absolutely number plus 1 greater than A)
		And then call function sum_of_digit to return sum of digit a first number in the range */
		max_digit = sum_of_digit(pow(int(sqrt(A)) + 1, 2));
		i++;
	}
	else
		max_digit = sum_of_digit(pow(int(sqrt(A)), 2));

	/* the algorithm is that you find small upper bound and lower bound from A and B 
	and the number in the range after you find if it square of 2 that is in the range 
	from A to B */
	for (; i <= int(sqrt(B)); i++) {
		// if sum of digit at running time greater than max_digit then update max digit and position
		if (sum_of_digit(pow(i, 2)) > max_digit) {
			max_digit = sum_of_digit(pow(i, 2));
			pos = i;
		}
	}

	// and at here the last thing you do is check again that is in the range 
	if (A <= pow(pos, 2) && pow(pos, 2) <= B)
		return pow(pos, 2);
	// if not return -1
	return -1;
}

int find_fruits_by_day(int day) {
	return (day * (day + 1)) / 2;
}
int searchHarvestDay(int N, int T) {
	// set the range is from day 1 to day N
	int day_min = 1, day_max = N;

	/* the algorithm is similar to binary method 
	(because fruits day by day is increasing to use this method), find fruits at mid day 
	in the range if fruits here equal to T the return fruits, if T maybe less than mid day,
	you absolutely know day of havesting enough fruits is less than mid day 
	(because fruits day by day is increasing), and if not check the same in the other side */
	while (day_min < day_max) {
		int day_mid = (day_min + day_max) / 2;

		if (find_fruits_by_day(day_mid) == T)
			return day_mid;
		else if (find_fruits_by_day(day_mid) < T)
			day_min = day_mid + 1;
		else
			day_max = day_mid - 1;
	}

	return -1;
}

int main() {

	clock_t start = clock();
	cout << searchWinningLotteryTicket(3, 9);
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << endl << duration << endl;

	cout << "Day of havest:\n";
	cout << searchHarvestDay(5, 10);

}