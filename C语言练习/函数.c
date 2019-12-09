//
// Created by Jesson on 2019-11-24.
//

/***
 * 可变参数
 */
//#include <stdarg.h>
//#include <printf.h>
//
//double sum(int, ...);
//
//int main(int argc, char* argv[])
//{
//    double s, t;
//
//    s = sum(3, 1.1, 2.5, 13.3);
//    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
//    printf("return value for "
//           "sum(3, 1.1, 2.5, 13.3): %g\n", s);
//    printf("return value for "
//           "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n", t);
//
//    return 0;
//}
///**
// * 多参函数的实现
// * @param 参数lim 代表几个参数
// * @param 参数2
// * @return 求和
// */
//double sum(int lim, ...)
//{
//
//    va_list ap;
//    double tot = 0;
//    int i;
//    va_start(ap, lim);
//    for (i = 0; i < lim; i++){
//        tot += va_arg(ap, double);
//    }
//    va_end(ap);
//
//    return tot;
//}


////-------------- 函数指针----------------------------
//
#include <stdio.h>
#include <stdlib.h>

void (*funP)(int);   //声明也可写成void(*funP)(int x)，但习惯上一般不这样。
void (*funA)(int);
void myFun(int x);    //声明也可写成：void myFun( int );

int main()
{
    //一般的函数调用
    myFun(100);

    //myFun与funP的类型关系类似于int 与int *的关系。
    funP=&myFun;  //将myFun函数的地址赋给funP变量
    (*funP)(200);  //通过函数指针变量来调用函数

    //myFun与funA的类型关系类似于int 与int 的关系。
    funA=myFun;
    funA(300);

    //三个貌似错乱的调用
    funP(400);
    (*funA)(600);
    (*myFun)(1000);

    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    printf("ANSI :%d\n", __STDC__ );


    return 0;
}

void myFun(int x)
{
    printf("myFun: %d\n",x);
}