
#include <stdio.h>
#include <string.h>
#include <signal.h>


//获取字符串的信息
int mystrlen(char* str){
    int count = 0;
    while (*str!='\0'){
        count++;
        str++;
    }
    return count;

}


int cmp(char* str, char* str2){
    //int strncmp( const char *lhs, const char *rhs, size_t count );
    return strcmp(str,str2); //aaa hello
}


void main(){

    char str[] = {'s','s','s','\0'};
////    printf("%s\n",str);
////    str[1] = 'a';
////    printf("%s\n",str);
    char* str1 = "sss"; //常量 不能修改
//    //printf("%s\n",str);
    str1 = "aaa";
//    printf("%s\n",str1);

    const int num = 100;
    int* p = &num;
    *p = 300;
    printf("num=%d",num);


//    printf("name 的 长度是 %d",strlen(str1));
    printf("name 的 长度是 %d",strlen(str));

    //char str[] 数据存放在栈上面
    //char* str 字符串存在全局静态只读区域

    //如何实现计算字符串的计数？


    printf("字符串比较%d",cmp(str,str1));

}
//
//
//void main(){
//    volatile const int a=1;
//    int *c = (int *)(&a);
//    *c=*c+1;
//    printf("%d\t",a);
//    printf("%d\t",*c);
//}