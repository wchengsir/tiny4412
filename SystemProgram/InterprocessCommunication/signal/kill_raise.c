/*
 *分别用 kill 和 raise 向自 己发送信号。
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

void fun(int n)
{
 	printf("aaaa n = %d\n",n);
}

int main()
{
 	signal(3,fun);
 	while(1)
 	{
  		printf("hello\n");
  		raise(3);
  		//kill(getpid(), 3);//getpid()是获取本进程的pid， 等价于raise(3);
  		sleep(2);
 	}
 	
	return 0;
}
