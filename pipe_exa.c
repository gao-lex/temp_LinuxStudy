#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int pipe_fd[2];
  char *argv1[]={"ls","-al","/etc",(char *)0};
  char *argv2[]={"less",(char *)0};
  if(pipe(pipe_fd)<0)
  {
    perror("pipe failed");
    exit(errno);
  }
  if(vfork()==0)
  {
    close(pipe_fd[0]);
    dup2(pipe_fd[1],1);
    close(pipe_fd[1]);
    execv("/bin/ls",argv1);
  }
  else
    close(pipe_fd[1]);
    dup2(pipe_fd[0],0);
    close(pipe_fd[0]);
    execv("/usr/bin/less",argv2);
}
