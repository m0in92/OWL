#include <cmath>

#include "owl.h"
#include "numerical_methods.h"


double func(double x)
{
    return std::sin(x);
}


int main()
{
    int Nx = 10;
    OWL::ArrayXD x = OWL::LinSpaced(0, 3.141592/2, Nx);
    // x.display();
    double h = x[1] - x[0];

    OWL::ArrayXD y = OWL::sin(x);
    // y.display();

    // first order centered finite difference
    OWL::ArrayXD diff_array = first_order::diff_centered(func, x, h);

    diff_array.display();

    return 0;
}