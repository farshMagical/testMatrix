#include "factoryWorker.hpp"
#include "Iworker.hpp"
#include "sThreadWorker.hpp"
#include "mThreadWorker.hpp"

#include <memory>
#include <utility>

std::unique_ptr<WorkerInterface> get_new_worker(WorkerType type){

    if(type == WorkerType::sThread){
        return std::make_unique<SThreadWorker>();
    }
    else if(type == WorkerType::mThread){
        return std::make_unique<MThreadWorker>();
    }
    
    return std::make_unique<SThreadWorker>();
}