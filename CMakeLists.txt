cmake_minimum_required(VERSION 3.22)

project(matrixTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")

include_directories(src
    src/workers)

set(SRC src/main.cpp
    src/workers/sThreadWorker.cpp
    src/workers/testMatrix.cpp
    src/workers/factoryWorker.cpp)

add_executable(${PROJECT_NAME} ${SRC})