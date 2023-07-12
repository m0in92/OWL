##  <img title="" src="https://github.com/m0in92/OWL/blob/main/docs/Assets/owl.png" alt="" data-align="inline"> Owl Array Library

**Author:** Moin Ahmed <br>
**Originally created in 2022.**

Owl Array Library provides functionality to handle arrays and matrices in C++, as well as perform basic arithmetic and mathematical operations on them. This library can used by linking the static library and including header files into your project directory.

The member and free functions in this library have been tested using varous tests written using Google Tests. The conducted tests are included in the tests directory, however, it is important to note that these tests are conducted in another visual studio project by the author. Hence if anyone tries to run the test files, they will have to include OWL header file(s) and link the lib file(s) themselves.

Please refer to documentations in the docs folder for contained classes, methods, and functions.

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

