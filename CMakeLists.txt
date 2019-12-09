#cmake_minimum_required(VERSION 3.13)
#project(c_demo)
#
#set(CMAKE_CXX_STANDARD 14)
#
#include_directories(.)
#include_directories(文件加密)
#include_directories(配置文件项目)
#
#add_executable(c_demo
#        文件加密/cfg.ini
#        文件加密/cfg_crypt.ini
#        文件加密/cfg_decrypt.ini
#        文件加密/jiami.c
#        配置文件项目/cfg.ini
#        配置文件项目/cfgfile.c
#        配置文件项目/file.h
#        配置文件项目/接口测试.c
#        cfg_crypt.ini
#        CMakeLists.txt
#        first.c
#        main.c
#        maopao.cpp
#        test.txt
#        二级指针函数输出.c
#        二级指针操作文件.c
#        指针数组和数组指针.c
#        模拟字符串函数实现.c
#        模拟实现C语言中的字符串函数.c
#        自己实现string相关函数.c
#        间接赋值.c)
cmake_minimum_required(VERSION 3.13)
project(c_demo)

        set (CMAKE_C_STANDARD 99)
        set (CMAKE_CXX_STANDARD 11)
        if (HAVE_NO_ARRAY_BOUNDS)
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-array-bounds")
        endif ()
        add_executable (c_demo C语言练习/main.c C语言练习/自己实现string相关函数.c)
        add_executable (first C语言练习/first.c)
        add_executable (second C语言练习/maopao.cpp)
        add_executable (third C语言练习/指针数组和数组指针.c)
        add_executable (four C语言练习/间接赋值.c)
        add_executable (five C语言练习/模拟实现C语言中的字符串函数.c)
        add_executable (six C语言练习/模拟字符串函数实现.c)
        add_executable (seven C语言练习/二级指针操作文件.c)
        add_executable (eight C语言练习/二级指针函数输出.c)
        add_executable (night C语言练习/自己实现string相关函数.c)
        add_executable (ten C语言练习/文件加密/jiami.c)
        add_executable (eleven C语言练习/配置文件项目/接口测试.c C语言练习/配置文件项目/cfgfile.c)
        add_executable (mem C语言练习/动态内存分配.c)
        add_executable (function C语言练习/函数.c)
        add_executable (test C语言练习/test.c)
        add_executable (pointer C语言练习/指针增强.c)
        add_executable (leakmem C语言练习/内存泄漏/leakmem.h C语言练习/内存泄漏/leakmem.c C语言练习/内存泄漏/leakmem_test.c)
        add_executable (mystring C语言练习/字符串/mystring.c)
        add_executable (file C语言练习/文件操作/file.c)
        add_executable (struct C语言练习/structlearning.c)
        add_executable (siqu C语言练习/四驱模型/static.c)
        add_executable (functionpointer C语言练习/函数指针/callback.c)
        add_executable (file_back C语言练习/文件操作.c)
        add_executable (file_feng C语言练习/文件封装/file_operate.c C语言练习/文件封装/file_operate.h C语言练习/文件封装/test.c)