//
// Created by Jesson on 2019/10/29.
//

#include <stdio.h>

void exchangeNum(int *a,int *b);
void myarray();
void myarray_pointer();
void myarrayreverse();

int main() {
//    printf("===\n");
//    int a=10,b=1;
//    exchangeNum(&a,&b);
//    printf("a==>%d,b===>%d",a,b);
    //myarray();
    myarray_pointer();
    myarrayreverse();

}
/*数组reverse*/
void myarrayreverse() {
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int i,t;
    for(i=0;i<10/2;i++)//使用了反转的对称性,a[9]与a[0]交换，a[8]与a[1]交换，直到a[5]时交换完毕
    {
        t=a[i];
        a[i]=a[10-i-1];
        a[10-i-1]=t;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }

}

/*交互2个数的大小*/
void exchangeNum(int *a,int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
/*读取字符char，并保存起来*/
void myarray(){
    int x[50];
    int i=0;
    unsigned char resp = 'y';
    char buffer[100];
    int *p1 = &x[0],*p2;
    while (resp =='Y' || resp == 'y'){
        printf("enter element\n");
        scanf("%d",&x[i]);
        printf(" enter one more?");
        fflush(stdin);
        buffer[i] = getchar();
        i++;
        if(i >5){
            resp = 'N';
        }
    }
    p2 = &x[i];
    printf("数组元素一共有%ld\n",p2-p1);
    for(;p1<p2;){
        printf("%d\t",*p1++);
//        printf("%d\t",*(p1++));
//        printf("%d\t",(*p1)++);
    }
}

/*指针和数组的关系*/
void myarray_pointer(){
    int array[5] = {10,11,22,33,56};
    int *ptr = array;
    for (int j = 0; j < 5; ++j) {
        printf("%d\t",*(array+j)); //获取数组的元素 通过取值操作符* array
        printf("%d\t",*(ptr++)); //指针做增量运算 结合访问指针引用的数据元素的值
        printf("%d\t",array[j]);
        printf("%d\t",(*ptr)++);
    }

    int array2[][4] = {{1,2,3,4},
                      {5,6,7,8},
                      {10,11,12,31}};
    int *ptr2 = &array2[0][0];

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 4; k++) {
            printf("%d\t",*ptr2++);
            printf("%d\t",*(*(array2+j)+k)); //二维数组的取数值 把数组当成指针看 来用间接引用符来
        }
    }
}

