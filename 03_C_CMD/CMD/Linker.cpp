#include "stdfax.h"
#include "Linker.h"

node *g_phead = NULL;
node *g_pEnd = NULL;

void MyInputNode(node& pt)    //输入一个刚创建好的空白节点
{
    pt.m_pFront = NULL;
    pt.m_pNext = NULL;
    cout << "请输入您的姓名：";
    cin >> pt.m_szName;
    cout << "请输入您的年龄：";
    cin >> pt.m_Age;
    cout << "请输入您的性别：";
    cin >> pt.m_szSex;
    cout << "请输入您的电话：";
    cin >> pt.m_szTel;
    cout << "请输入您的住址：";
    cin >> pt.m_szAddr;
}

void MyOutputNode(node& pt)    //输出一个已有的节点
{
    cout << "姓名：" << pt.m_szName << endl;
    cout << "年龄：" << pt.m_Age << endl;
    cout << "性别：" << pt.m_szSex << endl;
    cout << "电话：" << pt.m_szTel << endl;
    cout << "住址：" << pt.m_szAddr << endl;
}

void MyCreateList()            //创建链表
{
    node *pTemp = new node;

    if(pTemp == NULL)
        cout << "链表创建失败！" << endl;
    else{
        MyInputNode(*pTemp);
        cout << "链表创建成功！" << endl;
    }
    g_phead = pTemp;
    g_pEnd = pTemp;
}

node& MyAdd_Node()            //单独只是创建一个节点
{
    node* pTemp = new node;
    if(pTemp != NULL)
        MyInputNode(*pTemp);
    return *pTemp;
}

node* MyAddNode()            //在链表尾部添加一个节点
{
    if(NULL == g_phead || NULL == g_pEnd)
        cout << "链表尚未创建！" << endl;
    node* pNew = &MyAdd_Node();   //引用的使用
    g_pEnd->m_pNext = pNew;
    pNew->m_pFront = g_pEnd;
    g_pEnd = pNew;
    return NULL;
}

void MyShowList()              //显示链表
{
    int nCount = 1;
    if(g_phead != NULL || g_pEnd != NULL){
        node* pt = g_phead;
        cout << "---------显示链表开始---------" << endl;
        while(pt != NULL){
            cout << "第" << nCount << "个节点：" << endl;
            MyOutputNode(*pt);
            pt = pt->m_pNext;
            nCount++;
        }
        cout << "---------显示链表结束---------" << endl;
    }
}

node& MyFindNode(char *FindName)//根据姓名查找
{
    node* pt = g_phead;
    while(true){
        if(pt != NULL){
            if(strcmp(pt->m_szName , FindName) == 0)
                return *pt;
            else    
                pt = pt->m_pNext;
        }
        else{
            cout << "您要查找的节点不存在！" << endl;
            return *pt;
        }
    }
}

void MyShowNode()              //根据姓名查找信息，等价于MyFindNode() + MyOutputNode()
{
    char szName[20];
    cout << "请输入您要查找的姓名：";
    cin >> szName;
    MyOutputNode(MyFindNode(szName));
}

void MyInsertFront(char* ptName , node* pResFindNode , node* pNew) //前插（插在查询到的节点之前)
{
    if(pResFindNode == g_phead){
        pNew->m_pNext = g_phead;
        g_phead->m_pFront = pNew;
        g_phead = pNew;
    }
    else{
        pNew->m_pFront = pResFindNode->m_pFront;
        pNew->m_pNext = pResFindNode;
        pResFindNode->m_pFront->m_pNext = pNew;
        pResFindNode->m_pFront = pNew;
    }
}

void MyInsertNext(char* ptName , node* pResFindNode , node* pNew)  //后插（插在查询到的节点之后）
{
    if(pResFindNode == g_pEnd){
        pNew->m_pFront = g_pEnd;
        g_pEnd->m_pNext = pNew;
        g_pEnd = pNew;
    }
    else{
        pNew->m_pNext = pResFindNode->m_pNext;
        pNew->m_pFront = pResFindNode;
        pResFindNode->m_pNext->m_pFront = pNew;
        pResFindNode->m_pNext = pNew;
    }
}

void MyInsertNode()            //插入一个节点
{
    char szNameBuf[20] = "";
    cout << "请输入姓名（待会将会选择插入该节点之前或者之后）：";
    cin >> szNameBuf;

    cout << "--------------插入操作开始--------------" << endl;
    node* pNew = &MyAdd_Node();
    node* pResFindNode = &MyFindNode(szNameBuf);

    int nChoose = 1;
    cout << "请选择插入方式（1.前插 2.后插）：" << endl;
    cin >> nChoose;
    if(nChoose == 1)
        MyInsertFront(szNameBuf , pResFindNode , pNew);
    else if(nChoose == 2)
        MyInsertNext(szNameBuf , pResFindNode , pNew);
    else
        cout << "您的选择有误！" << endl;
    cout << "--------------插入操作结束--------------" << endl;
}

void MyModifyNode()            //修改一个节点
{
    char szNameBuf[20] = "";
    cout << "请输入您要修改的节点的姓名：";
    cin >> szNameBuf;
    cout << "--------------修改操作开始--------------" << endl;
    node *pResFindNode = &MyFindNode(szNameBuf);
    MyInputNode(*pResFindNode);
    cout << "--------------修改操作结束--------------" << endl;
}

void MyDeleteNode()            //删除一个节点
{
    char szNameBuf[20] = "";
    cout << "请输入您要删除的节点的姓名：";
    cin >> szNameBuf;

    cout << "--------------删除操作开始--------------" << endl;
    node *pResFindNode = &MyFindNode(szNameBuf);
    if(pResFindNode == g_phead){
        g_phead = pResFindNode->m_pNext;
        g_phead->m_pFront = NULL;
    }
    else if(pResFindNode == g_pEnd){
        g_pEnd = pResFindNode->m_pFront;
        g_pEnd->m_pNext = NULL;
    }
    else{
        pResFindNode->m_pFront->m_pNext = pResFindNode->m_pNext;
        pResFindNode->m_pNext->m_pFront = pResFindNode->m_pFront;
    }
    delete [] pResFindNode;
    cout << "--------------删除操作结束--------------" << endl;
}

void MyClearnList()             //清空链表
{
    node* pt = g_phead;

    cout << "--------------清空链表开始--------------" << endl;
    while(pt != NULL){
        delete [] pt;
        pt = pt->m_pNext;
    }
    g_phead = NULL;
    g_pEnd = NULL;
    cout << "--------------清空链表结束--------------" << endl;
}

void MyHelp()                  //帮助
{
    for(int i = 0 ; i < 80 ; i++)
        cout << "-";
    cout << endl;

    void Create();
    void Add();
    void Insert();
    void Delete();
    void Clearn();
    void Modify();
    void Find();
    void Show();
    void Help();
    void Exit();

    cout << "命令            语句           操作含义" << endl;
	cout << "Create         创建         创建一个链表" << endl;
	cout << "Add            添加         在该链表结尾处添加一个新的节点" << endl;
	cout << "Insert         插入         在链表任意地方随意插入一个新节点" << endl;
	cout << "Delete         删除         在链表任意地方随意删除一个已有节点" << endl;
	cout << "Clearn         清空         清空整个链表" << endl;
	cout << "Modify         修改         在链表任意地方随意是修改一个已有节点" << endl;
	cout << "Show           显示         完整的显示该链表的所有节点的详细信息" << endl;
	cout << "Help           帮助         查看帮助说明文档" << endl;
	cout << "Exit           退出         退出，结束本程序" << endl << endl;

    for(int i = 0 ; i < 80 ; i++)
        cout << "-";
    cout << endl << endl;
}