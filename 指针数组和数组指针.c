//
// Created by Jesson on 2019-11-24.
//

# include<stdio.h>
# include<stdlib.h>
# include <unistd.h>

void main(){
    int array[2][3] = {{1,2,3},{4,5,6}};
    //数组指针（也称行指针）
    //int (*p)[n]; p是一个指针，指向一个整型的一维数组，这个一维数组的长度是n
    int (*array_p)[3] = array;
    //取出5
    printf("%x\n", (unsigned int) array_p);
    printf("%x\n", (unsigned int) (array_p + 1));
    //printf("%x\n", (unsigned int) (array_p + 2));
    printf("取出2元素==>%d\n",*(*(array_p+0)+1));

    //普通遍历
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d\n",array[i][j]);
        }
    }
    //求二维数组元素的最大值。
    int *p,max;
    for(p=array[0],max=*p;p<array[0]+6;p++)
        if(*p>max)
            max=*p;
    printf("MAX=%d",max);
}