#include <vector>
#include <ctime>
#include <cstdlib>

#include "util.h"
#include "sort.h"

int main(int argc, char** argv) {

    std::vector<int> arr;

    int n[] = {2500, 5000, 7500, 10000, 15000, 20000, 25000, 50000};

    for(int j = 0; j < 8; j++) {

        for(int i = 0; i < n[j]; i++) arr.push_back(rand() % 10001);

        clock_t start = clock();
        insertionSort(arr);
        clock_t end = clock();

        std::cout << n[j] << " numbers sorted using insertion sort in " << (end - start) / (double) CLOCKS_PER_SEC
            << " seconds." << std::endl;

    }
    
    return 0;

}