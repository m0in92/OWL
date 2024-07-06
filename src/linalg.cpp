#include <iostream>

extern "C" void dgesv_( int *n, int *nrhs, double  *a, int *lda, int *ipiv, double *b, int *lbd, int *info  );
extern "C" void dgttrs_();

int main() {
    int SIZE = 3;
    int nrhs = 1; // one column in b
    int lda = SIZE;  // leading dimension of A
    int ldb = SIZE;  // leading dimension of b
    int i_piv[SIZE] = {0};
    int info;

    double A[SIZE * SIZE] = {1, 0, 2, 1, 2, 5, 1, 5, -1};
    double b[SIZE] = {6, -4, 27};

    dgesv_( &SIZE, &nrhs, &*A, &lda, &*i_piv, &*b, &ldb, &info );	
    
    if (info == 0) {
        std::cout << "Simulation run successfully." << std::endl;

        // output results
        std::cout <<  b[0] << std::endl;
        std::cout << b[1]  << std::endl;
        std::cout << b[2] << std::endl;
    }
    else {
        std::cout << "Simulation didnot run properly." << std::endl;
    }

    return 0;

}
