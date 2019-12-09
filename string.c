#include <stdio.h>
#include <string.h>

void paixu(char (*p)[10]);


void main()
{
    char a[10][10],(*p)[10],i;
    printf("请输入10个字符串(每个字符串长度不大于10):\n");
    for (i=0;i<10;i++)
    {
        scanf("%s",a[i]);//按行输入
    }
    p=a;//P指向二维数组的第0行,注意不能写成p=a[0]
    paixu(p);
    printf("排序后为：\n");
    for (i=0;i<10;i++)
    {
        printf("%s\n",a[i]);//按行输出
    }
}
void paixu(char (*p)[10]) {
    //注意:此时P已经指向二维数组的首行了
    int i, j;
    char temp[10], *t = temp;//这里不能直接定义一个*t,因为(*p)[10]必须指向一维数组
    for (i = 0; i < 9; i++)//9趟排序
    {
        for (j = 0; j < 9 - i; j++) {
            if (strcmp(p[j], p[j + 1]) > 0)//只要前一行大于后一行就交换
            {
                strcpy(t, p[j]);          /*这里不好理解，p[j]就是p指向j行*/
                strcpy(p[j], p[j + 1]);
                strcpy(p[j + 1], t);
            }
        }
    }
}