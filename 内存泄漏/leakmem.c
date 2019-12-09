#include "leakmem.h"

#define SIZE 256
/* 动态内存申请参数结构体 */
typedef struct
{
    void* pointer;
    int size;
    const char* file;
    int line;
} MItem;



static MItem g_record[SIZE]; /* 记录动态内存申请的操作 */

void* mallocEx(size_t n, const char* file, const int line)
{
    void* ret = malloc(n); /* 动态内存申请 */

    if( ret != NULL )
    {
        int i = 0;

        /* 遍历全局数组，记录此次操作 */
        for(i=0; i<SIZE; i++)
        {
            /* 查找位置 */
            if( g_record[i].pointer == NULL )
            {
                g_record[i].pointer = ret;
                g_record[i].size = n;
                g_record[i].file = file;
                g_record[i].line = line;
                break;
            }
        }
    }

    return ret;
}

//java aop 切面编程

void freeEx(void* p)
{
    if( p != NULL )
    {
        int i = 0;

        /* 遍历全局数组，释放内存空间，并清除操作记录 */
        for(i=0; i<SIZE; i++)
        {
            if( g_record[i].pointer == p )
            {
                g_record[i].pointer = NULL;
                g_record[i].size = 0;
                g_record[i].file = NULL;
                g_record[i].line = 0;

                free(p);

                break;
            }
        }
    }
}
/**
 * 定位debug output的print
 */
void PRINT_LEAK_INFO()
{
    int i = 0;

    printf("Potential Memory Leak Info:\n");

    /* 遍历全局数组，打印未释放的空间记录 */
    for(i=0; i<SIZE; i++)
    {
        if( g_record[i].pointer != NULL )
        {
            printf("Address: %p, size:%d, Location: %s:%d\n", g_record[i].pointer, g_record[i].size, g_record[i].file, g_record[i].line);
        }
    }
}