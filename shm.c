#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define PERM S_IRUSR | S_IWUSR
int main(int argc,char **argv)
{
    int shmid;
    char *p_addr,*c_addr;
    if(argc!=2)
    {
    	printf("please input two parameters\n");
    	exit(1);
    }
    if((shmid=shmget(IPC_PRIVATE,1024,PERM))==-1)
    {
    	fprintf(stderr,"Create Share Memory Error\n");
    	exit(1);
    }
    if(!vfork())
    {
    	p_addr=shmat(shmid,0,0);
    	memset(p_addr,'\0',1024);
    	strncpy(p_addr,argv[1],1024);
    	wait(NULL);
    	exit(0);
    }
    else
    {
    	sleep(1);
    	c_addr=shmat(shmid,0,0);
    	printf("Client get %s\n",c_addr);
    	exit(0);
    }
}
