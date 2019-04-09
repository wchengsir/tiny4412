/*
 *模拟睡眠 3 秒
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void fun(int n)//空函数， 用于对 SIGALRM 信号进行捕捉处理。
{

}

void my_sleep(int n)
{
 	signal(SIGALRM, fun);
 	alarm(n);
 	pause();
}

int main()
{
 	printf("aaaa\n");
 	my_sleep(3);
 	printf("bbbb\n");
 	return 0;
}

/*
 *
unsigned int sleep(unsigned int seconds);
void usleep(unsigned long usec);
函数 sleep 让进程睡眠 seconds 秒， 函数 usleep 让进程睡眠 usec 微秒。
 sleep 睡眠函数内部是用信号机制进行处理的， 用到的函数有：
unsigned int alarm(unsigned int seconds);
//告知自身进程， 要进程在 seconds 秒后自动产生一个 SIGALRM 的信号
int pause(void); //将自身进程挂起， 直到有信号发生时返回
*/
