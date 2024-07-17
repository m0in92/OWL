cmake_minimum_required(VERSION 3.12)

project(GTests)

enable_testing()

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include lib/googletest)

add_executable(GTest_run test_ArrayXD.cpp test_ArrayXD_operatoroverloads.cpp test_customArrays.cpp
        test_mathOperations.cpp test_MatrixXD.cpp test_MatrixXD_operatorOverloads.cpp test_numerical_methods.cpp
        test_differential_equations.cpp)

target_link_libraries(GTest_run gtest gtest_main)
target_link_libraries(GTest_run owl)