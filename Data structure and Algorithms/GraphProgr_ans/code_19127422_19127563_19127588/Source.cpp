#include "Header.h"

// Move the cursor to the position(x; y)
void _Common::GoTo(SHORT posX, SHORT posY)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = posX;
	position.Y = posY;

	SetConsoleCursorPosition(handle, position);
}

void _Common::Goodbye()
{
	system("CLS");
	stringstream color;
	for (int i = 9; i >= 0; i--)
	{
		_Common::GoTo(40, 10);
		color << "color f" << i;
		system((color.str()).c_str());  // background color & text color
		cout << "<< THANK YOU FOR VISTING! GOOD BYE! >>" << endl << endl;
		color.str(std::string());
	}
}

//------------------------------------------------------------------------------------

void initGraph(Graph& g) {
	vector<int> tmp(g.size, 0);
	for (int i = 0; i < g.size; i++)
		g.matrix.push_back(tmp);
}

void writeFile(Graph G)
{
	ofstream outFileT("transport_type.txt");
	ofstream outFileS("street.txt");

	outFileT << G.size;
	outFileS << G.size;

	for (int i = 0; i < G.size; i++)
	{
		outFileT << endl;
		outFileS << endl;

		for (int j = 0; j < G.matrix[i].size(); j++)
		{
			outFileT << G.matrix[i][j] << " ";

			if (G.matrix[i][j] != 0)
				G.matrix[i][j] = rand() % 9 + 1;
			outFileS << G.matrix[i][j] << " ";
		}
	}

	outFileT.close();
	outFileS.close();
}

void writeFile_query(int begin, int end, int type)
{
	ofstream outFile("query.txt");

	outFile << type << " ";
	outFile << begin << " ";
	outFile << end;

	outFile.close();
}

void createDatabase()
{
	srand(unsigned(time(NULL)));

	int begin, end, type;

	Graph G;
	G.size = rand() % MAX;
	while (G.size < 6)
	{
		G.size = rand() % MAX;
	}

	initGraph(G);
	for (int i = 0; i < G.size; i++)
		for (int j = i + 1; j < G.matrix[i].size(); j++)
			G.matrix[j][i] = G.matrix[i][j] = rand() % 4;
	
	_Common::GoTo(2, 1);
	cout << "Size of map - number of locations: " << G.size << endl;
	
	int line = 3;

	_Common::GoTo(5, line);
	cout << "*. Input the name of start location: ";
	cin >> begin;
	while ((begin < 1) || (begin > G.size))
	{
		cout << "Reselect: ";
		cin >> begin;
		line++;
	}

	_Common::GoTo(5, line + 1);
	cout << "*. Input the name of destination location: ";
	cin >> end;
	while ((end < 1) || (end > G.size))
	{
		cout << "Reselect: ";
		cin >> end;
		line++;
	}

	_Common::GoTo(5, line + 2);
	cout << "*. Choose a transport type : Motorbike(1) or Car(2): ";
	cin >> type;
	while ((type != 1) && (type != 2))
	{
		cout << "Reselect: ";
		cin >> type;
		line++;
	}

	writeFile(G);
	writeFile_query(begin, end, type);
}

//----------------------------------------------------------------------------------------------------------

int** createArray(int num) {
	int** arr = new int* [num];

	for (int i = 0; i < num; i++)
		arr[i] = new int[num];

	return arr;
}
int** readFile(string name_street, string name_transport, int type, int& num) {
	fstream street, transport;
	street.open(name_street, ios::in);
	transport.open(name_transport, ios::in);

	street >> num;
	transport >> num;
	int** arr = createArray(num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int temp_street, temp_transport;

			street >> temp_street;
			transport >> temp_transport;

			if (temp_transport == type || temp_transport == 3) {
				arr[i][j] = temp_street;
			}
			else {
				arr[i][j] = 0;
			}
		}
	}

	street.close();
	transport.close();

	return arr;
}

//----------------------------------------------------------------------------------------------------------

int findMin(vector<int>dist, vector<bool>visited) {
	int min = INT_MAX, index_min = 0;

	for (int i = 0; i < dist.size(); i++) {
		if (!visited[i] && dist[i] <= min) {
			min = dist[i];
			index_min = i;
		}
	}

	return index_min;
}
void Dijkstra(int** arr, int num, int start, int end) {
	vector<int>dist(num, INT_MAX);
	vector<bool>visited(num, false);
	vector<int>parent(num, 0);

	dist[start] = 0;
	parent[start] = 0;

	for (int i = 0; i < num - 1; i++) {
		int u = findMin(dist, visited);
		visited[u] = true;

		for (int j = 0; j < num; j++) {
			if (!visited[j] && arr[u][j] > 0 && dist[u] != INT_MAX
				&& (dist[u] + arr[u][j]) <= dist[j])
			{
				dist[j] = dist[u] + arr[u][j];
				parent[j] = u;
			}
		}
	}

	cout << endl;
	cout << "The minimum total consumption time is " << dist[end] << endl;
	
	cout << endl;
	cout << "Names of streets in turn passing are: ";
	vector<int>result;
	int i = end, x;

	result.push_back(i);
	while (parent[i] != start) {
		x = parent[i];
		result.push_back(x);
		i = parent[x];
	}
	result.push_back(start);

	for (int i = result.size() - 1; i > 0; i--) {
		if (i == result.size() - 1)
			cout << "(" << result[i] + 1 << "," << result[i - 1] + 1 << ") ";
		else
			cout << "--> " << "(" << result[i] + 1 << "," << result[i - 1] + 1 << ") ";
	}
}
void find_direction(string name_query) {
	fstream query;
	int start, end, type, num;

	query.open(name_query, ios::in);
	query >> type >> start >> end;

	int** arr = readFile("street.txt", "transport_type.txt", type, num);

	Dijkstra(arr, num, start - 1, end - 1);

	query.close();
}

//--------------------------------------------------------------------------------------------------
int main() {

	SetConsoleTitle(L"THE SHORTEST PATH - APP.ver2020");
	system("color f0");

	createDatabase();
	cout << endl;

	find_direction("query.txt");
	cout << endl << endl;
	system("pause");

	_Common::Goodbye();
	system("pause");
	return 0;
}