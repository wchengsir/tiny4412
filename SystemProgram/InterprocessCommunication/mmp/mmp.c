#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
int main()
{
 	int i;
 	int fd = open("mm.dat",O_RDWR|O_CREAT);
 	char buf[10] = {"abcdefghi"};
 	write(fd,buf,sizeof(buf));
 	char *p=(char*)mmap(NULL,10 ,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
 	p[2] = 'C';
 	p[3] = 'D';
 	for(i = 0; i <= 9; i++)
  		printf("p[%d] = %c\n", i, p[i]);
 	munmap(p, 10);
 	
	close(fd);
	return 0;
}
