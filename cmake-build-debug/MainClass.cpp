//
// Created by 26395 on 2023/6/5.
//
#include "MainClass.h"
#include <iomanip>
#include <fstream>

MainClass::MainClass(){
    this->study = new Study;
}
MainClass::~MainClass(){
    Study* temp = this->study->headerList();
    while(temp != nullptr){
        Study* lastTemp = temp;
        temp = temp->nextList();
        delete lastTemp;
    }
}
void MainClass::buildNewNode(){
    Study* temp = new Study;
    this->add(temp);
    this->study->push(temp);
}
bool MainClass::findRepeat(string &tname){
    Study* temp = this->study->headerList();
    while(temp->nextList() != nullptr){
        temp = temp->nextList();
        if(temp -> studyPhone == tname){
            return true;
        }
    }
    return false;
}
bool MainClass::add(Study *node){
    cout << "电话号码(长度为11个字符,输入“0”返回):" << endl;
    string stupho;
    cin >> stupho;
    if ((getchar() == 10 ? ungetc(10, stdin), true : false) && cin.good() && stupho == "0") {		//这些都是进行非法输入判断
        getchar();
        return false;
    }
    while ((getchar() == 10 ? ungetc(10, stdin), false : true) || cin.fail() || strspn(stupho.data(), "0123456789") != stupho.length() || stupho.length() != 11) {
        if ((getchar() == 10 ? ungetc(10, stdin), true : false) && cin.good() && stupho == "0") {
            getchar();
            return false;
        }
        cout << "电话号码应为纯数字且长度为11个字符,请重新输入" << endl;
        flushstd;
        cin.clear();
        cin >> stupho;
    }
    getchar();
    if (this->findRepeat(stupho) == true) {
        cout << "已有此同学" << endl;
        return false;
    }
    node->studyPhone = stupho;
    cout << "姓名:\t";
    node->studyName = this->tools->cinstr(2, 4);
    cout << "性别(女-0,男-1):\t";
    node->studyGender = this->tools->choose(0,1);
    cout << "年龄:\t";
    node->studyAge = this->tools->choose(0, 120);
    return true;
}
void MainClass::putstu(Study* node){
    cout << node->studyName << "\t";
    cout << node->studyPhone << "\t";
    cout << node->studyGender << "\t";
    cout << node->studyAge << "\n";
}
void MainClass::show(){
    if(this->study->listLong() > 0){
        Study* temp = this->study->headerList();
        while(temp->nextList() != nullptr){
            temp = temp->nextList();
            putstu(temp);
        }
    }else{
        cout << "无数据" << endl;
    }
    cout << endl;
}
void MainClass::search(){
    if(this->study->listLong() > 0){
        cout << "请输入要查询学生的电话号或者姓名，输入“0”退出" << endl;
        string TNAME;
        cin >> TNAME;
        flushstd;
        if (TNAME == "0") {
            return;
        }
        if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//判断输入的是学号还是姓名
            Study* temp = this->study->headerList();
            while(temp->nextList() != nullptr){	//学号执行
                temp = temp->nextList();
                if (temp->studyPhone == TNAME) {
//                    DIRECTORY(true);
                    this->putstu(temp);
                    return;
                }
            }
        }
        else {
            bool state = false;
            Study* temp = this->study->headerList();
            while(temp->nextList() != nullptr){	//姓名执行
                temp = temp->nextList();
                if (temp->studyName == TNAME) {
                    state = true;
//                    DIRECTORY(true);
                    this->putstu(temp);
                }
            }
            if (state == true) {
                return;
            }
        }
        cout << "没有此学生" << endl;
        return;
    }else{}
    cout << "无数据" << endl;
    return;
}
void MainClass::editStu(){
    if (this->study->listLong() > 0){
        cout << "请输入编辑学生的学号或者姓名,输入“0”返回" << endl;
        string TNAME;
        cin >> TNAME;
        flushstd;
        if (TNAME == "0") {
            return;
        }
        if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//判断输入的是电话号还是姓名
            Study* temp = this->study->headerList();
            while(temp->nextList() != nullptr){
                temp = temp->nextList();	//电话号执行
                if (temp->studyPhone == TNAME) {
//                    DIRECTORY(true);
                    this->putstu(temp);
                    cout << "确认修改？（1.确认 0.取消）" << endl;
                    if (this->tools->choose(0, 1)) {
                        bool state = this->add(temp);
//                        DIRECTORY(true);
                        this->putstu(temp);
                        if(state) cout << "修改成功" << endl;
                    }
                    return;
                }
            }
        }
        else {
            bool state = false;
            Study* temp = this->study->headerList();
            while(temp->nextList() != nullptr) {	//姓名执行
                temp = temp->nextList();
                if (temp->studyName == TNAME) {
                    state = true;
//                    DIRECTORY(true);
                    this->putstu(temp);
                    cout << "确认修改？（1.确认 0.取消）" << endl;
                    if (this->tools->choose(0, 1)) {
                        bool state = this->add(temp);
//                        DIRECTORY(true);
                        this->putstu(temp);
                        if(state) cout << "修改成功" << endl;
                    }
                }
            }
            if (state == true) {		//如果成功进行了一次修改，则结束函数
                return;
            }
        }
        cout << "没有此学生" << endl;
        return;
    }else{
        cout << "无数据" << endl;
        return;
    }
}
void MainClass::deleteStu(){
    if(this->study->listLong() > 0){
        cout << "请输入需要删除学生的电话号或者姓名,输入“0”返回" << endl;
        string TNAME;
        cin >> TNAME;
        flushstd;
        if (TNAME == "0") {
            return;
        }
        if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//判断输入的是学号还是姓名
            Study* temp = this->study->headerList();
            while(temp->nextList() != nullptr){	//电话号执行
                temp = temp->nextList();
                if (temp->studyPhone == TNAME) {
//                    DIRECTORY(true);
                    this->putstu(temp);
                    cout << "确认删除？（1.确认 0.取消）" << endl;
                    if (this->tools->choose(0, 1)) {
                        temp->deleteList();
                        cout << "删除成功" << endl;
                    }
                    return;
                }
            }
        }
        else {
            bool state = false;
            _delete_1:
            Study* temp = this->study->headerList();
            while(temp->nextList() != nullptr){	//姓名执行
                temp = temp->nextList();
                if (temp->studyName == TNAME) {
                    state = true;
//                    DIRECTORY(true);
                    this->putstu(temp);
                    cout << "确认删除？（1.确认 0.取消）" << endl;
                    if (this->tools->choose(0, 1)) {
                        temp->deleteList();
                        cout << "删除成功" << endl;
                        goto _delete_1;
                    }
                }
            }
            if (state == true) {	//如果成功删除了一次，则结束函数
                return;
            }
        }
        cout << "没有此学生" << endl;
        return;
    }else{
        cout << "无数据" << endl;
        return;
    }
}
void MainClass::import(){
    cout << "请将需要导入的文件拖入此处:";
    string filename;
    cin >> filename;		//将文件拖入到命令栏中会自动输入文件的位置，使用这种方法可以进行文件导入
    flushstd;
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {		//判断文件是否可以打开
        cout << "文件不存在" << endl;
    }
    else if (infile.get(), infile.eof()) {
        cout << "文件内无数据" << endl;
    }
    else {
        infile.seekg(ios::beg);
        while (infile.get(), !infile.eof()) {		//进行文件是否读取完毕判断
            infile.seekg(-1, ios::cur);
            Study* temp = new Study;
            if (infile >> temp->studyName >> temp->studyPhone >> temp->studyAge >> temp->studyGender, infile.fail() || infile.get() != 10)		//对文件的读取进行正确性判断，判断是否读取错误
            {
                cout << "文件无法导入" << endl;
                delete temp;
                return;
            }
            else if (this->findRepeat(temp->studyPhone)) {delete temp; }
            else { this->study->push(temp); }
        }
        infile.close();
        cout << "文件导入成功" << endl;
    return;
    }
}
void MainClass::readfile(){
    if (!this->can_open()) {		//判断文件是否可以打开
        this->state = false;
        return;
    }
    else {
        ifstream infile;
        infile.open(filename);
        if (infile.get(), infile.eof()) {
            return;
        }
        infile.seekg(ios::beg);
        while (infile.get(), !infile.eof()) {	//进行文件是否读取完毕判断
            infile.seekg(-1, ios::cur);
            Study* temp = new Study;
            if (infile >> temp->studyName >> temp->studyPhone >> temp->studyAge >> temp->studyGender, infile.fail() || infile.get() != 10)		//对文件的读取进行正确性判断，判断是否读取错误
            {
                cout << "文件无法导入" << endl;
                delete temp;
                this->state = false;		//如果读入失败，则会关闭程序
                return;
            }
            else { this->study->push(temp); }
        }
        infile.close();
        return;
    }
}
bool MainClass::savefile(bool force){
    if (this->study->listLong() < 1 && !force) {		//判断链表中是否有属于
        cout << "无数据" << endl;
        return false;
    }
    else if (!this->can_open()) {		//判断文件是否可以打开
        return false;
    }
    else {
        ofstream tmpfile;
        tmpfile.open(".tmpfile");
        bool error = false;
        Study* temp = this->study->headerList();
        while(temp->nextList() != nullptr) {	//对文件的写入进行正确性判断，判断是否读取错误
            temp = temp->nextList();
            tmpfile << temp->studyName << ' ' << temp->studyPhone << ' ' << temp->studyAge << ' ' << temp->studyGender << endl;
            error = tmpfile.fail();
        }
        tmpfile.close();
        if (!error) {
            remove(filename.data());
            if (rename(".tmpfile", filename.data()) == 0) {
                cout << "保存成功" << endl;
                return true;
            }
        }
        cout << "保存失败" << endl;
        return false;
    }
}
bool MainClass::can_open(){
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        cout << filename << "不存在" << endl;
        cout << "是否创建一个新的" << filename << "（1.是 0.否）" << endl;
        if (this->tools->choose(0, 1)) {
            ofstream tempfile;
            tempfile.open(filename);
            if (tempfile.is_open()) {
                cout << "文件创建成功\n" << endl;
                tempfile.close();
                return true;
            }
            else {
                cout << "文件创建失败\n" << endl;
            }
        }
        return false;
    }
    else {
        infile.close();
        return true;
    }
}
void MainClass::allStudyNumber(){
    cout << "学生总数:" << this->study->listLong() << endl;
}
void MainClass::ageAscSort(){
    this->study->ascSort();
    this->show();
}
void MainClass::ageDescSort(){
    this->study->descSort();
    this->show();
}
void MainClass::closeAll(){
    cout << "确认退出?(1.确认,0.取消)" << endl;
    if(this->tools->choose(0, 1) == 1) {
        Study *temp = this->study->headerList();
        while (temp != nullptr) {
            Study *lastTemp = temp;
            temp = temp->nextList();
            delete lastTemp;
        }
        this->study = new Study;
    }
    return;
}