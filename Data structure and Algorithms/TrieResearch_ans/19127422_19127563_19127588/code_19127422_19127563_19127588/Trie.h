#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

const int ALPHABET_SIZE = 26;

struct NODE {
	struct NODE* children[ALPHABET_SIZE];
	char key ;
	bool isEndOfWord;
};

NODE* createNODE(char key);
void insert(NODE* &proot, string key);
void readFile(string name, NODE* &proot);
void get_word(NODE* proot, string key, vector<string>& result);
void writeFile(vector<string>& result);