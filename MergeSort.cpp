/**
 * @file MergeSort.cpp
 * @brief Program demonstrujący działanie klasy MergeSort dla tablic int i double.
 */

#include <iostream>
#include <vector>
#include "MergeSort.h"
using namespace std;


/**
 * @brief Funkcja główna programu.
 *
 * Tworzy dwie tablice (z liczbami int i double) oraz dwie instancje
 * klasy MergeSort, sortuje obie tablice i wypisuje wyniki.
 *
 * @return 0 po poprawnym zakończeniu programu.
 */
int main() {
    vector<int> tabInt = { 4, 2, -1, 9, 4, -8, 6, 1 };
    vector<double> tabDouble = { 6.3, 2.5, -7.5, 7.1, 1.2, 3.8, -2.2 };

    MergeSort<int> sortInt;
    MergeSort<double> sortDouble;

    sortInt.sortuj(tabInt);
    sortDouble.sortuj(tabDouble);

    cout << "Tablica int: ";
    for (int i : tabInt) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Tablica double: ";
    for (double i : tabDouble) {
        cout << i << " ";
    }
    cout << endl;

    return 0;

}


