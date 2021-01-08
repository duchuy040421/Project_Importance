#include"Function.h"

int main() {
	Store store;
	store.generateRandomNumbers(10, 999);
	cout << "10 so nguyen ngau nhien la:" << endl;
	store.showCurrentNumbers();

	store.getNumbersFromKeyboard();
	cout << "Cac so nguyen ban vua nhap la:" << endl;
	store.showCurrentNumbers();
}