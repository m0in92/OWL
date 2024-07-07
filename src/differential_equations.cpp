#include <cmath>
#include <vector>

#include "differential_equations.h"
#include "linalg.h"

namespace one_dimensional
{
    OWL::ArrayXD poisson_equation(OWL::ArrayXD linesegment, double (*func)(double), double bc1, double bc2)
    {
        int SIZE = linesegment.getArray().size();
        double h = linesegment[1] - linesegment[0];

        // create the rhs col vector
        std::vector<double> rhs_;
        rhs_.push_back(bc1);
        for (int i = 0; i < linesegment.getArrayLength() - 1; i++)
        {
            rhs_.push_back(func(linesegment[i]));
        }
        rhs_.push_back(bc2);
        OWL::ArrayXD rhs = (std::pow(h, 2)) * rhs_;

        rhs.display();

        // Create the lhs matrix
        OWL::MatrixXD lhs_matrix = OWL::diff_second_order(SIZE);
        lhs_matrix[0][0] = 1;
        lhs_matrix[0][1] = 0;
        lhs_matrix[SIZE-1][SIZE-1] = 1;
        lhs_matrix[SIZE-1][SIZE - 2] = 0;

        // solve
        OWL::ArrayXD result = solve_dgsev(lhs_matrix, rhs);
        return result;
    }
}
