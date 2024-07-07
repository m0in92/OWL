#include <cmath>
#include <iostream>

#include "owl.h"
#include "numerical_methods.h"

#define PI 3.142

double h = 0.1;
double x = PI/4;

double func(double x)
{
    return std::sin(x);
}

int main() 
{
    std::cout << "Centered Finite Difference: " << first_order::diff_centered(func, x, h) << std::endl;

    return 0;
}
