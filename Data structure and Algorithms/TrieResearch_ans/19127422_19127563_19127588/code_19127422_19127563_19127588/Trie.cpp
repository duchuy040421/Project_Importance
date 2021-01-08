#include"Trie.h"

NODE* createNODE(char data) {
	NODE* p = new NODE;

	if (p == NULL)
		return NULL;

	p->isEndOfWord = false;
	p->key = data;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		p->children[i] = NULL;

	return p;
}

void insert(NODE* &proot, string key) {
	NODE* p = proot;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (p->children[index] == NULL) {
			p->children[index] = createNODE(key[i]);
		}

		p = p->children[index];
	}

	p->isEndOfWord = true;
}
NODE* search(NODE* proot, string key) {
	NODE* p = proot;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';

		if (p->children[index] == NULL)
			return NULL;

		p = p->children[index];
	}

	if (p)
		return p;
	else
		return NULL;
}

void collect(NODE* p, string key,vector<string>&result) {
	if (p == NULL) return;
	if (p->key != NULL && p->isEndOfWord)
		result.push_back(key);
	for (int c = 0; c < 26; c++) {
		char temp = 'a' + c;
		collect(p->children[c], key + temp, result);
	}
}
void get_word(NODE* proot, string key, vector<string>& result) {
	NODE* p = search(proot, key);
	collect(p, key, result);
}

void readFile(string name, NODE*& proot) {
	fstream read;
	read.open(name, ios::in);
	if (!read)
		cout << "\nCan't open file\n";
	else {
		while (!read.eof()) {
			string temp;
			getline(read, temp);
			insert(proot, temp);
		}
	}
	read.close();
}
void writeFile(vector<string>& result) {
	fstream write;
	write.open("output.txt", ios::out);
	if (!write)
		cout << "\nCan't open file\n";
	else {
		write << result.size() << endl;
		for (int i = 0; i < result.size(); i++)
			write << result[i] << endl;
	}
	write.close();
}

int main() {
	NODE* tree = createNODE(NULL);
	vector<string>result;

	readFile("Dic.txt", tree);
	//readFile("input.txt", tree);

	get_word(tree, "happ", result);

	writeFile(result);
}