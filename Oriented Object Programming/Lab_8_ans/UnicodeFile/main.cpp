#include"UnicodeFile.h"

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	writeFile();
	readFile();
}