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

    /**
     * @brief finds the first order differentive from the centered finite difference. The inputs include the array
     * containing the x values and the function.
     * 
     * @param func 
     * @param array 
     * @param step_size 
     * @return OWL::ArrayXD 
     */
    OWL::ArrayXD diff_centered(double (*func)(double), OWL::ArrayXD array, double step_size)
    {
        int SIZE = array.getArray().size();
        int SIZE_ARRAY = SIZE - 2;

        OWL::ArrayXD result_array = OWL::Zeros(SIZE_ARRAY);
        for (int i=1; i < (SIZE - 1); i++)
        {
            result_array[i-1] = (func(array[i+1]) - func(array[i-1])) / (2*step_size);
        }
        return result_array;
    }

    OWL::ArrayXD diff_centered(OWL::ArrayXD array, double step_size)
    {
        int SIZE = array.getArray().size();
        int SIZE_ARRAY = SIZE - 2;

        OWL::ArrayXD result_array = OWL::Zeros(SIZE_ARRAY);
        for (int i=1; i < (SIZE - 1); i++)
        {
            result_array[i-1] = (array[i+1] - array[i-1]) / (2*step_size);
        }
        return result_array;
    }
}

namespace second_order
{
    double diff_centered(double (*func)(double), double x, double step_size)
    {
        return (func(x+step_size) - 2 * func(x) + func(x-step_size)) / (std::pow(step_size, 2));
    }
}
