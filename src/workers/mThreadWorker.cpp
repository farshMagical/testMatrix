#include "mThreadWorker.hpp"
#include <iostream>

MThreadWorker::MThreadWorker(){
    isRunning = true;
    for(size_t i=0; i<poolSize; i++){
        workers.emplace_back([this](){
            while(isRunning){
                auto task = tasks.Take(); 
                if(!isRunning){
                    break;
                }
                task();
            }
        });
    }
}

MThreadWorker::~MThreadWorker(){
    isRunning = false;
    for(int i=0; i<workers.size(); i++){
        tasks.Put(Task());
    }
    for(auto& worker : workers){
        if(worker.joinable()){
            worker.join();
        }
    }
}

std::future<Matrix> MThreadWorker::AsyncProcess(Matrix& matrix){
    Task t ([&matrix](){
        return matrix.Transpose();
    });
    std::future<Matrix> future = t.get_future();
    tasks.Put(std::move(t));
    return future;
}

std::future<Matrix> MThreadWorker::AsyncParallelProcess(Matrix& matrix){
    Task t ([&matrix](){
        return matrix.Transpose();
    });
    std::future<Matrix> future = t.get_future();
    tasks.Put(std::move(t));
    return future;
}