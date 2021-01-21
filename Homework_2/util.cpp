#include "util.h"

#include <iostream>
#include <string>
#include <fstream>

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

        for(auto i : arr) std::cout << i << " ";
        std::cout << std::endl;

    }