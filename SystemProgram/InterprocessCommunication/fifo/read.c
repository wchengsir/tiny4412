#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
 	char buf[128];
 	int fd = open("f.fifo", O_RDONLY);
 	read(fd, buf, sizeof(buf));
 	puts(buf);
 	close(fd);
 	return 0;
}
