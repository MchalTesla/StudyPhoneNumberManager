//
// Created by 26395 on 2023/6/5.
//

#ifndef PHONENUMBERMANAGER_TOOLS_H
#define PHONENUMBERMANAGER_TOOLS_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Tools {
public:
    bool Filtration(string& ch);
    int choose(int left, int right);
    string cinstr(int left, int right);
};


#endif //PHONENUMBERMANAGER_TOOLS_H
