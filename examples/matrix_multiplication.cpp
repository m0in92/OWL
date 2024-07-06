/**
 * @file matrix_multiplication.cpp
 * @author your name (you@domain.com)
 * @brief This file gives examples of matrix multiplication.
 * @version 0.1
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>

#include "owl.h"

const int n = 3;

int main()
{
    OWL::ArrayXD row1;
	OWL::ArrayXD row2;
    OWL::ArrayXD row3;
	row1 << 0;
	row1 << 1;
	row1 << 2;
	row2 << 3;
	row2 << 4;
	row2 << 5;
    row3 << 6;
	row3 << 7;
	row3 << 8;

    OWL::MatrixXD sampleMatrix1 = OWL::MatrixXD();
	sampleMatrix1 << row1;
	sampleMatrix1 << row2;
    sampleMatrix1 << row3;
    OWL::ArrayXD row11;
	OWL::ArrayXD row22;
    OWL::ArrayXD row33;
	row11 << 0;
	row22 << 1;
    row33 << 1;
	OWL::MatrixXD sampleMatrix2 = OWL::MatrixXD();
	sampleMatrix2 << row11;
	sampleMatrix2 << row22;
    sampleMatrix2 << row33;
    OWL::MatrixXD sampleMatrix3 = sampleMatrix1 * sampleMatrix2;
    sampleMatrix3.display();

    // Create the first matrix
    std::vector<double> vec1 = {1, 2, 3};
    std::vector<double> vec2 = {4, 5, 6};
    std::vector<double> vec3 = {7, 8, 9};

    std::vector<std::vector<double>> vec4 = {vec1, vec2, vec3};
    OWL::MatrixXD mat1 = OWL::MatrixXD(vec4);

    // Create the second matrix
    std::vector<double> vec5 = {6};
    std::vector<double> vec6 = {3};
    std::vector<double> vec7 = {4};

    std::vector<std::vector<double>> vec8 = {vec5, vec6, vec7};
    OWL::MatrixXD mat2 = OWL::MatrixXD(vec8);
    OWL::MatrixXD A = mat1 * mat2;
    A.display();

    return 0;
}