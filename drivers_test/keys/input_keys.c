#include <stdio.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	if(argc != 2){
		printf("Usage : %s </dev/input/eventx> \r\n",argv[0]);
		return -1;
	}

	/* 1. 打开输入设备文件 */
	int fd = open(argv[1],O_RDWR);
	int cnt = 0;
	struct input_event tBtnsEvent;
	
	while(1){
		/* 2. 读取输入设备文件内容,如果没有内容则会发生堵塞 */
		cnt = read(fd,&tBtnsEvent,sizeof(struct input_event));
		if(cnt < 0){
			printf("APP Error : Read is Failed ! \r\n");
			return -1;
		}
		printf("cnt : %d\r\n",cnt);
		
		/* 3. 打印按键信息 */
		switch(tBtnsEvent.code){
			case KEY_1:{
				printf("-----------k1 : %d\r\n",tBtnsEvent.value);
				break;
			}
			case KEY_2:{
				printf("-----------k2 : %d\r\n",tBtnsEvent.value);
				break;
			}
			case KEY_3:{
				printf("-----------k3 : %d\r\n",tBtnsEvent.value);
				break;
			}
			case KEY_4:{
				printf("-----------k4 : %d\r\n",tBtnsEvent.value);
				break;
			}
			default:{
				//printf("APP Error : Read is not mean ! code : %d \r\n",tBtnsEvent.code);
				break;
			}
		}
		usleep(10000);
	}
	close(fd);
	
	return 0;
}


