#include "matrix.hpp"
#include <iostream>

int main()
{
    mat::matrix m1(3,3,0.0);
    
    // 方法1：使用指针数组（正确的方式）
    double row0[] = {1, 2, 3};
    double row1[] = {4, 5, 6};
    double row2[] = {7, 8, 9};
    double* m2[3] = {row0, row1, row2};
    mat::matrix m3(3, 3, m2);
    
    // 方法2：使用 initializer_list（推荐！）
    mat::matrix m4 = {{3,4,5}, {6,7,8}, {9,10,11}};
    
    std::cout << "m1(0,0) = " << m1(0,0) << "\n";
    std::cout << "m3(2,2) = " << m3(2,2) << "\n";
    std::cout << "m4(2,2) = " << m4(2,2) << "\n";
    return 0;
}