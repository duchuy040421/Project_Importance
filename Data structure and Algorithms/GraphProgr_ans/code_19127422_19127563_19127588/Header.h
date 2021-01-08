#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stack>
#include <ctime>
#include <sstream>
#include "Windows.h"
using namespace std;

#define MAX 20;

struct Graph {
	int size;
	vector<vector<int>> matrix;
};

class _Common
{
public:
    static void GoTo(SHORT, SHORT);
    static void Goodbye();
};

//-----------------------------------------------------------------------------

void initGraph(Graph& g);

void writeFile(Graph G);

void writeFile_query(int begin, int end, int type);

void createDatabase();

//-----------------------------------------------------------------------------

int** createArray(int num);
int** readFile(string name_street, string name_transport, int type, int& num);

//-----------------------------------------------------------------------------

int findMin(vector<int>dist, vector<bool>visited);
void Dijkstra(int** arr, int num, int start, int end);

void find_direction(string name_query);