/**
 * @file MergeSort.h
 * @brief Szablon klasy realizuj¹cej sortowanie przez scalanie (MergeSort).
 */

#pragma once
#include <vector>

using namespace std;

/**
 * @brief Klasa sortuj¹ca tablicê algorytmem sortowania przez scalanie.
 *
 * Klasa jest szablonem, wiêc dzia³a dla ka¿dego typu, który obs³uguje
 * operator <= (np. int, long, float, double).
 *
 * @tparam T Typ elementów sortowanej tablicy.
 */
template <typename T>
class MergeSort {
public:

    /**
     * @brief Sortuje tablicê rosn¹co.
     *
     * Pusta tablica oraz tablica z jednym elementem pozostaj¹ bez zmian.
     *
     * @param tab Tablica do posortowania (zmieniana w miejscu).
     */
    void sortuj(vector<T>& tab) {
        if (tab.size() > 1) {
            dziel(tab, 0, (int)tab.size() - 1);
        }
    }

private:

    /**
     * @brief Dzieli fragment tablicy na dwie po³owy, sortuje je rekurencyjnie i scala.
     * @param tab Sortowana tablica.
     * @param lewy Indeks pierwszego elementu fragmentu.
     * @param prawy Indeks ostatniego elementu fragmentu.
     */
    void dziel(vector<T>& tab, int lewy, int prawy) {
        if (lewy >= prawy) {
            return;
        }
        int srodek = (lewy + prawy) / 2;
        dziel(tab, lewy, srodek);
        dziel(tab, srodek + 1, prawy);
        scal(tab, lewy, srodek, prawy);
    }


    /**
     * @brief Scala dwie posortowane po³owy fragmentu tablicy w jedn¹ posortowan¹.
     * @param tab Sortowana tablica.
     * @param lewy Indeks pocz¹tku lewej po³owy.
     * @param srodek Indeks koñca lewej po³owy (prawa po³owa zaczyna siê od srodek + 1).
     * @param prawy Indeks koñca prawej po³owy.
     */
    void scal(vector<T>& tab, int lewy, int srodek, int prawy) {
        vector<T> pom;
        int i = lewy;
        int j = srodek + 1;

        while (i <= srodek && j <= prawy) {
            if (tab[i] <= tab[j]) {
                pom.push_back(tab[i]);
                i++;
            }
            else {
                pom.push_back(tab[j]);
                j++;
            }
        }
        while (i <= srodek) {
            pom.push_back(tab[i]);
            i++;
        }
        while (j <= prawy) {
            pom.push_back(tab[j]);
            j++;
        }

        for (int k = lewy; k <= prawy; k++) {
            tab[k] = pom[k - lewy];
        }
    }

};