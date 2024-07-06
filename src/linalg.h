#include "OWL.h"


extern "C" void dgesv_( int *n, int *nrhs, double  *a, int *lda, int *ipiv, double *b, int *lbd, int *info  );

OWL::ArrayXD solve_dgsev(OWL::MatrixXD, OWL::ArrayXD);