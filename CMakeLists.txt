cmake_minimum_required(VERSION 3.12)
project(OWL_PROJECT)

set(CMAKE_CXX_STANDARD 14)

# include(FindBLAS)
find_package(BLAS REQUIRED)

# set(TEST_OWL_SOURCES example.cpp)

add_subdirectory(src)
add_subdirectory(gtests)
add_subdirectory(examples)


