#include "matrix.hpp"
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace mat
{
    matrix::matrix(int rows, int cols): rows(rows), cols(cols)
    {
        if(rows<=0 || cols<=0)
            throw std::invalid_argument("rows and cols of the matrix must be over 0");
        data.resize(rows, std::vector<double>(cols, 0.0));
    }

    matrix::matrix(int rows, int cols, double value): rows(rows), cols(cols)
    {
        if(rows<=0 || cols<=0)
            throw std::invalid_argument("rows and cols of the matrix must be over 0");
        data.resize(rows, std::vector<double>(cols, value));
    }

    matrix::matrix(int rows, int cols, double **list): rows(rows), cols(cols)
    {
        if(rows<=0 || cols<=0)
            throw std::invalid_argument("rows and cols of the matrix must be over 0");
        data.resize(rows, std::vector<double>(cols));
        for(int a=0; a<rows; a++)
            for(int b=0; b<cols; b++)
                data[a][b] = list[a][b];
    }

    matrix::matrix(std::initializer_list<std::initializer_list<double>> list)
    {
        rows = (int)list.size();
        cols = (int)list.begin()->size();
        if(rows == 0 || cols ==0)
            throw std::invalid_argument("the matirx can't be empty");
        
        data.resize(rows, std::vector<double>(cols));
        
        int x=0;
        for(std::initializer_list<double> row : list)
        {
            if((int)row.size() != cols)
                throw std::invalid_argument("all the cols must have same amount of element");
            int y=0;
            for(double col : row)
            {   
                data[x][y] = col;
                y++;
            }
            x++;
        }
    }

    matrix::~matrix() {}

    double matrix::operator()(int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw std::out_of_range("");
        return data[i][j];
    }

    double matrix::determinant()
    {
        if(rows != cols)
            throw 
    }

}