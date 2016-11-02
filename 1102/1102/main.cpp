#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class VectorND
{
public:
	int size, temp=0;
	int *arr = nullptr;

	VectorND()
	{

	}

	VectorND(const int& input)
	{
		size = input;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i]= rand() % 10+1;
	}
	int operator*(const VectorND& vec)
	{
		int answer = 0;
		for (int i = 0; i < vec.size; i++) {
			answer += this->arr[i] * vec.arr[i];
		}
		return answer;
	}

	//friend ostream& operator<<(ostream& os, const VectorND& vec);
};

class MatrixMxN
{
public:
	int size_r;
	int size_c;
	VectorND *matrix;

	MatrixMxN(const int&row, const int&col)
	{
		size_r = row;
		size_c = col;
		matrix = new VectorND[size_r];

		for (int i = 0; i < size_r; i++) {
			VectorND v1(size_c);
			matrix[i] = v1;
		}
	}
	VectorND operator*(const VectorND& vec)
	{
		VectorND v2(size_r);
		for (int i = 0; i < size_r; i++) {
			v2.arr[i] = matrix[i] * vec;
		}
		return v2;
	}
};

ostream& operator<<(ostream& os, const VectorND& vec)
{
	for (int i = 0; i < vec.size; i++)
		os << vec.arr[i] << " ";
	return os;
}

ostream& operator<<(ostream& os, const MatrixMxN& mat)
{
	for (int i = 0; i < mat.size_r; i++)
		os << mat.matrix[i] << " " << endl;
	return os;
}

void main()
{
	srand((unsigned)time(NULL));

	cout << "Input your VectorND : 1 * 4" << endl;
	VectorND v(4);
	cout << "Input your MatrixMxN : 5 * 4" << endl;
	MatrixMxN m(5, 4);
	//m.size_r = row = 5

	VectorND f(5);
	f = m*v;

	f.temp = m.size_r;

	cout << "VertorND value" << endl;
	cout << v << endl;
	cout << "MatrixMxN value" << endl;
	cout << m << endl;
	cout << "Result value" << endl;
	cout << f << endl;
}