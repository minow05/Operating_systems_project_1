#include "../include/Algorithms/QuickMultithread.hpp"

template<typename T>
int QuickMultithread::partition(T *arr, int lowerBoundary, int upperBoundary) {
    T pivotValue = arr[pivot];

    std::swap(arr[pivot], arr[upperBoundary]);  // Move pivot to end

    int storeIndex = lowerBoundary;
    for (int i = lowerBoundary; i < upperBoundary; i++)
    {
        if (arr[i] < pivotValue) {
            delayFunction();
            std::swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }

    std::swap(arr[storeIndex], arr[upperBoundary]);  // Move pivot to correct position
    return storeIndex;
}

template<typename T>
void QuickMultithread::quicksort(T *arr, int lowerBoundary, int upperBoundary) {

}

void QuickMultithread::setPivotMode(int mode, int lowerBoundary, int upperBoundary, int maxNumOfThreads) {
    int size = upperBoundary - lowerBoundary + 1;
    switch (mode) {
        case 0: pivot = upperBoundary; break;  // Last element as pivot
        case 1: pivot = lowerBoundary + size / 2; break;  // Middle element as pivot
        case 2: pivot = lowerBoundary + rand() % size; break;  // Random pivot
        case 3: pivot = lowerBoundary; break;  // First element as pivot
        default: pivot = upperBoundary;
    }
    pivotMode = mode;
    maxThreads = maxNumOfThreads;
}

template<typename T>
void QuickMultithread::sortImpl(T *arr, int size) {
    setPivotMode(0, 0, size - 1, 1);
}



