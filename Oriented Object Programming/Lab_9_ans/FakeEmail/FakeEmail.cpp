#include"FakeEmail.h"

string domain[10] = { "gmail.com","microsoft.com","apple.com","amazon.com","msn.com","vrizon.net","att.net","yahoo.com","hotmail","mac.com" };

string Modernize(string n) {
	for (int i = 0; i < n.size(); i++)
		if ((n[i] < 65 || n[i]>90 && n[i] < 97 || n[i]>122)&&n[i]!='@'&&n[i] != '.') {
			n.erase(i, 1);
			i--;
		}
	return n;
}