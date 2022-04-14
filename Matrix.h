#pragma once
#include<vector>
#include <iostream>  
class Matrix
{
	struct vect {
		int* intern;
		int len;
		int operator[](int i) {
			if (i > -1) {
				if (i < len) {
					return intern[i];
				}
				throw Matrix::BadData(0);
				return INT_MIN;
			}
			throw Matrix::BadData(1);
			return INT_MIN;
		}
		void addArr(int m) { intern = new int[m]; }
		vect(int* row, int len);
		vect() {};

		vect(vect& v);
	};
	int rowCount,colCount;
	int** intern;
	vect* vectarr;
public:
	Matrix(int** vector, int rowCount, int colCount);
	~Matrix();
	struct BadMatrices{};
	struct BadPtr{};
	struct BadData{
		void getType() { std::cout << (under ? "underflow\n" : "overflow\n"); }
		BadData(bool type) {
			under = type;
		}
	private:
		bool under;

	};

	Matrix* operator-(Matrix  & m1);
	Matrix operator*(Matrix  & m1);
	Matrix* operator+(Matrix   &m1);
	vect  operator[](int i)const;	
	Matrix* operator =(Matrix const & m1);
	void Transform(Matrix& m1);
	void Print() const;
	void FillWithInput();
};

