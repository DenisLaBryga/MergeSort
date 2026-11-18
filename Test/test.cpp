/**
 * @file test.cpp
 * @brief Testy jednostkowe (Google Test) algorytmu sortowania przez scalanie.
 */
#include "pch.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "../MergeSort.h"   // popraw œcie¿kê do swojego projektu
using namespace std;

/**
 * @brief Sortuje tablicê klas¹ MergeSort i porównuje wynik z std::sort.
 * @param tab Tablica do przetestowania (przekazana przez kopiê).
 */
void sprawdz(vector<int> tab) {

    vector<int> oczekiwana = tab;
    sort(oczekiwana.begin(), oczekiwana.end());

    MergeSort<int> ms;
    ms.sortuj(tab);

    EXPECT_EQ(tab, oczekiwana);
}

/** @brief Tablica ju¿ posortowana rosn¹co pozostaje niezmieniona. */
TEST(MergeSortTest, JuzPosortowanaRosnaco) {
    sprawdz({ 1, 2, 3, 4, 5 });
}

/** @brief Tablica posortowana w odwrotnej kolejnoœci zostaje poprawnie posortowana. */
TEST(MergeSortTest, PosortowanaMalejaco) {
    sprawdz({ 5, 4, 3, 2, 1 });
}