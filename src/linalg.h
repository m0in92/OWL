#include "OWL.h"


extern "C" void dgesv_( int *n, int *nrhs, double  *a, int *lda, int *ipiv, double *b, int *lbd, int *info  );
extern "C" void dgtsv(int *n, int *nrhs, double *dl, double *d, double *du, double *b, int *ldb, int *info);

OWL::ArrayXD solve_dgsev(OWL::MatrixXD, OWL::ArrayXD);
OWL::ArrayXD solve_dgtsv(OWL::ArrayXD dl, OWL::ArrayXD d, OWL::ArrayXD du, OWL::ArrayXD b);