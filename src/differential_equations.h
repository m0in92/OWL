#include <vector>
#include "owl.h"

namespace one_dimensional
{
    OWL::ArrayXD poisson_equation(OWL::ArrayXD geometry, double (*func)(double), double bc1, double bc2);
    std::vector<double> poisson_equation(double A, double B, int Nx, double (*func)(double), double bc1, double bc2);

    OWL::MatrixXD heat_equation(OWL::ArrayXD geometry, double (*func)(double), double alpha, double dt, double total_sim_time,
                                double bc1, double bc2);

    class RadialHeatEquation
    {
    public:
        RadialHeatEquation(int spatial_grid_points, double c_init);

        // getters
        OWL::ArrayXD get_c_s() { return c_s; }

        // helper methods
        void solver(double i_j, double i_dt, double i_R, double i_D);

    private:
        double m_k; // number of spatial grid points
        double m_c_init;
        OWL::ArrayXD c_prev;
        OWL::ArrayXD c_s;

        // helper methods
        double calc_dr(double &i_R) { return i_R / m_k; }
        double calc_A(double &i_dt, double &i_R, double &i_D) { return i_dt * i_D / std::pow(calc_dr(i_R), 2); }
        double calc_B(double i_dt, double &i_R, double &i_D) { return i_dt * i_D / (2 * calc_dr(i_R)); }
        OWL::ArrayXD calc_array_R(double &i_R) { return OWL::LinSpaced(0, i_R, m_k); };

        OWL::ArrayXD get_LHS_diag(double i_dt, double i_R, double i_D);
        OWL::ArrayXD get_LHS_ldiag(double i_dt, double i_R, double i_D);
        OWL::ArrayXD get_LHS_udiag(double i_dt, double i_R, double i_D);
        OWL::ArrayXD get_RHS_array(double i_j, double i_dt, double i_R, double i_D);
    };
}