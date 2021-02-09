#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <vector>
#include <fstream>

struct activity {

    int number,
        start_time,
        finish_time;

};

std::vector<activity> load(std::ifstream&, int);
void mergeSort(std::vector<activity>&);
std::vector<activity> schedule(std::vector<activity>);
void print(std::vector<activity>);

#endif