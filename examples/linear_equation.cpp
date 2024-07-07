#include <vector>

#include "OWL.h"
#include "linalg.h"

int main()
{
    std::vector<double> row1 = {1, 1, 1};
    std::vector<double> row2 = {0, 2, 5};
    std::vector<double> row3 = {2, 5, -1};
    std::vector<std::vector<double>> vec = {row1, row2, row3};
    OWL::MatrixXD matrix = OWL::MatrixXD(vec);

    std::vector<double> vec_for_array = {6, -4, 27};
    OWL::ArrayXD array = OWL::ArrayXD(vec_for_array);

    OWL::ArrayXD result = solve_dgsev(matrix, array);

    result.display();
}
