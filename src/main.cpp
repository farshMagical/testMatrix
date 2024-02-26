#include "Iworker.hpp"
#include "factoryWorker.hpp"

#include <iostream>





int main(){
auto worker = get_new_worker(WorkerType::mThread);
Matrix mtx {
    .data = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    },
    .width = 3,
    .height = 3
};
std::cout << mtx << std::endl;
std::cout << "T\n" << mtx.Transpose() << std::endl;

mtx = Matrix {
    .data = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
        4, 5, 6, 7, 8, 9, 0, 0, 0,
        7, 8, 9, 10,11,12,13,14,15
    },
    .width = 9,
    .height = 3
};
std::cout << mtx << std::endl;
std::cout << "T\n" << mtx.Transpose() << std::endl;

mtx = Matrix {
    .data = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        10,11,12,
        13,14,15,
        16,17,18,
        19,20,21
    },
    .width = 3,
    .height = 7
};
std::cout << mtx << std::endl;
std::cout << "T\n" << mtx.Transpose() << std::endl;


// auto future = worker->AsyncProcess(mtx);
/*
Ожидаем, что future.get() вернет нам вот такой объект
Matrix {
.data = {
1, 4,
2, 5,
3, 6
},
.width = 2,
.height = 3
}
*/
    return 0;
}