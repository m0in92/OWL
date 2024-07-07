#include <vector>

#include "owl.h"
#include "linalg.h"

int main()
{
    int SIZE = 5;
    OWL::ArrayXD ldiag = -1 * OWL::Ones(SIZE-1);
    OWL::ArrayXD diag = 3 * OWL::Ones(SIZE);
    OWL::ArrayXD udiag = -1 * OWL::Ones(SIZE-1);
    OWL::ArrayXD b = OWL::Ones(SIZE);
    b[0] = 2.0;
    b[SIZE-1] = 2.0;

    OWL::ArrayXD result = solve_dgtsv(ldiag, diag, udiag, b);

    result.display();

    return 0;
}