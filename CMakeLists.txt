cmake_minimum_required(VERSION 3.23)
project(OWL_PROJECT)

set(CMAKE_CXX_STANDARD 14)

set(TEST_OWL_SOURCES main.cpp)

add_subdirectory(src)
add_subdirectory(gtests)

add_executable(test_owl ${TEST_OWL_SOURCES})

target_link_libraries(test_owl owl)
