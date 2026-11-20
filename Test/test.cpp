/**
 * @file test.cpp
 * @brief Testy jednostkowe (Google Test) algorytmu sortowania przez scalanie.
 */
#include "pch.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "../MergeSort.h"   
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

/** @brief Tablica z duplikatami zostaje poprawnie posortowana. */
TEST(MergeSortTest, Duplikaty) {
    sprawdz({ 3, 1, 3, 2, 1, 2, 3 });
}

/** @brief Tablica z liczbami ujemnymi i duplikatami zostaje poprawnie posortowana. */
TEST(MergeSortTest, UjemneZDuplikatami) {
    sprawdz({ -2, -5, -2, -8, -5, -8, -2 });
}

/** @brief Tablica z liczbami ujemnymi, dodatnimi i duplikatami zostaje poprawnie posortowana. */
TEST(MergeSortTest, UjemneDodatnieIDuplikaty) {
    sprawdz({ 5, -3, 5, 0, -3, 8, -1, 8, 0 });
}

/** @brief Tablica z dwoma elementami w kolejnoœci rosn¹cej zostaje poprawnie obs³u¿ona. */
TEST(MergeSortTest, DwaElementyRosnaco) {
    sprawdz({ 1, 2 });
}

/** @brief Du¿a tablica (ponad 100 elementów) zostaje poprawnie posortowana. */
TEST(MergeSortTest, DuzaTablica) {
    vector<int> tab;
    for (int i = 0; i < 150; i++) {
        tab.push_back(rand() % 1000);
    }
    sprawdz(tab);
}

/** @brief Du¿a tablica (ponad 100 elementów) z liczbami ujemnymi, dodatnimi i duplikatami. */
TEST(MergeSortTest, DuzaTablicaUjemneDodatnieDuplikaty) {
    vector<int> tab;
    for (int i = 0; i < 150; i++) {
        tab.push_back(rand() % 101 - 50);   // liczby od -50 do 50, przy 150 elementach bêd¹ duplikaty
    }
    sprawdz(tab);
}