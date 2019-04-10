#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

#define BUFFER 127

struct msgtype { //重新定义该结构体
 	long mtype; //第一个参数不变
 	char buf[BUFFER+1];
};

int main()
{
	key_t key = ftok("./b.txt", 1);
	int msgid = msgget(key, 0777 | IPC_CREAT); //获取消息队列
	printf("msgid = %d\n", msgid);

	struct msgtype msg;
	
	memset(&msg,0,sizeof(struct msgtype));
	
	msg.mtype = 1;     //给结构体的成员赋值
	strncpy(msg.buf,"hello",BUFFER);
	
	msgsnd(msgid,&msg,sizeof(struct msgtype),0); //发送信号
	
	memset(&msg,0,sizeof(struct msgtype)); //清空结构体
	
	msgrcv(msgid,&msg,sizeof(struct msgtype),2,0); //接收信号
	printf("客户端收到消息: %s\n", msg.buf);
	
	return 0;
}
