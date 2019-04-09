write.c read.c 

此时你会发现文件 mm.dat 的内容为 hello wrold。 因为 MAP_SHARED 会将修改的内容写回文件。如果你将上面的 MAP_SHARED 换成 MAP_PRIVATE，则没有任何输出效果。因为 MAP_PRIVATE是私人的“写入时复制” ，不会写回文件， 只是自己本身的进程有效， 即使你用有亲缘关系的也不行， 这是内存映射 MAP_PRIVATE 与 SYSTEM V 的共享内存的 IPC_PRIVATE 的区别
