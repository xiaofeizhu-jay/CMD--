#pragma once

struct node{
    char m_szName[20];
    int m_Age;
    char m_szSex[4];
    char m_szAddr[100];
    char m_szTel[20];

    node *m_pNext;
    node *m_pFront;
};

void MyInputNode(node& pt);       //输入一个刚创建好的空白节点

void MyOutputNode(node& pt);      //输出一个已经存在的结点

void MyCreateList();

node& MyAdd_Node();               //单独只是创建一个节点

node* MyAddNode();                //在链表尾部添加一个节点

void MyShowList();

void MyShowNode();                //等价于MyFindNode() + MyShowNode()

node& MyFindNode(char *FindName); //根据姓名查找

void MyInsertFront(char* ptName , node* pResFindNode , node* pNew);   //前插（插在查询到的结点之前）

void MyInsertNext(char* ptName , node* pResFindNode , node* pNew);    //后插（插在查询到的结点之后）

void MyInsertNode();              //插入一个节点

void MyModifyNode();              //修改一个节点

void MyDeleteNode();              //删除一个节点

void MyClearnList();              //清空链表

void MyHelp();                    //帮助

void MyExit();                    //退出
