//
// Created by minow on 13-Mar-25.
//
#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <thread>
#include <functional>

#ifndef PWR_AIZO_PROJECT1_SORTINGALGORITHM_H
#define PWR_AIZO_PROJECT1_SORTINGALGORITHM_H
#define WINDOW_SIZE 800
#define WINDOW_SIZE_FLOAT 800.f

template<class Derived>
class SortingAlgorithm {
public:

    explicit SortingAlgorithm(bool slow){
        setMode(slow);
        sortingFinished = false;
    }
    virtual ~SortingAlgorithm() = default;

    void setMode(bool slow){
        delayFunction = slow ? std::bind(&SortingAlgorithm::delayReal, this) : std::bind(&SortingAlgorithm::delayNone, this);
        this -> slowMode = slow;
    }

    template<typename T>
     void sort(T *arr, int size) {
        sortingFinished = false;
        if (slowMode){
            renderThread = std::thread(&SortingAlgorithm::drawPlot<T>, this, arr, size);
        }
        auto start = std::chrono::high_resolution_clock::now();
        static_cast<Derived*>(this)->sortImpl(arr, size);
        auto stop = std::chrono::high_resolution_clock::now();
        this -> duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        this -> printTime(size);
        sortingFinished = true;
        if (renderThread.joinable()) renderThread.join();
    }
    //Curiously recurring template pattern (CRTP) because I want to inherit virtual template method

    template<typename T>
    void printArray(T *arr, int size){
        printf("Array: \n");
        for (int i = 0; i < size; ++i){
            std::cout << *(arr + i) << " ";
        }
        std::cout << std::endl;
    };

    template<typename T>
    void drawPlot(T *arr, int size){
        sf::RenderWindow window{sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Sorting Algorithm"};
        T max = *std::max_element(arr, arr + size);
        while (window.isOpen()) {
            if (sortingFinished) window.close();
            updatePlot(arr, size, window, max);
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }

    }


    template<typename T>
    void updatePlot (T *arr, int size, sf::RenderWindow &window, T max){
        window.clear(sf::Color::Black);
        float barWidth = static_cast<float>(WINDOW_SIZE) / static_cast<float>(size);

//        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        for (int i = 0; i < size; i++) {

            float barHeight = static_cast<float>(arr[i]) / static_cast<float>(max) * WINDOW_SIZE_FLOAT;

            sf::RectangleShape rectangle(sf::Vector2f(barWidth, barHeight));
            rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * barWidth, WINDOW_SIZE_FLOAT - barHeight));  // Align bottom
            rectangle.setFillColor(sf::Color(2, 48, 32));
            window.draw(rectangle);
        }
    }

    void printTime(float sizeFloat){
        std::cout << "Time: " << duration.count()/1000.0 << " milliseconds\n";
    }

protected:
    bool sortingFinished;
    std::chrono::microseconds duration{};
    bool slowMode;
    std::thread renderThread;
    template<typename T>
    void sortImpl(T *arr, int size);
    std::function<void()> delayFunction;
    void delayReal() const {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    void delayNone() const {}
};



#endif //PWR_AIZO_PROJECT1_SORTINGALGORITHM_H