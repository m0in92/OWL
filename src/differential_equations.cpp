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

        OWL::MatrixXD c_init = OWL::MatrixXD(SIZE, 1);
        for (int i : geometry.getArray())
        {
            c_init[i][0] = func(geometry[i]);
        }

        OWL::ArrayXD diag = (1 - 2 * alpha * dt / std::pow(dx, 2)) * OWL::Ones(SIZE);
        diag[0] = 1;
        diag[SIZE - 1] = 1;
        OWL::ArrayXD udiag = alpha * dt / std::pow(dx, 2) * OWL::Ones(SIZE - 1);
        OWL::ArrayXD ldiag = udiag;
        udiag[0] = 0;
        ldiag[SIZE - 2] = 0;

        OWL::MatrixXD mat = OWL::MatrixXD(SIZE, SIZE);
        mat[0][0] = 1;
        for (int i = 1; i < (SIZE - 1); i++)
        {
            mat[i][i] = 1 - 2 * alpha * dt / std::pow(dx, 2);
            mat[i][i - 1] = alpha * dt / std::pow(dx, 2);
            mat[i][i + 1] = alpha * dt / std::pow(dx, 2);
        }
        mat[SIZE - 1][SIZE - 1] = 0;

        OWL::MatrixXD c_prev = c_init;
        OWL::MatrixXD result = OWL::MatrixXD(SIZE, 1);
        for (int i = 0; i < (int)(total_sim_time / dx); i++)
        {
            result = mat * c_prev;
            c_prev = result;
            result.display();
        }

        return result;
    }

    RadialHeatEquation::RadialHeatEquation(int spatial_grid_points, double c_init) : m_k(spatial_grid_points), m_c_init(c_init) 
    {
        c_prev = c_init * OWL::Ones(m_k);
        c_s = c_prev;
    }

    OWL::ArrayXD RadialHeatEquation::get_LHS_diag(double i_dt, double i_R, double i_D)
    {
        double A = calc_A(i_dt, i_R, i_D);
        OWL::ArrayXD result_array = (1+A) * OWL::Ones(m_k);
        result_array[0] = 1 + 3 * A;
        result_array[m_k-1] = 1 + A;

        return result_array;
    }

    OWL::ArrayXD RadialHeatEquation::get_LHS_ldiag(double i_dt, double i_R, double i_D)
    {
        double A = calc_A(i_dt, i_R, i_D);
        double B = calc_B(i_dt, i_R, i_D);
        OWL::ArrayXD result_array = OWL::Ones(m_k-1);

        OWL::ArrayXD array_R = calc_array_R(i_R);

        for (int i=0; i<(m_k-2); i++)
        {
            result_array[i] = -(A/2 - B/array_R[i+1]);
        }
        result_array[m_k-2] = -A;

        return result_array;
    }

    OWL::ArrayXD RadialHeatEquation::get_LHS_udiag(double i_dt, double i_R, double i_D)
    {
        double A = calc_A(i_dt, i_R, i_D);
        double B = calc_B(i_dt, i_R, i_D);
        OWL::ArrayXD array_R = calc_array_R(i_R);

        OWL::ArrayXD result_array = OWL::Zeros(m_k-1);
        result_array[0] = -3*A;
        for (int i=1; i<(m_k-2); i++)
        {
            result_array[i] = -(A/2 + B/array_R[i]);
        }

        return result_array;
    }

    OWL::ArrayXD RadialHeatEquation::get_RHS_array(double i_j, double i_dt, double i_R, double i_D)
    {
        double A = calc_A(i_dt, i_R, i_D);
        double B = calc_B(i_dt, i_R, i_D);
        OWL::ArrayXD array_R = calc_array_R(i_R);
        
        OWL::ArrayXD result_array = OWL::Zeros(m_k);
        result_array[0] = (1-3*A)*c_prev[0] + 3*A*c_prev[1];
        result_array[m_k-1] = (1-A)*c_prev[m_k-1] - (A+B/i_R)*(2*i_j/i_D) * calc_dr(i_R) + A*c_prev[m_k-2];
        for (int i=1; i<(m_k-2); i++){
            result_array[i] = (1-A)*c_prev[i] + (A/2+B/array_R[i])*c_prev[i+1] + (A/2-B/array_R[i])*c_prev[i-1];
        }

        return result_array;
    }

    void RadialHeatEquation::solver(double i_j, double i_dt, double i_R, double i_D)
    {
        OWL::ArrayXD ldiag = get_LHS_ldiag(i_dt, i_R, i_D);
        OWL::ArrayXD diag = get_LHS_diag(i_dt, i_R, i_D);
        OWL::ArrayXD udiag = get_LHS_udiag(i_dt, i_R, i_D);

        OWL::ArrayXD RHS = get_RHS_array(i_j, i_dt, i_R, i_D);

        c_s = solve_dgtsv(ldiag, diag, udiag, RHS);
    }
}
