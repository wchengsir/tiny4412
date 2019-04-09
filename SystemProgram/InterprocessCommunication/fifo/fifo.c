#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc,char *argv[])//演示通过命令行传递参数
{
	if(argc != 2)
	{
  		puts("Usage: MkFifo.exe {filename}");
  		return -1;
 	}
	if(mkfifo(argv[1], 0666) == -1)
	{
 	 	perror("mkfifo fail");
  		return -2;
	}
	//unlink(argv[1]);//加上这句会将创建的FIFO文件删除。
 	
	return 0;
}

/*
 *
用命令创建和删除FIFO文件
 ·用命令mkfifo创建 不能重复创建
 ·用命令unlink删除

创建完毕之后， 就可以访问FIFO文件了：
一个终端： cat < myfifo
另一个终端： echo hello > myfifo
*/
