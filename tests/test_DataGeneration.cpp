//
// Created by minow on 25-Apr-25.
//
#include <gtest/gtest.h>
#include "../include/DataGeneration.h"

TEST(files, DataGenerationTest){
    DataGeneration dataGeneration = DataGeneration<int>(100);
    dataGeneration.getArray("sorted");
}

TEST(testSorted, DataGenerationTest) {
    int size = 100;
    DataGeneration dataGeneration = DataGeneration<int>(size);
    int* arr = dataGeneration.getArray("sorted");
    for (int i = 0; i < size - 2; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}