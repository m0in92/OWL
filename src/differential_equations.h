#include <vector>
#include "owl.h"

namespace one_dimensional
{
    OWL::ArrayXD poisson_equation(OWL::ArrayXD geometry, double (*func)(double), double bc1, double bc2);
    std::vector<double> poisson_equation(double A, double B, int Nx, double(*func)(double), double bc1, double bc2);
}