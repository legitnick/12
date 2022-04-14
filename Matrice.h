#pragma once
#include<vector>
#include <iostream>
class Matrice
{
	int rowCount,colCount;
	int** intern;
public:
	Matrice(int** vector, int rowCount, int colCount);
	~Matrice();

	Matrice* operator-(Matrice const& m1);
	Matrice operator*(Matrice const& m1);
	Matrice* operator+(Matrice const &m1);
	void operator[](Matrice* m1);
	Matrice* operator=(Matrice const& m1);
	void Print();
	void FillWithInput();
};

