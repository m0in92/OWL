set(OWL_SOURCES OWL.h OWL.cpp)
set(LINALG_SOURCES linalg.h linalg.cpp)

add_library(owl STATIC ${OWL_SOURCES})
add_library(linalg STATIC ${LINALG_SOURCES})
add_library(numerical_methods STATIC numerical_methods.h numerical_methods.cpp)

target_include_directories(owl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(owl ${BLAS_LIBRARIES})

target_include_directories(linalg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(linalg owl)
target_link_libraries(linalg ${LAPACK_LIBRARIES})

target_include_directories(numerical_methods PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


