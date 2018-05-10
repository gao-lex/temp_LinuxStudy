#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	pid_t pc,pr;

	/* 创建子进程 */
	pc=vfork();
	if(pc==0)
	{
		printf("I am the child: %d\n", getpid());
	        sleep(10);
	}
	else if(pc>0)       //父进程
		{
			pr=wait(NULL); //等到子进程退出，父进程才会运行
			printf("I am the father:%d\n",getpid());
		}
	exit(0);
}
