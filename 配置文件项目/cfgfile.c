

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxLine 2048

//写文件
int writeFile(const char* fileName, const char* key,const char* value){
    int		rv = 0, iTag = 0, length = 0;
    FILE	*fp = NULL;
    char	lineBuf[MaxLine];
    char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
    char	filebuf[1024*8] = {0};

    if (fileName==NULL || key==NULL || value==NULL)
    {
        rv = -1;
        printf("SetCfgItem() err. param err \n");
        goto End;
    }

    fp = fopen(fileName, "r+");
    if (fp == NULL)
    {
        rv = -2;
        printf("fopen() err. \n");
        //goto End;
    }

    if (fp == NULL)
    {
        fp = fopen(fileName, "w+t");
        if (fp == NULL)
        {
            rv = -3;
            printf("fopen() err. \n");
            goto End;
        }
    }

    fseek(fp, 0L, SEEK_END); //把文件指针从0位置开始，移动到文件末尾
    //获取文件长度;
    length = ftell(fp);

    fseek(fp, 0L, SEEK_SET);

    if (length > 1024*8)
    {
        rv = -3;
        printf("文件超过1024*8, nunsupport");
        goto End;
    }

    while (!feof(fp))
    {
        //读每一行
        memset(lineBuf, 0, sizeof(lineBuf));
        pTmp = fgets(lineBuf, MaxLine, fp);
        if (pTmp == NULL)
        {
            break;
        }

        //key关键字是否在本行
        pTmp = strstr(lineBuf, key);
        if (pTmp == NULL) //key关键字不在本行， copy到filebuf中
        {
            strcat(filebuf, lineBuf);
            continue;
        }
        else  //key关键在在本行中，替换旧的行，再copy到filebuf中 
        {
            sprintf(lineBuf, "%s = %s\n", key, value);
            strcat(filebuf, lineBuf);
            //若存在key
            iTag = 1;
        }
    }

    //若key关键字，不存在 追加
    if (iTag == 0)
    {
        fprintf(fp, "%s = %s\n", key, value);
    }
    else //若key关键字，存在，则重新创建文件
    {
        if (fp != NULL)
        {
            fclose(fp);
            fp = NULL; //避免野指针
        }

        fp = fopen(fileName, "w+t");
        if (fp == NULL)
        {
            rv = -4;
            printf("fopen() err. \n");
            goto End;
        }
        fputs(filebuf, fp);
        //fwrite(filebuf, sizeof(char), strlen(filebuf), fp);
    }

    End:
    if (fp != NULL)
    {
        fclose(fp);
    }
    return rv;
}
//读文件
int readFile(const char* fileName, const char* key,const char** value){
    int		ret = 0;
    FILE	*fp = NULL;
    char	*pTmp = NULL, *pEnd = NULL, *pBegin = NULL;

    char lineBuf[MaxLine]; //开了一个内存空间 没有初始化

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        ret = -1;
        return ret;
    }

    while (!feof(fp))
    {
        memset(lineBuf, 0, sizeof(lineBuf));
        //fgets(_Out_z_cap_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);
        fgets(lineBuf, MaxLine, fp);
        //printf("lineBuf:%s ",lineBuf );

        pTmp = strchr(lineBuf, '='); // name = jesson
        if (pTmp == NULL) //没有=号
        {
            continue;
        }

        pTmp = strstr(lineBuf, key);
        if (pTmp == NULL) //判断key是不是在 //所在行 是不是有key
        {
            continue;
        }
        pTmp = pTmp + strlen(key); //mykey1 = myvalude11111111 ==> "= myvalude1111111"

        pTmp = strchr(pTmp, '=');
        if (pTmp == NULL) //判断key是不是在 //所在行 是不是有key
        {
            continue;
        }
        pTmp = pTmp + 1;
        //
        //printf("pTmp:%s ", pTmp);

        //获取value 起点
        while (1)
        {
            if (*pTmp == ' ')
            {
                pTmp ++ ;
            }
            else
            {
                pBegin = pTmp;
                if (*pBegin == '\n')
                {
                    //没有配置value
                    //printf("配置项:%s 没有配置value \n", key);
                    goto End;
                }
                break;
            }
        }

        //获取valude结束点
        while (1)
        {
            if ((*pTmp == ' ' || *pTmp == '\n'))
            {
                break;
            }
            else
            {
                pTmp ++;
            }
        }
        pEnd = pTmp;

        //赋值
        *value = pEnd-pBegin;
        memcpy(value, pBegin, pEnd-pBegin);
    }

    End:
    if (fp == NULL)
    {
        fclose(fp);
    }
    return 0;
}
