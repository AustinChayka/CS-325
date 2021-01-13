#include <fstream>
#include <vector>

#include "util.h"
#include "sort.h"

int main(int argc, char** argv) {

    std::ifstream f;

    f.open("data.txt");

    std::vector<int> arr;

    loadData(arr, f);
    mergeSort(arr);
    print(arr);
    
    arr.clear();
    loadData(arr, f);
    mergeSort(arr);
    print(arr);
    
    arr.clear();
    loadData(arr, f);
    mergeSort(arr);
    print(arr);

    f.close();

    return 0;

}