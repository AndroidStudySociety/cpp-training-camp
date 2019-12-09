
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>


//char 1字节、short 2字节、int 4字节

//1，每个结构体成员的起始地址为该成员大小的整数倍，即int型成员的其实地址只能为0、4、8等
//2，结构体的大小为其中最大成员大小的整数倍

#pragma pack(10)
struct A{
    char a; //1
    int b; //3(空出来)+4= 7 （规则1）
    short c; //2+2 （规则2）
};

#pragma pack(10)
struct B{
    char a; //1
    short b; //1（空出来）+2
    int c; //4
};

int main(int argc, char *argv[])
{
    printf("sizeof(struct A)=%d, sizeof(struct B)=%d\n", sizeof(struct A), sizeof(struct B));

    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    printf("ANSI :%d\n", __STDC__ );


    return 1;
}