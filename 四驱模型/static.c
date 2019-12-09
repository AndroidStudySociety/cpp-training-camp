#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char * getStr1()
{
    char *p1 = "abcdefg2";
    return p1;
}
char *getStr2()
{
    char *p2 = "abcdefg2";
    return p2;
}
void main22()
{
    char *p1 = NULL;
    char *p2 = NULL;
    p1 = getStr1();
    p2 = getStr2();
    //打印p1 p2 所指向内存空间的数据
    printf("p1:%s , p2:%s \n", p1, p2);
    //打印p1 p2 的值
    printf("p1:%d , p2:%d \n", p1, p2);
    printf("hello...\n");

    return;

    //你自己在复习的时候 一定要学会分析内存


}


//堆
char *getMem(int num)
{
    char *p1 = NULL;
    p1 = (char *)malloc(sizeof(char) * num);
    if (p1 == NULL)
    {
        return NULL;
    }
    return p1;
}
void main() {
    char *tmp = NULL;
    tmp = getMem(10);
    if (tmp == NULL) {
        return;
    }
    strcpy(tmp, "111222"); //向tmp做指向的内存空间中copy数据
    printf("hello..tmp:%s.\n", tmp);
    //system("pause");
    return;
}

//栈
//注意 return不是把内存块 64个字节,给return出来,而是把内存块的首地址 ,返回给 tmp
//理解指针的关键,是内存. 没有内存哪里的指针
char * getMem2()
{
    char buf[64]; //临时变量 栈区存放
    strcpy(buf, "123456789");
    return buf;
}
void main77()
{
    char *tmp = NULL;
    tmp = getMem2();
    printf("hello..tmp:%s.\n", tmp);
    system("pause");
    return;
}

