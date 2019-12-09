
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int *a,*b;
    a = (int*)malloc(sizeof(int));
    b = (int*)malloc(sizeof(int));
    *a = 100;
    *b = 200;
    printf("a的地址是:%p,%p,%d\n",&a,a,*a); //地址空间占用8个字节
    printf("b的地址是:%p,%p,%d\n",&b,b,*b);

    int c[3] = {0,1,2}; //计算机中 数组就是一个地址了，注意和变量的区别
    printf("c的地址是:%p,%p,%d,%d,%d\n",&c,c,c[0],c[1],c[2]);


    //内存图 & * 函数指针 结构体 io
    return 0;

}
