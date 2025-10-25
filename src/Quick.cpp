//
// Created by minow on 13-Mar-25.
//
#include <array>
#include "Algorithms/Quick.h"

void Quick::setPivotMode(int mode, int lowerBoundary, int upperBoundary) {
    int size = upperBoundary - lowerBoundary + 1;
    pivotMode = mode;
    switch (pivotMode) {
        case 0: pivot = upperBoundary; break;  // Last element as a pivot
        case 1: pivot = lowerBoundary + size / 2; break;  // Middle element as a pivot
        case 2: pivot = lowerBoundary + rand() % size; break;  // Random pivot
        case 3: pivot = lowerBoundary; break;  // First element as a pivot
        default: pivot = upperBoundary;
    }
}

template<typename T>
int Quick::partition(T *arr, int lowerBoundary, int upperBoundary) {
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
void Quick::quicksort(T *arr, int lowerBoundary, int upperBoundary) {
    if (lowerBoundary >= upperBoundary) return;
    int pivotIndex = partition(arr, lowerBoundary, upperBoundary);

    quicksort(arr, lowerBoundary, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, upperBoundary);
}

template<typename T>
void Quick::sortImpl(T *arr, int size) {
    if (size <= 1) return;
    quicksort(arr, 0, size - 1);
}

template void Quick::sortImpl(float *arr, int size);
template void Quick::sortImpl(int *arr, int size);