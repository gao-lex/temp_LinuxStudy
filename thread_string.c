#include <stdio.h>
#include <pthread.h>

void *create(void *arg)
{
    char *str;
    str=(char *)arg;
    printf("Creat parameter passed from main function is: %s\n",str);
    return (void *) 0;
    
}

int main()
{
    pthread_t pt;
    int rn;
    
    char *s="hello world";
    
    rn=pthread_create(&pt,NULL,create,(void *)s);
    
    if(rn)
    {
    	printf("pthread_create is not created \n");
    	return -1;
    }
    
    sleep(1);
    printf("pthread_create is created!\n");
    
    return 0;
	
}
