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
        add_executable (c_demo main.c 自己实现string相关函数.c)
        add_executable (first first.c)
        add_executable (second maopao.cpp)
        add_executable (third 指针数组和数组指针.c)
        add_executable (four 间接赋值.c)
        add_executable (five 模拟实现C语言中的字符串函数.c)
        add_executable (six 模拟字符串函数实现.c)
        add_executable (seven 二级指针操作文件.c)
        add_executable (eight 二级指针函数输出.c)
        add_executable (night 自己实现string相关函数.c)
        add_executable (ten 文件加密/jiami.c)
        add_executable (eleven 配置文件项目/接口测试.c 配置文件项目/cfgfile.c)
        add_executable (mem 动态内存分配.c)
        add_executable (function 函数.c)
        add_executable (test test.c)
        add_executable (pointer 指针增强.c)
        add_executable (leakmem 内存泄漏/leakmem.h 内存泄漏/leakmem.c 内存泄漏/leakmem_test.c)
        add_executable (mystring 字符串/mystring.c)
        add_executable (file 文件操作/file.c)
        add_executable (struct structlearning.c)
        add_executable (siqu 四驱模型/static.c)
        add_executable (functionpointer 函数指针/callback.c)
        add_executable (file_back 文件操作.c)
        add_executable (file_feng 文件封装/file_operate.c 文件封装/file_operate.h 文件封装/test.c)