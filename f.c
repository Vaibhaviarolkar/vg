#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
   
   int CreateSocket , n=0,cnt=0,ClintConnt=0,a,b;

   char dataReceived[1024];

   struct sockaddr_in ipOfServer;

   char buf1[50],str[50],oper;

   if((CreateSocket=socket(AF_INET,SOCK_STREAM,0))<0)
   {
    printf("Socket not connected");
    return 1;
   }

   ipOfServer.sin_family=AF_INET;
   ipOfServer.sin_port=htons(2017);
   ipOfServer.sin_addr.s_addr=sock_inet("127.0.0.1");

   if(connect(CreateSocket ,(struct sockaddr)&ipOfServer sizeof(ipOfServer))<0)
   {
    printf("Connect failed due to port and ip problems");
    return 1;
   }

   printf("Enter name");
   scanf("%s",buf1);

   write(CreateSocket,buf1,strlen(buf1)+1);
   n=read(CreateSocket,dataReceived,512);



}