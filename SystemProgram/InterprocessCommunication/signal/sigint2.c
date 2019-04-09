/*
 *忽略掉终端 CTRL+c 产生的 SIGINT 信号
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
 	signal(SIGINT,SIG_IGN);
	while(1)
  		sleep(1);
 	return 0;
}

/*
 * 该程序运行起来以后， 将 CTRL+C 产生的 SIGINT 信号忽略掉了，所以 CTRL＋ C 将不再能使该进程终止， 要终止该进程， 可以向进程发送 SIGQUIT 信号， 即组合键 CTRL+\。 或者另外开一个端口， 然后执行 ps –aux 查看进程，发现该进程号之后用 kill -9 进程号 杀掉该进程。
*/
