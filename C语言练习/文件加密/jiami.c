//
// Created by jesson on 2019-01-02.
//

#include <stdio.h>
#include <string.h>

/***
 * 加密
 * @param normal_path
 * @param crypt_path
 * @param password
 */
void crypt(char normal_path[], char crypt_path[], char password[]){
    //打开文件
    FILE *normal_fp = fopen(normal_path, "rb");
    FILE *crypt_fp = fopen(crypt_path, "wb");
    //一次读取一个字符
    int ch;
    int i = 0; //循环使用密码中的字母进行异或运算
    int pwd_len = strlen(password);//密码长度
    while ((ch = fgetc(normal_fp)) != EOF){
        //写入异或运算 自己实现 ch ^ password[i % pwd_len]
        fputc(ch ^ password[i % pwd_len], crypt_fp);
        i++;
    }
    //关闭
    fclose(crypt_fp);
    fclose(normal_fp);
}
/***
 * 解密
 * @param crypt_path
 * @param decrypt_path
 * @param password
 */
void decrpypt(char crypt_path[], char decrypt_path[], char password[]){
    //打开文件
    FILE *normal_fp = fopen(crypt_path, "rb");
    FILE *crypt_fp = fopen(decrypt_path, "wb");
    //一次读取一个字符
    int ch;
    int i = 0;
    int pwd_len = strlen(password);//密码的长度
    while ((ch = fgetc(normal_fp)) != EOF){
        //写入（异或运算）
        fputc(ch ^ password[i % pwd_len], crypt_fp);
        i++;
    }
    //关闭
    fclose(crypt_fp);
    fclose(normal_fp);
}
void main(){
    char *normal_path = "../文件加密/cfg.ini";
    char *crypt_path = "../文件加密/cfg_crypt.ini";
    char *decrypt_path = "../文件加密/cfg_decrypt.ini";

    //加密：密钥 ndk
    char* str = "hellocpp";
    crypt(normal_path, crypt_path, str);
    //解密
    decrpypt(crypt_path, decrypt_path, str);
    //getchar();
}
