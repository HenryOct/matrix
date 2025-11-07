#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <initializer_list>

namespace mat
{
    class matrix
    {
        private:
            int rows, cols;
            std::vector<std::vector<double>> data;

        public:
            matrix(int i, int j);
            matrix(int i, int j, double value);
            matrix(int i, int j, double** data);
            matrix(std::initializer_list<std::initializer_list<double>> list);

            matrix(const matrix &other): rows(other.rows), cols(other.cols), data(other.data) {}
            ~matrix();

            double operator() (int i, int j);
            int GetRows() {return rows;}
            int GetCols() {return cols;}

        public:
           double determinant();
    };
}

#endif