/*
    stdfax.h -- 标准系统包含文件的包含文件夹，
    或是经常使用但不经常更改的
    特定于项目的包含文件

    当大量源文件都需要包含相同的头文件时，
    传统的编译方式会导致重复加载和编译这些头文件，增加了编译时间和系统负载。
    为了解决这个问题，引入了预编译头文件机制。
    在编译过程中，stdafx.cpp和stdafx.h用于生成一个预编译头文件
    （例如 project.pch）和预编译类型文件（例如 stdafx.obj）。
    在第一次编译时，stdafx.cpp会被编译处理，
    将头文件stdafx.h中包含的所有头文件进行预编译，生成一个预编译头文件。
    此后，只要stdafx.h没有被修改，编译器则可以直接使用这个预编译头文件，
    避免了重新编译stdafx.h的工作。
*/
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string.h>

using namespace std;