////
//// Created by Jesson on 2019-11-24. edit mem
////
//
//#include <printf.h>
//#include <stdlib.h>
//
//int main(){
//    int len;
//    printf("请输入首次分配内存大小：");
//    scanf("%d", &len);
//    // 动态分配内存,内存空间是连续的
//    int* p = (int*)malloc(len * sizeof(int));
//    int i = 0;
//    for (; i < len ; i++)
//    {
//        p[i] = rand()% 100;
//        printf("array[%d] = %d , %d\n", i, p[i], *(p+i));
//    }
//
//    //在原有内存上面，重新分配内存大小
//    printf("请输入增加的内存大小");
//    int add;
//    scanf("%d", &add);
//    // 重新申请内存大小 ， 传入申请的内存指针 ， 申请内存总大小
//    //一定要注意这里的realloc 本质上有3中意思  pnull sizenull 否则容易内存泄漏
//
//    int* p2 = (int*)realloc(p, (len + add) * sizeof(int));
//    // 给新申请的内存空间赋值
//    int j = len;
//    for (; j < len + add ; j++)
//    {
//        p2[j] = rand() % 200;
//
//    }
//    // 打印
//    j = 0;
//    for (; j < len + add; j++)
//    {
//        printf("array[%d] = %d , %#x\n", j, p2[j], &p2[j]);
//    }
//
//    // 回收申请的动态内存
//    if (p2 != NULL)
//    {
//        free(p2);
//        p2 = NULL;
//    }
//
//    return -1;
//}


#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* calloc, exit, free */

int main ()
{
    int i,n;
    int * pData;
    printf ("Amount of numbers to be entered: ");
    scanf ("%d",&i);
    pData = (int*) calloc (i,sizeof(int));
    if (pData==NULL) exit (1);
    for (n=0;n<i;n++)
    {
        printf ("Enter number #%d: ",n+1);
        scanf ("%d",&pData[n]);
    }
    printf ("You have entered: ");
    for (n=0;n<i;n++) printf ("%d ",pData[n]);
    free (pData);
    return 0;
}