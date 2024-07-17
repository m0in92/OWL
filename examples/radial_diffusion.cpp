#include <cmath>

#include "owl.h"
#include "differential_equations.h"

#define CONSTANT_F 96487

int main() 
{
    double R = 8.5e-6;
    double c_max = 51410;
    double D = 1e-14;
    double S = 1.1167;
    double soc_init = 0.4956;
    double c_init = soc_init * c_max;

    double I_app = -1.65;
    double dt = 0.1;

    double j = I_app / (CONSTANT_F * S);

    one_dimensional::RadialHeatEquation solver_instance = one_dimensional::RadialHeatEquation(100, c_init);

    double t_prev = 0.0;
    for (int i=0; i<10; i++){
        solver_instance.solver(j, dt, R, D);
    }

    solver_instance.get_c_s().display();
}