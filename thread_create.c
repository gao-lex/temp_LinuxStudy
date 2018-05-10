#include <stdio.h>
#include <pthread.h>

void *myThread1(void)
{
    int i;
    for(i=0;i<10;i++)
    {
    	printf("This is the lst pthread!\n");
    	sleep(1);
    }
}

void *myThread2(void)
{
    int i;
    for(i=0;i<10;i++)
    {
    	printf("This is the 2st pthread!\n");
    	sleep(1);
    }
}
int main()
{
    int i=0,rn=0;
    pthread_t pt1,pt2;
    
    /*创建线程1*/
    rn=pthread_create(&pt1,NULL,(void *)myThread1,NULL);
    if(rn)
    {
    	printf("Create pthread1 error\n");
    	return 1;
    }
    
    /*创建线程2*/
    rn=pthread_create(&pt2,NULL,(void *)myThread2,NULL);
    if(rn)
    {
    	printf("Create pthread2 error\n");
    	return 1;
    }
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);
    
    return 0;
	
}
