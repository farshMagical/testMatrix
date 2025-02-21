cmake_minimum_required(VERSION 3.22)

project(matrixTest)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

include_directories(src
    src/tests
    src/workers
    src/workers/threadPool)

set(SRC_TESTS src/tests/MatrixTest.cpp
    src/tests/sThreadWorkerTest.cpp
    src/tests/mThreadWorkerTest.cpp
    src/tests/workerTimeTest.cpp)

set(SRC src/main.cpp
    src/workers/sThreadWorker.cpp
    src/workers/mThreadWorker.cpp
    src/workers/testMatrix.cpp
    src/workers/factoryWorker.cpp)

add_executable(${PROJECT_NAME} ${SRC} ${SRC_TESTS})
target_link_libraries(${PROJECT_NAME} gtest)