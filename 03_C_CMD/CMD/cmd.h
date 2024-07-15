#pragma once

typedef void (*pfun)();

/*
    这段话定义了一个名为pfun的类型别名，它是一个指向函数的指针类型。具体来说：

    typedef是C++中的一个关键字，用于为现有的类型创建一个新的名称。
    void表示这个函数没有返回值。
    (*pfun)()是一个函数指针的声明，括号内的空参数列表表示这个函数没有参数。

    所以，pfun类型的变量可以存储一个指向无参数且无返回值的函数的指针。
*/

// struct CMD_MAP{
//     char *m_szcmd;
//     pfun m_pfun;
// };

struct CMD_MAP {

    const char* m_szcmd;

    void (*m_pfun)();

};

/*
    char *m_szcmd：一个指向字符的指针，用于存储命令字符串。
    pfun m_pfun：一个函数指针，指向一个返回类型为void且无参数的函数。
*/

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

void Finally();
