//
// Created by 26395 on 2023/6/5.
//

#ifndef PHONENUMBERMANAGER_STUDY_H
#define PHONENUMBERMANAGER_STUDY_H

#include "BaseList.h"
#include "tools.h"
#include <string>
#include <iostream>

using namespace std;
class Study: public BaseList{
public:
    Study* headerList() override;
    Study* endList() override;
    Study* nextList() override;
    Study* lastList() override;
    Study* numberToList(int number) override;
    void copy(void* newnode, void* oldnode);
    void* test_NewNode();
    string studyName;
    string studyPhone;
    int studyAge = 0;
    int studyGender = 0;

    void ascSort();
    void descSort(int left, int right);
};


#endif //PHONENUMBERMANAGER_STUDY_H
