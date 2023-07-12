#include "gtest/gtest.h"
#include <vector>
#include <cmath>
#include "OWL.h"

// Indexing overloads
TEST(TestIndexOverloads, TestIndexAccess) {
	std::vector<double> vec1 = { 0,1,2,3,4,5 };
	OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
	EXPECT_EQ(0, sampleArray1[0]);
	EXPECT_EQ(1, sampleArray1[1]);
	EXPECT_EQ(2, sampleArray1[2]);
	EXPECT_EQ(3, sampleArray1[3]);
	EXPECT_EQ(4, sampleArray1[4]);
	EXPECT_EQ(5, sampleArray1[5]);
	EXPECT_THROW(sampleArray1[6], std::invalid_argument);
}

TEST(TestOperatorOverloads, TestIndexManu) {
	// initialize OWL::ArrayXD
	std::vector<double> vec1 = { 0,1,2,3,4,5 };
	OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
	// Change the values of all elements of the OWL::ArrayxXD
	sampleArray1[0] = 100;
	sampleArray1[1] = 200;
	sampleArray1[2] = 300;
	sampleArray1[3] = 400;
	sampleArray1[4] = 500;
	sampleArray1[5] = 600;
	// Google Tests on all the elements.
	EXPECT_EQ(100, sampleArray1[0]);
	EXPECT_EQ(200, sampleArray1[1]);
	EXPECT_EQ(300, sampleArray1[2]);
	EXPECT_EQ(400, sampleArray1[3]);
	EXPECT_EQ(500, sampleArray1[4]);
	EXPECT_EQ(600, sampleArray1[5]);
}

// Arithmetic overloads

/**
* Test for scalar  addition is the scalar is on the rhs of the addition.
*/
TEST(TestArithmeticOperators, TestAddScalarRHS) {
	std::vector<double> vec1 = { 0,1,2,3,4,5 };
	double scalar = 1;
	OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
	OWL::ArrayXD resultArray = sampleArray1 + scalar;
	EXPECT_EQ(1, resultArray[0]);
	EXPECT_EQ(2, resultArray[1]);
	EXPECT_EQ(3, resultArray[2]);
	EXPECT_EQ(4, resultArray[3]);
	EXPECT_EQ(5, resultArray[4]);
	EXPECT_EQ(6, resultArray[5]);
}

/**
* Test for scalar  addition is the scalar is on the lhs of the addition.
*/
TEST(TestArithmeticOperators, TestAddScalarLHS) {
	std::vector<double> vec1 = { 0,1,2,3,4,5 };
	double scalar = 1;
	OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
	OWL::ArrayXD resultArray = scalar + sampleArray1;
	EXPECT_EQ(1, resultArray[0]);
	EXPECT_EQ(2, resultArray[1]);
	EXPECT_EQ(3, resultArray[2]);
	EXPECT_EQ(4, resultArray[3]);
	EXPECT_EQ(5, resultArray[4]);
	EXPECT_EQ(6, resultArray[5]);
}

TEST(TestArithmeticOperators, TestAdd) {
	std::vector<double> vec1 = { 0,1,2,3,4,5 };
	std::vector<double> vec2 = { 6,7,8,9,10,11 };
	OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
	OWL::ArrayXD sampleArray2 = OWL::ArrayXD(vec2);
	OWL::ArrayXD resultArray = sampleArray1 + sampleArray2;
	EXPECT_EQ(6, resultArray[0]);
	EXPECT_EQ(8, resultArray[1]);
	EXPECT_EQ(10, resultArray[2]);
	EXPECT_EQ(12, resultArray[3]);
	EXPECT_EQ(14, resultArray[4]);
	EXPECT_EQ(16, resultArray[5]);
}

TEST(TestArithmeticOperators, TestSubtract) {
	std::vector<double> vec1 = { 0,1,2,3,4,5 };
	std::vector<double> vec2 = { 6,7,8,9,10,11 };
	OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
	OWL::ArrayXD sampleArray2 = OWL::ArrayXD(vec2);
	OWL::ArrayXD resultArray = sampleArray1 - sampleArray2;
	EXPECT_EQ(-6, resultArray[0]);
	EXPECT_EQ(-6, resultArray[1]);
	EXPECT_EQ(-6, resultArray[2]);
	EXPECT_EQ(-6, resultArray[3]);
	EXPECT_EQ(-6, resultArray[4]);
	EXPECT_EQ(-6, resultArray[5]);
}

TEST(TestArithmeticOperators, TestScalarMultiply) {
	std::vector<double> vecInit = { 0,1,2,3,4,5 };
	OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
	OWL::ArrayXD resultArray = sampleArray * 10;
	EXPECT_EQ(0, resultArray[0]);
	EXPECT_EQ(10, resultArray[1]);
	EXPECT_EQ(20, resultArray[2]);
	EXPECT_EQ(30, resultArray[3]);
	EXPECT_EQ(40, resultArray[4]);
	EXPECT_EQ(50, resultArray[5]);
}

TEST(TestArithmeticOperators, TestElementMultiply) {
	std::vector<double> vec1 = { 0,1,2,3,4,5 };
	std::vector<double> vec2 = { 6,7,8,9,10,11 };
	OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
	OWL::ArrayXD sampleArray2 = OWL::ArrayXD(vec2);
	OWL::ArrayXD resultArray = sampleArray1 * sampleArray2;
	EXPECT_EQ(0, resultArray[0]);
	EXPECT_EQ(7, resultArray[1]);
	EXPECT_EQ(16, resultArray[2]);
	EXPECT_EQ(27, resultArray[3]);
	EXPECT_EQ(40, resultArray[4]);
	EXPECT_EQ(55, resultArray[5]);
}

TEST(TestArithmeticOperators, TestScalarMultiplyRHS) {
	std::vector<double> vec1 = { 0,1,2,3,4,5 };
	double scalar = 10;
	OWL::ArrayXD resultArray = scalar * vec1;
	EXPECT_EQ(0, resultArray[0]);
	EXPECT_EQ(10, resultArray[1]);
	EXPECT_EQ(20, resultArray[2]);
	EXPECT_EQ(30, resultArray[3]);
	EXPECT_EQ(40, resultArray[4]);
	EXPECT_EQ(50, resultArray[5]);
}

// input operators
TEST(TestInputOutputOperator, TestInputOperator) {
	OWL::ArrayXD sampleArray;
	sampleArray << 0.0;
	sampleArray << 1.0;
	EXPECT_EQ(0, sampleArray[0]);
	EXPECT_EQ(1, sampleArray[1]);
	EXPECT_EQ(2, sampleArray.getArrayLength());
}