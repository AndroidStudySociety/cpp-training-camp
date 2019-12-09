//
// Created by Jesson on 2019-11-24.
//


#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>
//void change(int a,int b){
//
//
//}
void change(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    //百度面试  不要临时变量
    //temp = a+b b = temp-b a=temp-b
    //a = a+b b=a a=b
}




int main(){
//    int i = 0;
//    double a = 200;
//    float c = 300;
//    char d = 's';
//    long e = 400;
//    short f = 500;
//
//    printf("int==>%d\n", sizeof(i));
//    printf("double==>%d\n", sizeof(a));
//    printf("float==>%d\n", sizeof(c));
//    printf("char==>%d\n", sizeof(d));
//    printf("long==>%d\n", sizeof(e));
//    printf("short==>%d\n", sizeof(f));
////
//    printf("int==>%d\n", i);
//    printf("double==>%lf\n", a);
//    printf("float==>%f\n", c);
//    printf("char==>%c\n", d);
//    printf("long==>%ld\n", e);
//    printf("short==>%hd\n", f);


    //变量地址等信息 指针就是存放变量的地址的
    int i = 200;
    printf("i的数值是%d\n",i); //200
    printf("i变量的内存地址是%p\n",&i); //%p 输出地址的
    printf("取i变量的内存地址里面的数据%d\n",*(&i)); //*(地址)
//
    int* d = &i; //int类型的指针 double
    printf("int指针对应的数值是%d\n",*d);
    printf("int指针对应地址是%p\n",&d);
    printf("int指针存放的内容是%p\n",d);



    //修改i的数值
    *d = 1000;
    printf("int指针对应的数值是%d\n",i);


    int c = 100;
    int f =200;
    change(&c,&f);
    printf("c的数值是%d,f的数值是%d\n",c,f);
    return -1;

    //数值传递和引用传递 面试题 change()
}
