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
        for (int i = 1; i < (SIZE - 1); i++)
        {
            rhs_.push_back(func(linesegment[i]));
        }
        rhs_.push_back(bc2);
        OWL::ArrayXD rhs = (std::pow(h, 2)) * rhs_;

        // Create the lhs matrix
        // OWL::MatrixXD lhs_matrix = OWL::diff_second_order(SIZE);
        // lhs_matrix[0][0] = 1;
        // lhs_matrix[0][1] = 0;
        // lhs_matrix[SIZE-1][SIZE-1] = 1;
        // lhs_matrix[SIZE-1][SIZE - 2] = 0;
        OWL::ArrayXD diag = -2 * OWL::Ones(SIZE);
        diag[0] = 1;
        diag[SIZE - 1] = 1;
        OWL::ArrayXD udiag = OWL::Ones(SIZE - 1);
        OWL::ArrayXD ldiag = udiag;
        udiag[0] = 0;
        ldiag[SIZE - 2] = 0;

        // solve
        // OWL::ArrayXD result = solve_dgsev(lhs_matrix, rhs);
        OWL::ArrayXD result = solve_dgtsv(ldiag, diag, udiag, rhs);
        return result;
    }

    std::vector<double> poisson_equation(double A, double B, double Nx, double (*func)(double), double bc1, double bc2)
    {
        OWL::ArrayXD array = OWL::LinSpaced(A, B, Nx);
        OWL::ArrayXD result = poisson_equation(array, func, bc1, bc2);

        return result.getArray();
    }

    OWL::MatrixXD heat_equation(OWL::ArrayXD geometry, double (*func)(double), double alpha, double dt, double total_sim_time,
                               double bc1, double bc2)
    {
        int SIZE = geometry.getArray().size();
        double dx = geometry[1] - geometry[0];

        OWL::MatrixXD c_init = OWL::MatrixXD(SIZE,1);
        for (int i : geometry.getArray())
        {
            c_init[i][0] = func(geometry[i]);
        }

        OWL::ArrayXD diag = (1 - 2*alpha*dt/std::pow(dx,2)) * OWL::Ones(SIZE);
        diag[0] = 1;
        diag[SIZE - 1] = 1;
        OWL::ArrayXD udiag = alpha*dt/std::pow(dx, 2) * OWL::Ones(SIZE - 1);
        OWL::ArrayXD ldiag = udiag;
        udiag[0] = 0;
        ldiag[SIZE - 2] = 0;

        OWL::MatrixXD mat = OWL::MatrixXD(SIZE, SIZE);
        mat[0][0] = 1;
        for (int i=1; i<(SIZE-1); i++){
            mat[i][i] = 1 - 2*alpha*dt/std::pow(dx,2);
            mat[i][i-1] = alpha*dt/std::pow(dx, 2);
            mat[i][i+1] = alpha*dt/std::pow(dx, 2);
        }
        mat[SIZE-1][SIZE-1] = 0;
        
        OWL::MatrixXD c_prev = c_init;
        OWL::MatrixXD result = OWL::MatrixXD(SIZE, 1);
        for(int i = 0; i < (int)(total_sim_time/dx); i++)
        {
            result = mat * c_prev;
            c_prev = result;
            result.display();
        }

        return result;
    }
}
