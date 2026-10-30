#include "merge-sort.hpp"
#include <iostream>

int main() {
    vector<int> arr = {1, 5, 6, 0, 2, 9, 4};

    mergeSort(arr);

    for (int i : arr) {
        cout << i << ", ";
    }

    return 0;
}
