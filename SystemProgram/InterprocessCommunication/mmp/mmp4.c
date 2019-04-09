#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>

typedef struct {
 int integer;
 char string[24];
} RECORD;

#define NRECORDS 100

int main()
{
	RECORD record, *mapped;
 	int i, f;
 	FILE *fp;
	fp = fopen("records.dat","w+");
	
	//写入 100 个学生
 	for(i=0; i<NRECORDS; i++) {
  		record.integer = i;
  		sprintf(record.string,"RECORD-%d",i);
  		fwrite(&record,sizeof(record),1,fp);
 	}
 
	fclose(fp);
   	
	/* 采用普通的方式修改 */
 	fp = fopen("records.dat","r+");
 	fseek(fp,43*sizeof(record),SEEK_SET);//跳过前 43 个
 	fread(&record,sizeof(record),1,fp);//读出第 44 个
 	
	record.integer = 143;//修改第 44 个
 	sprintf(record.string,"RECORD-%d",record.integer);
 	
	fseek(fp,43*sizeof(record),SEEK_SET);//定位到 43
 	fwrite(&record,sizeof(record),1,fp);//写入第 44 个
 	fclose(fp);
	
	/* 采用内存映射的形式修改 */
 	int fd= open("records.dat",O_RDWR);
 	mapped = (RECORD *)mmap(NULL, NRECORDS*sizeof(record), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	//内存从 0 开始,长度是 100*学生的大小,可读可写,可以进程间共享,fd 是文件描述符,0 是偏移量
 	mapped[43].integer = 243;//直接修改 44
 	sprintf(mapped[43].string,"RECORD-%d",mapped[43].integer);
  	msync((void *)mapped, NRECORDS*sizeof(record), MS_ASYNC);//写入文件
 	munmap((void *)mapped, NRECORDS*sizeof(record));//取消内存映射
 	close(fd);
 	
	exit(0);
}
