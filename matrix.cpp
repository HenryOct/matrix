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
        if (i < 0 || i > rows || j < 0 || j > cols)
            throw std::out_of_range("");
        return data[i-1][j-1];
    }

    double matrix::determinant()
    {
        if(rows != cols)
            throw std::logic_error("rows and cols of the matrix must be equal to have a determinant");
        if(rows == 0 || cols == 0)
            throw std::logic_error("empty matrix has no determinant");
        
        std::vector<std::vector<double>> mat = data;
        double det = 1.0;
        double epsilon = 1e-10;
        
        for(int i=0; i<rows; i++)
        {
            double main_val = std::abs(mat[i][i]);
            int pivot_row = i;
            for(int j=i+1; j<rows; j++)
            {
                if (std::abs(mat[j][i]) > main_val)
                {
                    main_val = std::abs(mat[j][i]);
                    pivot_row = j;
                }
            }

            if(main_val <= epsilon)
                return 0.0;
            
            if(pivot_row != i)
            {
                std::swap(mat[i], mat[pivot_row]);
                det = -det;
            }

            det *= mat[i][i];

            double pivot = mat[i][i];
            for(int j=i; j<cols; j++)
                mat[i][j] /= pivot;

            for (int k = i + 1; k < rows; k++)
            {
                double factor = mat[k][i];
                for (int j = i; j < cols; j++)
                    mat[k][j] -= factor * mat[i][j];
            }
        }

        return det;
    }
}