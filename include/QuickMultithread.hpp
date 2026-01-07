#ifndef OPERATING_SYSTEMS_PROJECT_1_QUICKMULTITHREAD_HPP
#define OPERATING_SYSTEMS_PROJECT_1_QUICKMULTITHREAD_HPP

#define WINDOW_SIZE 800
#define WINDOW_SIZE_FLOAT 800.f

#include <atomic>
#include <functional>
#include <thread>
#include <vector>

#include "SFML/Graphics/RenderWindow.hpp"

class QuickMultithread {
private:
    int partition(int *arr, int lowerBoundary, int upperBoundary);
    void quicksort(int *arr, int lowerBoundary, int upperBoundary);
    std::function<void()> delayFunction;
    std::atomic<int> threadCounter = 0;
    int maxThreads = 4;
    void drawPlot(int *arr, int size);
    void updatePlot(int *arr, int size, sf::RenderWindow &w, int &max);
    bool sortingFinished = false;
    void config(bool slow);
public:
    QuickMultithread(bool visualization);
    void sort(int *arr, int size);
};

#endif //OPERATING_SYSTEMS_PROJECT_1_QUICKMULTITHREAD_HPP