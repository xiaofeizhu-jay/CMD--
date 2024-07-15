#include "stdfax.h"
#include "Linker.h"

node *g_phead = NULL;
node *g_pEnd = NULL;

void MyInputNode(node& pt)    //����һ���մ����õĿհ׽ڵ�
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

void MyOutputNode(node& pt)    //���һ�����еĽڵ�
{
    cout << "������" << pt.m_szName << endl;
    cout << "���䣺" << pt.m_Age << endl;
    cout << "�Ա�" << pt.m_szSex << endl;
    cout << "�绰��" << pt.m_szTel << endl;
    cout << "סַ��" << pt.m_szAddr << endl;
}

void MyCreateList()            //��������
{
    node *pTemp = new node;

    if(pTemp == NULL)
        cout << "������ʧ�ܣ�" << endl;
    else{
        MyInputNode(*pTemp);
        cout << "�������ɹ���" << endl;
    }
    g_phead = pTemp;
    g_pEnd = pTemp;
}

node& MyAdd_Node()            //����ֻ�Ǵ���һ���ڵ�
{
    node* pTemp = new node;
    if(pTemp != NULL)
        MyInputNode(*pTemp);
    return *pTemp;
}

node* MyAddNode()            //������β�����һ���ڵ�
{
    if(NULL == g_phead || NULL == g_pEnd)
        cout << "������δ������" << endl;
    node* pNew = &MyAdd_Node();   //���õ�ʹ��
    g_pEnd->m_pNext = pNew;
    pNew->m_pFront = g_pEnd;
    g_pEnd = pNew;
    return NULL;
}

void MyShowList()              //��ʾ����
{
    int nCount = 1;
    if(g_phead != NULL || g_pEnd != NULL){
        node* pt = g_phead;
        cout << "---------��ʾ����ʼ---------" << endl;
        while(pt != NULL){
            cout << "��" << nCount << "���ڵ㣺" << endl;
            MyOutputNode(*pt);
            pt = pt->m_pNext;
            nCount++;
        }
        cout << "---------��ʾ�������---------" << endl;
    }
}

node& MyFindNode(char *FindName)//������������
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
            cout << "��Ҫ���ҵĽڵ㲻���ڣ�" << endl;
            return *pt;
        }
    }
}

void MyShowNode()              //��������������Ϣ���ȼ���MyFindNode() + MyOutputNode()
{
    char szName[20];
    cout << "��������Ҫ���ҵ�������";
    cin >> szName;
    MyOutputNode(MyFindNode(szName));
}

void MyInsertFront(char* ptName , node* pResFindNode , node* pNew) //ǰ�壨���ڲ�ѯ���Ľڵ�֮ǰ)
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

void MyInsertNext(char* ptName , node* pResFindNode , node* pNew)  //��壨���ڲ�ѯ���Ľڵ�֮��
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

void MyInsertNode()            //����һ���ڵ�
{
    char szNameBuf[20] = "";
    cout << "���������������Ὣ��ѡ�����ýڵ�֮ǰ����֮�󣩣�";
    cin >> szNameBuf;

    cout << "--------------���������ʼ--------------" << endl;
    node* pNew = &MyAdd_Node();
    node* pResFindNode = &MyFindNode(szNameBuf);

    int nChoose = 1;
    cout << "��ѡ����뷽ʽ��1.ǰ�� 2.��壩��" << endl;
    cin >> nChoose;
    if(nChoose == 1)
        MyInsertFront(szNameBuf , pResFindNode , pNew);
    else if(nChoose == 2)
        MyInsertNext(szNameBuf , pResFindNode , pNew);
    else
        cout << "����ѡ������" << endl;
    cout << "--------------�����������--------------" << endl;
}

void MyModifyNode()            //�޸�һ���ڵ�
{
    char szNameBuf[20] = "";
    cout << "��������Ҫ�޸ĵĽڵ��������";
    cin >> szNameBuf;
    cout << "--------------�޸Ĳ�����ʼ--------------" << endl;
    node *pResFindNode = &MyFindNode(szNameBuf);
    MyInputNode(*pResFindNode);
    cout << "--------------�޸Ĳ�������--------------" << endl;
}

void MyDeleteNode()            //ɾ��һ���ڵ�
{
    char szNameBuf[20] = "";
    cout << "��������Ҫɾ���Ľڵ��������";
    cin >> szNameBuf;

    cout << "--------------ɾ��������ʼ--------------" << endl;
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
    cout << "--------------ɾ����������--------------" << endl;
}

void MyClearnList()             //�������
{
    node* pt = g_phead;

    cout << "--------------�������ʼ--------------" << endl;
    while(pt != NULL){
        delete [] pt;
        pt = pt->m_pNext;
    }
    g_phead = NULL;
    g_pEnd = NULL;
    cout << "--------------����������--------------" << endl;
}

void MyHelp()                  //����
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

    cout << "����            ���           ��������" << endl;
	cout << "Create         ����         ����һ������" << endl;
	cout << "Add            ���         �ڸ������β�����һ���µĽڵ�" << endl;
	cout << "Insert         ����         ����������ط��������һ���½ڵ�" << endl;
	cout << "Delete         ɾ��         ����������ط�����ɾ��һ�����нڵ�" << endl;
	cout << "Clearn         ���         �����������" << endl;
	cout << "Modify         �޸�         ����������ط��������޸�һ�����нڵ�" << endl;
	cout << "Show           ��ʾ         ��������ʾ����������нڵ����ϸ��Ϣ" << endl;
	cout << "Help           ����         �鿴����˵���ĵ�" << endl;
	cout << "Exit           �˳�         �˳�������������" << endl << endl;

    for(int i = 0 ; i < 80 ; i++)
        cout << "-";
    cout << endl << endl;
}