#pragma once

#include "Iworker.hpp"
// #include "threadPool.hpp"
#include "threadQueue.hpp"
#include <future>
#include <vector>
#include <thread>
#include <atomic>

using Task = std::packaged_task<Matrix(void)>;

class MThreadWorker : public WorkerInterface {
public:
    MThreadWorker();
    ~MThreadWorker();
    std::future<Matrix> AsyncProcess(Matrix& matrix) override;
    std::future<Matrix> AsyncParallelProcess(Matrix& matrix) override;

private:
    std::vector<std::thread> workers;
    ThreadQueue<Task> tasks;
    std::atomic_bool isRunning;
    size_t poolSize = 3;
};

