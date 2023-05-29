#include <iostream>
#include "Matrix.h"

using namespace std;



int main() {

	int m;
	int n;

	cout << "How many rows do you want in the matrix" << endl;
	cin >> m;
	cout << "How many columns do you want in the matrix" << endl;
	cin >> n;
	Matrix matrix(m, n);
	cout << endl;

	string input;
	cout << "Please enter an option" << endl;
	cout << "(i) input an entry/entries" << endl;
	cout << "(p) print matrix" << endl;
	cout << "(q) quit program" << endl;
	cout << "(s) resize matrix" << endl;
	cout << "(r) row reduce matrix" << endl;
	cout << endl;
	cin >> input;
	cout << endl;
	while (input != "q")
	{
		if (input == "p")
		{
			matrix.print();
			cout << endl;
		}
		else if (input == "i")
		{
			matrix.input();
			cout << endl;
		}
		else if (input == "s")
		{
			cout << "How many rows do you want in the matrix" << endl;
			cin >> m;
			cout << "How many columns do you want in the matrix" << endl;
			cin >> n;
			matrix.resize(m, n);
			cout << endl;
		}
		else if(input == "r")
		{
			int bottom_row = matrix.getRows() - 1;
			matrix.echelon(matrix.getMatrix(), 0, matrix.getRows(), matrix.getCols());
			matrix.rref(bottom_row,matrix.getMatrix(),matrix.getRows(),matrix.getCols());
		}
		cout << "Please enter an option" << endl;
		cout << "(i) input an entry/entries" << endl;
		cout << "(p) print matrix" << endl;
		cout << "(q) quit program" << endl;
		cout << "(s) resize matrix" << endl;
		cout << "(r) row reduce matrix" << endl;
		cout << endl;
		cin >> input;
		cout << endl;
	}

	return 0;
}