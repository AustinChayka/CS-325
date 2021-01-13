#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "sort.h"

int main(int argc, char** argv) {

    std::vector<int> arr;

    int n[] = {10000, 25000, 50000, 100000, 150000, 200000, 250000, 300000};

    for(int j = 0; j < 8; j++) {

        for(int i = 0; i < n[j]; i++) arr.push_back(rand() % 10001);

        clock_t start = clock();
        mergeSort(arr);
        clock_t end = clock();

        std::cout << n[j] << " numbers sorted using merge sort in " << (end - start) / (double) CLOCKS_PER_SEC
            << " seconds." << std::endl;

    }
    
    return 0;

}