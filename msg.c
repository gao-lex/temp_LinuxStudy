#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buf
{
    int mtype;
    char data[255];
};

int main()
{
    key_t key;
    int msgid;
    int ret;
    struct msg_buf msgbuf;
	
	key=ftok("/tmp/2",'a');  /*�����ļ�����Ӧ�ļ�ֵ*/
	printf("key=[%x]\n",key);
	msgid=msgget(key,IPC_CREAT|IPC_EXCL|0666);  /*�������ֵkey���Ӧ����Ϣ����������*/
	
	if(msgid==-1)
	{
	    printf("create error\n");
            return -1;
	}
	
	msgbuf.mtype=getpid();
	strcpy(msgbuf.data,"hello world");
        ret=msgsnd(msgid,&msgbuf,sizeof(msgbuf.data),IPC_NOWAIT);   /*������Ϣ*/
        if(ret==-1)
        {
        	printf("send message error!\n");
        	return -1;
        }
        
        memset(&msgbuf ,0,sizeof(msgbuf));
        ret=msgrcv(msgid,&msgbuf,sizeof(msgbuf.data),getpid(),IPC_NOWAIT);   /*������Ϣ*/
        if(ret==-1)
        {
        	printf("recv message error!\n");
        	return -1;
        }
        printf("recv msg =[%s]\n",msgbuf.data);
        
}
