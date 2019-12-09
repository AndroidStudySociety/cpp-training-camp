//
// Created by Jesson on 2019-11-24.
//

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    int fd=-1;
    int ret=-1;
    char buf[32];

    //打开hello.c文件，如果不存在则创建
    //fd = open("hello.c",O_CREAT | O_TRUNC | O_WRONLY,00600);

    //这里 O_RDWR 是以读写方式打开
    fd = open("hello.c",O_CREAT | O_RDWR,00600);
    if(fd < 0){
        perror("open:");
        exit(1);
    }else{
        printf("open file:hello.c %d\n",fd);
    }

    //读取文件
    ret = read(fd,buf,12);
    if(ret<0)
    {
        printf("read err\n");
    }else{
        //为字符串添加结束标记
        buf[ret]='\0';
        //打印读取的字符串
        printf("str=%s\n",buf);
    }

    //向文件中写入数据
    ret = write(fd,"\ni can write!",strlen("\ni can write!"));
    if(ret == strlen("\ni can write!")){
        printf("successfully write\n");
    }else{
        printf("write erro...\n");
    }

    //关闭文件
    if(close(fd) < 0)
    {
        perror("close:");
        exit(1);
    }
    else
        printf("close file:hello.c\n");
    exit(0);
}