#pragma once

#include <vector>
#include <fstream>

struct Matrix {
    std::vector<int> data; // инкапсулировал бы, чтобы не устроить гонку
    unsigned width, height;// при параллельном транспонировании
    Matrix Transpose() const;
    Matrix ParallelTranspose() const;

private:
    Matrix CopySizeToTranspose() const;
    void WriteTransposePart(Matrix& mtx,
                            const size_t startPosRaw, 
                            const size_t countRaw) const;
};

std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
bool operator==(const Matrix& lhs, const Matrix& rhs);

