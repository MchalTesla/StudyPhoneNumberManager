//
// Created by 26395 on 2023/6/5.
//

#ifndef PHONENUMBERMANAGER_MAIN_H
#define PHONENUMBERMANAGER_MAIN_H

#endif //PHONENUMBERMANAGER_MAIN_H
#include <string>
#include <cstring>
#include "study.h"
#define flushstd while (getchar() != '\n')
#ifdef __linux__
#define cls "clear"
#elif _WIN32
#define cls "cls"
#else
#define cls "clear"
#endif
constexpr int modelength = sizeof("模") - 1;
using namespace std;

class MainClass{
public:
    string filename = "student1.txt";
    Study* study = nullptr;
    Tools* tools = nullptr;
    bool state = true;

    MainClass();
    ~MainClass();
    void buildNewNode();
    bool findRepeat(string& tname);
    void show();
    void search();
    void editStu();
    void deleteStu();
    void import();
    void readfile();
    bool savefile(bool force);
    bool can_open();
    void ageAscSort();
    void ageDescSort();
    void allStudyNumber();
    bool add(Study* node);
    void putstu(Study* node);
    void closeAll();
};
