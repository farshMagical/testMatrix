#include "factoryWorker.hpp"
#include "testMatrix.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <future>

TEST(timeTest, Matrix_Transpose) {
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }

    for(size_t i=0; i<1000; i++){
        matrix.Transpose();    
    }
}

TEST(timeTest, Matrix_Parallel_Transpose) {
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }

    for(size_t i=0; i<1000; i++){
        matrix.ParallelTranspose();    
    }
}

TEST(timeTest, asyn_Transpose) {
    auto worker = get_new_worker(WorkerType::sThread);
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }
    std::vector<std::future<Matrix>> futures;
    futures.reserve(1000);

    for(size_t i=0; i<1000; i++){
        futures.push_back(worker->AsyncProcess(matrix));
    }
    for(auto& future : futures){
        future.get();
    }
}

TEST(timeTest, asyn_withBoundedPool_Transpose) {
    auto worker = get_new_worker(WorkerType::mThread);
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }
    std::vector<std::future<Matrix>> futures;
    futures.reserve(1000);

    for(size_t i=0; i<1000; i++){
        futures.push_back(worker->AsyncProcess(matrix));
    }
    for(auto& future : futures){
        future.get();
    }
}

TEST(timeTest, asyn_Parallel_Transpose) {
    auto worker = get_new_worker(WorkerType::sThread);
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }
    std::vector<std::future<Matrix>> futures;
    futures.reserve(1000);

    // testing::TimeInMillis
    for(size_t i=0; i<1000; i++){
        futures.push_back(worker->AsyncParallelProcess(matrix));
    }
    for(auto& future : futures){
        future.get();
    }
}

TEST(timeTest, asyn_withBoundedPool_Parallel_Transpose) {
    auto worker = get_new_worker(WorkerType::mThread);
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }
    std::vector<std::future<Matrix>> futures;
    futures.reserve(1000);

    for(size_t i=0; i<1000; i++){
        futures.push_back(worker->AsyncParallelProcess(matrix));
    }
    for(auto& future : futures){
        future.get();
    }
}