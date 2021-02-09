#include "activity.h"

#include <iostream>

int main(int argc, char** argv) {

    std::ifstream f;
    f.open("act.txt");

    int n, i = 1;
    do {

        f >> n;

        std::vector<activity> v = load(f, n);
        std::vector<activity> s = schedule(v);

        std::cout << "Set " << i++ << std::endl;
        print(s);
        std::cout << std::endl;

    } while(!f.eof());

    f.close();

    return 0;

}