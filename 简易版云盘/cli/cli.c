#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX 30

int recv_file(int sockfd,char* name)
{
    char srcname[20] = {0};
    int j = 0;
    int m = 0;
    while(name[j] != '\0')
    {
        srcname[m++] = name[j++];
    }
    srcname[m] = '\0';
    char buff[128]={0};

    char* str = ".download";
    strcat(name,str);

    int fd = open(name,O_WRONLY|O_CREAT,0600);
    if( fd == -1)
    {
        send(sockfd,"err",3,0);
        return;
    }
    int size_have = 0;
    size_have = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
    printf("%d\n",size_have);
    char have_len[20]={0};
    sprintf(have_len,"%d",size_have);
    lseek(fd,size_have,SEEK_SET);
    char bu[10]={0};
    send(sockfd,have_len,19,0);
    recv(sockfd,bu,9,0);
    send(sockfd,"ok",2,0);
    if( recv(sockfd,buff,127,0) <= 0)
    {
        return -1;
    }
    if( strncmp(buff,"ok",2) != 0)
    {
        printf("%s\n",buff);
        return 0;
    }
    send(sockfd,"ok",2,0);
    int size =0;
    sscanf(buff+3,"%d",&size);
    
    /*char* str = ".download";
    strcat(name,str);

    int fd = open(name,O_WRONLY|O_CREAT,0600);
    if( fd == -1)
    {
        send(sockfd,"err",3,0);
        return;
    }*/
    //printf("send 2\n");

    int num = 0;
    int cur_size = size_have;
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

        float f = cur_size*100.0/(size+size_have);
        printf("download:%.2f%%\r",f);
        fflush(stdout);
        if( cur_size >= (size+size_have))
        {
            char cut[MAX] = "mv";
            strcat(cut," ");
            strcat(cut,name);
            strcat(cut," ");
            strcat(cut,srcname);
            printf("%s\n",cut);

            char* myargv[MAX]={0};
            char* s = strtok(cut," ");
            if(s == NULL)
            {
                continue;
            }
            myargv[0] = s;
            int i=1;
            while( (s = strtok(NULL," ")) != NULL )
            {
                myargv[i++] = s;
            }
            

            pid_t pid = fork();
            assert( pid != -1);

            if(pid == 0)
            {
                execvp(myargv[0],myargv);
                printf("error");
                exit(0);
            }

            wait(NULL);
            break;
        }
    }
    printf("\n");
    return 0;
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
   int cur_size = 0;
   while(1)
    {  
       num = read(fd,data,256);
       if( num < 0)
       {
           return ;
       }
       send(c,data,num,0);
       cur_size = cur_size + num;
       float f = cur_size * 100.0/size;
       printf("upload:%.2f%%\r",f);
       fflush(stdout);
       if( cur_size >= size)
       {
           break;
       }
   }

   printf("\n");
   close(fd);

   return;
}

int main()
{
   int sockfd = socket(AF_INET,SOCK_STREAM,0);
   assert( sockfd != -1);
   struct sockaddr_in saddr;
   memset(&saddr,0,sizeof(saddr));
   saddr.sin_family = AF_INET;
   saddr.sin_port = htons(6000);
   saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

   int res = connect(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
   assert( res != -1);
   while( 1 )
   {
     char buff[128]={0};
     printf("Connect success ~]$ ");
     fflush(stdout);
     fgets(buff,128,stdin);

     if(strncmp(buff,"end",3) == 0)
     {
         break;
     }

     buff[strlen(buff)-1]=0;

     if( buff[0] == 0)
     {
         continue;
     }

     char tmp[128] = {0};
     strcpy(tmp,buff);

     char* myargv[10] = {0};
     char *s = strtok(tmp," ");

     int i=0;
     while( s != NULL)
     {
         myargv[i++] = s;
         s = strtok(NULL," ");
     }
     if( strcmp(myargv[0],"get") == 0)
     {
         send(sockfd,buff,strlen(buff),0);
         recv_file(sockfd,myargv[1]);
     }
     else if( strcmp(myargv[0],"put") == 0)
     {
         send(sockfd,buff,strlen(buff),0);
         send_file(sockfd,myargv);
     }
     else
     {
         send(sockfd,buff,strlen(buff),0);
         char read_buff[1024] = {0};
         recv(sockfd,read_buff,1023,0);
         printf("%s",read_buff+3);
     }
   }
   close(sockfd);

   exit(0);
}
