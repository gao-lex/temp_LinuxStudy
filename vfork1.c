#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
   pid_t pid;
   int count=0;
   pid=vfork();
   count++;
   printf("count=%d\n",count);
   if(pid==0)
       printf("The child process ID is %d\n",getpid());
   else
       printf("The parent process ID is %d\n",getpid());
   execl("/bin/ls","ls","-al","/etc/passwd",(char *)0);
}
