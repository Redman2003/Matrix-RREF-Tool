#pragma once
#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix(int rows , int cols);
	~Matrix();
	void print();
	void input();
	void remove();
	void resize(int rows , int cols);
	void echelon(float** matrix, int index,int rows, int columns);
	void rref(int index, float** matrix, int rows, int columns);
	bool scanrow(float* row, int columns);
	float** getMatrix();
	int getRows();
	int getCols();

private:
	int m_rows;
	int m_cols;
	float** matrix;

};

