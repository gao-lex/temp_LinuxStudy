#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{ int fd[2];
   char *argv1[]={"ls","-al","/etc",(char *)0};
   char *argv2[]={"less",(char *)0};
   if(pipe(fd)<0)
   {  perror("pipe failed");
       exit(errno);  }
   if(vfork()==0)
   {  close(fd[0]);
       dup2(fd[1],stdout); 
            // ls命令的标准输出指向管道的写端口
       execv("/bin/ls",argv1);  }
    else
     {  close(fd[1]);
         dup2(fd[0],stdin);
         execv("/usr/bin/less",argv2); }
  close(fd[0]);
  close(fd[1]);
}
