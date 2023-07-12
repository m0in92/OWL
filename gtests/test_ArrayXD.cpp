//
// Created by moina on 7/10/2023.
//

#include "gtest/gtest.h"
#include <vector>
#include <cmath>
#include "OWL.h"


TEST(TestArrayXDConstructor, EmptyArray) {
        OWL::ArrayXD sampleArray = OWL::ArrayXD();
        EXPECT_EQ(0, sampleArray.getArrayLength());
}

TEST(TestArrayXDConstructor, stdVector) {
    std::vector<double> vec = { 0,1,2,3,4,5 };
    OWL::ArrayXD sampleArray = OWL::ArrayXD(vec);
    // test array size
    EXPECT_EQ(6, sampleArray.getArrayLength());
    // test array contents
    EXPECT_EQ(0, sampleArray[0]);
    EXPECT_EQ(1, sampleArray[1]);
    EXPECT_EQ(2, sampleArray[2]);
    EXPECT_EQ(3, sampleArray[3]);
    EXPECT_EQ(4, sampleArray[4]);
    EXPECT_EQ(5, sampleArray[5]);
}

TEST(TestSetters, TestGetArray) {
    std::vector<double> vecInit = { 0,1,2,3,4,5 };
    std::vector<double> vecNew = { 6,7,8,9,10,11,12 };
    OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
    sampleArray.setArray(vecNew);
    // test array size
    EXPECT_EQ(7, sampleArray.getArrayLength());
    // test array contents
    EXPECT_EQ(6, sampleArray[0]);
    EXPECT_EQ(7, sampleArray[1]);
    EXPECT_EQ(8, sampleArray[2]);
    EXPECT_EQ(9, sampleArray[3]);
    EXPECT_EQ(10, sampleArray[4]);
    EXPECT_EQ(11, sampleArray[5]);
    EXPECT_EQ(12, sampleArray[6]);
}

TEST(TestAuxilaries, TestcompareArrayLengths) {
    std::vector<double> vec1 = { 0,1,2,3,4,5 };
    std::vector<double> vec2 = { 6,7,8,9,10,11 };
    OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
    OWL::ArrayXD sampleArray2 = OWL::ArrayXD(vec2);
    EXPECT_TRUE(sampleArray1.compareArrayLength(sampleArray2));
}

TEST(TestAuxilaries, TestSum) {
    std::vector<double> vec1 = { 0,1,2,3,4,5 };
    OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
    EXPECT_EQ(15, sampleArray1.sum());
}
TEST(TestAuxilaries, TestcompareArrayLengthsException) {
    std::vector<double> vec1 = { 0,1,2,3,4,5 };
    std::vector<double> vec2 = { 6,7,8,9,10 };
    OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vec1);
    OWL::ArrayXD sampleArray2 = OWL::ArrayXD(vec2);
    EXPECT_THROW(sampleArray1.compareArrayLength(sampleArray2), std::invalid_argument);
}
TEST(TestAuxilaries, TestcheckEmptyArray) {
    std::vector<double> vecInit = { 0,1,2,3,4,5 };
    OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
    EXPECT_FALSE(sampleArray.checkEmptyArray());
}

TEST(TestAuxilaries, TestcheckEmptyArrayException) {
    OWL::ArrayXD sampleArray = OWL::ArrayXD();
    EXPECT_THROW(sampleArray.checkEmptyArray(), std::invalid_argument);
}

TEST(TestAuxilaries, TestIsEqual) {
    std::vector<double> vecInit1 = { 0,1,2,3,4,5 };
    std::vector<double> vecInit2 = { 0,1,2,3,4,5 };
    std::vector<double> vecInit3 = { 0,1,2,3,6,5 };
    std::vector<double> vecInit4 = { 0,1,2,3 };
    OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vecInit1);
    OWL::ArrayXD sampleArray2 = OWL::ArrayXD(vecInit2);
    OWL::ArrayXD sampleArray3 = OWL::ArrayXD(vecInit3);
    OWL::ArrayXD sampleArray4 = OWL::ArrayXD(vecInit4);
    EXPECT_TRUE(sampleArray1.isEqual(sampleArray2));
    EXPECT_FALSE(sampleArray1.isEqual(sampleArray3));
    EXPECT_FALSE(sampleArray1.isEqual(sampleArray4));
}

TEST(TestAuxilaries, TestIsApproxEqual) {
    std::vector<double> vecInit1 = { 0,0.95,2,3.1,4.05,5.03 };
    std::vector<double> vecInit2 = { 0,1,2,3,4,5 };
    std::vector<double> vecInit3 = { 0,1,2,3,6,5 };
    std::vector<double> vecInit4 = { 0,1,2,3 };
    OWL::ArrayXD sampleArray1 = OWL::ArrayXD(vecInit1);
    OWL::ArrayXD sampleArray2 = OWL::ArrayXD(vecInit2);
    OWL::ArrayXD sampleArray3 = OWL::ArrayXD(vecInit3);
    OWL::ArrayXD sampleArray4 = OWL::ArrayXD(vecInit4);
    EXPECT_TRUE(sampleArray1.isApproxEqual(sampleArray2, 0.1));
}

TEST(TestAuxilaries, TestFindMinValue) {
    std::vector<double> vecInit = { 0,5,10,225,20,25 };
    OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
    OWL::ArrayXD EmptyArray = OWL::ArrayXD();
    EXPECT_EQ(0, sampleArray.findMinElement());
    EXPECT_THROW(EmptyArray.findMinElement(), OWL::EmptyArrayException);
}

TEST(TestAuxilaries, TestFindMaxValue) {
    std::vector<double> vecInit = { 0,5,10,225,20,25 };
    OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
    OWL::ArrayXD EmptyArray = OWL::ArrayXD();
    EXPECT_EQ(225, sampleArray.findMaxELement());
    EXPECT_THROW(EmptyArray.findMaxELement(), OWL::EmptyArrayException);
}

TEST(TestAuxilaries, TestFindClosestElement) {
    std::vector<double> vecInit = { 0,1,2,3,4,5 };
    OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
    double inputValue = 2.25;
    EXPECT_EQ(2, sampleArray.findClosestElement(inputValue));
}

TEST(TestAuxilaries, TestFindClosestElementIndex) {
    std::vector<double> vecInit = { 0,1,2,3,4,5 };
    OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
    double inputValue1 = 1.25;
    double inputValue2 = 2.25;
    double inputValue3 = 3.75;
    double inputValue4 = 10;
    EXPECT_EQ(1, sampleArray.findClosestElementIndex(inputValue1));
    EXPECT_EQ(2, sampleArray.findClosestElementIndex(inputValue2));
    EXPECT_EQ(4, sampleArray.findClosestElementIndex(inputValue3));
    EXPECT_EQ(5, sampleArray.findClosestElementIndex(inputValue4));
}

TEST(TestAuxilaries, TestFindClosestElementLessThan1) {
std::vector<double> vecInit = { 0,1,2,3,4,5 };
OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
double inputValue = 2.25;
EXPECT_EQ(2, sampleArray.findCLosestElementLessThan(inputValue));
}

TEST(TestAuxilaries, TestFindClosestElementLessThan2) {
std::vector<double> vecInit = { 0,5,10,15,20,25 };
OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
double inputValue = 7.25;
EXPECT_EQ(5, sampleArray.findCLosestElementLessThan(inputValue));
}

TEST(TestAuxilaries, TestFindClosestElementLessThan3) {
std::vector<double> vecInit = { 0,5,10,15,20,25 };
OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
double inputValue = -0.5;
EXPECT_THROW(sampleArray.findCLosestElementLessThan(inputValue), std::invalid_argument);
}

TEST(TestAuxilaries, TestFindClosestElementLessThanIndex) {
std::vector<double> vecInit = { 0,5,10,15,20,25 };
OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
OWL::ArrayXD EmptyArray = OWL::ArrayXD();
double inputValue1 = 5.5;
double inputValue2 = 12.5;
double inputValue3 = 50;
double inputValue4 = -1;
EXPECT_EQ(1, sampleArray.findCLosestElementLessThanIndex(inputValue1));
EXPECT_EQ(2, sampleArray.findCLosestElementLessThanIndex(inputValue2));
EXPECT_EQ(5, sampleArray.findCLosestElementLessThanIndex(inputValue3));
EXPECT_THROW(sampleArray.findCLosestElementLessThanIndex(inputValue4), std::invalid_argument);
EXPECT_THROW(EmptyArray.findCLosestElementLessThanIndex(inputValue1), OWL::EmptyArrayException);
}

TEST(TestAuxilaries, TestFindClosestElementGreaterThan1) {
std::vector<double> vecInit = { 0,5,10,15,20,25 };
OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
double inputValue = 7.25;
EXPECT_EQ(10, sampleArray.findCLosestElementGreaterThan(inputValue));
}

TEST(TestAuxilaries, TestFindClosestElementGreaterThan2) {
std::vector<double> vecInit = { 0,5,10,15,20,25 };
OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
double inputValue = 50;
EXPECT_THROW(sampleArray.findCLosestElementGreaterThan(inputValue), std::invalid_argument);
}

TEST(TestAuxilaries, TestFindClosestElementGreaterThanIndex) {
std::vector<double> vecInit = { 0,5,10,15,20,25 };
OWL::ArrayXD sampleArray = OWL::ArrayXD(vecInit);
OWL::ArrayXD EmptyArray = OWL::ArrayXD();
double inputValue1 = 5.5;
double inputValue2 = 12.5;
double inputValue3 = -1;
double inputValue4 = 50;
EXPECT_EQ(2, sampleArray.findCLosestElementGreaterThanIndex(inputValue1));
EXPECT_EQ(3, sampleArray.findCLosestElementGreaterThanIndex(inputValue2));
EXPECT_EQ(0, sampleArray.findCLosestElementGreaterThanIndex(inputValue3));
EXPECT_THROW(sampleArray.findCLosestElementGreaterThanIndex(inputValue4), std::invalid_argument);
EXPECT_THROW(EmptyArray.findCLosestElementGreaterThanIndex(inputValue1), OWL::EmptyArrayException);
}

