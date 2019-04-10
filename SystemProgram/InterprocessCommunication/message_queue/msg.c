/*
 * 有亲缘关系的消息队列
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

struct MSG{
 	long mtype;
	char buf[64];
};


int main()
{
 	int msgid = msgget(1234, 0666|IPC_CREAT);
 	printf("msgid = %d\n", msgid);

 	struct MSG msg;
 	memset(&msg, 0, sizeof(struct MSG));
 	
	if(fork() > 0)
 	{
		msg.mtype = 1;
		strcpy(msg.buf,"aaaa");
		msgsnd(msgid, &msg, sizeof(struct MSG), 0);
		wait(NULL);
		msgctl(msgid, IPC_RMID, NULL);
	}else {
		sleep(2);  //让父进程有时间往消息队列里面写
		msgrcv(msgid, &msg, sizeof(struct MSG), 1, 0);
		puts(msg.buf);
	}
	
	return 0;
}
