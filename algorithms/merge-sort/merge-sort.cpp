#include "merge-sort.hpp"

void mergeSort(vector<int> &arr) {
    int n = arr.size();
    if (n < 2) {
        return;
    }
    int mid = n / 2;
    vector<int> left(mid), right(n - mid);
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left);
    mergeSort(right);
    merge(left, right, arr);
}

void merge(vector<int> &left, vector<int> &right, vector<int> &arr) {
    int i = 0;
    int j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[i + j] = left[i];
            i++;
        } else {
            arr[i + j] = right[j];
            j++;
        }
    }
    // copy remaining elements
    while (i < left.size()) {
        arr[i + j] = left[i];
        i++;
    }
    while (j < right.size()) {
        arr[i + j] = right[j];
        j++;
    }
}
