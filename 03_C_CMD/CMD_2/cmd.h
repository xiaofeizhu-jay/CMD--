#pragma once

typedef void (*pfun)();

struct CMD_MAP{
    const char* m_szcmd;
    void (*m_pfun)();
};

/*
    char *m_szcmd：一个指向字符的指针，用于存储命令字符串。
    pfun m_pfun：一个函数指针，指向一个返回类型为void且无参数的函数。
*/
