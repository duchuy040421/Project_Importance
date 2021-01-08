#include"UnicodeFile.h"

void readFile() {
	wifstream reader("test.txt", ios::in);
	reader.imbue(locale(std::locale(),
		new codecvt_utf8_utf16 <
		wchar_t, 0x10ffff,
		codecvt_mode(consume_header | generate_header)>
	));

	wstring buffer;
	getline(reader, buffer);

	wcout << buffer;

	reader.close();
}

void writeFile() {
	wofstream writer("test.txt", ios::out);
	writer.imbue(locale(std::locale(),
		new codecvt_utf8_utf16 <
			wchar_t, 0x10ffff,
			codecvt_mode (consume_header | generate_header)>
	));

	writer << L"Xin chào thầy và các bạn đây là cách đọc Unicode :Tiếng Việt \n";
	writer.close();
}