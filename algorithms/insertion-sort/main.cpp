#include "insertion-sort.hpp"
#include <iostream>

int main() {
    std::vector<int> arr = {1, 4, 2, 9, 8, 11};

    insertionSort(arr);

    for (int i : arr) {
        std::cout << i << ", ";
    }

    return 0;
}
