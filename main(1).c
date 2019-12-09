#include <stdio.h>
void fun();
void fun2();
void fun3();
void fun4();
void fun5();


int main() {
    printf("打印三角形星星\n");
    int i, j, k;
    for (i = 1; i < 5; i++) {
        /* 观察每行的空格数量，补全循环条件 */
        for (j = i; j < 5; j++) {
            printf(" ");    //输出空格
        }
        /* 观察每行*号的数量，补全循环条件 */
        for (k = 0; k < 2 * i - 1; k++) {
            printf("*");
        }
        //每次循环换行
        printf("\n");
    }
    fun();
    fun2();
    return 0;
}
/*给一个时间，计算它是一年的中的第多少天*/
void fun(){
    int date = 0;
    int year = 2018;
    int month = 11;
    int day = 8;
    switch(month)
    {
        case 12:date+=30;
        case 11:date+=31;
        case 10:date+=30;
        case 9:date+=31;
        case 8:date+=31;
        case 7:date+=30;
        case 6:date+=31;
        case 5:date+=30;
        case 4:date+=31;
        case 3:
            if((year%4==0&&year%100!=0)||year%400==0)
            {
                date+=29;
            }
            else
            {
                date+=28;
            }
        case 2:
            date+=31;
        case 1:
            date+=day;
            printf("%d年%d月%d日是该年的第%d天\n",year,month,day,date);
            break;
        default:
            printf("error");
            break;
    }
}
/*测试goto语句的基本用法*/
void fun2(){
    int sum = 0;
    int i = 1;
    LOOP:if(i<10){
        sum+=i;
        i++;
        goto LOOP;
    }
    printf("sum=%d\n",sum);
}
