#include"FakeEmail.h"

int main() {
	srand(time(NULL));
	cout << "Danh sach 20 Email ngau nhien: \n";
	for (int i = 0; i < 20; i++)
	{
		string temp_1 = Fakename::firstName[rand() % 132].substr(0, 1) + Fakename::middleName[rand() % 5].substr(0, 1);
		string temp_2 = Fakename::lastName[rand() % 850];
		cout << Modernize(temp_1 + temp_2 + '@' + domain[rand() % 10]) << endl;
	}
}