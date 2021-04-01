#include <vector>
#include <fstream>
#include <iostream>

#include "points.h"

int main(int argc, char** argv) {

    std::ifstream f;
    f.open("graph.txt");

    int n;
    f >> n;
    for(int i = 0; i < n; i++) {

        std::vector<p> v = loadPoints(f);
        std::vector<link> l = prim(v);

        int tW = 0;
        std::cout << "Test case " << i + 1 << ":" << std::endl << "Edges in MST" << std::endl << "Points (x, y)\t\t\tDistance" << std::endl;
        for(int j = 0; j < l.size(); j++) {
            print(v[l[j].p0]);
            std::cout << " - ";
            print(v[l[j].p1]);
            std::cout << "  \t\t" << l[j].w << std::endl;
            tW += l[j].w;
        }
        std::cout << "\tTotal Discance: " << tW << std::endl << std::endl;

    }

    return 0;

}