cmake_minimum_required(VERSION 3.12)
project(OWL_PROJECT)

set(CMAKE_CXX_STANDARD 14)

find_package(LAPACK REQUIRED)
if (LAPACK_FOUND)
    message("LAPACK FOUND.")
endif()
find_package(BLAS REQUIRED)
if (BLAS_FOUND)
    message("BLAS FOUND.")
endif()

# set(TEST_OWL_SOURCES example.cpp)

add_subdirectory(src)
add_subdirectory(gtests)
add_subdirectory(examples)


