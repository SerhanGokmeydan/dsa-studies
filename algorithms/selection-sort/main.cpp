#include "selection-sort.hpp"
#include <iostream>

int main() {
    std::vector<int> arr = {2, 5, 1, 8, 3, 9, 0};

    selectionSort(arr);

    for (int i : arr) {
        std::cout << i << ", ";
    }

    return 0;
}
