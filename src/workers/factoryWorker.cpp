#include "factoryWorker.hpp"
#include "Iworker.hpp"
#include "sThreadWorker.hpp"

#include <memory>
#include <utility>

std::unique_ptr<WorkerInterface> get_new_worker(WorkerType type){

    if(type == WorkerType::sThread){
        return std::make_unique<SThreadWorker>();
    }
    
    return std::make_unique<SThreadWorker>();
}