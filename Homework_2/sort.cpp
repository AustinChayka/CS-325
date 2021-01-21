#include "sort.h"

std::vector<int> merge3(std::vector<int> a, std::vector<int> b, std::vector<int> c) {

    std::vector<int> d, e;

    int aN = 0, bN = 0, cN = 0, dN = 0;

    while(aN < a.size() && bN < b.size()) {

        if(a[aN] < b[bN]) d.push_back(a[aN++]);
        else d.push_back(b[bN++]);

    }

    while(aN < a.size()) d.push_back(a[aN++]);
    while(bN < b.size()) d.push_back(b[bN++]);
    
    while(cN < c.size() && dN < d.size()) {

        if(c[cN] < d[dN]) e.push_back(c[cN++]);
        else e.push_back(d[dN++]);
        
    }

    while(cN < c.size()) e.push_back(c[cN++]);
    while(dN < d.size()) e.push_back(d[dN++]);

    return e;

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

void merge3Sort(std::vector<int>& arr) {

    if(arr.size() <= 1) return;
    else if(arr.size() == 2) {
        int n = arr.size() / 2;
        std::vector<int> a(arr.begin(), arr.begin() + n);
        std::vector<int> b(arr.begin() + n, arr.end());
        arr = merge(a, b);
        return;
    }

    int n = arr.size() / 3;
    std::vector<int> a(arr.begin(), arr.begin() + n);
    std::vector<int> b(arr.begin() + n, arr.begin() + 2 * n);
    std::vector<int> c(arr.begin() + 2 * n, arr.end());

    merge3Sort(a);
    merge3Sort(b);
    merge3Sort(c);
    
    arr = merge3(a, b, c);

}