#include <cmath>

#include "gtest/gtest.h"
#include "owl.h"
#include "numerical_methods.h"

double func(double x)
{
    return std::sin(x);
}

TEST(TestLingAlg, CenteredDifferenceArray)
{

    int Nx = 10;
    OWL::ArrayXD x = OWL::LinSpaced(0, 3.141592 / 2, Nx);
    double h = x[1] - x[0];

    // first order centered finite difference
    OWL::ArrayXD diff_array = first_order::diff_centered(func, x, h);

    EXPECT_NEAR(0.97981554, diff_array[0], 0.0001);
    EXPECT_NEAR(0.9349291, diff_array[1], 0.0001);
    EXPECT_NEAR(0.86163532, diff_array[2], 0.0001);
    EXPECT_NEAR(0.76216119, diff_array[3], 0.0001);
    EXPECT_NEAR(0.63952917, diff_array[4], 0.0001);
}

TEST(TestLingAlg, CenterdDiffererenceArray2)
{
    int Nx = 10;
    OWL::ArrayXD x = OWL::LinSpaced(0, 3.141592 / 2, Nx);
    double h = x[1] - x[0];

    OWL::ArrayXD y = OWL::sin(x);

    // first order centered finite difference
    OWL::ArrayXD diff_array = first_order::diff_centered(y, h);

    EXPECT_NEAR(0.97981554, diff_array[0], 0.0001);
    EXPECT_NEAR(0.9349291, diff_array[1], 0.0001);
    EXPECT_NEAR(0.86163532, diff_array[2], 0.0001);
    EXPECT_NEAR(0.76216119, diff_array[3], 0.0001);
    EXPECT_NEAR(0.63952917, diff_array[4], 0.0001);
}
