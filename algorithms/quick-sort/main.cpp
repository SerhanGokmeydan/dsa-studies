#include "quick-sort.hpp"
#include <iostream>

int main() {
    vector<int> arr = {1, 5, 6, 0, 2, 9, 4};

    quickSort(arr, 0, arr.size() - 1);

    for (int i : arr) {
        cout << i << ", ";
    }

    return 0;
}
