#pragma once

#include "Iworker.hpp"
#include <future>

class SThreadWorker : public WorkerInterface {
public:
    std::future<Matrix> AsyncProcess(Matrix& matrix) override;
    std::future<Matrix> AsyncParallelProcess(Matrix& matrix) override;
};

