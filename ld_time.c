//
// Created by xusheng on 2/23/17.
//


#include <time.h>
#include <sys/time.h>
//typedef time_t (orig_time_func)(time_t *t);

static long tt = 1487861125;

time_t time (time_t *t){
    return (time_t) tt;
}


static long ttt = 1487861125;
int gettimeofday(struct timeval *tv, struct timezone *tz){
    tv->tv_sec = (time_t) ttt;
    tv->tv_usec = 0;
    return 0;
}