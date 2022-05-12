#include "Matrix.h" 
void deleteVec(int **arr,int rowCount){
	for(int i = 0;i< rowCount;i++){
		delete arr[i]; 
	}
	delete arr;
}
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
        for (int i = 0; i < rowCount; i++) {
	    _v[i]= std::vector<int>(vector[i],vector[i]+colCount);
	   } 
	    //InsertVect(vector[i],colCount,vectarr);
        }
    
    else {
        throw BadPtr();
    }
}
Matrix Matrix::operator =(Matrix const & m1) {
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        rowCount = m1.rowCount;
        colCount = m1.colCount;
        std::copy(m1._v->begin(), m1._v->begin() + rowCount, _v);
    }
    else
    {
        throw BadMatrices();//2check
    }
    
    return m1;
}
void Matrix::Transform(Matrix& m1)
{
}
Matrix Matrix::operator+(Matrix  & m1)
{
    if (rowCount == m1.rowCount && colCount == m1.colCount) {

        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                m1[i][j] += _v[i][j];
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
            os << m1._v[i][j]<<" ";
        }
        os << "\n";
    }
    return os;
}
 
std::vector<int> Matrix::operator[](int i)  const
{
    if (i > -1) {
        if (i < rowCount) {
            return _v[i]; 
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
                m1[i][j] -= _v[i][j];
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

    if (rowCount == m1.rowCount && colCount == m1.colCount) {
        
	int arr**= newVec(colCount,rowCount);
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < m1.colCount; j++) {
                }
            }
	    
    Matrix m2(arr, rowCount, colCount);
    deleteVec(arr,rowCount); 
    return m2; 

    }
    else
    {
        throw BadMatrices(); 
    } 
}
Matrix::~Matrix() {
    
    delete _v;
} 
void Matrix::FillWithInput() {
    std::cout << "Please, enter values of the matrix in order, there are " << rowCount * colCount << " elements\n";
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            std::cin >> _v[i][j];
        }
	std::cout<<std::endl;
    }
} 

