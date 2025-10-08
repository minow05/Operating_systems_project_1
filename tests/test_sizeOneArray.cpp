//
// Created by minow on 14-Mar-25.
//
#include <gtest/gtest.h>
#include <shldisp.h>
#include "Algorithms/Heap.h"
#include "Algorithms/Quick.h"
#include "Algorithms/Insertion.h"
#include "Algorithms/Shell.h"
#include "Algorithms/SortingAlgorithm.h"

TEST(HeapSortTest, TestSizeOneArray) {
    int arr[] = {1};
    Heap heap(false);
    heap.sort(arr, 1);
    EXPECT_EQ(arr[0], 1);
}
TEST(QuickSortTest, TestSizeOneArray) {
    int arr[] = {1};
    Quick quick(false);
    quick.sort(arr, 1);
    EXPECT_EQ(arr[0], 1);
}
TEST(ShellSortTest, TestSizeOneArray) {
    int arr[] = {1};
    Shell shell(false);
    shell.sort(arr, 1);
    EXPECT_EQ(arr[0], 1);
}
TEST(InsertionSortTest, TestSizeOneArray) {
    int arr[] = {1};
    Insertion insertion(false);
    insertion.sort(arr, 1);
    EXPECT_EQ(arr[0], 1);
}