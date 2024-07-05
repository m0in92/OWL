#include "gtest/gtest.h"
#include <vector>
#include <cmath>
#include "OWL.h"

TEST(TestCustomArray, TestZeros) {
	int length = 100;
	OWL::ArrayXD sampleArray = OWL::Zeros(100);
	for (int i = 0; i < sampleArray.getArrayLength(); i++) {
		EXPECT_EQ(0, sampleArray[i]);
	}
}

TEST(TestCustomArray, TestOnes) {
	int length = 100;
	OWL::ArrayXD sampleArray = OWL::Ones(100);
	for (int i = 0; i < sampleArray.getArrayLength(); i++) {
		EXPECT_EQ(1, sampleArray[i]);
	}
}

TEST(TestCustomArray, TestArange) {
	OWL::ArrayXD sampleArray = OWL::aRange(0, 10, 1);
	// Check the array size
	EXPECT_EQ(10, sampleArray.getArrayLength());
	// Check the array elements
	EXPECT_EQ(0, sampleArray[0]);
	EXPECT_EQ(1, sampleArray[1]);
	EXPECT_EQ(2, sampleArray[2]);
	EXPECT_EQ(3, sampleArray[3]);
	EXPECT_EQ(4, sampleArray[4]);
	EXPECT_EQ(5, sampleArray[5]);
	EXPECT_EQ(6, sampleArray[6]);
	EXPECT_EQ(7, sampleArray[7]);
	EXPECT_EQ(8, sampleArray[8]);
	EXPECT_EQ(9, sampleArray[9]);
}

TEST(TestCustomArray, TestLinSpaced) {
	int length = 100;
	OWL::ArrayXD sampleArray = OWL::LinSpaced(1,100,100);
	for (int i = 0; i < sampleArray.getArrayLength(); i++) {
		EXPECT_EQ(i+1, sampleArray[i]);
	}
}