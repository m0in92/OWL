#include "gtest/gtest.h"

#include "OWL.h"
#include "differential_equations.h"

double A = 0.0;
double B = 1.0;
int Nx = 101;

static double func(double x)
{
    return 1-2*std::pow(x,2);
}

double BC1 = 0.0;
double BC2 = 0.0;

TEST(TestDifferentialEquations, TestPoissonEquation1D)
{
    OWL::ArrayXD linesegment = OWL::LinSpaced(A, B, Nx);
    
    OWL::ArrayXD result = one_dimensional::poisson_equation(linesegment, func, BC1, BC2);

    EXPECT_EQ(0.0, result[0]);
    EXPECT_NEAR(-3.2835e-3, result[1], 0.0001);
    EXPECT_NEAR(-6.467020e-03, result[2], 0.00001);
}
