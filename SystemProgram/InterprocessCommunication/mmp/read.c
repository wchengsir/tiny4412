#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
main()
{
 	int fd = open("mm.dat",O_RDWR); //需要打开同一个文件
	
	char*p=(char*)mmap(NULL,20*sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
 	
	puts(p);
 	
	munmap(p, 20);
 	
	close(fd);

}
