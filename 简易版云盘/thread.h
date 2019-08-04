#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

/*
 *qi dong xian cheng
 *
 */
void thread_start(int c);

void resume(int c,char* myargv[]);
/*
 *gong zuo xian cheng
 *
 */
void*  work_thread(void * arg);


void get_argv(char buff[],char * myargv[]);

void send_file(int c,char* myargv[]);

int recv_file(int sockfd,char *name);
