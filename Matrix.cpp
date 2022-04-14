#include "Matrix.h" 

int** newVec(int rowCount, int colCount) {
    int** intern = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i)
        intern[i] = new int[colCount];
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            intern[i][j] = 0;
        }
    }
    return intern;
}
Matrix::Matrix(int** vector,int rowCount,int colCount) {
    if (vector != nullptr) { 
        vectarr = new vect[rowCount];
        for (int i = 0; i < rowCount; i++) {
            vectarr[i] = vect(vector[i], colCount); 
        }
        this->colCount = colCount;
        this->rowCount = rowCount;
    }
    else {
        if (rowCount & colCount) {
            throw BadData(1);
        }
    }
}
Matrix* Matrix::operator =(Matrix const & m1) {
    rowCount = m1.rowCount;
    colCount = m1.colCount;
    for (int i = 0; i < rowCount; i++) {
        vectarr[i] = vect(m1.vectarr[i]);
    }
    return this;
}
void Matrix::Transform(Matrix& m1)
{
}
Matrix* Matrix::operator+(Matrix  & m1)
{
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                m1.intern[i][j] += intern[i][j];
            }
        }
    }
    else
    {
        throw BadMatrices();//2check
    } 
    return this;
}
 
Matrix::vect Matrix::operator[](int i) const
{
    if (i > -1) {
        if (i < rowCount) {
            return vectarr[i];
        }
        throw Matrix::BadData(0);
        return vectarr[0];
    }
    throw Matrix::BadData(1);
}
Matrix* Matrix::operator-(Matrix  & m1)
{
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                m1.intern[i][j] -= intern[i][j];
            }
        }
    }
    else
    {
        throw BadMatrices();//2check
    }
    return this;
}
Matrix Matrix::operator*(Matrix  & m1)
{
    
    if (colCount == m1.rowCount) { 
        int** arr = newVec(rowCount, m1.colCount);
        for(int h = 0;h<rowCount;h++)
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < m1.colCount; j++) {
                arr[h][i] += intern[i][j] * m1.intern[j][i];
            } 
        } 
        Matrix mat(arr, rowCount, m1.colCount);


        return mat;
    }
    else 
    {
        std::cout << "ERR!Matrixs sizes are incompatible!\n";
    }
}
Matrix::~Matrix() {
    for (int i = 0; i <rowCount; ++i) {
        delete[] intern[i];
    }
    delete[] intern;
} 
void Matrix::FillWithInput() {
    std::cout << "Please, enter values of the matrix in order, there are " << rowCount * colCount << " elements\n";
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            std::cin >> vectarr[i][j];
        }
    }
}void Matrix::Print() const
{
    std::cout <<  " elements:\n";
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j<colCount; j++) {
            std::cout << (*this)[i][j] << (i + 1 == rowCount ? "\n" : " ");
        }
    }
}
Matrix::vect::vect(int* row, int len) {
    intern = new int[len];
    for (int i = 0; i < len; i++) {
        intern[i] = row[i];
    }
    this->len = len;
}

 
Matrix::vect::vect(vect& v) {
    this->len = v.len;
    intern = new int[len];
    for (int i = 0; i < len; i++) {
        intern[i] = v[i];
    }
}