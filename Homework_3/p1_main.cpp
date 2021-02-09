#include <iostream>
#include <ctime>
#include <cstdlib>

#include "knapsack.h"

int main(int argc, char** argv) {

    int n0[] = {140, 145, 150, 155, 160, 165, 170};
    int n1[] = {100000, 110000, 120000, 130000, 140000, 150000, 160000};
    int w[] = {20, 40, 60, 80};

    srand(time(0));

    for(int i = 0; i < 7; i++) {

        int* wt0 = new int[n0[i]];
        int* val0 = new int[n0[i]];
        for(int j = 0; j < n0[i]; j++) {
            wt0[j] = rand() % 100 + 1;
            val0[j] = rand() % 100 + 1;
        }
        int* wt1 = new int[n1[i]];
        int* val1 = new int[n1[i]];
        for(int j = 0; j < n1[i]; j++) {
            wt1[j] = rand() % 100 + 1;
            val1[j] = rand() % 100 + 1;
        }

        for(int j = 0; j < 4; j++) {

            clock_t start = clock();
            int v0 = recursive_knap(w[j], wt0, val0, n0[i]);
            clock_t end = clock();
            double time_0 = (end - start) / (double) CLOCKS_PER_SEC;

            start = clock();
            int v1 = dynamic_knap(w[j], wt1, val1, n1[i]);
            end = clock();
            double time_1 = (end - start) / (double) CLOCKS_PER_SEC;

            std::cout << "rec n = " << n0[i] << ", dyn n = " << n1[i] << ", w = " << w[j] << ", rec time = " << time_0 << ", dyn time = " << time_1 << ", max rec = " << v0 << ", dyn max = " << v1 << std::endl;

        }

        delete[] wt0;
        delete[] val0;
        delete[] wt1;
        delete[] val1;

    }

    return 0;

}