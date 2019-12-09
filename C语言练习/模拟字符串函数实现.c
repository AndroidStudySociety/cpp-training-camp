#include<stdio.h>
#include<string.h>

int main(){

    char str_array[20] = {'\0'};
    //gets(str_array);
    //puts(str_array);

    fgets(str_array,sizeof(str_array),stdin);//从标准输入中读入字节数-1个字节的字符
    fputs(str_array,stdout);

    char *ptr_string = "helloworld";
    printf("ptr_string len:%d\n",strlen(ptr_string));

    printf("==============strcpy==================\n");
    char str_array2[20] = {'\0'};
    strcpy(str_array2,ptr_string);
    printf("str_array2:%s\n",str_array2);
    printf("---------------------------\n");

    char str_array3[10] = {"1234567890"};
    strncpy(str_array3,ptr_string,7);//将ptr_str的前7位拷贝进去
    printf("str_array3:%s\n",str_array3);

    printf("===============strcmp===============\n");

    char *ptr_string_1 = "helloworld";
    char *ptr_string_2 = "helloworld";

    printf("value:%d\n",strcmp(ptr_string_1,ptr_string_2));//等于0相等，大于零，即前一个大于后一个，小于0,前一个小于后一个，按ascii码比较
    char *ptr_string_3 = "nuli";
    printf("value:%d\n",strcmp(ptr_string_3,ptr_string_2));

    printf("=============strcat=================\n");
    char str_array4[10] = "hello";
    strcat(str_array4,str_array3);
    printf("str_array4:%s\n",str_array4);

    printf("============strchr=================\n");//判断字符串中是否包含字符，返回的是这个字符的指针(从左往右边)
    char *ptr_string_4 = strchr(str_array4,'l');
    printf("ptr_string4:%s,%c\n",ptr_string_4,*ptr_string_4);

    char *ptr_string_5 = strrchr(str_array4,'l');//从右往左寻找
    printf("ptr_string4:%s,%c\n",ptr_string_5,*ptr_string_5);

    if(strchr(ptr_string_5,'o')!=NULL){
        printf("ptr_string_5 contains o!\n");
    }else{
        printf("ptr_string_5 not contains o!\n");
    }

    printf("==================strstr===========\n");//字符串中是否包含另外一个字符串
    char *str9 = "hello";
    char *str10 = "first helloworld";
    if(strstr(str10,str9) != NULL){
        printf("str10 contains str9\n");
    }else{
        printf("str10 not contains str9\n");
    }

    printf("=================strtok=============\n");

    char str[] ="hello:zzf:hello:tom";
    int counter = 0;
    char *p = strtok(str,":");
    while(p!=NULL){
        counter++;
        printf("%s",p);
        p = strtok(NULL,":");
    }

    printf("================memset,memcpy==========");//内存清空和拷贝
    char src[] = "i love you";
    char des[] = "you love me";
    memset(des,0,sizeof(des));//清空或者初始化
    memcpy(des,src,sizeof(des)-1);//拷贝des字节数-1,最后一个符号用于存储结束符号
    return 0;
}
