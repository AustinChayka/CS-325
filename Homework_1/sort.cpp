#include "sort.h"

void swap(int& a, int &b) {

    int temp = a;
    a = b;
    b = temp;

}

void insertionSort(std::vector<int>& arr) {

    for(int i = 1; i < arr.size(); i++) {

        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }

    }

}

std::vector<int> merge(std::vector<int> a, std::vector<int> b) {

    std::vector<int> temp;

    int aN = 0, bN = 0;

    while(aN < a.size() && bN < b.size()) {

        if(a[aN] < b[bN]) temp.push_back(a[aN++]);
        else temp.push_back(b[bN++]);

    }

    while(aN < a.size()) temp.push_back(a[aN++]);
    while(bN < b.size()) temp.push_back(b[bN++]);

    return temp;

}

void mergeSort(std::vector<int>& arr) {

    if(arr.size() <= 1) return;

    int n = arr.size() / 2;
    std::vector<int> a(arr.begin(), arr.begin() + n);
    std::vector<int> b(arr.begin() + n, arr.end());

    mergeSort(a);
    mergeSort(b);
    arr = merge(a, b);

}