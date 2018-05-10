#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

main()
{
   pid_t pid;

   pid=fork();
   if(pid<0)
      printf("pid<0\n");
   else if(pid==0)
      printf("pid == 0\n");
   else
      printf("pid > 0\n");
}
