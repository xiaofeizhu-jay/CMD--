#include "stdfax.h"
#include "Linker.h"

node *g_phead = NULL; //全局变量，链表头指针
node *g_pEnd = NULL;  //全局变量，链表尾指针

void MyCreateList()
{
    if(g_phead != NULL && g_pEnd != NULL)
        cout << "链表已经创建！" << endl;
    else{
        node *pTemp = new node;
        if(pTemp == NULL)
            cout << "链表创建失败！" << endl;
        else
        {
            MyInputNode(*pTemp);
            cout << "链表创建成功！" << endl;
        }
        g_phead = pTemp;
        g_pEnd = pTemp;
    }
}

void MyInputNode(node& pt)  //输入一个刚创建好的空白节点
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

void MyOutputNode(node& pt)  //输出一个已经存在的结点
{
    if(&pt == NULL)
        return ;
    cout << "姓名：" << pt.m_szName << endl;
    cout << "年龄：" << pt.m_Age << endl;
    cout << "性别：" << pt.m_szSex << endl;
    cout << "电话：" << pt.m_szTel << endl;
    cout << "住址：" << pt.m_szAddr << endl;
}

void MyShowList()            //显示链表
{
    int nCount = 1;
    if(g_phead != NULL && g_pEnd != NULL){
        cout << "----------开始显示！ ----------" << endl;
        node *pt = g_phead;
        while(pt != NULL){
            cout << "第" << nCount << "个用户：" << endl;
            MyOutputNode(*pt);
            nCount++;
            pt = pt->m_pNext;
        }
        cout << "----------显示完毕！----------" << endl;
    }
    else
        cout << "链表为空！" << endl;
}

void MyExit()
{
    exit(0);
}

void MyHelp()
{
    for(int i = 0 ; i < 20 ; i++)
        cout << "=·=";
    cout << endl;

    cout << "命令            语句           操作含义" << endl;
    cout << "Create          创建           创建一个链表" << endl;
    cout << "Show            显示           显示链表" << endl;
    cout << "Help            帮助           显示帮助" << endl;
    cout << "Exit            退出           退出程序" << endl;
    cout << "Add             添加           添加一个节点" << endl;
    cout << "Find            查找           查找一个节点" << endl;
    cout << "Modify          修改           修改一个节点" << endl;
    cout << "Delete          删除           删除一个节点" << endl;
    cout << "Insert          插入           插入一个节点" << endl;
    cout << "Clearn          清空           清空链表" << endl;

    for(int i = 0 ; i < 20 ; i++)
        cout << "=·=";
    cout << endl;
}

node& MyAdd_Node()           //单独只是创建一个节点
{
    node* pTemp = new node;
    if(pTemp != NULL){
        MyInputNode(*pTemp);
        cout << "用户创建成功！" << endl;
    }
    return *pTemp;
}

node* MyAddNode()            //在链表尾部添加一个节点
{
    if(g_phead == NULL || g_pEnd == NULL)
        cout << "链表尚未创建！" << endl;
    else{
        node* pNew = &MyAdd_Node();
        g_pEnd->m_pNext = pNew;
        pNew->m_pFront = g_pEnd;
        g_pEnd = pNew;
        cout << "用户添加成功！" << endl;
    }
    return NULL;
}

node& MyFindNode(char *FindName) //根据姓名查找
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
            cout << "您要查找的用户不存在！" << endl;
            return *pt;
        }
    }
}

void MyShowNode()             //等价于MyFindNode() + MyOutputNode()
{
    char szName[20] = "";
    cout << "请输入您要查找的用户姓名：";
    cin >> szName;
    MyOutputNode(MyFindNode(szName));
}

void MyModifyNode()
{
    char szName[20] = "";
    cout << "请输入您要修改的用户姓名：";
    cin >> szName;
    cout << "正在查找..." << endl;
    node* pt = &MyFindNode(szName);
    if(pt != NULL){
        cout << "正在修改..." << endl;
        MyInputNode(*pt);
        cout << "修改成功！" << endl;
    }
    else
        cout << "修改失败！该用户不存在！" << endl;
}

void MyDeleteNode()          //删除一个节点
{
    char szName[20] = "";
    cout << "请输入您要删除的用户姓名：";
    cin >> szName;

    cout << "正在删除..." << endl;
    node* pt = &MyFindNode(szName);
    if(pt != NULL){
        if(pt == g_phead){
            g_phead = pt->m_pNext;
            g_phead->m_pFront = NULL;
        }
        else if(pt == g_pEnd){
            g_pEnd = pt->m_pFront;
            g_pEnd->m_pNext = NULL;
        }
        else{
            pt->m_pFront->m_pNext = pt->m_pNext;
            pt->m_pNext->m_pFront = pt->m_pFront;
        }
        cout << "删除成功！" << endl;
    }
    else
        cout << "删除失败！该用户不存在！" << endl;
    delete [] pt;
}

void MyInsertFront(node* pResFindNode , node* pNew)   //前插（插在查询到的结点之前）
{   
    if(pResFindNode == g_phead){
        g_phead = pNew;
        pNew->m_pNext = pResFindNode;
        pResFindNode->m_pFront = pNew;
    }
    else{
        pNew->m_pFront = pResFindNode->m_pFront;
        pNew->m_pNext = pResFindNode;
        pResFindNode->m_pFront->m_pNext = pNew;
        pResFindNode->m_pFront = pNew;
    }
}

void MyInsertNext(node* pResFindNode , node* pNew)    //后插（插在查询到的结点之后）
{
    if(pResFindNode == g_pEnd){
        g_pEnd = pNew;
        pNew->m_pFront = pResFindNode;
        pResFindNode->m_pNext = pNew;
    }
    else{
        pNew->m_pNext = pResFindNode->m_pNext;
        pNew->m_pFront = pResFindNode;
        pResFindNode->m_pNext->m_pFront = pNew;
        pResFindNode->m_pNext = pNew;
    }
}

void MyInsertNode()
{
    char szName[20] = "";
    cout << "请输入插入位置的用户姓名：" ;
    cin >> szName;
    node* pResFindNode = &MyFindNode(szName);

    if(pResFindNode == NULL){
        cout << "插入失败！该用户不存在！" << endl;
        return ;
    }
    cout << "正在进行插入操作..." << endl;
    cout << "输入新用户信息：" << endl;
    node* pNew = &MyAdd_Node();

    int nChoose = 1;

    while(true){
        cout << "请选择插入方式（1.前插 2.后插）：";
        cin >> nChoose;
        if(nChoose == 1){
            MyInsertFront(pResFindNode , pNew);
            break;
        }
        else if(nChoose == 2){
            MyInsertNext(pResFindNode , pNew);
            break;
        }
        else
            cout << "您的选择有误！请重新选择！" << endl;
    }
    cout << "插入成功！" << endl;
}

void MyClearnList()
{
    node* pt = g_phead;
    while(pt != NULL){
        node* pTemp = pt;
        pt = pt->m_pNext;
        delete [] pTemp;
    }
    g_phead = NULL;
    g_pEnd = NULL;
    cout << "链表已清空！" << endl;
}