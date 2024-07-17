set(OWL_SOURCES OWL.h OWL.cpp)
set(LINALG_SOURCES linalg.h linalg.cpp)
set(NUMERICAL_METHOD_SOURCES numerical_methods.h numerical_methods.cpp)
set(DIFFERENTIAL_EQUATION_SOURCES differential_equations.h differential_equations.cpp)

add_library(owl STATIC ${OWL_SOURCES} ${LINALG_SOURCES} ${NUMERICAL_METHOD_SOURCES} ${DIFFERENTIAL_EQUATION_SOURCES})
target_include_directories(owl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(owl ${BLAS_LIBRARIES} ${LAPACK_SOURCEs})



