#include <iostream>
#include <fstream>

#include "famKnap.h"

int main(int argc, char** argv) {

    std::ifstream f;
    f.open("shopping.txt");

    int l, n, *wt, *val, nf, *fam;
    f >> l;

    for(int i = 0; i < l; i++) {

        f >> n;
        wt = new int[n];
        val = new int[n];

        for(int j = 0; j < n; j++) {
            f >> val[j];
            f >> wt[j];
        }

        f >> nf;
        fam = new int[nf];
        for(int j = 0; j < nf; j++) {
            f >> fam[j];
        }
        std::vector<int>* r = famKnap(fam, nf, wt, val, n);
        int t = 0;
        for(int j = 0; j < nf; j++) t += r[j][0];
        
        std::cout << "Test Case: " << i << std::endl << "Total Price: " << t << std::endl
            << "Member Items:" << std::endl;
        for(int j = 0; j < nf; j++) {
            std::cout << "\t" << j + 1 << ": ";
            for(int k = r[j].size() - 1; k > 0 ; k--)
                std::cout << r[j][k] << " ";
            std::cout << std::endl;
        }

        delete[] r;

    }

    return 0;

}