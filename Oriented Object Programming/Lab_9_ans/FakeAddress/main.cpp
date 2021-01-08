#include"FakeAddress.h"

int main() {
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		Address temp = FakeHcmAddress::next();
		temp.show();
		cout << "\n\n";
	}
}