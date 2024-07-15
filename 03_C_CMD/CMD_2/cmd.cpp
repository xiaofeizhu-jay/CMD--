#include "stdfax.h"
#include "Linker.h"
#include "cmd.h"

void Create(){
    MyCreateList();
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

void Add(){
    MyAddNode();
}

void Find(){
    return MyShowNode();
}

void Modify(){
    MyModifyNode();
}

void Delete(){
    MyDeleteNode();
}

void Insert(){
    MyInsertNode();
}

void Clearn(){
    MyClearnList();
}

CMD_MAP g_Cmd_Map[] = {
    {"Create", Create},
    {"Show", Show},
    {"Help", Help},
    {"Exit", Exit},
    {"Add",  Add},
    {"Find", Find},
    {"Modify",Modify},
    {"Delete", Delete},
    {"Insert", Insert},
    {"Clearn", Clearn},
    {"NULL", NULL}
};

int main(){
    Help();

    char szCmdBuf[20]="";
    CMD_MAP *pCmdMap = NULL;
    while(true){
        cout << "请输入命令：";
        cin >> szCmdBuf;
        pCmdMap = g_Cmd_Map;

        while(true){
            if(strcmp(pCmdMap->m_szcmd , szCmdBuf) == 0){
                cout << "命令正确，正在执行..." << endl;
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