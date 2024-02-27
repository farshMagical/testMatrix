#include "testMatrix.hpp"
#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

Matrix Matrix::Transpose() const{
    Matrix matrix = CopySizeToTranspose();
    for(unsigned int raw=0; raw<height; raw++){
        for(unsigned int col=0; col<width; col++){
            matrix.data[col * matrix.width + raw] = data[raw*width + col];
        }
    }
    return matrix;
}

Matrix Matrix::ParallelTranspose() const{
    size_t parts = 2;

    Matrix matrix = CopySizeToTranspose();
    std::vector<std::future<void>> futures;
    size_t partSize = height/parts; //count of col in part
    size_t startPos;

    for(size_t part=0; part < parts; part++){
        startPos = partSize * part;
        if(part+1 == parts){
            partSize = height - startPos;
        }
        futures.push_back(std::async( std::launch::async,
                [this,&matrix,startPos,partSize](){
                    this->WriteTransposePart(matrix, startPos, partSize);
                }));
    }
    for(auto& future : futures){
        future.get();
    }
    return matrix;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix){
    for(unsigned int raw=0; raw<matrix.height; raw++){
        for(unsigned int col=0; col<matrix.width; col++){
            out << matrix.data[raw * matrix.width + col] << " ";
        }
        out << std::endl;
    }
    return out;
}

Matrix Matrix::CopySizeToTranspose() const{
    Matrix matrix;
    matrix.height = width;
    matrix.width = height;
    matrix.data.reserve(data.size());
    return matrix;
}

void Matrix::WriteTransposePart(Matrix& mtx, const size_t startPosRaw, const size_t countRaw) const{
    for(unsigned int raw=startPosRaw; raw<startPosRaw+countRaw; raw++){
        for(unsigned int col=0; col<width; col++){
            mtx.data[col * mtx.width + raw] = data[raw*width + col];
        }
    }
}

bool operator==(const Matrix& lhs, const Matrix& rhs){
    return std::equal(lhs.data.begin(), lhs.data.end(), rhs.data.begin())
        && lhs.height==rhs.height 
        && lhs.width==rhs.width;
}