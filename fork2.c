#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

main()
{
   pid_t pid;
   int count=0;

   pid=fork();
   
   count++;
   printf("count=%d\n",count);
   return 0;
}
