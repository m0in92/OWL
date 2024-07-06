set(OWL_SOURCES OWL.h OWL.cpp)

add_library(owl STATIC ${OWL_SOURCES})

target_include_directories(owl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(owl ${BLAS_LIBRARIES})