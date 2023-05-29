#include "Matrix.h"
#include <string>


Matrix::Matrix(int rows, int cols) 
{
	m_rows = rows;
	m_cols = cols;
	matrix = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new float[cols]();
	}
}

Matrix::~Matrix()
{
	remove();
}

void Matrix::print()
{

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

void Matrix::resize(int rows, int cols) 
{
	remove();
	m_rows = rows;
	m_cols = cols;
	matrix = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new float[cols]();
	}
	
}


void Matrix::remove() 
{
	for (int i = 0; i < m_rows; i++)
	{
		delete matrix[i];
	}
	delete matrix;
}




void Matrix :: input() 
{
	int row;
	int col;
	string input;
	while (input != "q")
	{
		cout << "Enter a row (Press q to exit)" << endl;
		cin >> input;
		cout << endl;
		try
		{
			row = stoi(input);
			if (row > m_rows)
			{
				cout << "Enter a valid row number" << endl;
				cout << endl;
			}
			else
			{
				bool valid_col = false;
				while (!valid_col)
				{
					cout << "Enter a column" << endl;
					cin >> input;
					cout << endl;
					try
					{
						col = stoi(input);
						if (col > m_cols)
						{
							cout << "Enter a valid column number" << endl;
							cout << endl;
						}
						else
						{
							bool valid_input = false;
							while (!valid_input)
							{
								cout << "Enter a number" << endl;
								cin >> input;
								cout << endl;
								try
								{
									float entry = stof(input);
									matrix[row][col] = entry;
									cout << endl;
									valid_input = true;
								}
								catch (const std::invalid_argument&)
								{
									cout << "Enter a number please" << endl;
									cout << endl;
								}
								;
							}
							valid_col = true;
						}
					}
					catch (const std::invalid_argument& ia)
					{
						cout << "Enter a number please" << endl;
						cout << endl;
					}
				}
				
			}
		}
		catch (std::invalid_argument& ia)
		{
			if (input != "q") {
				cout << "Enter a number please" << endl;
				cout << endl;
			}
		}
		
	}

}

void Matrix::echelon(float** matrix, int index, int rows, int columns) 
{
	if (index + 1 == rows)
	{
		if (matrix[index][index] != 0)
		{
			float base = matrix[index][index];
			for (int i = index; i < columns; i++)
			{
				matrix[index][i] = matrix[index][i] / base;
			}
		}
		return;
	}
	float pivot = matrix[index][index];

	for (int i = index; i < columns; i++)
	{
		if (matrix[index][i] != 0)
		{
			matrix[index][i] = matrix[index][i] / pivot;
		}
	}
	for (int i = index + 1; i < rows; i++)
	{
		float lower_entry = matrix[i][index];
		for (int j = index; j < columns; j++)
		{
			matrix[i][j] = (-lower_entry * matrix[index][j]) + matrix[i][j];
		}
	}
	bool zerorow = scanrow(matrix[index + 1], columns);

	if (zerorow)
	{
		for (int i = index + 1; i < rows; i++)
		{
			if (matrix[i][index + 1] != 0)
			{
				float* nonzero = matrix[i];
				float* zerorow = matrix[index + 1];
				matrix[index + 1] = nonzero;
				matrix[i] = zerorow;
			}
		}
	}
	echelon(matrix, index + 1, rows, columns);
}


void Matrix::rref(int index, float** matrix, int rows, int columns)
{
	if (index == 0)
	{
		return;
	}
	for (int i = index; i > 0; i--)
	{
		float upper_entry = matrix[i - 1][index];
		for (int j = index; j < columns; j++)
		{
			matrix[i - 1][j] = (-upper_entry * matrix[index][j]) + matrix[i - 1][j];
		}
	}
	rref(index - 1, matrix, rows, columns);
}

bool Matrix::scanrow(float* row, int columns) 
{

	int count = 0;
	for (int i = 0; i < columns; i++)
	{
		if (row[i] == 0)
		{
			count++;
		}
	}
	if (count == columns)
	{
		return true;
	}
	return false;
}

float ** Matrix::getMatrix()
{
	return matrix;
}

int Matrix::getRows() 
{
	return m_rows;
}

int Matrix::getCols() 
{
	return m_cols;
}