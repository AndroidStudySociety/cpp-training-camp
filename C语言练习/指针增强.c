//
// Created by Jesson on 2019-11-24.
//
#include <stdlib.h>
#include <stdio.h>
//android 的bitmap

//    AndroidBitmapInfo bmpInfo={0};
//    if(AndroidBitmap_getInfo(env,bmpObj,&bmpInfo)<0)
//    {return -1}
//    int* dataFromBmp=NULL;
//    if(AndroidBitmap_lockPixels(env,bmpObj,(void**)&dataFromBmp))
//    {return -1;}

void main(){
    //二级指针
    int i = 100;
    int* p = &i;
    int** d = &p;
    printf("d的地址是%p\n",*d);
    printf("i的数据是%p\n",p);
    printf("d的内容是%d\n",**d);
    printf("d的内容是%p\n",d);

    //一定要理解

    //数组指针 指针可以操作  自己写一下指针的赋值操作
    int array[] = {1,2,3,4};
    for (int j = 0; j < 4; ++j) {
       // printf("arr[%d]的数据是%d",j,array[j]);
    }
    int* array_p = array; //数组和指针关联
    for (int j = 0; j < 4; ++j) {
       // printf("arr[%d]的数据是%d",j,*array_p++); //第一种
//        printf("======\n");
        printf("arr[%d]的数据是%d\n",j,array_p[j]); //第二种
    }

    //熟悉写法 ffmpeg的 **inputfile  inputfile[0] 获取的是一级指针

    


}