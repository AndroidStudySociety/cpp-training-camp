//
// Created by jesson on 2019-11-24.
//

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>


void testfunction();

void allocaMem(int **pInt);

void printArray(int **pInt, int i);

int main(){
    printf("======BEGIN=========\n");
    testfunction();
}

void testfunction() {
    int* p = NULL;
    allocaMem(&p);
    printArray(&p,10);
    //freeMem();
}

//内存四区 + 地址传值 （引用传递和数值传递）

void printArray(int **p, int i) {
    for (int j = 0; j < i; ++j) {
        printf("%d\n",(*p)[j]);
    }
}

void allocaMem(int **p) {
    int* arr = malloc(sizeof(int)*10);
    for (int i = 0; i < 10; ++i) {
        arr[i] = i+100;
    }
    *p = arr;
}