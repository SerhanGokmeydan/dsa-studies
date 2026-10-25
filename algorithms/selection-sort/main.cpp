#include "selection-sort.hpp"
#include <iostream>

int main() {
    vector<int> arr = {2, 5, 1, 8, 3, 9, 0};

    selectionSort(arr);

    for (int i : arr) {
        cout << i << ", ";
    }

    return 0;
}
