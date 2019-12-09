#include <stdio.h>

int main() {
    int a,b,sum; /*定义变量a,b，sum为整型变量*/
    a=20; /*把整数20赋值给整型变量a*/
    b=15; /*把整数15赋值给整型变量b*/
    sum=a+b; /*把两个数之和赋值给整型变量sum*/
    printf("a=%d,b=%d,sum=%d\n",a,b,sum);
    printf("===================================\n");
    printf("char占用%d字节\n", sizeof(char));
    printf("int占用%d字节\n", sizeof(int));
    printf("double占用%d字节\n", sizeof(double));
    printf("long占用%d字节\n", sizeof(long));


    int c[5];
    int i;
    for(i = 0; i < 5; i++)
    {
        c[i] = i + 1;
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d ", c[i]);
    }
}