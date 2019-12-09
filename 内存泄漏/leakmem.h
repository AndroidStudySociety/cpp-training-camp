

#ifndef C_DEMO_LEAKMEM_H
#define C_DEMO_LEAKMEM_H

#include <mm_malloc.h>
#include "stdio.h"

#define MALLOC(n) mallocEx(n, __FILE__, __LINE__)
#define FREE(p) freeEx(p)

void* mallocEx(size_t n, const char* file, const line);
void freeEx(void* p);
void PRINT_LEAK_INFO();



#endif //C_DEMO_LEAKMEM_H



#思路是什么？ Java 包装类 设计模式 aop 能不能别让其他的组的同学直接调用sdk的莫个方法，我们应该自己实现一个方法 名字叫做FREE（）MALLOC（） 钩子HOOk


