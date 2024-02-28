#include "factoryWorker.hpp"
#include <gtest/gtest.h>

TEST(timeTest, sThread_Transpose) {
    auto worker = get_new_worker(WorkerType::sThread);
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }

    for(size_t i=0; i<1000; i++){
        worker->AsyncProcess(matrix); 
    }
}

TEST(timeTest, mThread_Transpose) {
    auto worker = get_new_worker(WorkerType::mThread);
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }

    for(size_t i=0; i<1000; i++){
        worker->AsyncProcess(matrix); 
    }
}

TEST(timeTest, sThread_Parallel_Transpose) {
    auto worker = get_new_worker(WorkerType::sThread);
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }

    for(size_t i=0; i<1000; i++){
        worker->AsyncParallelProcess(matrix); 
    }
}

TEST(timeTest, mThread_Parallel_Transpose) {
    auto worker = get_new_worker(WorkerType::mThread);
    Matrix matrix;
    matrix.height = 1000;
    matrix.width = 1000;
    for(int i=0; i<matrix.height*matrix.width;i++){
        matrix.data.push_back(i);
    }

    for(size_t i=0; i<1000; i++){
        worker->AsyncParallelProcess(matrix); 
    }
}