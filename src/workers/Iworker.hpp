#pragma once

#include <ostream>
#include <vector>
#include <future>
#include <fstream>

struct Matrix {
    std::vector<int> data;
    unsigned width, height;
    Matrix Transpose() const;
};
std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

class WorkerInterface {
public:
    WorkerInterface() = default;

    WorkerInterface(WorkerInterface &&) = delete;
    WorkerInterface(const WorkerInterface &) = delete;
    WorkerInterface & operator=(WorkerInterface &&) = delete;
    WorkerInterface & operator=(const WorkerInterface &) = delete;

    virtual ~WorkerInterface() = default;
    virtual std::future<Matrix> AsyncProcess(Matrix& matrix) = 0;
};

