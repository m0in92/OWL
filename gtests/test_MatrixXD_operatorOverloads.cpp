#include "gtest/gtest.h"
#include <vector>
#include <cmath>
#include "OWL.h"

TEST(TestMatrixXDOperatorOverload, TestInputOperator) {
	OWL::MatrixXD sampleMatrix = OWL::MatrixXD();
	OWL::ArrayXD sampleArray = OWL::ArrayXD();
	sampleArray << 0;
	sampleArray << 1;
	sampleArray << 2;
	sampleMatrix << sampleArray;
	EXPECT_EQ(1, sampleMatrix.getRowSize());
	EXPECT_EQ(3, sampleMatrix.getColSize());
}

TEST(TestMatrixXDOperatorOverload, TestIndexOperator) {
	OWL::MatrixXD sampleMatrix = OWL::MatrixXD();
	OWL::ArrayXD sampleArray = OWL::ArrayXD();
	sampleArray << 0;
	sampleArray << 1;
	sampleArray << 2;
	sampleMatrix << sampleArray;
	EXPECT_EQ(0, sampleMatrix[0][0]);
	EXPECT_EQ(1, sampleMatrix[0][1]);
	EXPECT_EQ(2, sampleMatrix[0][2]);
	EXPECT_EQ(3, sampleMatrix.getColSize());
	EXPECT_THROW(sampleMatrix[1], OWL::RowIndexExceedRowSizeException);
}

TEST(TestMatrixXDOperatorOverload, TestMatrixAddition) {
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

	OWL::MatrixXD sampleMatrix2 = sampleMatrix1;
	OWL::MatrixXD sampleMatrix3 = sampleMatrix1 + sampleMatrix2;

	EXPECT_EQ(0, sampleMatrix3[0][0]);
	EXPECT_EQ(2, sampleMatrix3[0][1]);
	EXPECT_EQ(4, sampleMatrix3[0][2]);
	EXPECT_EQ(6, sampleMatrix3[1][0]);
	EXPECT_EQ(8, sampleMatrix3[1][1]);
	EXPECT_EQ(10, sampleMatrix3[1][2]);
	EXPECT_EQ(12, sampleMatrix3[2][0]);
	EXPECT_EQ(14, sampleMatrix3[2][1]);
	EXPECT_EQ(16, sampleMatrix3[2][2]);
}

TEST(TestMatrixXDOperatorOverload, TestMatrixSubtraction) {
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

	OWL::MatrixXD sampleMatrix2 = sampleMatrix1;
	OWL::MatrixXD sampleMatrix3 = sampleMatrix1 - sampleMatrix2;

	EXPECT_EQ(0, sampleMatrix3[0][0]);
	EXPECT_EQ(0, sampleMatrix3[0][1]);
	EXPECT_EQ(0, sampleMatrix3[0][2]);
	EXPECT_EQ(0, sampleMatrix3[1][0]);
	EXPECT_EQ(0, sampleMatrix3[1][1]);
	EXPECT_EQ(0, sampleMatrix3[1][2]);
	EXPECT_EQ(0, sampleMatrix3[2][0]);
	EXPECT_EQ(0, sampleMatrix3[2][1]);
	EXPECT_EQ(0, sampleMatrix3[2][2]);
}

TEST(TestMatrixXDOperatorOverload, TestMatrixMultiplication) {
	OWL::ArrayXD row1;
	OWL::ArrayXD row2;
	row1 << 0;
	row1 << 1;
	row2 << 2;
	row2 << 3;
	OWL::MatrixXD sampleMatrix1 = OWL::MatrixXD();
	sampleMatrix1 << row1;
	sampleMatrix1 << row2;

	OWL::ArrayXD row11;
	OWL::ArrayXD row22;
	row11 << 0;
	row22 << 1;
	OWL::MatrixXD sampleMatrix2 = OWL::MatrixXD();
	sampleMatrix2 << row11;
	sampleMatrix2 << row22;

	OWL::MatrixXD sampleMatrix3 = sampleMatrix1 * sampleMatrix2;

	EXPECT_EQ(1, sampleMatrix3[0][0]);
	EXPECT_EQ(3, sampleMatrix3[1][0]);
	EXPECT_EQ(2, sampleMatrix3.getRowSize());
	EXPECT_EQ(1, sampleMatrix3.getColSize());
}

TEST(TestMatrixXDOperatorOverload, TestMatrixArrayMultiplication) {
	int Nx = 10;
    OWL::ArrayXD x = OWL::LinSpaced(0, 3.141592/2, Nx);
    double h = x[1] - x[0];

    OWL::ArrayXD y = OWL::sin(x);

    OWL::MatrixXD diff_matrix = OWL::diff_second_order(Nx);
    OWL::MatrixXD diff_results = (1/std::pow(h,2)) * diff_matrix * y;
    
	EXPECT_NEAR(5.7005346, diff_results[0][0], 0.00001);
	EXPECT_NEAR(-0.17320779, diff_results[1][0], 0.00001);
}