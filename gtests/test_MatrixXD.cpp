#include "gtest/gtest.h"
#include <vector>
#include <cmath>
#include "OWL.h"

TEST(TestMatrixXDConstructor, TestDefaultConstructor) {
	OWL::MatrixXD sampleMatrix = OWL::MatrixXD();
	EXPECT_EQ(0, sampleMatrix.getRowSize());
	EXPECT_EQ(0, sampleMatrix.getColSize());
}

TEST(TestMatrixXDConstructor, TestOverloadConstructor) {
	// Check if exception is thrown in case of inputting an empty std::vector.
	std::vector<OWL::ArrayXD> emptyVec;
	EXPECT_THROW(OWL::MatrixXD(emptyVec).getColSize(), std::invalid_argument);
	// Check overload constructor
	std::vector<OWL::ArrayXD> sampleVec;
	OWL::ArrayXD sampleArray = OWL::ArrayXD();
	sampleVec.push_back(sampleArray);
	OWL::MatrixXD sampleMatrix = OWL::MatrixXD(sampleVec);
	EXPECT_EQ(0, sampleMatrix.getRowSize());
	EXPECT_EQ(0, sampleMatrix.getColSize());
	sampleVec.push_back(sampleArray);
	OWL::MatrixXD sampleMatrix2 = OWL::MatrixXD(sampleVec);
	EXPECT_EQ(0, sampleMatrix2.getRowSize());
	EXPECT_EQ(0, sampleMatrix2.getColSize());
	// test with a non-empty array
	std::vector<double> sampleVec1;
	sampleVec1.push_back(1);
	OWL::ArrayXD sampleArray1 = OWL::ArrayXD(sampleVec1);
	std::vector<OWL::ArrayXD> sampleArrayMat;
	sampleArrayMat.push_back(sampleArray1);
	sampleArrayMat.push_back(sampleArray1);
	sampleArrayMat.push_back(sampleArray1);
	OWL::MatrixXD sampleMatrix3 = OWL::MatrixXD(sampleArrayMat);
	EXPECT_EQ(1, sampleMatrix3[0][0]);
	EXPECT_EQ(1, sampleMatrix3[1][0]);
	EXPECT_EQ(1, sampleMatrix3[2][0]);
	EXPECT_EQ(3, sampleMatrix3.getRowSize());
	EXPECT_EQ(1, sampleMatrix3.getColSize());
}

TEST(TestMatrixXDConstructor, TestOverloadConstructor2) {
	OWL::MatrixXD sampleMatrix = OWL::MatrixXD(2, 3);
	// check size
	EXPECT_EQ(2, sampleMatrix.getRowSize());
	EXPECT_EQ(3, sampleMatrix.getColSize());
	// check elements
	EXPECT_EQ(0, sampleMatrix[0][0]);
	EXPECT_EQ(0, sampleMatrix[0][1]);
	EXPECT_EQ(0, sampleMatrix[0][2]);
	EXPECT_EQ(0, sampleMatrix[1][0]);
	EXPECT_EQ(0, sampleMatrix[1][1]);
	EXPECT_EQ(0, sampleMatrix[1][2]);
}

TEST(TestMatrixXDFunctions, TestCompareSize) {
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

	OWL::MatrixXD sampleMatrix2 = OWL::MatrixXD();
	sampleMatrix2 << row1;

	EXPECT_FALSE(sampleMatrix1.compareSize(sampleMatrix2));
	EXPECT_TRUE(sampleMatrix1.compareSize(sampleMatrix1));
}

TEST(TestMatrixXDFunctions, TestGetCol) {
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

	OWL::ArrayXD sampleArray = sampleMatrix1.getCol(0);

	EXPECT_EQ(0, sampleArray[0]);
	EXPECT_EQ(3, sampleArray[1]);
	EXPECT_EQ(6, sampleArray[2]);
}

TEST(TestMatrixXDFunctions, TestisSquare) {
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

	OWL::MatrixXD sampleMatrix2 = OWL::MatrixXD();
	sampleMatrix2 << row1;

	EXPECT_TRUE(sampleMatrix1.isSquare());
	EXPECT_FALSE(sampleMatrix2.isSquare());
}

TEST(TestMatrixXDFunctions, TestSubMatrix) {
	OWL::ArrayXD row1;
	OWL::ArrayXD row2;
	OWL::ArrayXD row3;
	row1 << 7;
	row1 << 1;
	row1 << 3;
	row2 << 2;
	row2 << 4;
	row2 << 1;
	row3 << 1;
	row3 << 5;
	row3 << 1;

	OWL::MatrixXD sampleMatrix1 = OWL::MatrixXD();
	sampleMatrix1 << row1;
	sampleMatrix1 << row2;
	sampleMatrix1 << row3;

	OWL::MatrixXD sampleMatrix2 = sampleMatrix1.submatrix(0,0);

	// test size
	EXPECT_EQ(2, sampleMatrix2.getRowSize());
	EXPECT_EQ(2, sampleMatrix2.getColSize());
	// test element values
	EXPECT_EQ(4, sampleMatrix2[0][0]);
	EXPECT_EQ(1, sampleMatrix2[0][1]);
	EXPECT_EQ(5, sampleMatrix2[1][0]);
	EXPECT_EQ(1, sampleMatrix2[1][1]);
}
TEST(TestMatrixXDFunctions, TestDet) {
	OWL::ArrayXD row10;
	OWL::ArrayXD row20;
	row10 << 1;
	row10 << 7;
	row20 << 5;
	row20 << 2;

	OWL::MatrixXD sampleMatrix10 = OWL::MatrixXD();
	sampleMatrix10 << row10;
	sampleMatrix10 << row20;

	OWL::ArrayXD row1;
	OWL::ArrayXD row2;
	OWL::ArrayXD row3;
	row1 << 7;
	row1 << 1;
	row1 << 3;
	row2 << 2;
	row2 << 4;
	row2 << 1;
	row3 << 1;
	row3 << 5;
	row3 << 1;

	OWL::MatrixXD sampleMatrix1 = OWL::MatrixXD();
	sampleMatrix1 << row1;
	sampleMatrix1 << row2;
	sampleMatrix1 << row3;

	EXPECT_EQ(-33, sampleMatrix10.det());
	EXPECT_EQ(10, sampleMatrix1.det());
}

TEST(TestMatrixXDFunctions, TestisSingular) {
	OWL::ArrayXD row10;
	OWL::ArrayXD row20;
	row10 << 1;
	row10 << 7;
	row20 << 5;
	row20 << 2;

	OWL::MatrixXD sampleMatrix10 = OWL::MatrixXD();
	sampleMatrix10 << row10;
	sampleMatrix10 << row20;

	OWL::ArrayXD row1;
	OWL::ArrayXD row2;
	OWL::ArrayXD row3;
	row1 << 1;
	row1 << -2;
	row1 << -1;
	row2 << -3;
	row2 << 3;
	row2 << 0;
	row3 << 2;
	row3 << 2;
	row3 << 4;

	OWL::MatrixXD sampleMatrix1 = OWL::MatrixXD();
	sampleMatrix1 << row1;
	sampleMatrix1 << row2;
	sampleMatrix1 << row3;

	EXPECT_FALSE(sampleMatrix10.isSingular());
	EXPECT_TRUE(sampleMatrix1.isSingular());
}