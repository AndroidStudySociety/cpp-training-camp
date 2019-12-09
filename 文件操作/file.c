#include <stdbool.h>
#include <string.h>
#include "stdio.h"
#include "stdlib.h"




//内存泄漏？ 定义 查 C语言 free（打开一个文件 ）
#define  BUFFSIZE  1024     // 缓冲区大小

void testBasicAPI();


bool copyFile( const char * srcFile , const char * destFile ) {
    FILE *src, *dst;
    if (NULL == srcFile || NULL == destFile) {
       printf("copyFile src or dest file null !" );
       return false;
    }
    src = fopen(srcFile, "rb");
    dst = fopen(destFile, "wb");
    if (NULL == src || NULL == dst) {
        printf("copyFile fopen failed !");
        return false;
    }
    // copy file
    //char buf[1024];
    char *buff = alloca(BUFFSIZE);
    //int len;
    //搞清楚具体的含义
    while (fread(buff, sizeof(char), 1, src) != 0) {
        // write to dst file !
        fwrite(buff, sizeof(char), 1, dst);
        //printf("%3d",len);
    }
    // don't forget to close the files
    fclose(src);
    fclose(dst);
    return true;
}






void main(){
    //testBasicAPI();
    copyFile("../文件操作/src.txt","../文件操作/desc.txt");
}


void testBasicAPI() {
    printf("开始测试file的api\n");
    const char * filepath = "../文件操作/test.txt";
    char ch;
    char out[] = {"abcdefg"};
    FILE* file = fopen(filepath,"r+");
    if(file!= NULL){
        while((ch = fgetc(file)) != EOF){
            printf("%c", ch);
        }
        //写入char字符串信息
        for (int i = 0; i < 7; ++i) {
            printf("返回数值是:%d",fputc(out[i],file));
        }

        while((ch = fgetc(file)) != EOF){
            printf("%3c", ch);
        }
    }
    fclose(file);
}