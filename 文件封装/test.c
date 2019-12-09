//
// Created by Jesson on 2019-11-24.
//

#include "file_operate.h"

#include <stdio.h>


const char *w_file = "./w_file";
const char *r_file = "/etc/profile";

void run(){
//    const char *filename = "/etc/profile";
//    printf("file length: %ld\n", length(filename));
    int ret = -1;
    if((ret = read_by_text_line(r_file))){
//    if((ret = read_by_text_block(r_file))){
        printf("Read file err.\n");
    }
}

int main(int argc, char *argv[])
{
    run();
    return 0;
}
