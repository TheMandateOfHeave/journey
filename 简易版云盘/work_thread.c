#include "thread.h"
#include <fcntl.h>

#define ARGC 10

void thread_start(int c)
{
    pthread_t id;
    pthread_create(&id,NULL,work_thread,(void *)c);
}

void get_argv(char buff[],char * myargv[])
{
      //strtok()
    char *p = NULL;
    char *s = strtok_r(buff," ",&p);
    int i=0;
    while(s != NULL)
    {
        myargv[i++]=s;
        s = strtok_r(NULL," ",&p);
    }
}

void send_file(int c,char* myargv[])
{
   if( myargv[1] == NULL)
   {
       send(c,"get:no file name!",17,0);
       return ;
   }
   int fd = open(myargv[1],O_RDONLY);
   if( fd == -1)
   {
       send(c,"not found!",10,0);
       return ;
   }

   int size = lseek(fd,0,SEEK_END);
   lseek(fd,0,SEEK_SET);

   char status[32] = {0};
   sprintf(status,"ok#%d",size);
   send(c,status,strlen(status),0);

   char cli_status[32]={0};
   if( recv(c,cli_status,31,0) <= 0)
   {
       return ;
   }

   if( strcmp(cli_status,"ok") != 0)
   {
       return;
   }

   char data[256]={0};
   int num = 0;

   while((num = read(fd,data,256)) > 0)
   {
       send(c,data,num,0);
   }

   close(fd);

   return;
}

int recv_file(int sockfd,char* name)
{
    char buff[128]={0};
    if( recv(sockfd,buff,127,0) <= 0)
    {
        return -1;
    }

    if( strncmp(buff,"ok",2) != 0)
    {
        printf("%s\n",buff);
        return 0;
    }

    int size =0;
    sscanf(buff+3,"%d",&size);
    printf("file(%s):%d\n",name,size);
    int fd = open(name,O_WRONLY|O_CREAT,0600);
    if( fd == -1)
    {
        send(sockfd,"err",3,0);
        return;
    }

    send(sockfd,"ok",2,0);

    int num = 0;
    int cur_size = 0;
    char data[256] = {0};
    while(1)
    {
        num = recv(sockfd,data,256,0);
        if( num <= 0)
        {
            return -1;
        }
        write(fd,data,num);
        cur_size = cur_size+num;

        float f = cur_size*100.0/size;
        printf("download:%.2f%%\r",f);
        fflush(stdout);
        if( cur_size >= size)
        {
            break;
        }
    }
    printf("\n");
    return 0;
}

/*
 *gong zuo xian cheng
 *
 */
void* work_thread(void * arg)
{
    int c = (int)arg;

    while(1)
    {
        char buff[128] = {0};
        int n = recv(c,buff,127,0);
        if( n <= 0)
        {
            close(c);
            printf("one client closed\n");
            break;
        }

        printf("recv:%s\n",buff);
        char * myargv[ARGC] = {0};
        get_argv(buff,myargv);

        if( strcmp(myargv[0],"get")==0)
        {
            send_file(c,myargv);
        }
        else if( strcmp(myargv[0],"put") == 0)
        {
            recv_file(c,myargv[1]);
        }
        else
        {

        int pipefd[2];         // 0 du  1 xie 
        pipe(pipefd);          // zi jin cheng he fu jin cheng fen bie guan yi ge
        pid_t pid = fork();
        if( pid == 0)
        {
            //guan dao  he dup2(1,pipfd[1])
            //guan dao  he dup2(2,pipfd[1])
            dup2(pipefd[1],1);
            dup2(pipefd[1],2);
            execvp(myargv[0],myargv);
            perror("exec error");
            exit(0);
        }
            close(pipefd[1]);
            wait(NULL);

            char read_buff[1024]={0};
            strcpy(read_buff,"ok#");
            read(pipefd[0],read_buff+strlen(read_buff),1000);
            send(c,read_buff,strlen(read_buff),0);
        }
    }
}
