#include "quick-sort.hpp"
#include <utility>

void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pIndex = partition(arr, start, end);
    quickSort(arr, start, pIndex - 1);
    quickSort(arr, pIndex + 1, end);
}

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}
