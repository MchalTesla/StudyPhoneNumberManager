//
// Created by 26395 on 2023/6/5.
//

#include "study.h"

Study* Study::headerList(){
    return (Study*)this->BaseList::headerList();
}
Study* Study::endList(){
    return (Study*)this->BaseList::endList();
}
Study* Study::nextList(){
    return (Study*)this->next;
}
Study* Study::lastList(){
    return (Study*)this->last;
}
Study* Study::numberToList(int number){
    return (Study*)this->BaseList::numberToList(number);
}
void Study::ascSort(){
    int i,j,gap;
    BaseList* key = nullptr;
    for(gap = this->listLong(); gap > 0; gap /= 2){
        for(i = gap; i < this->listLong(); i += gap){
            key = this->numberToList(i);
            for(j = i - gap; j >= 0 && this->numberToList(j) > key; j -= gap){
                this->exchangeList(this->numberToList(j), this->numberToList(j+gap));
            }
            this->exchangeList(key, this->numberToList(j+gap));
        }
    }
}
void Study::descSort(){
    int i,j,gap;
    BaseList* key = nullptr;
    for(gap = this->listLong(); gap > 0; gap /= 2){
        for(i = gap; i < this->listLong(); i += gap){
            key = this->numberToList(i);
            for(j = i - gap; j >= 0 && this->numberToList(j) < key; j -= gap){
                this->exchangeList(this->numberToList(j), this->numberToList(j+gap));
            }
            this->exchangeList(key, this->numberToList(j+gap));
        }
    }
}