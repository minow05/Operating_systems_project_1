#include "../include/QuickMultithread.hpp"

#include "Algorithms/Quick.h"

void QuickMultithread::sort(int *arr, int size) {
    std::thread renderThread(&QuickMultithread::drawPlot, this, arr, size);
    quicksort(arr, 0, size - 1);
    // for (auto& t: threads) {
    //     if (t.joinable()) {
    //         t.join();
    //     }
    // }
    sortingFinished = true;
    renderThread.join();
}

void QuickMultithread::quicksort(int *arr, int lowerBoundary, int upperBoundary) {
    std::cout << "Thread " << threadCounter.load() << " started\n";
    threadCounter.fetch_add(1);
    if (lowerBoundary >= upperBoundary) return;
    int pivotIndex = partition(arr, lowerBoundary, upperBoundary);
    if (threadCounter.load() < maxThreads) {
        std::thread left(&QuickMultithread::quicksort, this, arr, lowerBoundary, pivotIndex - 1);
        left.join();
        std::cout << "Thread " << threadCounter.load() << " finished\n";
        threadCounter.fetch_sub(1);
        quicksort(arr, pivotIndex + 1, upperBoundary);
    } else {
        quicksort(arr, lowerBoundary, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, upperBoundary);
    }
}

int QuickMultithread::partition(int *arr, int lowerBoundary, int upperBoundary) {
    int pivot = lowerBoundary;
    int pivotValue = arr[pivot];

    std::swap(arr[pivot], arr[upperBoundary]);  // Move pivot to end

    for (int i = lowerBoundary; i < upperBoundary; i++)
    {
        if (arr[i] < pivotValue) {
            delayFunction();
            std::swap(arr[i], arr[pivot]);
            pivot++;
        }
    }

    std::swap(arr[pivot], arr[upperBoundary]);  // Move pivot to correct position
    return pivot;
}

void QuickMultithread::delayFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

void QuickMultithread::drawPlot(int *arr, int size){
    sf::RenderWindow window{sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Sorting Algorithm"};
    int max = *std::max_element(arr, arr + size);
    while (window.isOpen()) {
        if (sortingFinished) window.close();
        updatePlot(arr, size, window, max);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

}

void QuickMultithread::updatePlot (int *arr, int size, sf::RenderWindow &window, int &max){
    window.clear(sf::Color::Black);
    float barWidth = static_cast<float>(WINDOW_SIZE) / static_cast<float>(size);

    for (int i = 0; i < size; i++) {

        float barHeight = static_cast<float>(arr[i]) / static_cast<float>(max) * WINDOW_SIZE_FLOAT;

        sf::RectangleShape rectangle(sf::Vector2f(barWidth, barHeight));
        rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * barWidth, WINDOW_SIZE_FLOAT - barHeight));
        rectangle.setFillColor(sf::Color(2, 48, 32));
        window.draw(rectangle);
    }
}



