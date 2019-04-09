/*
 * 捕捉终端 CTRL+c 产生的 SIGINT 信号
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
void fun(int n)
{
 	printf("aaaa n = %d\n", n);
}

int main()
{
	signal(SIGINT,fun);//也可以写成 signal(2,fun)
	while(1)
  		sleep(1);
 	return 0;
}

/*
 *该程序运行起来以后， 通过按 CTRL+c 将不再终止程序的运行（或者另开一个终端， 然后发送消息： “ kill –s 2 进程号” 或“ kill -2 进程号” ， 可以实现 Ctrl + c 同样的效果。 因为 CTRL+c 产生的 SIGINT 信号已经由进程中注册的 SignHandler 函数捕捉了。 该程序可以通过 Ctrl+\终止， 因为组合键 Ctrl+\能够产生 SIGQUIT 信号， 而该信号的捕捉函数尚未在程序中注册。
 */
