/*
 *创建父子进程， 创建无名管道， 父写子读
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
 	int fds[2] = {0};
 	char buf[32];
	
	pipe(fds);
 
	if(fork() == 0)
 	{
  		sleep(2);
  		read(fds[0], buf, sizeof(buf));//从读端读数据
  		puts(buf);
  		close(fds[0]);
  		close(fds[1]);
 	}
 	else
 	{
  		write(fds[1], "hello", 6); //向写端写数据
  		waitpid(-1, NULL, 0);//等子退出
  		close(fds[0]);
  		close(fds[1]);
 	}
 
	return 0;
}

/*
 *
管道是 linux 进程间通信的一种方式， 如命令 ps -ef | grep ntp
无名管道的特点：
 1 只能在亲缘关系进程间通信（父子或兄弟）
 2 半双工（固定的读端和固定的写端）
 3 他是特殊的文件， 可以用 read、 write 等， 只能在内存中存在
*/
