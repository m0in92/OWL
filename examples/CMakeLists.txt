add_executable(array_addition array_addition.cpp)
target_link_libraries(array_addition owl)

add_executable(matrix_multiplication matrix_multiplication.cpp)
target_link_libraries(matrix_multiplication owl)

add_executable(tri_mat_mult tridiagonal_matrix_multiplication.cpp)
target_link_libraries(tri_mat_mult owl)

add_executable(differentiation differentiation.cpp)
target_link_libraries(differentiation owl)

add_executable(linear_equation linear_equation.cpp)
target_link_libraries(linear_equation owl)

add_executable(linear_equation_2 linear_equations_2.cpp)
target_link_libraries(linear_equation_2 owl)

add_executable(first_order_finite_differences first_order_finite_differences.cpp)
target_link_libraries(first_order_finite_differences owl)

add_executable(poisson_equation_1D poisson_equation_1D.cpp)
target_link_libraries(poisson_equation_1D owl)

add_executable(diff diff.cpp)
target_link_libraries(diff owl)

add_executable(radial_diffusion radial_diffusion.cpp)
target_link_libraries(radial_diffusion owl)
