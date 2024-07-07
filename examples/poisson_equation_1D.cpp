#include <cmath>

#include "owl.h"
#include "differential_equations.h"


double A = 0.0;
double B = 1.0;
int Nx = 101;

double func(double x)
{
    return 1-2*std::pow(x,2);
}

double BC1 = 0.0;
double BC2 = 1.0;

int main()
{
    OWL::ArrayXD linesegment = OWL::LinSpaced(A, B, Nx);
    
    OWL::ArrayXD result = one_dimensional::poisson_equation(linesegment, func, BC1, BC2);

    result.display();
}