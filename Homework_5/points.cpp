#include "points.h"

#include <math.h>
#include <iostream>

int d(p& a, p& b) {

    return round(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));

}

std::vector<p> loadPoints(std::ifstream& f) {

    std::vector<p> v;
    int n;

    f >> n;
    for(int i = 0; i < n; i++) {

        p temp;
        temp.n = i;
        f >> temp.x >> temp.y;
        v.push_back(temp);

    }

    return v;

}

void print(p& a) {

    std::cout << "(" << a.x << ", " << a.y << ")";

}

link makeLink(p& a, p& b) {

    link temp;
    temp.p0 = a.n;
    temp.p1 = b.n;
    temp.w = d(a, b);
    return temp;

}

link minLink(p& p0, std::vector<p>& v) {

    int min = d(p0, v[0]), vMin = 0, n;
    
    for(int i = 1; i < v.size(); i++) {

        n = d(p0, v[i]);
        if(n < min) {
            min = n;
            vMin = i;
        }

    }

    return makeLink(p0, v[vMin]);

}

std::vector<link> prim(std::vector<p>& v) {

    std::vector<link> links;
    std::vector<p> chosen, remaining = v;

    chosen.push_back(v[0]);
    remaining.erase(remaining.begin() + 0);

    while(remaining.size() > 0) {

        link min = minLink(chosen[0], remaining), temp;
        for(int i = 1; i < chosen.size(); i++) {

            temp = minLink(chosen[i], remaining);
            if(temp.w < min.w) min = temp;

        }

        links.push_back(min);
        for(int i = 0; i < remaining.size(); i++) {
            if(remaining[i].n == min.p1) {
                chosen.push_back(remaining[i]);
                remaining.erase(remaining.begin() + i);
            }
        }

    }

    return links;

}