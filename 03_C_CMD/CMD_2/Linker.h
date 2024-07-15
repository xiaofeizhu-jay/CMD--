#pragma once

struct node{
    char m_szName[20]; //姓名
    char m_szSex[4];   //性别
    int m_Age;         //年龄
    char m_szAddr[100];//地址
    char m_szTel[20];  //电话

    node *m_pNext;     //指向下一个节点
    node *m_pFront;    //指向上一个节点
};

void MyCreateList();              //创建一个链表
void MyInputNode(node& pt);       //输入一个刚创建好的空白节点
void MyOutputNode(node& pt);      //输出一个已经存在的结点
void MyShowList();                //显示链表
void MyHelp();                    //帮助
void MyExit();                    //退出
node* MyAddNode();                //在链表尾部添加一个节点
node& MyFindNode(char *FindName); //根据姓名查找
void MyShowNode();                //等价于MyFindNode() + MyOutputNode()
void MyModifyNode();              //修改一个节点
void MyDeleteNode();              //删除一个节点
void MyInsertNode();              //插入一个节点
void MyClearnList();               //清空链表