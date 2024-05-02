cmake_minimum_required(VERSION 3.12)
project(OWL_PROJECT)

set(CMAKE_CXX_STANDARD 14)

set(TEST_OWL_SOURCES example.cpp)

add_subdirectory(src)
add_subdirectory(gtests)

add_executable(example ${TEST_OWL_SOURCES})

target_link_libraries(example owl)
