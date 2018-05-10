\uFEFF#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
   pid_t pid;
   int count=0;
   pid=vfork();
   count++;
   printf("count=%d\n",count);
   exit(0);
   //return 0;
}
