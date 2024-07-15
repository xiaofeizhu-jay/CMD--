#include "stdfax.h"
#include "cmd.h"
/*
    ģ�黯��ͨ����������������һ��������ͷ�ļ��У����Խ���صĺ�����֯��һ�������������ڴ������֯��ģ�黯��ʹ�ô����������������ά������չ��

    �����ظ�������ʹ��#pragma onceָ�����ȷ��ͷ�ļ�ֻ������һ�Σ��������ظ���������⡣����ڴ�����Ŀ������Ҫ����Ϊ������Դ�ļ���������ͬһ��ͷ�ļ������ܻᵼ�±�����������ʱ���⡣

    ��߱���Ч�ʣ�������������Դ�ļ�ʱ����ֻ��Ҫ�鿴ͷ�ļ�һ������ȡ����������Ϣ���������Լ��ٱ���ʱ�䣬�ر����ڴ�����Ŀ�У���Ϊ����Ҫÿ�ζ����½�����ͬ�ĺ���������

    �����Ŷ�Э������������������һ��������ͷ�ļ��У��������Ŷӳ�Ա�����׵��˽��ʹ����Щ����������������Աֻ��������ͷ�ļ�����������ľ����ʵ��ϸ�ڡ��������ڼ��ٹ�ͨ�ɱ�������Ŷ�Э��Ч�ʡ�

    ����ʵ��ϸ�ڣ�������������ʵ�ַ��룬����������ʵ��ϸ�ڡ�����ζ������ģ��ֻ��Ҫ֪�����ʹ����Щ�������������˽����ǵľ���ʵ�ַ�ʽ���������ڽ���ģ������϶ȣ���ߴ���Ŀ�ά���ԺͿ���չ�ԡ�
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
    system("title ˫������ 2024.7.13");
    system("color 0e");

    Help();

    char szCmdBuf[20] = "";
    CMD_MAP *pCmdMap = NULL;

    while(true){
        pCmdMap = g_Cmd_Map;
        cout << "���������";
        cin >> szCmdBuf;

        while(true){
            system("cls");
            if(strcmp(szCmdBuf , pCmdMap->m_szcmd) == 0){
                pCmdMap->m_pfun();
                break;
            }
            if(pCmdMap->m_szcmd == "NULL"){
                cout << "����������������룡" << endl;
                break;
            }
            pCmdMap++;
        }
    }
    return 0;
}