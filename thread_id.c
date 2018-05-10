#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/*�߳�ִ�к���*/
void *create(void *arg)
{
    printf("New thread ...\n");
    printf("This thread's id is %u\n",(unsigned int)pthread_self());
    printf("This process's id is %d\n",getpid()); 
    return (void *)0;
}

int main(int argc,char *argv[])
{
    pthread_t tidp;
    int error;
    printf("Main thread is starting ....\n");
    error = pthread_create(&tidp, NULL, create, NULL);
    if( error )
    {
        printf("phread is not created...\n");
        return -1;
    }
    /*���������̴߳�����pidһ����*/
    printf("This main process's id is %d\n",getpid()); 
    sleep(1); 

    return 0;
}