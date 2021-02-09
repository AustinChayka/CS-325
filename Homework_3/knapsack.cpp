#include "knapsack.h"

int max(int a, int b) {

    return (a > b) ? a : b;

}

int recursive_knap(int w, int* wt, int* val, int n) {

    if(n == 0 || w == 0) return 0;

    if(wt[n - 1] > w) return recursive_knap(w, wt, val, n - 1);
    else return max(
        val[n - 1] + recursive_knap(w - wt[n - 1], wt, val, n - 1),
        recursive_knap(w, wt, val, n - 1)
    );

}

int dynamic_knap(int w, int* wt, int* val, int n) {

    int** t = new int*[n + 1];
    for(int i = 0; i < n + 1; i++) t[i] = new int[w + 1];

    for(int i = 0; i < n + 1; i++) for(int j = 0; j < w + 1; j++) {

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

    int r = t[n][w];

    for(int i = 0; i < n + 1; i++) delete[] t[i];
    delete[] t;

    return r;

}