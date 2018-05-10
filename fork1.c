#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

main()
{
   pid_t pid;

   pid=fork();
   if(pid<0)
      printf("error in fork!\n");
   else if(pid==0)
      printf("I am the child process, my ID is %d\n",getpid());
   else
      printf("I am the parent process,my ID is %d\n",getppid());
}
