#include <iostream>
#include <vector>

#include "linalg.h"


OWL::ArrayXD solve_dgsev(OWL::MatrixXD i_matrix, OWL::ArrayXD i_array)
{
    int SIZE = i_matrix.getColSize();
    int nrhs = 1;   // one column in b
    int lda = SIZE; // leading dimension of A
    int ldb = SIZE; // leading dimension of b
    int i_piv[SIZE] = {0};
    int info;

    // create A
    double A[SIZE * SIZE];
    int idx = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            A[idx] = i_matrix.getElements()[j].getArray()[i];
            idx++;
        }
    }

    // create B
    int B_NROW = i_array.getArrayLength();
    int B_NCOL = 1;
    double B[B_NROW] = {0.0};
    idx = 0;
    for (int i = 0; i < B_NROW; i++)
    {
        // std::cout << elements[i].getArray()[j] << std::endl;
        B[idx] = i_array.getArray()[i];
        idx++;
    }

    // solve
    dgesv_(&SIZE, &nrhs, &*A, &lda, &*i_piv, &*B, &ldb, &info);

    if (info == 0)
    {
        std::cout << "Simulation run successfully." << std::endl;
    }

    idx = 0;
    std::vector<double> result_vec;
    for (int i=0; i<SIZE; i++)
    {
        result_vec.push_back(B[i]);
    }

    return OWL::ArrayXD(result_vec);
}

