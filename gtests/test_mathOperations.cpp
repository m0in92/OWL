#include "gtest/gtest.h"
#include <vector>
#include <cmath>
#include "OWL.h"

TEST(TestFunctions, TestAbs) {
	std::vector<double> vec = { -1, -2, -3, -4 };
	// check input array values
	OWL::ArrayXD array = OWL::ArrayXD(vec);
	EXPECT_EQ(-1, array[0]);
	EXPECT_EQ(-2, array[1]);
	EXPECT_EQ(-3, array[2]);
	EXPECT_EQ(-4, array[3]);
	// check output array values
	OWL::ArrayXD absArray = OWL::abs(array);
	EXPECT_EQ(1, absArray[0]);
	EXPECT_EQ(2, absArray[1]);
	EXPECT_EQ(3, absArray[2]);
	EXPECT_EQ(4, absArray[3]);
}

// Trig functions
TEST(TestTrigFunctions, TestSin) {
	std::vector<double> angleVec = { 0, 1.57, 2.36, 3.14 };
	OWL::ArrayXD angleArray = OWL::ArrayXD(angleVec);
	OWL::ArrayXD resultArray = OWL::sin(angleArray);
	EXPECT_EQ(std::sin(angleVec[0]), resultArray[0]);
	EXPECT_EQ(std::sin(angleVec[1]), resultArray[1]);
	EXPECT_EQ(std::sin(angleVec[2]), resultArray[2]);
	EXPECT_EQ(std::sin(angleVec[3]), resultArray[3]);
}

TEST(TestTrigFunctions, TestCos) {
	std::vector<double> angleVec = { 0, 1.57, 2.36, 3.14 };
	OWL::ArrayXD angleArray = OWL::ArrayXD(angleVec);
	OWL::ArrayXD resultArray = OWL::cos(angleArray);
	EXPECT_EQ(std::cos(angleVec[0]), resultArray[0]);
	EXPECT_EQ(std::cos(angleVec[1]), resultArray[1]);
	EXPECT_EQ(std::cos(angleVec[2]), resultArray[2]);
	EXPECT_EQ(std::cos(angleVec[3]), resultArray[3]);
}

TEST(TestTrigFunctions, TestTan) {
	std::vector<double> angleVec = { 0, 1.57, 2.36, 3.14 };
	OWL::ArrayXD angleArray = OWL::ArrayXD(angleVec);
	OWL::ArrayXD resultArray = OWL::tan(angleArray);
	EXPECT_EQ(std::tan(angleVec[0]), resultArray[0]);
	EXPECT_EQ(std::tan(angleVec[1]), resultArray[1]);
	EXPECT_EQ(std::tan(angleVec[2]), resultArray[2]);
	EXPECT_EQ(std::tan(angleVec[3]), resultArray[3]);
}

TEST(TestTrigFunctions, TestArcSin) {
	std::vector<double> angleVec = { 0, 0.25, 0.5, 0.75 };
	OWL::ArrayXD angleArray = OWL::ArrayXD(angleVec);
	OWL::ArrayXD resultArray = OWL::asin(angleArray);
	EXPECT_EQ(std::asin(angleVec[0]), resultArray[0]);
	EXPECT_EQ(std::asin(angleVec[1]), resultArray[1]);
	EXPECT_EQ(std::asin(angleVec[2]), resultArray[2]);
	EXPECT_EQ(std::asin(angleVec[3]), resultArray[3]);
}

TEST(TestTrigFunctions, TestArcCos) {
	std::vector<double> angleVec = { 0, 0.25, 0.5, 0.75 };
	OWL::ArrayXD angleArray = OWL::ArrayXD(angleVec);
	OWL::ArrayXD resultArray = OWL::acos(angleArray);
	EXPECT_EQ(std::acos(angleVec[0]), resultArray[0]);
	EXPECT_EQ(std::acos(angleVec[1]), resultArray[1]);
	EXPECT_EQ(std::acos(angleVec[2]), resultArray[2]);
	EXPECT_EQ(std::acos(angleVec[3]), resultArray[3]);
}

TEST(TestTrigFunctions, TestArcTan) {
	std::vector<double> angleVec = { 0, 0.25, 0.5, 0.75 };
	OWL::ArrayXD angleArray = OWL::ArrayXD(angleVec);
	OWL::ArrayXD resultArray = OWL::atan(angleArray);
	EXPECT_EQ(std::atan(angleVec[0]), resultArray[0]);
	EXPECT_EQ(std::atan(angleVec[1]), resultArray[1]);
	EXPECT_EQ(std::atan(angleVec[2]), resultArray[2]);
	EXPECT_EQ(std::atan(angleVec[3]), resultArray[3]);
}

// exponential and log functions
TEST(TestExpLogFunctions, TestExp) {
	int length = 10;
	OWL::ArrayXD inputArray = OWL::LinSpaced(0,10,11);
	OWL::ArrayXD resultArray = OWL::exp(inputArray);
	for (size_t i = 0; i < inputArray.getArrayLength(); i++) {
		EXPECT_EQ(std::exp(i), resultArray[i]);
	}
}

TEST(TestExpLogFunctions, TestLog10) {
	OWL::ArrayXD inputArray = OWL::LinSpaced(1, 10, 10);
	OWL::ArrayXD resultArray = OWL::log10(inputArray);
	for (size_t i = 0; i < inputArray.getArrayLength(); i++) {
		EXPECT_EQ(std::log10(i + 1), resultArray[i]);
	}
}

TEST(TestExpLogFunctions, TestLn) {
	OWL::ArrayXD inputArray = OWL::LinSpaced(1, 10, 10);
	OWL::ArrayXD resultArray = OWL::ln(inputArray);
	for (size_t i = 0; i < inputArray.getArrayLength(); i++) {
		EXPECT_EQ(std::log(i + 1), resultArray[i]);
	}
}