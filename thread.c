//
// Created by Jesson on 2019/12/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
//
//int gcn = 0;
//pthread_mutex_t mutex;
//
//void* thread_1(void* arg){
//    int i;
//    for (int i = 0; i < 1000000; i++) {
//        pthread_mutex_lock(&mutex);
//        gcn++;
//        pthread_mutex_unlock(&mutex);
//    }
//    pthread_exit((void *)0);
//}
//
//
//void* thread_2(void* arg){
//    int i;
//    for (int i = 0; i < 1000000; i++) {
//        pthread_mutex_lock(&mutex);
//        gcn++;
//        pthread_mutex_unlock(&mutex);
//    }
//    pthread_exit((void *)0);
//}
//
//int main(){
//    int j,error;
//    pthread_t t1,t2;
//
//    pthread_mutex_init(&mutex,NULL);
//    for (int j = 0; j < 10; j++) {
//        error = pthread_create(&t1,NULL,thread_1,0);
//        if(error !=0){
//            printf("创建pthread1 失败");
//            _exit(0);
//        }
//        error = pthread_create(&t2,NULL,thread_1,0);
//        if(error !=0){
//            printf("创建pthread2 失败");
//            _exit(0);
//        }
//        error = pthread_join(t1,NULL);
//        if(error !=0){
//            printf("join pthread1 失败");
//            _exit(0);
//        }
//        error = pthread_join(t2,NULL);
//        if(error !=0){
//            printf("join pthread2 失败");
//            _exit(0);
//        }
//        printf("gcn=>%d",gcn);
//        gcn = 0;
//    }
//    pthread_mutex_destroy(&mutex);
//}

//开始读写锁和互斥锁的速度调研
//pthread_rwlock_t rwlock;//声明读写锁
//int count;
////写者线程的入口函数
//void* route_write(void* arg)
//{
//    int i= *(int*)arg;//i是写者线程的编号
//    free(arg);
//    while(1){
//        int t=count;
//        //加锁
//        pthread_rwlock_wrlock(&rwlock);
//        printf("route_write:%d,%#x,count=%d,++count=%d\n",i,\
//                pthread_self(),t,++count);
//        //解锁
//        pthread_rwlock_unlock(&rwlock);
//        sleep(1);
//    }
//}
////读者线程的入口函数
//void*route_read(void*arg)
//{
//    int i=*(int*)arg;//i是读者线程的编号
//    free(arg);
//    while(1){
//        //加锁
//        pthread_rwlock_rdlock(&rwlock);
//        printf("route_read:%d,%#x,count=%d\n",i,pthread_self(),count);
//        //解锁
//        pthread_rwlock_unlock(&rwlock);
//        sleep(1);
//    }
//}
//int main()
//{
//    int i=0;
//    //初始化读写锁
//    pthread_rwlock_init(&rwlock,NULL);
//    pthread_t tid[8];
//    //创建3个写者线程
//    for(i=0;i<3;i++){
//        int*p=(int*)malloc(sizeof(int));
//        *p=i;
//        pthread_create(&tid[i],NULL,route_write,(void*)p);
//    }
//    //创建3个读者线程
//    for(i=0;i<5;i++){
//        int*p=(int*)malloc(sizeof(int));
//        *p=i;
//        pthread_create(&tid[i+3],NULL,route_read,(void*)p);
//    }
//    //主线程等待新创建的线程
//    for(i=0;i<8;i++)
//        pthread_join(tid[i],NULL);
//    //销毁读写锁
//    pthread_rwlock_destroy(&rwlock);
//    return 0;
//}

//==========条件变量===========
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 3
#define TCOUNT      10
#define COUNT_LIMIT 10

int count = 0;
int thread_ids[3] = {0,1,2};
pthread_mutex_t count_mutex;//互斥量
pthread_cond_t  count_threshold_cv;//条件变量

void *inc_count(void *idp)
{
    int i = 0;
    int taskid = 0;
    int *my_id = (int*)idp;

    for (i=0; i<TCOUNT; i++) {
        pthread_mutex_lock(&count_mutex);
        taskid = count;
        count++;

        /*
          唤醒一个阻塞在该条件变量到线程
          如果没有线程被阻塞在条件变量上，那么调用pthread_cond_signal()将没有作用
        */
        pthread_cond_signal(&count_threshold_cv);

        printf("inc_count(): thread %d, count = %d, unlocking mutex,i=%d\n", *my_id, count,i);
        pthread_mutex_unlock(&count_mutex);
        sleep(1);
    }
    printf("inc_count(): thread %d, Threshold reached.\n", *my_id);

    pthread_exit(NULL);
}

void *watch_count(void *idp)
{
    int *my_id = (int*)idp;
    printf("Starting watch_count(): thread %d\n", *my_id);

    pthread_mutex_lock(&count_mutex);
    while(count<COUNT_LIMIT) {
        sleep(3);
        /*
          函数将自动/原子到解锁mutex参数指向的互斥锁，并使当前线程阻塞在cv参数指向的条件变量上
          被阻塞的线程可以被pthread_cond_signal函数，pthread_cond_broadcast函数唤醒，也可能在被信号中断后被唤醒
          pthread_cond_wait函数的返回并不意味着条件的值一定发生了变化，必须重新检查条件的值.
          本例子中使用类COUNT_LIMIT最为满足条件的值
          pthread_cond_wait函数返回时，相应的互斥锁将被当前线程锁定，即使是函数出错返回
        */
        pthread_cond_wait(&count_threshold_cv, &count_mutex);
        printf("watch_count(): thread %d Condition signal received.\n", *my_id);
    }

    count += 100;
    pthread_mutex_unlock(&count_mutex);
    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    int i, rc;
    pthread_t threads[3];
    pthread_attr_t attr;


    pthread_mutex_init(&count_mutex, NULL);
    pthread_cond_init (&count_threshold_cv, NULL);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&threads[0], &attr, inc_count,   (void *)&thread_ids[0]);
    pthread_create(&threads[1], &attr, inc_count,   (void *)&thread_ids[1]);
    pthread_create(&threads[2], &attr, watch_count, (void *)&thread_ids[2]);

    for (i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf ("Main(): Waited on %d  threads. Done.\n", NUM_THREADS);

    /* Clean up and exit */
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&count_threshold_cv);
    pthread_exit(NULL);

    return 0;
}