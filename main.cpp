#include "OWL.h"
#include <vector>

int main() {
    std::vector<double> vec = {0,1,2,3,4};
    OWL::ArrayXD sampleArray = OWL::ArrayXD(vec);

    OWL::ArrayXD sum_array = sampleArray + sampleArray;

    sum_array.display();
}
