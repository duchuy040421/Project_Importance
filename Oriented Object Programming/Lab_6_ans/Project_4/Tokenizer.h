#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//class
class Tokenizer {
public:
	static vector<string> split(string haystack, string separator = " ") {
		vector<string> result;

		int startPos = 0;
		while (true)
		{
			size_t found_pos = haystack.find(separator, startPos);

			if (found_pos != string::npos) {
				string token = haystack.substr(startPos, found_pos - startPos);

				if (token[0]!=NULL) {
					result.push_back(token);
					//startPos = found_pos + separator.length();
				}
				startPos = found_pos + separator.length();
			}
			else {
				
				int last = haystack.length() - startPos;
				if (haystack.substr(startPos, last)[0] != NULL)
					result.push_back(haystack.substr(startPos, last));
				break;
			}
		}
		return result;
	}
};
//lab 3+4
class Convert {
private:
	vector<int>list;
public:
	static vector<int> find(string haystack);
	Convert(string haystack);
	int sum_list();
	int smallest();
	void largest();
	float average();
	void show_isprime();
};


//function addition
void sort(vector<int>&temp);
void swap(int& a, int& b);
bool Isprime(int a);
void menu_1();
void menu_2();
void menu_3();






