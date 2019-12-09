//
// Created by Jesson on 2019-11-24.
//

#include "file_operate.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <time.h>


#define MAX_LINE 1024              // max line-length of the file.
#define MAX_SIZE 1024*100          // max file size.
#define MAX_BLOCK_SIZE 1          // set '1', ensure read all bytes.
#define MAX_BLOCK_NUM 1024*1024

char *buff = NULL;  // use for complete file caching.

long length(const char *filename){
    if (NULL == filename){
        printf("file name cannot be empty.\n");
        return -1;
    }

    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL){
        printf("%s: open failed.\n", filename);
        return -1;
    }

    int f_tail = 0;
    fseek(fp, 0L, SEEK_END);
    f_tail = ftell(fp);
    fclose(fp);

    return f_tail;
}

/***
 *
 * @param filename
 * @return
 */
int read_by_text_line(const char *filename){
    if (NULL == filename){
        printf("file name cannot be empty.\n");
        return -1;
    }

    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL){
        printf("%s: open failed.\n", filename);
        return -1;
    }

    char str[MAX_LINE+1] = {0};
    buff = (char*)malloc(MAX_SIZE +1);
    if (buff == NULL){
        printf("Failure to apply for heap space.\n");
        return -1;
    }
    /* notes:
            return null when error or 'EOF', check err by feof();
            auto insert '\n' when last line not contain '\n'
            and it's lenght not to MAX_LINE.*/
    size_t line_len = 0;
    while(NULL != fgets(str, MAX_LINE, fp)){
        memcpy((void*)&buff[line_len], (void*)str, strlen(str));
        line_len += strlen(str);
    }
    /*notes:
     *     why the tail of buff contain a '\n'
     * */
    printf("Read from %s :\n%s", filename, buff);

    free(buff);
    return 0;
}
int read_by_text_block(const char *filename){
    if (NULL == filename){
        printf("file name cannot be empty.\n");
        return -1;
    }

    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL){
        printf("%s: open failed.\n", filename);
        return -1;
    }

    char blocks_[MAX_BLOCK_SIZE * MAX_BLOCK_NUM +1] = {0};
    buff = (char*)malloc(MAX_SIZE);
    if (buff == NULL){
        printf("Failure to apply for heap space.\n");
        return -1;
    }
    /* notes:
     * */
    size_t pos_ = 0;
    while(0 != fread(blocks_, MAX_BLOCK_SIZE, MAX_BLOCK_NUM, fp)){
        //printf("blocks_ : %s\n", blocks_);
        memcpy((void*)&buff[pos_], (void*)blocks_, strlen(blocks_));
        pos_ += strlen(blocks_);
    }
    printf("[%d]:[%d]", MAX_BLOCK_SIZE, MAX_BLOCK_NUM);
    printf("Read from %s :\n%s", filename, buff);

    free(buff);
    fclose(fp);
    return 0;
}

int read_by_binary_line(const char *filename){
    return 0;
}
int read_by_binary_block(const char *filename){
    return 0;
}
int write_by_text_line(const char *filename){
    return 0;
}
int write_by_text_block(const char *filename){
    return 0;
}
int write_by_binary_line(const char *filename){
    return 0;
}
int write_by_binary_block(const char *filename){
    return 0;
}