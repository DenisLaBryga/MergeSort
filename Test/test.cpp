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

/** @brief Losowa tablica liczb zostaje poprawnie posortowana. */
TEST(MergeSortTest, LosowaTablica) {
    vector<int> tab;
    for (int i = 0; i < 20; i++) {
        tab.push_back(rand() % 100);
    }
    sprawdz(tab);
}

/** @brief Tablica z samymi liczbami ujemnymi zostaje poprawnie posortowana. */
TEST(MergeSortTest, TylkoUjemne) {
    sprawdz({ -3, -10, -1, -7, -5 });
}

/** @brief Tablica z liczbami ujemnymi i dodatnimi zostaje poprawnie posortowana. */
TEST(MergeSortTest, UjemneIDodatnie) {
    sprawdz({ 4, -2, 7, -9, 0, 3, -1 });
}

/** @brief Pusta tablica jest obs³ugiwana bez rzucania wyj¹tku. */
TEST(MergeSortTest, PustaTablica) {
    vector<int> tab;
    MergeSort<int> ms;
    EXPECT_NO_THROW(ms.sortuj(tab));
    EXPECT_TRUE(tab.empty());
}

/** @brief Tablica z jednym elementem pozostaje niezmieniona. */
TEST(MergeSortTest, JedenElement) {
    sprawdz({ 42 });
}