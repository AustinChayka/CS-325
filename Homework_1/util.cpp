#include "util.h"
#include <fstream>
#include <string>

void loadData(std::vector<int>& arr, std::ifstream& f) {

    std::string l, temp = "";
    getline(f, l);
    l += ' ';
    
    for(int i = 0; i < l.size(); i++) {

        if(l[i] != ' ') temp += l[i];
        else {
            if(temp.size() > 0) arr.push_back(std::stoi(temp));
            temp = "";
        }

    }

}

void print(std::vector<int>& arr) {

    for(int i = 0; i < arr.size(); i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

}