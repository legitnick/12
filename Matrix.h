#pragma once
#include<vector>
#include <algorithm>
#include <climits>
#include <iostream>  
class Matrix
{
	int rowCount,colCount; 
	std::vector<int>* _v;
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
	
	std::vector<int> operator[](int i)const;
	Matrix operator-(Matrix  & m1);
	Matrix operator*(Matrix  & m1);
	Matrix operator+(Matrix   &m1);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& m1); 
	Matrix operator =(Matrix const & m1);
	void Transform(Matrix& m1);
	void FillWithInput();
};

