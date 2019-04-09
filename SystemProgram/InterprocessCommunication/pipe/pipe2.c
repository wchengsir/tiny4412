/*
 *
管道两端的关闭是有先后顺序的， 如果先关闭写端则从另一端读数据时， read 函数将返回 0，表示管道已经关闭； 但是如果先关闭读端， 则从另一端写数据时， 将会使写数据的进程接收到SIGPIPE 信号， 如果写进程不对该信号进行处理， 将导致写进程终止， 如果写进程处理了该信号，则写数据的 write 函数返回一个负值， 表示管道已经关闭。 
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void fun(int n)
{
 	printf("receive a signal:SIGPIPE\n");
}

int main()
{
 	int fds[2];
 	char buf[10];
	
	pipe(fds);
 	signal(SIGPIPE, fun);
 
	if(fork() == 0)
 	{
  		sleep(2);//确保父关闭读
  		read(fds[0], buf, sizeof(buf));
  		puts(buf);
  		close(fds[0]);//子关闭读
  		close(fds[1]);//子关闭写
 	}
 	else
 	{
  		close(fds[0]);//父关闭读
  		write(fds[1], "hello", 6);
  		wait(NULL);
  		write(fds[1], "world", 6);//管道读端已全关闭， 父还在写， 将产生 SIGPIPE 信号
  		close(fds[1]);//父关闭写
 	}
 	
	return 0;
}


