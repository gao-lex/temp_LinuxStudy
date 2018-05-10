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
	
	key=ftok("/tmp/2",'a');  /*返回文件名对应的键值*/
	printf("key=[%x]\n",key);
	msgid=msgget(key,IPC_CREAT|IPC_EXCL|0666);  /*返回与键值key相对应的消息队列描述字*/
	
	if(msgid==-1)
	{
	    printf("create error\n");
            return -1;
	}
	
	msgbuf.mtype=getpid();
	strcpy(msgbuf.data,"hello world");
        ret=msgsnd(msgid,&msgbuf,sizeof(msgbuf.data),IPC_NOWAIT);   /*发送消息*/
        if(ret==-1)
        {
        	printf("send message error!\n");
        	return -1;
        }
        
        memset(&msgbuf ,0,sizeof(msgbuf));
        ret=msgrcv(msgid,&msgbuf,sizeof(msgbuf.data),getpid(),IPC_NOWAIT);   /*接收消息*/
        if(ret==-1)
        {
        	printf("recv message error!\n");
        	return -1;
        }
        printf("recv msg =[%s]\n",msgbuf.data);
        
}
