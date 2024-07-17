##  <img title="" src="https://github.com/m0in92/OWL/blob/main/docs/Assets/owl.png" alt="" data-align="inline"> Owl Array Library

**Author:** Moin Ahmed <br>
**Originally created in 2022.**

This repository provides the following functionality in the C++ programming language
- creating and handling arrays and matrices
- basic arithematic and algebraic operations on arrays and matrices
- linear algebra operations such as matrix multiplications and the linear system of equations solution.
- numerical methods for solving ordinary differential equations

This source code is intended to be compiled as a static library that can be linked to any other code. Please find the CMakeLists.txt under examples folder for ideas to include the source code to your projects. 

The member and free functions in this library have been tested using varous tests written using Google Tests. The conducted tests are included in the tests directory.

Please refer to documentations in the docs folder for contained classes, methods, and functions.

### Installation

1. Clone the repository
	```
	git clone --recurse-submodules git@github.com:m0in92/OWL.git
	```
2. Build the project using cmake
	```
	mkdir build
	cd build
	cmake ..
	cmake --build .
	```
3. Test the installation of the build. From the build directory, run the following executable.
	```
	./GTest_run
	```

### Usage
#### Initialization

Array can be initialized by several ways
1. using std::vector
```
std::vector<double> vec1 = { 0,1,2,3,4,5 };
```
2. Creating empty object and adding values using << operator

```
OWL::ArrayXD sampleArray;
sampleArray << 0.0;
sampleArray << 1.0;
```
3. Using Ones, Zeros, LinSpaced, and aRange functions
```
OWL::ArrayXD sampleArray = OWL::Ones(100);
```

Similarily, the matrices can be initialized by initialing the arrays and then adding them as rows to the matrixXD object.

```
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
```

