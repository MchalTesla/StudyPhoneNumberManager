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
void* Study::test_NewNode(){
    Study* newNode = new Study;
    return newNode;
}
void Study::copy(void* newnode, void* oldnode){
    BaseList::copy(newnode, oldnode);
    ((Study*)newnode)->studyName=((Study*)oldnode)->studyName;
    ((Study*)newnode)->studyPhone=((Study*)oldnode)->studyPhone;
    ((Study*)newnode)->studyAge=((Study*)oldnode)->studyAge;
    ((Study*)newnode)->studyGender=((Study*)oldnode)->studyGender;
}
void Study::ascSort(){
    int i,j,gap;
    Study* key = new Study;
    for(gap = this->listLong()/2; gap > 0; gap /= 2){
        for(i = gap; i < this->listLong(); i += gap){
            this->copy(key, this->numberToList(i));
            for(j = i - gap; j >= 0 && this->numberToList(j)->studyAge > key->studyAge; j -= gap){
                this->exchangeList(this->numberToList(j), this->numberToList(j+gap));
            }
            this->exchangeList(key, this->numberToList(j+gap));
        }
    }
}
void Study::descSort(){
    int i, j, gap;
    Study* key = new Study;
    for(gap = this->listLong() / 2; gap > 0; gap /= 2){
        for(i = gap; i < this->listLong(); i += gap){
            this->copy(key, this->numberToList(i));
            for(j = i - gap; j >= 0 && this->numberToList(j)->studyAge < key->studyAge; j -= gap){
                this->exchangeList(this->numberToList(j), this->numberToList(j+gap));
            }
            this->exchangeList(key, this->numberToList(j+gap));
        }
    }
}