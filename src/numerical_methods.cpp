#include <cmath>

#include "numerical_methods.h"

namespace first_order
{
    double diff_forward(double (*func)(double), double x, double step_size)
    {
        return (func(x + step_size) - func(x)) / step_size;
    }

    double diff_backward(double (*func)(double), double x, double step_size)
    {
        return (func(x) - func(x-step_size)) / step_size;
    }

    double diff_centered(double (*func)(double), double x, double step_size) 
    {
        return (func(x+step_size) - func(x-step_size)) / (2*step_size);
    }
}

namespace second_order
{
    double diff_centered(double (*func)(double), double x, double step_size)
    {
        return (func(x+step_size) - 2 * func(x) + func(x-step_size)) / (std::pow(step_size, 2));
    }
}
