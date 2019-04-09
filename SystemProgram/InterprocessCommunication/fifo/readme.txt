创建命名管道文件
$ mkfifo f.fifo
读写端

然后 gcc –o write write.c
 gcc –o read read.c
./write //发现阻塞，要等待执行./read
 ./read
在屏幕上输出 hello


如果以读取方式打开 FIFO， 并且还没有其它进程以写入方式打开 FIFO， open 函数将被阻塞；同样， 如果以写入方式打开 FIFO， 并且还没其它进程以读取方式 FIFO， open 函数也将被阻塞。但是， 如果 open 函数中包含 O_NONBLOCK 选项， 则上述两种情况下调用 open 都不被阻塞。与 PIPE 相同， 关闭 FIFO 时， 如果先关读取端， 将导致继续往 FIFO 中写数据的进程收到SIG_PIPE 的信号。
