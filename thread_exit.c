#include <stdio.h>
#include <pthread.h>

void *create(void *arg)
{
    printf("new thread is created\n");
    //return (void *)1;
    //pthread_exit((void *)2);
    exit(0);
    
}

int main()
{
    pthread_t pt;
    int rn;
    void *tmp;
    
    rn=pthread_create(&pt,NULL,create,NULL);
    printf("main thread!\n");
    
    if(rn)
    {
    	printf("pthread is not created \n");
    	return -1;
    }
    rn=pthread_join(pt,&tmp); //等待线程退出
    
    if(rn)
    {
    	printf("pthread is not exit \n");
    	return -2;
    }
    
    printf("thread is exit code %d\n",(int)tmp);  //判断该语句是否能执行
    
    return 0;
	
}
