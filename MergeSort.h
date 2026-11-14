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

};