#include "Matrice.h"
int** newVec(int rowCount, int colCount) {
    int** intern = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i)
        intern[i] = new int[colCount];
    for (size_t i = 0; i < rowCount; i++) {
        for (size_t j = 0; j < colCount; j++) {
            intern[i][j] = 0;
        }
    }
    return intern;
}
Matrice::Matrice(int** vector,int rowCount,int colCount) {
    if (vector != nullptr) {
        intern = newVec(rowCount, colCount);
        for (size_t i = 0; i < rowCount; i++) {
            for (size_t j = 0; j < colCount; j++) {
                intern[i][j] = vector[i][j];
            }
        }
        this->colCount = colCount;
        this->rowCount = rowCount;
    }
    else {
        if (rowCount & colCount) {

        }
    }
}
Matrice* Matrice::operator=(Matrice const& m1) {
    rowCount = m1.rowCount;
    colCount = m1.colCount;
    for (size_t i = 0; i < rowCount; i++) {
        for (size_t j = 0; j < colCount; j++) {
            intern[i][j] = m1.intern[i][j];
        }
    }
    return this;
}
Matrice* Matrice::operator+(Matrice const& m1)
{
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        for (size_t i = 0; i < rowCount; i++) {
            for (size_t j = 0; j < colCount; j++) {
                m1.intern[i][j] += intern[i][j];
            }
        }
    }
    else
    {
        std::cout << "ERR!Matrices sizes are incompatible!\n";
    } 
    return this;
}
Matrice* Matrice::operator-(Matrice const& m1)
{
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        for (size_t i = 0; i < rowCount; i++) {
            for (size_t j = 0; j < colCount; j++) {
                m1.intern[i][j] -= intern[i][j];
            }
        }
    }
    else
    {
        std::cout << "ERR!Matrices sizes are incompatible!\n";
    }
    return this;
}
Matrice Matrice::operator*(Matrice const& m1)
{
    
    if (colCount == m1.rowCount) { 
        int** arr = newVec(rowCount, m1.colCount);
        int k = 0, m = 0;
        for (size_t j = 0; j < colCount; ) {
            for (size_t i = 0; i < rowCount; i++) {
                arr[k][m] += intern[j][i] * m1.intern[i][j];
            }
            m++;
            if (m == m1.colCount) {
                j++;
                m = 0;
                k++;
            }   
        } 
        Matrice mat(arr, rowCount, m1.colCount);


        return mat;
    }
    else 
    {
        std::cout << "ERR!Matrices sizes are incompatible!\n";
    }
}
Matrice::~Matrice() {
    for (int i = 0; i <rowCount; ++i) {
        delete[] intern[i];
    }
    delete[] intern;
} 
void Matrice::FillWithInput() {
    std::cout << "Please, enter values of the matrix in order, there are " << rowCount * colCount << " elements\n";
    for (size_t i = 0; i < rowCount; i++) {
        for (size_t j = 0; j < colCount; j++) {
            std::cin>>intern[i][j];
        }
    }
}void Matrice::Print() {
    std::cout <<  " elements:\n";
    for (size_t i = 0; i < rowCount; i++) {
        for (size_t j = 0; j<colCount; j++) {
            std::cout << intern[i][j];
        }
    }
}