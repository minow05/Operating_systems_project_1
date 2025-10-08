#include "Algorithms/Quick.h"
#include "DataGeneration.h"
#include "UI/UserInterface.h"
#define SIZE_OF_ARRAY 200

int main() {

    DataGeneration<int> dataGeneration(SIZE_OF_ARRAY);

    Quick quick(true);
    quick.sort(dataGeneration.getArray("random"), SIZE_OF_ARRAY);

    return 0;
}