//
// Created by jesson on 2019-11-24.
//


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>


void readFileData(FILE *pFILE, int num, char **pString);

void printData(char **pString, int num);

void freespace(char **pString,int num);

int getFilelinenum(FILE* file){
    if(file ==NULL){
        printf("文件打开失败");
        return -1;
    }
    int num = 0;
    char buff[1024];//定义1024缓冲区
    while(fgets(buff,1024,file)!=NULL){
        printf("%s",buff);
        num++;
    }

    //文件光标处理 放置头部
    fseek(file,0,SEEK_SET);
    return num;
}

/**
 *
 * @param pFILE  文件指针
 * @param num 有效行数
 * @param pString 把有效的数据放到堆区
 */
void readFileData(FILE *pFILE, int num, char **pString) {
    if(pFILE ==NULL||num<0||pString==NULL){
        printf("参数错误");
        return ;
    }
    int index =0;
    char buff[1024];//定义1024缓冲区
    while(fgets(buff,1024,pFILE)!=NULL){
        int currentLen = strlen(buff)+1;
        char * current = malloc(sizeof(char*)*currentLen);
        strcpy(current,buff);
        pString[index++] = current;
        //清空缓冲区
        memset(buff,0,1024);
    }
}

void printData(char **pString, int num) {
    for (int i = 0; i < num; ++i) {
        printf("第%d行的数据是%s",i+1,pString[i]);
    }
}

int main(){
    printf("======BEGIN=========\n");
    FILE* file = fopen("../test.txt","r");
    if(file == NULL){
        printf("文件打开失败");
        return -1;
    }
    int num = getFilelinenum(file);
    //int num = 5;
    char** pArrays = malloc(sizeof(char*)*num);
    readFileData(file,num,pArrays);
    printData(pArrays,num);
    //释放数据
    freespace(pArrays,num);
    pArrays = NULL;



}

void freespace(char **pString,int num) {
    for (int i = 0; i < num; ++i) {
        if(pString[i]!=NULL){
            free(pString[i]);
            pString[i] = NULL;
        }
    }
    free(pString);
    pString = NULL;
}




