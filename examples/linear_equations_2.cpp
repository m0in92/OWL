/**
 * @file linear_equations_2.cpp
 * @author your name (you@domain.com)
 * @brief This contains an example of solving a system of equations after application of numerical finite differences on
 *                      u'' + 2 u' - 3u = 9x
 * This example was obtained from https://wiki.math.ntnu.no/_media/tma4130/2020h/pde.pdf
 * @version 0.1
 * @date 2024-07-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>

#include "owl.h"
#include "linalg.h"

int main()
{
    std::vector<double> row1 = {-2.1875, 1.25, 0};
    std::vector<double> row2 = {0.75, -2.1875, 1.25};
    std::vector<double> row3 = {0, 0.75, -2.1875};
    std::vector<std::vector<double>> vec = {row1, row2, row3};
    OWL::MatrixXD matrix = OWL::MatrixXD(vec);

    std::vector<double> vec_for_array = {0.140625-0.75, 0.28125, 0.421875-1.25*0.48635073};
    OWL::ArrayXD array = OWL::ArrayXD(vec_for_array);
    
    OWL::ArrayXD result = solve_dgsev(matrix, array);
    result.display();
    
    return 0;
}