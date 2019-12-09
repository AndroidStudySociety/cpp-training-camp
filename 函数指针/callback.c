//
// Created by Jesson on 2019-11-24.
//


//函数指针的原型：int (*function)(int,int)

//实现一个普通的函数

#include <printf.h>


typedef void (*PtrFunA)();
typedef void (*PtrFunB)(int);

//1. callback  自己定义一个普通的函数，这个是被其他函数来调用 其他函数要拿到他的地址
int add(int a, int b){
    return a+b;
}

//1。自己定义一个普通的函数，
void FunA() {
    printf("call FunA\n");
}

void FunB(int n) {
    printf("call FunB. n is : %d\n", n);
}

// 函数指针作为函数参数使用
void usePtrFunA(PtrFunA p) {
    p();
}

void usePtrFunB(PtrFunB p, int n) {
    p(n);
}


//2.自己实现回掉函数

int ADD(int (*callback)(int,int), int a, int b){
    return (*callback)(a,b);//此处回调add函数...
}

void main(){

    //这是比较简单的写法

    printf("%d\n",add(1,2)); //3
    printf("%d\n",ADD(add,10,2)); //12


    printf("this is %s ,%d","sss",11);// this is sss 11
    PtrFunA ptrFunA = FunA;
    usePtrFunA(ptrFunA); //printf("call FunA\n");
}




