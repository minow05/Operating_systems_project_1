#include "Algorithms/Quick.h"
#include "DataGeneration.h"
#include "../include/QuickMultithread.hpp"
#define SIZE_OF_ARRAY 800

int main() {

    DataGeneration<int> dataGeneration(SIZE_OF_ARRAY);

    // Quick quick(true);
    // quick.sort(dataGeneration.getArray("random"), SIZE_OF_ARRAY);
    QuickMultithread quick;
    quick.sort(dataGeneration.getArray("random"), SIZE_OF_ARRAY);

    return 0;
}