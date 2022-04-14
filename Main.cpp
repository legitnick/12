#include"Matrix.h"

int main() {
    int rowCount,colCount;
    std::cout << "enter row and column count\n";
    std::cin >> rowCount>>colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];
    for (int i = rowCount-1; i+1; i--) {
        for (int j = colCount-1; j+1; j--) {
            a[i][j] = (1+i) * (1+j);
            std::cout << a[i][j]<<"\n";
        }
    }
    int rand = 5;  

    Matrix mat1(a,rowCount,colCount);
    Matrix mat2(a,rowCount,colCount);
    mat1.Print(); 
    mat2 = mat1;
    mat2.FillWithInput();
    std::cout << "\n";
    mat1 = ( mat1 * mat2);
    mat1.Print(); 
    mat2.Print(); 
    std::cout << typeid(mat1[0]).name() << "\n";
    std::cout << (mat1[0][0]) << "\n";
    std::cout << (mat1 + mat2) << std::endl;
    std::cout << (mat1 - mat2) << std::endl;
}
/*
Develop a class to represent two-dimensional array of integers (matrix) of arbitrary size. Create  constructors and destructors,
overload operations of addition, subtraction and multiplication (according to the rules of working with Matrixs), getting items by index,
as well as stream input and output. Create your own exception classes and generate relevant objects, if it is impossible to perform a particular operation.

Create a separate function that gets reference to an array and pe   rforms actions listed in the table. The function should not be friend or member function.

Index of variant
(from students list)
Rule of a source array transformation 
3 
All elements with null value should be replaced with ones
*/