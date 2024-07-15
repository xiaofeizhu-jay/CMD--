#include "stdfax.h"
#include "Linker.h"

node *g_phead = NULL; //ȫ�ֱ���������ͷָ��
node *g_pEnd = NULL;  //ȫ�ֱ���������βָ��

void MyCreateList()
{
    if(g_phead != NULL && g_pEnd != NULL)
        cout << "�����Ѿ�������" << endl;
    else{
        node *pTemp = new node;
        if(pTemp == NULL)
            cout << "������ʧ�ܣ�" << endl;
        else
        {
            MyInputNode(*pTemp);
            cout << "�������ɹ���" << endl;
        }
        g_phead = pTemp;
        g_pEnd = pTemp;
    }
}

void MyInputNode(node& pt)  //����һ���մ����õĿհ׽ڵ�
{
    pt.m_pFront = NULL;
    pt.m_pNext = NULL;
    cout << "����������������";
    cin >> pt.m_szName;
    cout << "�������������䣺";
    cin >> pt.m_Age;
    cout << "�����������Ա�";
    cin >> pt.m_szSex;
    cout << "���������ĵ绰��";
    cin >> pt.m_szTel;
    cout << "����������סַ��";
    cin >> pt.m_szAddr;
}

void MyOutputNode(node& pt)  //���һ���Ѿ����ڵĽ��
{
    if(&pt == NULL)
        return ;
    cout << "������" << pt.m_szName << endl;
    cout << "���䣺" << pt.m_Age << endl;
    cout << "�Ա�" << pt.m_szSex << endl;
    cout << "�绰��" << pt.m_szTel << endl;
    cout << "סַ��" << pt.m_szAddr << endl;
}

void MyShowList()            //��ʾ����
{
    int nCount = 1;
    if(g_phead != NULL && g_pEnd != NULL){
        cout << "----------��ʼ��ʾ�� ----------" << endl;
        node *pt = g_phead;
        while(pt != NULL){
            cout << "��" << nCount << "���û���" << endl;
            MyOutputNode(*pt);
            nCount++;
            pt = pt->m_pNext;
        }
        cout << "----------��ʾ��ϣ�----------" << endl;
    }
    else
        cout << "����Ϊ�գ�" << endl;
}

void MyExit()
{
    exit(0);
}

void MyHelp()
{
    for(int i = 0 ; i < 20 ; i++)
        cout << "=��=";
    cout << endl;

    cout << "����            ���           ��������" << endl;
    cout << "Create          ����           ����һ������" << endl;
    cout << "Show            ��ʾ           ��ʾ����" << endl;
    cout << "Help            ����           ��ʾ����" << endl;
    cout << "Exit            �˳�           �˳�����" << endl;
    cout << "Add             ���           ���һ���ڵ�" << endl;
    cout << "Find            ����           ����һ���ڵ�" << endl;
    cout << "Modify          �޸�           �޸�һ���ڵ�" << endl;
    cout << "Delete          ɾ��           ɾ��һ���ڵ�" << endl;
    cout << "Insert          ����           ����һ���ڵ�" << endl;
    cout << "Clearn          ���           �������" << endl;

    for(int i = 0 ; i < 20 ; i++)
        cout << "=��=";
    cout << endl;
}

node& MyAdd_Node()           //����ֻ�Ǵ���һ���ڵ�
{
    node* pTemp = new node;
    if(pTemp != NULL){
        MyInputNode(*pTemp);
        cout << "�û������ɹ���" << endl;
    }
    return *pTemp;
}

node* MyAddNode()            //������β�����һ���ڵ�
{
    if(g_phead == NULL || g_pEnd == NULL)
        cout << "������δ������" << endl;
    else{
        node* pNew = &MyAdd_Node();
        g_pEnd->m_pNext = pNew;
        pNew->m_pFront = g_pEnd;
        g_pEnd = pNew;
        cout << "�û���ӳɹ���" << endl;
    }
    return NULL;
}

node& MyFindNode(char *FindName) //������������
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
            cout << "��Ҫ���ҵ��û������ڣ�" << endl;
            return *pt;
        }
    }
}

void MyShowNode()             //�ȼ���MyFindNode() + MyOutputNode()
{
    char szName[20] = "";
    cout << "��������Ҫ���ҵ��û�������";
    cin >> szName;
    MyOutputNode(MyFindNode(szName));
}

void MyModifyNode()
{
    char szName[20] = "";
    cout << "��������Ҫ�޸ĵ��û�������";
    cin >> szName;
    cout << "���ڲ���..." << endl;
    node* pt = &MyFindNode(szName);
    if(pt != NULL){
        cout << "�����޸�..." << endl;
        MyInputNode(*pt);
        cout << "�޸ĳɹ���" << endl;
    }
    else
        cout << "�޸�ʧ�ܣ����û������ڣ�" << endl;
}

void MyDeleteNode()          //ɾ��һ���ڵ�
{
    char szName[20] = "";
    cout << "��������Ҫɾ�����û�������";
    cin >> szName;

    cout << "����ɾ��..." << endl;
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
        cout << "ɾ���ɹ���" << endl;
    }
    else
        cout << "ɾ��ʧ�ܣ����û������ڣ�" << endl;
    delete [] pt;
}

void MyInsertFront(node* pResFindNode , node* pNew)   //ǰ�壨���ڲ�ѯ���Ľ��֮ǰ��
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

void MyInsertNext(node* pResFindNode , node* pNew)    //��壨���ڲ�ѯ���Ľ��֮��
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
    cout << "���������λ�õ��û�������" ;
    cin >> szName;
    node* pResFindNode = &MyFindNode(szName);

    if(pResFindNode == NULL){
        cout << "����ʧ�ܣ����û������ڣ�" << endl;
        return ;
    }
    cout << "���ڽ��в������..." << endl;
    cout << "�������û���Ϣ��" << endl;
    node* pNew = &MyAdd_Node();

    int nChoose = 1;

    while(true){
        cout << "��ѡ����뷽ʽ��1.ǰ�� 2.��壩��";
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
            cout << "����ѡ������������ѡ��" << endl;
    }
    cout << "����ɹ���" << endl;
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
    cout << "��������գ�" << endl;
}