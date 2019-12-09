//
// Created by Jesson on 2019/12/2.
//
#include <stdio.h>
#include <time.h>
typedef struct date{
    int day_year;
    char day_day;
    char day_mon;
};

typedef struct time{
    unsigned char ti_min;
    unsigned char ti_hour;
    unsigned char ti_second;
    unsigned char ti_hund;
};


int main(){
    struct date d;
    struct time t;
    getdate(&d);
    printf("%2d/%2d/%2d",d.day_day,d.day_mon,d.day_year);
}
