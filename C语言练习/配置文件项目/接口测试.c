
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#define CFGFILENAME "/Users/jesson/Desktop/c_demo/配置文件项目/cfg.ini"

void print();

int WriteCfgFile();

int ReadCfgFile();

void main(){
    int num;
    for (;;) {
        print();
        scanf("%d",&num);
        switch(num){
            case 1:
                WriteCfgFile();
                break;
            case 2:
                ReadCfgFile(); //读配置项
                break;
            case 0:
                exit(0);
            default:
                exit(0);
        }
    }
}

int ReadCfgFile() {
    int ret = 0;
    //读配置项
    char name[1024] = {0};
    char valude[1024] = {0};
    int	 vlen = 0;

    printf("\n请键入key:");
    scanf("%s", name);

    ret = readFile(CFGFILENAME,name,valude,&vlen);
    if (ret != 0)
    {
        printf("func WriteCfgItem err:%d \n", ret);
        return ret;
    }
    printf("valude:%s \n", valude);
}

int WriteCfgFile() {
    int	ret = 0;
    //写配置项
    char name[1024] = {0};
    char valude[1024] = {0};


    printf("\n请键入key:");
    scanf("%s", name);

    printf("\n请键入valude:");
    scanf("%s", valude);

    ret = writeFile(CFGFILENAME, name, valude,strlen(valude));
    if (ret != 0)
    {
        printf("func WriteCfgItem err:%d \n", ret);
        return ret;
    }
    printf("你的输入是：%s = %s \n", name , valude);
    return ret;
}

void print() {
    printf("==========读写配置文件案例===========\n");
    printf("1===>写配置文件\n");
    printf("2===>读配置文件\n");
    printf("0==>退出\n");
    printf("============begin=================\n");
}
