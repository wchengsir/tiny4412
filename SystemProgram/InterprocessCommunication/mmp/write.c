#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
main()
{
 	int fd = open("mm.dat",O_RDWR|O_CREAT); //创建一个新文件并以读写方式打开
 	char buf[20] = {0};
 	
	write(fd,buf,sizeof(buf));//文件不能为空,写入 20 个 0， 保证文件不为空 
	
	char*p=(char*)mmap(NULL,20*sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
 	
	memset(p, 0, 20); //最好先初始化为 0
 	
	memcpy(p, "hello world", 12);//写 hello 到内存
 	
	sleep(5);
 	
	munmap(p, 20);
 	
	close(fd);
	
}
