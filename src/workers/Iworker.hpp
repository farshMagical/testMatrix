#pragma once

#include "testMatrix.hpp"
#include <ostream>
#include <vector>
#include <future>

class WorkerInterface {
public:
    WorkerInterface() = default;

    WorkerInterface(WorkerInterface &&) = delete;
    WorkerInterface(const WorkerInterface &) = delete;
    WorkerInterface & operator=(WorkerInterface &&) = delete;
    WorkerInterface & operator=(const WorkerInterface &) = delete;

    virtual ~WorkerInterface() = default;
    virtual std::future<Matrix> AsyncProcess(Matrix& matrix) = 0;
    virtual std::future<Matrix> AsyncParallelProcess(Matrix& matrix) = 0;
};

