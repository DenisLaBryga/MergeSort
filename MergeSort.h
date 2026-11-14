#pragma once
#include <vector>

using namespace std;

template <typename T>
class MergeSort {
public:
    void sortuj(vector<T>& tab) {
        if (tab.size() > 1) {
            dziel(tab, 0, (int)tab.size() - 1);
        }
    }

private:
    void dziel(vector<T>& tab, int lewy, int prawy) {
        if (lewy >= prawy) {
            return;
        }
        int srodek = (lewy + prawy) / 2;
        dziel(tab, lewy, srodek);
        dziel(tab, srodek + 1, prawy);
        scal(tab, lewy, srodek, prawy);
    }

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