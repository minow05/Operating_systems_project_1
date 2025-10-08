//
// Created by minow on 13-Mar-25.
//

#ifndef PWR_AIZO_PROJECT1_QUICK_H
#define PWR_AIZO_PROJECT1_QUICK_H

#include "SortingAlgorithm.h"

class Quick : public SortingAlgorithm<Quick> {
private:
    int pivot = 0;
    int pivotMode = 0;
    template<typename T>
    int partition(T *arr, int lowerBoundary, int upperBoundary);
    template<typename T>
    void quicksort(T *arr, int lowerBoundary, int upperBoundary);
public:
    using SortingAlgorithm<Quick>::SortingAlgorithm;
    void setPivotMode(int mode, int lowerBoundary, int upperBoundary);
    template<typename T>
    void sortImpl(T *arr, int size);

};

#endif //PWR_AIZO_PROJECT1_QUICK_H
