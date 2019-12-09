#include <stdio.h>
#include "leakmem.h"

void f()
{
    MALLOC(100);
}

int main()
{
    //开辟内存空间
    int* p1 = (int*)MALLOC(3 * sizeof(int));
    int* p2 = (int*)MALLOC(3 * sizeof(int));

    f();

    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;
    p2[4] = 100;

    //内存泄漏


    FREE(p1);
    //FREE(p2);

    PRINT_LEAK_INFO();

    return 0;
}