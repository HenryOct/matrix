#include "matrix.hpp"
#include <iostream>

int main()
{
    mat::matrix m1(3,3,0.0);
    
    double row0[] = {1, 2, 3};
    double row1[] = {4, 5, 6};
    double row2[] = {7, 8, 9};
    double* m2[3] = {row0, row1, row2};
    mat::matrix m3(3, 3, m2);
    
    mat::matrix m4 = {{5,4,6,3,6,4,3,2,5}, 
                      {6,4,8,3,6,3,4,7,2}, 
                      {9,1,1,4,7,2,4,6,1}, 
                      {3,3,6,6,3,5,2,5,9}, 
                      {4,6,2,5,3,2,5,9,6},
                      {3,6,3,2,5,7,7,4,4}, 
                      {3,6,3,7,4,5,3,6,7},
                      {6,1,2,2,4,6,2,4,3}, 
                      {3,6,3,5,6,3,2,5,6}};

    double det = m4.determinant();
    
    std::cout << "m1(1,1) = " << m1(1,1) << "\n";
    std::cout << "m3(2,2) = " << m3(2,2) << "\n";
    std::cout << "m4(9,9) = " << m4(9,9) << "\n";
    std::cout << "determinant of m4 is:" << det << "\n";
    return 0;
}