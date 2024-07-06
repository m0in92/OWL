namespace first_order
{
    double diff_forward(double (*func)(double), double x, double step_size);
    double diff_backward(double (*func)(double), double x, double step_size);
    double diff_centered(double (*func)(double), double x, double step_size);
}

namespace second_order
{
    double diff_centered(double (*func)(double, double), double x, double step_size);
}