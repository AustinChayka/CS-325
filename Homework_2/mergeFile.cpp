#include <fstream>
#include <vector>

#include "util.h"
#include "sort.h"

int main(int argc, char** argv) {


    std::vector<int> arr;
    std::ifstream f;

    f.open("data.txt");
    
    while(!f.eof()) {

        loadData(arr, f);
        merge3Sort(arr);
        print(arr);
        arr.clear();

    }

    f.close();

    return 0;

}