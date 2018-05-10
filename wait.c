#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	pid_t pc,pr;

	/* �����ӽ��� */
	pc=vfork();
	if(pc==0)
	{
		printf("I am the child: %d\n", getpid());
	        sleep(10);
	}
	else if(pc>0)       //������
		{
			pr=wait(NULL); //�ȵ��ӽ����˳��������̲Ż�����
			printf("I am the father:%d\n",getpid());
		}
	exit(0);
}
