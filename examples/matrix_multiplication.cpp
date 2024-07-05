#include <iostream>
#include <vector>

#include "cblas.h"

#include "owl.h"

const int n = 3;

int main()
{
    std::vector<double> vec1 = {2, 0, 0};
    std::vector<double> vec2 = {0, 2, 0};
    std::vector<double> vec3 = {0, 0, 2};

    OWL::ArrayXD array1 = OWL::ArrayXD(vec1);
    OWL::ArrayXD array2 = OWL::ArrayXD(vec2);
    OWL::ArrayXD array3 = OWL::ArrayXD(vec3);

    std::vector<OWL::ArrayXD> vec4 = {array1, array2, array3};
    OWL::MatrixXD mat1 = OWL::MatrixXD(vec4);

    double* A = mat1.convert_to_double();

    // print A
    std::cout << A[0] << " " << A[1] << " " << A[2] << std::endl;
    std::cout << A[3] << " " << A[4] << " " << A[5] << std::endl;
    std::cout << A[6] << " " << A[7] << " " << A[8] << std::endl;


    // double  C[n];
    double C[n * n];
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, A, n, A, n, 0.0, C, n);

    // print C
    std::cout << C[0] << " " << C[1] << " " << C[2] << std::endl;
    std::cout << C[3] << " " << C[4] << " " << C[5] << std::endl;
    std::cout << C[6] << " " << C[7] << " " << C[8] << std::endl;

    delete[] A;

    return 0;
}