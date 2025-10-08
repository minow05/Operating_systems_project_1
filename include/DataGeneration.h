#ifndef PWR_AIZO_PROJECT1_DATAGENERATION_H
#define PWR_AIZO_PROJECT1_DATAGENERATION_H

#include    <fstream>
#include "Algorithms/SortingAlgorithm.h"

#include "Algorithms/Quick.h"

#include <random>

template<typename T>
class DataGeneration {
public:

    DataGeneration(int size) : size(size){
        arrRandom = generateRandom();
        arrSorted = generateSorted();
        arrReverseSorted = generateReverseSorted();
    };

    ~DataGeneration(){
        delete[] arrRandom;
        delete[] arrSorted;
        delete[] arrReverseSorted;
    };

    T* getArray(const std::string name){
        return readFromFile(name);
    }

    void saveArray(T* arr, std::string name){
        writeToFile(arr, name);
    }

private:

    int size = 0;
    T* arrRandom = nullptr;
    T* arrSorted = nullptr;
    T* arrReverseSorted = nullptr;

    T *generateRandom() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, size - 1);

        T *arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = static_cast<T>(dis(gen));
        }
        writeToFile(arr, "random");
        return arr;
    }

    T *generateSorted() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, size - 1);

        T *arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = static_cast<T>(dis(gen));
        }
        std::sort(arr, arr + size);
        writeToFile(arr, "sorted");
        return arr;
    }

    T* generateReverseSorted() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, size - 1);

        T *temp = new T[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = static_cast<T>(dis(gen));
        }
        std::sort(temp, temp + size);
        T* arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = temp[size - i - 1];
        }
        delete[] temp;
        writeToFile(arr, "reverseSorted");
        return arr;
    }

    T* readFromFile(const std::string& filename) {
        std::ifstream inFile(filename + ".txt");
        if (!inFile) {
            std::cerr << "Error: Could not open file " << filename << ".txt for reading.\n";
            size = 0;
            return nullptr;
        }

        T* arr = new T[size];
        int index = 0;
        T value;
        while (inFile >> value) {
            arr[index] = value;
            index++;
        }
        return arr;
    }

    void writeToFile(T *arr, const std::string &filename) {
        std::ofstream outFile(filename + ".txt");
        if (!outFile) {
            std::cerr << "Error: Unable to open file for writing.\n";
            return;
        }

        for (int i = 0; i < size; ++i) {
            outFile << arr[i] << "\n";
        }

        outFile.close();
    }

};



#endif //PWR_AIZO_PROJECT1_DATAGENERATION_H