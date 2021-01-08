#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

#define PI 3.14

int random() {
	return 10 + rand() % 11;
}

class Shape {
public:
	virtual float perimeter() = 0;
	virtual float area() = 0;
	virtual string name() = 0;
	virtual string info() = 0;
	static vector<Shape*> generate(int n, vector<Shape*>s);
};
class Circle :public Shape {
private:
	int radius;
public:
	float perimeter() {
		return PI * 2 * radius;
	}
	float area() {
		return PI * pow(radius, 2);
	}
	Circle(int r) {
		radius = r;
	}
	string name() {
		return "Circle";
	}
	string info() {
		return "r=" + to_string(radius);
	}
};

class Rectangle:public Shape {
protected:
	int width, height;
public:
	float perimeter() {
		return 2 * (width + height);
	}
	float area() {
		return width * height;
	}
	Rectangle(int wid,int height) {
		width = wid;
		this->height = height;
	}
	string name() {
		return "Rectangle";
	}
	string info() {
		return "a=" + to_string(width) + " b=" + to_string(height);
	}
};

class Square :public Rectangle {
public:
	float perimeter() {
		return width * 4;
	}
	float area() {
		return width * height;
	}
	Square(int size) :Rectangle(size, size) {}
	string name() {
		return "Square";
	}
	string info() {
		return "a=" + to_string(width) ;
	}
};

class Triangle :public Shape {
private:
	int edge_1, edge_2, edge_3;
public:
	float perimeter() {
		return edge_1 + edge_2 + edge_3;
	}
	float area() {
		return sqrt(perimeter() * (perimeter() - edge_1) * (perimeter() - edge_2) * (perimeter() - edge_3));
	}
	Triangle(int edge_1, int edge_2, int edge_3) {
		this->edge_1 = edge_1;
		this->edge_2 = edge_2;
		this->edge_3 = edge_3;
	}
	string name() {
		return "Triangle";
	}
	string info() {
		return "a=" + to_string(edge_1) + " b=" + to_string(edge_2) + " c=" + to_string(edge_3);
	}
};

void writeFile(vector<Shape*>s) {
	fstream w;
	w.open("Ex1.txt", ios::out);
	if (!w)
		cout << "Can't open file\n";
	else {
		w << s.size() << endl;
		for (int i = 0; i < s.size(); i++) {
			w << s[i]->name() <<" "<< s[i]->info() << endl;
		}
	}
	w.close();
}

vector<Shape*> largest_area(vector<Shape*>s) {
	vector<Shape*>result;
	int pos_1 = 0, pos_2 = 0, pos_3 = 0;
	float max = s[0]->area();

	for(int i=0;i<s.size();i++)
		if (s[i]->area()>max)
		{
			max = s[i]->area();
			pos_1 = i;
		}

	max = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i]->area() > max&& i != pos_1)
		{
			max = s[i]->area();
			pos_2 = i;
		}
	max = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i]->area() > max&& i != pos_1 && i != pos_2)
		{
			max = s[i]->area();
			pos_3 = i;
		}

	result.push_back(s[pos_1]);
	result.push_back(s[pos_2]);
	result.push_back(s[pos_3]);

	return result;
}

void readFile(string name) {
	fstream r;
	r.open(name, ios::in);
	if (!r)
		cout << "Can't open File\n";
	else {
		int num;
		r >> num;
		cout << num;

		for (int i = 0; i < num; i++)
		{
			string temp;
			getline(r, temp);
			cout << temp << endl;
		}
	}
	r.close();
}

vector<Shape*>Shape::generate(int n, vector<Shape*>s) {
	for (int i = 0; i < n; i++)
	{
		int num = 1 + rand() % 4;

		switch (num)
		{
		case 1:
			s.push_back(new Circle(random()));
			break;
		case 2:
			s.push_back(new Square(random()));
			break;
		case 3:
			s.push_back(new Rectangle(random(), random()));
			break;
		case 4:
			s.push_back(new Triangle(random(), random(), random()));
			break;
		default:
			break;
		}
	}

	return s;
}

int main() {
	srand(time(NULL));
	int num = random();
	cout << "Gererate number (10<=n<=20): " << num << endl;
	cout << "---------------------------------------------------\n";

	vector<Shape*>s = Shape::generate(num, s);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i]->name() << " Perimeter:" << s[i]->perimeter() << " Area:" << s[i]->area() << endl;
	}
	writeFile(s);
	cout << "---------------------------------------------------\n";
	readFile("Ex1.txt");
	cout << "---------------------------------------------------\n";
	vector<Shape*>result = largest_area(s);
	for (Shape* s : result)
		cout << s->name() << " Perimeter:" << s->perimeter() << " Area:" << s->area() << endl;
		
}