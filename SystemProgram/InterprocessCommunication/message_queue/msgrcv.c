#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/msg.h>

#define BUFFER 127

struct msgtype {
 long mtype;
 char buf[BUFFER+1];
};

int main()
{
	key_t key = ftok("./b.txt", 1);
	int msgid = msgget(key, 0777 | IPC_CREAT); //获得消息队列
	printf("msgid = %d\n", msgid);
	
	struct msgtype msg;
	memset(&msg,0,sizeof(struct msgtype));
	while(1)
	{
		msgrcv(msgid,&msg,sizeof(struct msgtype),1,0); //接收信号
		printf("服务器收到消息: %s\n", msg.buf);
		msg.mtype = 2;
		strncpy(msg.buf,"world",BUFFER);
		msgsnd(msgid,&msg,sizeof(struct msgtype),0);  //4. 发送信号
	}
	
	return 0;
}
