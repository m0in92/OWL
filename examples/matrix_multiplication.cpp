#include <iostream>
#include <vector>

#include "owl.h"


int main()
{
    std::vector<double> vec1 = {1, 0, 0};
    std::vector<double> vec2 = {0, 1, 0};
    std::vector<double> vec3 = {0, 0, 1};

    OWL::ArrayXD array1 = OWL::ArrayXD(vec1);
    OWL::ArrayXD array2 = OWL::ArrayXD(vec2);
    OWL::ArrayXD array3 = OWL::ArrayXD(vec3);

    std::vector<OWL::ArrayXD> vec4 = {array1, array2, array3};
    OWL::MatrixXD mat1 = OWL::MatrixXD(vec4);
    mat1.display();

    OWL::MatrixXD mat2 = mat1 * mat1;
    mat2.display();

    return 0;
}