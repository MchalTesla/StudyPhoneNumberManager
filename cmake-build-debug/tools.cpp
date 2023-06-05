//
// Created by 26395 on 2023/6/5.
//

#include "tools.h"
#include "MainClass.h"

bool Tools::Filtration(string &ch){
    if (ch.length() == 0) {
        return false;
    }
    char* s = (char*)malloc(ch.length() + 1);
    strcpy(s, ch.data());
    int i = 0;
    int j = 0;
    for (i = 0; s[i]; i++) {	//英文，及标点符号判断，因为英文不管是utf-8编码还是gbk编码，都是以一个字节，并且每个字节都是大于零的
        if (s[i] < 0) {
            s[j++] = s[i];
        }
    }
    s[j] = 0;
    int n = 0;
    while (s[n]) {
        if (s[n] == (modelength == 3 ? -30 : -95) || s[n] == (modelength == 3 ? -19 : -93) \
			|| s[n] == (modelength == 3 ? -17 : 0)) {	//进行中文标点符号判断，当编码为gbk时，中文标点符号的第一个字节主要在-95，-93；当编码为utf-8时，中文标点符号的第一个字节主要在-30,-19,-17
            free(s);
            return false;
        }
        n += modelength;
    }
    if (ch.length() == strlen(s)) {
        free(s);
        return true;
    }
    else {
        free(s);
        return false;
    }
}
int Tools::choose(int left, int right){
    int choosesta = 0;
    while (!(cin >> choosesta) || (getchar() == 10 ? ungetc(10, stdin), false : true) || choosesta < left || choosesta > right) {	//通过判断数字后的一个字符是不是回车，就可以是否为纯数字
        cout << "Input error, please retype" << endl;	//进行数字判断，当数字超过限定范围时或者不是数字的时候将回驳回
        flushstd;		//清空stdin缓冲区
        cin.clear();	//清空cin状态
    }
    getchar();
    return choosesta;
}
string Tools::cinstr(int left, int right){
    string out0 = "It must be in pure Chinese and the length must be between";
    string out1 = to_string(left);
    string out2 = "to";
    string out3 = to_string(right);
    string out4 = "Chinese character, please re-enter\n";
    out0 = out0 + out1 + out2 + out3 + out4;
    string name;
    while (!(cin >> name) || (getchar() == 10 ? ungetc(10, stdin), false : true) || !Filtration(name) || name.length() < left*modelength || name.length() > right*modelength) {	//通过判断getc的字符是不是回车，就可以判断stdin缓冲区是否为空
        cout << out0;		//进行中文判断，当中文超过限定范围时或者不是中文的时候将回驳回
        flushstd;
        cin.clear();
    }
    return name;
}