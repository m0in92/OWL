#include <cmath>
#include <thread>

#include "owl.h"
#include "differential_equations.h"


int main() 
{
    double R = 1;
    double D = 1e-3;
    double c_init = 1.0;

    int N_SIM = 1000;
    double dt = 1;
    double j = -0.01;

    one_dimensional::RadialHeatEquation solver_instance = one_dimensional::RadialHeatEquation(1000, c_init);

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i=0; i<N_SIM; i++){
        solver_instance.solve(j, dt, R, D);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1);

    std::cout << "Simulation time (C++): " << duration.count() << " ms" << std::endl;

    solver_instance.get_c_prev().display();

}