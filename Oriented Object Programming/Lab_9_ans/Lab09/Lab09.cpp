#include"Lab09.h"

Student::Student(string id, string name, string date, string address, string email, string tel, float mark) {
	_id = id;
	_date = date;
	_address = address;
	_email = email;
	_tel = tel;
	_mark = mark;
	_name = name;
}
void Class::next(int num) {
	string temp;

	for (int i = 1; i <= num; i++) {
	char s = 65 + rand() % 26;
	temp = s + to_string(rand() % 10);

	//name
	Fullname fullname = Fakename::next();
	//date
	Date date = FakeBirthday::next();
	//address
	Address address = FakeHcmAddress::next();

	//email
	string temp_1 = Fakename::firstName[rand() % 132].substr(0, 1) + Fakename::middleName[rand() % 5].substr(0, 1);
	string temp_2 = Fakename::lastName[rand() % 850];
	string email = Modernize(temp_1 + temp_2 + '@' + domain[rand() % 10]);

	//telephone
	string temp_3;
	for (int i = 0; i < 7; i++) {
		string temp_4 = to_string(rand() % 10);
		temp_3 += temp_4;
	}
	string tel = number[rand() % 33] + temp_3;
	Student student(temp, fullname.toString(), date.toString(), address.toString(), email, tel, (rand() % 101 / 10));

	this->s.push_back(student);
	}
}

void swap_Student(Student& a, Student& b) {
	Student temp = a;
	a = b;
	b = temp;
}
void Class::sort() {
	for (int i = 0; i < s.size() - 1; i++)
	{
		for (int j = i + 1; j <s.size(); j++)
			if (s[i]._mark < s[j]._mark)
				swap_Student(s[i], s[j]);
	}
}
void Student::show() {
	cout << "\nID: " << _id << "\tTen: " << _name << "\tNgay Sinh: " << _date;
	cout << "\nDia chi: " << _address << "\tEmail: " << _email << "\tSDT: " << _tel;
	cout << "\nDiem: " << _mark << "\n\n";
}
string Student::toString() {
	stringstream writer;
	writer << "\nID: " << _id << "\tTen: " << _name << "\tNgay Sinh: " << _date;
	writer << "\nDia chi: " << _address << "\tEmail: " << _email << "\tSDT: " << _tel;
	writer << "\nDiem: " << _mark << "\n\n";

	return writer.str();
}

vector<Student>Class::top(){
	int k = 4;
	vector < Student> temp;

	if (this->s[0]._mark < 9)
	{
		cout << "Khong co hoc sinh nao nhan duoc hoc bong\n";
		return temp;
	}

	int count = 0;

	/*if (this->s[4]._mark >= 9 && this->s[5]._mark - this->s[4]._mark < EPSILON) {
		while (this->s[k + 1]._mark - this->s[4]._mark < EPSILON && k < s.size() - 1)
		{
			count++;
			k++;
		}
	}*/

	for (int i = 0; i < s.size(); i++)
		if (s[i]._mark >= 9) {
			s[i].show();
			temp.push_back(s[i]);
		}
	return temp;
}
void Class::writeFile() {
	fstream writeFile("Database.txt", ios::out);
	if (!writeFile)
		cout << "Khong mo duoc file\n";
	else {
		for (int i = 0; i < s.size(); i++)
		{
			writeFile << s[i].toString();
		}
	}
	writeFile.close();
}



	