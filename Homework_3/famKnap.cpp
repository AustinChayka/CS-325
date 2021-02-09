#include "famKnap.h"

#include <iostream>
#include <fstream>

int max(int a, int b) {

    return (a > b) ? a : b;

}

std::vector<int>* famKnap(int* fam, int n_fam, int* wt, int* val, int n) {

    std::vector<int>* r = new std::vector<int>[n_fam];

    for(int f = 0; f < n_fam; f++) {

        int** t = new int*[n + 1];
        for(int i = 0; i < n + 1; i++) t[i] = new int[fam[f] + 1];

        for(int i = 0; i < n + 1; i++) for(int j = 0; j < fam[f] + 1; j++) {

            if(i == 0 || j == 0) 
                t[i][j] = 0;
            else if(wt[i - 1] <= j) 
                t[i][j] = max(
                    val[i - 1] + t[i - 1][j - wt[i - 1]],
                    t[i - 1][j]
                );
            else 
                t[i][j] = t[i - 1][j];

        }

        int v = t[n][fam[f]];
        r[f].push_back(v);
        
        int j = fam[f];
        for(int i = n; i > 0 && v > 0; i--) {
            if(v == t[i - 1][j]) continue;
            else {
                r[f].push_back(i);
                v -= val[i - 1];
                j -= wt[i - 1];
            }
        }

        for(int i = 0; i < n + 1; i++) delete[] t[i];
        delete[] t;

    }

    return r;

}