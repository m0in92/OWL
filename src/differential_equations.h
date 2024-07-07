#include "owl.h"

namespace one_dimensional
{
    OWL::ArrayXD poisson_equation(OWL::ArrayXD geometry, double (*func)(double), double bc1, double bc2);
}