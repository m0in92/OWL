#include "owl.h"


int main()
{
    int Nx = 10;
    OWL::ArrayXD x = OWL::LinSpaced(0, 3.141592/2, Nx);
    // x.display();
    double h = x[1] - x[0];

    OWL::ArrayXD y = OWL::sin(x);
    // y.display();

    OWL::MatrixXD diff_matrix = OWL::diff_second_order(Nx);
    OWL::MatrixXD diff_results = (1/std::pow(h,2)) * diff_matrix * y;
    diff_results.display();

    return 0;
}