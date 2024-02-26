#pragma once

#include "Iworker.hpp"
#include <memory>

enum class WorkerType{
    sThread,
    mThread
};

std::unique_ptr<WorkerInterface> get_new_worker(WorkerType type);