#include "stdfax.h"
#include "cmd.h"
/*
    模块化：通过将函数声明放在一个独立的头文件中，可以将相关的函数组织在一起。这样做有助于代码的组织和模块化，使得代码更加清晰、易于维护和扩展。

    避免重复包含：使用#pragma once指令可以确保头文件只被包含一次，避免了重复定义的问题。这对于大型项目尤其重要，因为如果多个源文件都包含了同一个头文件，可能会导致编译错误或运行时问题。

    提高编译效率：当编译器处理源文件时，它只需要查看头文件一次来获取函数声明信息。这样可以减少编译时间，特别是在大型项目中，因为不需要每次都重新解析相同的函数声明。

    便于团队协作：将函数声明放在一个单独的头文件中，可以让团队成员更容易地了解和使用这些函数。其他开发人员只需包含这个头文件，而无需关心具体的实现细节。这有助于减少沟通成本，提高团队协作效率。

    隐藏实现细节：将函数声明与实现分离，有助于隐藏实现细节。这意味着其他模块只需要知道如何使用这些函数，而不必了解它们的具体实现方式。这有助于降低模块间的耦合度，提高代码的可维护性和可扩展性。
*/
#include "Linker.h"

void Create(){
    MyCreateList();
}

void Add(){
    MyAddNode();
}

void Insert(){
    MyInsertNode();
}

void Delete(){
    MyDeleteNode();
}

void Clearn(){
    MyClearnList();
}

void Modify(){
    MyModifyNode();
}

void Find(){
    MyShowNode();
}

void Show(){
    MyShowList();
}

void Help(){
    MyHelp();
}

void Exit(){
    exit(0);
}

CMD_MAP g_Cmd_Map[] = {
    {"Create", Create},
    {"Add", Add},
    {"Insert", Insert},
    {"Delete", Delete},
    {"Clearn", Clearn},
    {"Modify", Modify},
    {"Find", Find},
    {"Show", Show},
    {"Help", Help},
    {"Exit", Exit},
    {"NULL", NULL}
};

int main(){
    system("title 双向链表 2024.7.13");
    system("color 0e");

    Help();

    char szCmdBuf[20] = "";
    CMD_MAP *pCmdMap = NULL;

    while(true){
        pCmdMap = g_Cmd_Map;
        cout << "请输入命令：";
        cin >> szCmdBuf;

        while(true){
            system("cls");
            if(strcmp(szCmdBuf , pCmdMap->m_szcmd) == 0){
                pCmdMap->m_pfun();
                break;
            }
            if(pCmdMap->m_szcmd == "NULL"){
                cout << "命令错误，请重新输入！" << endl;
                break;
            }
            pCmdMap++;
        }
    }
    return 0;
}