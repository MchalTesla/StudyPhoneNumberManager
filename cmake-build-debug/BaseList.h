//
// Created by 26395 on 2023/6/1.
//

#ifndef PHONENUMBERMANAGER_BASELIST_H
#define PHONENUMBERMANAGER_BASELIST_H
#include <iostream>

class BaseList {
protected:
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
    virtual void copy(void* newnode, void* oldnode);
    void insertBefore(void* newnode, void* node);
    void insertAfter(void* newnode, void* node);
    void push(void* newnode);
    void deleteList(void* node);
    void deleteList();
    void coverList(void* newnode, void* node);
    void exchangeList(void* node_1, void* node_2);
    virtual void* test_NewNode() = 0;
};


#endif //PHONENUMBERMANAGER_BASELIST_H
