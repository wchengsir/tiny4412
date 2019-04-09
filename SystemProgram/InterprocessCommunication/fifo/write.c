#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
 	int fd = open("f.fifo", O_WRONLY); //1. 打开（判断是否成功打开略）
 	write(fd, "hello", 6);  //2. 写
 	close(fd);  //3. 关闭
 	return 0;
}


