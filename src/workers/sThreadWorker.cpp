#include "sThreadWorker.hpp"

std::future<Matrix> SThreadWorker::AsyncProcess(Matrix& matrix){
    std::future<Matrix> future;
    future = std::async(std::launch::async, &Matrix::Transpose, &matrix);
    return future;
}

std::future<Matrix> SThreadWorker::AsyncParallelProcess(Matrix& matrix){
    std::future<Matrix> future;
    future = std::async(std::launch::async, &Matrix::ParallelTranspose, &matrix);
    return future;
}