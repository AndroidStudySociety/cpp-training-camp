#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//指针做函数参数间接改变我们的运算结果
//int getFoleLen(int*p)
//{
//    *p = 40;
//    return true;
//}
////这样只能修改形参的值  不能改变实参的值
////不通过操作地址的话  编译器是将实参的值复制给形参 而不是把实参传递进来
int getFoleLen(int b)
{
    //形参变量和函数里面的变量本质是一样的  只不过形参变量具有对外的属性
    b = 100;
    return true;
}
////return只能返回一个结果
//int getFoleLen()
//{
//    int a = 100;
//    return a;
//}

char* getStr(){
    char * str = NULL;
    str = "safdjk";
    return str;
}


//一级指针到0级指针
void main999() {
    int *a = NULL;
    int b = 100;
    a = &b;
    *a = 200;
    int c =0;
    c = *a;
    printf("b的数值是：%d,a的数值是：%d,C的数值是：%d",b,*a,c);

    char * str = getStr();
    printf("字符信息是：%s\n",str);
    *(str+1)='r';
    printf("字符信息是：%s\n",str);


//    int* p = NULL;
//
//    int a = 10;
//    //修改a的值
//
//    //直接修改
//    a = 12;
//    //间接修改
//    p = &a;
//    *p = 20;//p的值是a的地址 *就像一把钥匙  通过地址 找到一块内存空间  就间接修改了a的值
//    printf("a,%d\n", a);
//    getFoleLen(&a);
//    printf("a1,%d\n",a);
//    getFoleLen(a);
//    printf("a2,%d\n", a);
}


int getlength(int* p){
    *p = 300;
    return *p;
}



void main(){
    int a = 10;
    int *p = NULL;
    p = &a;
    *p = 30;
    printf("a的数值是：%d",a);
    getlength(p);
    printf("a的数值是：%d",a);
}



