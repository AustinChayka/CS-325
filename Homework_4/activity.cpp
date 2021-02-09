#include "activity.h"

#include <iostream>

std::vector<activity> load(std::ifstream& f, int n) {

    std::vector<activity> v;
    int num, start, finish;
    for(int i = 0; i < n; i++) {
        f >> num >> start >> finish;
        activity a;
        a.number = num;
        a.start_time = start;
        a.finish_time = finish;
        v.push_back(a);
    }

    return v;

}

std::vector<activity> merge(std::vector<activity> a, std::vector<activity> b) {

    std::vector<activity> temp;

    int aN = 0, bN = 0;

    while(aN < a.size() && bN < b.size()) {

        if(a[aN].start_time > b[bN].start_time) temp.push_back(a[aN++]);
        else temp.push_back(b[bN++]);

    }

    while(aN < a.size()) temp.push_back(a[aN++]);
    while(bN < b.size()) temp.push_back(b[bN++]);

    return temp;

}

void mergeSort(std::vector<activity>& v) {

    if(v.size() <= 1) return;

    int n = v.size() / 2;
    std::vector<activity> a(v.begin(), v.begin() + n);
    std::vector<activity> b(v.begin() + n, v.end());

    mergeSort(a);
    mergeSort(b);
    v = merge(a, b);

}

std::vector<activity> schedule(std::vector<activity> v) {

    mergeSort(v);

    std::vector<activity> result;

    result.push_back(v[0]);

    for(int i = 1; i < v.size(); i++) {
        
        if(v[i].finish_time <= result[result.size() - 1].start_time)
            result.push_back(v[i]);

    }

    return result;

}

void print(std::vector<activity> v) {

    std::cout << "Number of activities: " << v.size() << std::endl << "Activities: ";
    for(int i = v.size() - 1; i >= 0; i--) std::cout << v[i].number << " ";
    std::cout << std::endl;

}