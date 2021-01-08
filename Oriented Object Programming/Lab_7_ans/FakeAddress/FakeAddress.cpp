#include"FakeAddress.h"

Address FakeHcmAddress::next() {
	Address temp;
	temp._number = number[rand() % 5];
	temp._street = street[rand() % 5];
	temp._ward = ward[rand() % 8];
	temp._district = district[rand() % 5];
	return temp;
}
void Address::show() {
	cout << _number << " " << _street << " " << _ward << " " << _district << "," << "Thanh Pho Ho Chi Minh,Viet Nam";
}

string FakeHcmAddress::number[15] = { "52","154/10","30/7/10","256","5/3/10","29A","5","17B","215B37","67","15A","4B","56/3B","9B","5C" };
string FakeHcmAddress::street[5] = { "CMT8","Truong Chinh","Cong Hoa","Duong Quang Ham","Ly Chinh Thang" };
string FakeHcmAddress::ward[40] = { "Phuong Tan Dinh","Phuong Da Kao","Phuong Ben Nghe","Phuong Nguyen Thai Binh","Phuong Cau Ong Lanh","Phuong Co Giang","Phuong Nguyen Cu Trinh","Phuong Ben Thanh",
"Phuong 1","Phuong 2","Phuong 3","Phuong 4","Phuong 5","Phuong 6","Phuong 7","Phuong 8",
"Phuong 9","Phuong 10","Phuong 11","Phuong 12","Phuong 13","Phuong 14","Phuong 15","Phuong 8",
"Phuong Binh Hung Hoa","Phuong Binh Hung Hoa A","Phuong Binh Hung Hoa B","Phuong Tan Tao","Phuong An Lac","Phuong An Lac A","Phuong Binh Tri Dong A","Phuong Binh Tri Dong B",
"Phuong Tan Thuan Dong","Phuong Tan Thuan Tay","Phuong Tan Kieng","Phuong Tan Hung","Phuong Binh Thuan","Phuong Tan Quy","Phuong Phu Thuan","Phuong Phu My"};
string FakeHcmAddress::district[5] = { "Quan 1","Quan Tan Binh","Quan 7","Quan Binh Tan","Quan 3" };

