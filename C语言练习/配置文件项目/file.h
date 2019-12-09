

#ifndef C_DEMO_FILE_H
#define C_DEMO_FILE_H



#ifdef __cplusplus
extern "C"{
#endif

//写文件
int writeFile(char* fileName, char* key, char* value,int* len);
//读文件
int readFile(char* fileName, char* key, char** value,int* len);

#ifdef __cplusplus
}
#endif

#endif //C_DEMO_FILE_H
