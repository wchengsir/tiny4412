/*
 * 接受信号的默认处理,接受默认处理就相当于没有写信号处理程序
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
int main()
{
 	signal(SIGINT,SIG_DFL);
 	while(1)
  		sleep(1);
 	return 0;
}


