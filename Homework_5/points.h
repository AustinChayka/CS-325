#ifndef POINTS_H
#define PONTS_H

#include <vector>
#include <fstream>

struct p {

    int n, x, y;

};

struct link {

    int p0, p1, w;

};

int d(p&, p&);
std::vector<p> loadPoints(std::ifstream&);
std::vector<link> calcLinks(std::vector<p>&);
void print(p&);

std::vector<link> prim(std::vector<p>&);

#endif