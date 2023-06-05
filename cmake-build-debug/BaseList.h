//
// Created by 26395 on 2023/6/1.
//

#ifndef PHONENUMBERMANAGER_BASELIST_H
#define PHONENUMBERMANAGER_BASELIST_H
#include <iostream>

class BaseList {
public:
    BaseList* header = nullptr;
    BaseList* last = nullptr;
    BaseList* next = nullptr;
public:
    BaseList();
    virtual BaseList* headerList();
    virtual BaseList* endList();
    virtual BaseList* nextList();
    virtual BaseList* lastList();
    virtual BaseList* numberToList(int number);
    int listLong();
    void insertBefore(void* newnode, void* node);
    void insertAfter(void* newnode, void* node);
    void push(void* newnode);
    void deleteList(void* node);
    void deleteList();
    static void exchangeList(void* newnode, void* node);
};


#endif //PHONENUMBERMANAGER_BASELIST_H
