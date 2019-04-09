#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <string.h>
int main()
{
 	int fd = open("a.txt", O_RDWR | O_CREAT);
	if(fd == -1)
 	{
  		perror("open error");
  		exit(-1);
 	}
 	
	if(fork() > 0)
 	{
  		char buf[64] = {'\0'};
  		write(fd, buf, sizeof(buf));
  		lseek(fd, 0, 0);
  		char* pStr = (char*)mmap(NULL, 64, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd,0);
  		memset(pStr, 0, 64);
  		memcpy(pStr, "world", 6);
  		sleep(10);
  		munmap(pStr, 64);
  		close(fd);
 	}
 	else
	{
		sleep(2); //保证父有时间写
  		char* pStr = (char*)mmap(NULL, 64, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd,0);
  		puts(pStr);
  		munmap(pStr, 64);
  		close(fd);
 	}
 	
	return 0;
}

/*
 *此时还是没有数据输出， 还是要将 MAP_PRIVATE 更换成 MAP_SHARED 即可。
 */
