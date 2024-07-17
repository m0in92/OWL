#include <cmath>

#include "owl.h"
#include "differential_equations.h"

double A = 0.0;
double B = 1.0;
int Nx = 101;
double BC1 = 0.0;
double BC2 = 0.0;
double alpha = 0.01;
double dt = 000160256;
double tot_time = 0.1;

double guassian(double x)
{
    return std::exp(-0.5 * (std::pow(x - 1.0 / 2.0, 2) / std::pow(0.05, 2)));
}

int main()
{
    OWL::ArrayXD geometry = OWL::LinSpaced(A, B, Nx);
    OWL::MatrixXD result = one_dimensional::heat_equation(geometry, guassian, alpha, dt, tot_time, BC1, BC2);

    result.display();

    return 0;
}
