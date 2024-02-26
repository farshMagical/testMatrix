#pragma once

#include "Iworker.hpp"

class SThreadWorker : public WorkerInterface {
public:
    std::future<Matrix> AsyncProcess(Matrix& matrix) override;

private:
    
};

