#include"Lab09.h"

int main() {
	srand(time(NULL));
	Class clc6;

	clc6.next(30);
	clc6.writeFile();
	clc6.sort();
	vector<Student>hocbong = clc6.top();
}