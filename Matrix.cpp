#include "Matrix.h" 

int** newVec(int rowCount, int colCount) {
    int** intern = new int* [rowCount]; 
    for (int i = 0; i < rowCount; i++) {
        intern[i] = new int[colCount];
        for (int j = 0; j < colCount; j++) {
            intern[i][j] = 0;
        }
    }
    return intern;
}
Matrix::Matrix(int** vector,int rowCount,int colCount) {
    if (vector != nullptr) { 

        this->colCount = colCount;
        this->rowCount = rowCount; 
         //the adress shouldn't change
            head = vectarr = new vect();
        for (int i = 0; i < rowCount; i++) {
            InsertVect(vector[i],colCount,vectarr);
            vectarr++;
        }
        vectarr = head;
    }
    else {
        throw BadPtr();
    }
}
Matrix& Matrix::operator =(Matrix const & m1) {
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        rowCount = m1.rowCount;
        colCount = m1.colCount;
        std::copy(m1.vectarr, m1.vectarr + m1.rowCount, vectarr);
    }
    else
    {
        throw BadMatrices();//2check
    }
    
    return *this;
}
void Matrix::Transform(Matrix& m1)
{
}
Matrix Matrix::operator+(Matrix  & m1)
{
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                m1.vectarr[i].intern[j] += vectarr[i][j];
            }
        }
    }
    else
    {
        throw BadMatrices();//2check
    } 
    return m1;
} 
std::ostream& operator<<(std::ostream& os, const Matrix& m1)
{   
    std::cout << " elements:\n";
    for (int i = 0; i < m1.rowCount; i++) {
        for (int j = 0; j < m1.colCount; j++) {
            os << (m1[i][j])<<" ";
        }
        os << "\n";
    }
    return os;
}
 
Matrix::vect& Matrix::operator[](int i)  const
{
    if (i > -1) {
        if (i < rowCount) {
            return vectarr[i];
        }
        throw Matrix::BadData(0); 
    }
    throw Matrix::BadData(1);
}
Matrix Matrix::operator-(Matrix  & m1)
{
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                m1[i].intern[j] -= vectarr[i][j];
            }
        }
    }
    else
    {
        throw BadMatrices(); //incompatible matrices
    }
    return m1;
}
Matrix Matrix::operator*(Matrix  & m1)
{
        int** res = newVec(rowCount, colCount);
    if (rowCount == m1.rowCount && colCount == m1.colCount) {
        for (int h = 0; h < rowCount; h++)
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < m1.colCount; j++) {
                    res[h][i] += m1[h][j] * vectarr[j][i];
                }
            }

    }
    else
    {
        throw BadMatrices(); 
    } 
    Matrix m2(res, rowCount, colCount);

        return m2; 
}
Matrix::~Matrix() {
    for (int i = 1; i <rowCount; ++i) {
        vectarr[i].~vect();
    }
    delete[] vectarr;
} 
void Matrix::FillWithInput() {
    std::cout << "Please, enter values of the matrix in order, there are " << rowCount * colCount << " elements\n";
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            std::cin >> vectarr[i].intern[j];
        }
    }
} 
Matrix::vect::vect(int* row, int len) {
    this->intern = new int[len];

    std::copy(row, row+ len, intern);
    this->len = len;
}
void Matrix::InsertVect(int* row, int len, vect* v) {
    vect* v1 = new vect();
    v1->intern = new int[len];

    std::copy(row, row + len, v1->intern);
    v1->len = len;
    std::copy(v1, v1 + len, v); 
}
 
Matrix::vect::vect(vect& v) {
    this->len = v.len;
    intern = new int[len];
    std::copy(v.intern, v.intern+ len, intern);
}