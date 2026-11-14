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
};