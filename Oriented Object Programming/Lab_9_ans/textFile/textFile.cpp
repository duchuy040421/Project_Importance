#include"textFile.h"

string Client::separator = " - ";

void writeFile() {
	vector<Client> clients;
	clients.push_back(Client("001", "Tran Duc Thuan", 10000000));
	clients.push_back(Client("002", "Nguyen Thi Ly", 20000000));
	clients.push_back(Client("003", "Le My Linh", 30000000));
	clients.push_back(Client("004", "Tran Hoang Long", 40000000));
	clients.push_back(Client("005", "Luu Thuy Lan", 50000000));

	ofstream writer("clients.txt", ios::out);
	writer << clients.size();

	for (auto& client : clients) {
		writer << endl << client.toString();
	}

	writer.close();
}
void readFile() {
	ifstream reader("clients.txt", ios::in);
	vector <Client> clients;

	if (!reader) {
		cout << "Can't open file\n";
		return;
	}
	else {
		string line;
		getline(reader, line);
		int count = stoi(line);

		while (!reader.eof()) {
			string buffer;
			getline(reader, buffer);
			clients.push_back(Client::parse(buffer));
		}
	}

	cout << "Thong tin cac client\n";
	for (auto& client : clients) {
		cout << client.toString() << endl;
	}

	reader.close();
}