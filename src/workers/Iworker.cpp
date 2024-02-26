#include "Iworker.hpp"

Matrix Matrix::Transpose() const{
    Matrix matrix;
    matrix.height = width;
    matrix.width = height;
    matrix.data.reserve(data.size());
    for(int raw=0; raw<height; raw++){
        for(int col=0; col<width; col++){
            matrix.data[col * matrix.width + raw] = data[raw*width + col];
        }
    }
    return matrix;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix){
    for(int raw=0; raw<matrix.height; raw++){
        for(int col=0; col<matrix.width; col++){
            out << matrix.data[raw * matrix.width + col] << " ";
        }
        out << std::endl;
    }
    return out;
}
