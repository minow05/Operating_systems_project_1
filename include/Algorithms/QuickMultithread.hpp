#ifndef OPERATING_SYSTEMS_PROJECT_1_QUICKMULTITHREAD_HPP
#define OPERATING_SYSTEMS_PROJECT_1_QUICKMULTITHREAD_HPP

#include "SortingAlgorithm.h"

class QuickMultithread : public SortingAlgorithm<QuickMultithread> {
    int pivot = 0;
    int pivotMode = 0;
    int maxThreads = 0;
    template<typename T>
    int partition(T *arr, int lowerBoundary, int upperBoundary);
    template<typename T>
    void quicksort(T *arr, int lowerBoundary, int upperBoundary);
public:
    using SortingAlgorithm<QuickMultithread>::SortingAlgorithm;
    void setPivotMode(int mode, int lowerBoundary, int upperBoundary, int maxNumOfThreads);
    template<typename T>
    void sortImpl(T *arr, int size);
};

#endif //OPERATING_SYSTEMS_PROJECT_1_QUICKMULTITHREAD_HPP