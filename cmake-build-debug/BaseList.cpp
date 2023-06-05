//
// Created by 26395 on 2023/6/1.
//

#include "BaseList.h"

using namespace std;
BaseList::BaseList(){
    this->header = nullptr;
    this->last = nullptr;
    this->next = nullptr;
}
BaseList* BaseList::headerList(){
    if(this->lastList() == nullptr){
        this->header = this;
    }
    if(this->header == nullptr){
        this->header = this->lastList()->headerList();
    }
    return(this->header);
}
BaseList* BaseList::endList(){
    BaseList* end = this;
    if(this->nextList() != nullptr){
        end = this->nextList()->endList();
    }
    return end;
}
BaseList* BaseList::nextList(){
    return(this->next);
}
BaseList* BaseList::lastList(){
    return(this->last);
}
BaseList* BaseList::numberToList(int number){
    if(number > this->listLong()){
        return(nullptr);
    }
    BaseList* node = this->headerList();
    for(int pointer = 0; pointer <= number; pointer ++){
        node = node->nextList();
    }
    return node;
}
int BaseList::listLong(){
    BaseList* node = this->headerList();
    int listNumber = 0;
    do{
        listNumber ++;
        node = node->nextList();
    }while(node != nullptr);
    return(listNumber);
}
void BaseList::insertBefore(void* newnode, void* node){
    try {
        if(newnode == nullptr || node == nullptr){throw "know node from nullptr";}
        BaseList *temp = ((BaseList*)node)->nextList();
        ((BaseList*)node)->next = ((BaseList*)newnode);
        ((BaseList*)newnode)->last = ((BaseList*)node);
        ((BaseList*)newnode)->next = temp;
    }catch(const char* msg){
        cerr << msg << endl;
    }
}
void BaseList::insertAfter(void* newnode, void* node){
    try{
        if(newnode == nullptr || node == nullptr){throw "know node from nullptr";}
        BaseList * temp = ((BaseList*)node)->lastList();
        ((BaseList*)node)->last = ((BaseList*)newnode);
        ((BaseList*)newnode)->next = ((BaseList*)node);
        ((BaseList*)newnode)->last = temp;
        if (node == ((BaseList*)node)->headerList()){
            ((BaseList*)newnode)->header = ((BaseList*)newnode)->headerList();
        }
    }catch(const char* msg){
        cerr << msg << endl;
    }
}
void BaseList::push(void* newnode){
    try{
        if(newnode == nullptr){throw "know node from nullptr";}
        BaseList* temp = this->endList();
        ((BaseList*)newnode)->last = temp;
        ((BaseList*)newnode)->next = temp->nextList();
        temp->next = ((BaseList*)newnode);
    }catch(const char* msg){
        cerr << msg << endl;
    }
}
void BaseList::deleteList(void *node){
    try{
        if(node == nullptr){throw "know node from nullptr";}
        ((BaseList*)node)->lastList()->next = ((BaseList*)node)->nextList();
        ((BaseList*)node)->lastList()->last = ((BaseList*)node)->lastList();
        delete ((BaseList*)node);
    }catch(const char* msg){
        cerr << msg << endl;
    }
}
void BaseList::deleteList(){
    this->lastList()->next = this->nextList();
    this->lastList()->last = this->lastList();
    delete this;
}
void BaseList::exchangeList(void* newnode, void* node){
    ((BaseList*)newnode)->last = ((BaseList*)node)->lastList();
    ((BaseList*)node)->lastList()->next = ((BaseList*)newnode);
    ((BaseList*)newnode)->next = ((BaseList*)node)->nextList();
    ((BaseList*)node)->nextList()->last = ((BaseList*)newnode);
}