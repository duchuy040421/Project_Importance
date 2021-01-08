#include"Function.h"

int main()
{
	int** a, ** b, ** c, n, m;

	cout << "Insert n,m" << endl;
	cin >> n >> m;

	a = generateMatrix(n, m);
	output(a, n, m);
	c = tranposeMatrix(a, n, m);

	cout << "Insert matrix b:" << endl;
	cout << "Sum of 2 matrix: " << endl;

	//insert maxtrix b;
	b = generateMatrix(n, m);		
	c = sumMatrices(a, b, n, m);
	output(c, n, m);

	cout << "ascending order of sums of elements in each row in matrix a." << endl;
	a = rowAscendingMatrix(a, n, m);
	output(a, n, m);

	cout << "Remove column matrix a:" << endl;	
	//example remove column has position 1;
	removeColumn(a, 3, n, m);		
	output(a, n, m - 1);
}