//
// Created by 26395 on 2023/6/5.
//
#include "MainClass.h"
using namespace std;
int begin(){
    int space = 0;
    int ret = 0;
    cout << "1.展示学生信息\n";
    cout << "2.新增学生信息\n";
    cout << "3.删除学生信息\n";
    cout << "4.搜索学生信息\n";
    cout << "5.编辑学生信息\n";
    cout << "6.导入学生信息\n";
    cout << "7.保存学生信息\n";
    cout << "8.年龄升序排序\n";
    cout << "9.年龄降序排序\n";
    cout << "10.清空学生信息\n";
    cout << "0.退出学生系统\n\n";
    cout << "请选择：";
    Tools* tools = new Tools;
    int ch = tools->choose(0, 10);
    delete tools;
    return ch;
}
void pause()
{
    cout << "按 Enter 键继续...: ";
    flushstd;
    return;
}
int main()
{
    MainClass* mainclass = new MainClass;
    mainclass->filename = "student1.txt";
    mainclass->readfile();
    Tools* tools = new Tools;
    while (mainclass->state) {
        system(cls);
        switch (begin()) {
            case 1:				//刷新学生信息
                mainclass->show();
                break;
            case 2:				//新增学生信息
                mainclass->buildNewNode();
                break;
            case 3:				//删除学生信息
                mainclass->deleteStu();
                break;
            case 4:				//学生信息搜索
                mainclass->search();
                break;
            case 5:				//学生信息编辑
                mainclass->editStu();
                break;
            case 6:				//导入学生信息
                mainclass->import();
                break;
            case 7:				//保存学生信息
                mainclass->savefile( false);
                break;
            case 8:
                mainclass->ageAscSort();
                break;
            case 9:
                mainclass->ageDescSort();
                break;
            case 10:				//清空学生信息
                mainclass->closeAll();
                break;
            case 0:				//退出
                cout << "1.保存后退出 2.不保存直接退出 3.取消" << endl;
                switch (tools->choose(1, 3)) {
                    case 1:
                        if (mainclass->savefile(false) || (cout << "是否继续（1.是 0.否）", (tools->choose(0, 1) == 1 ? mainclass->savefile(true), true : false))) {
                            mainclass->state = false;
                        }
                        break;
                    case 2:
                        if (cout << "确认不保存退出（1.确认 0.取消）" << endl, tools->choose(0, 1)) {
                            mainclass->state = false;
                        }
                        break;
                    case 3:
                        break;
                }
                break;
        }
        pause();	//按 Enter 继续
    }
    delete tools;
    delete mainclass;
    return 0;
}